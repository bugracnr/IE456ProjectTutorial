#include<iostream>
#include<vector>
#include<fstream> // read-write input-output
#include<string> // using strings
#include<chrono> // for chrono-time record
#include<algorithm> // for sort

using namespace std;
using namespace chrono;

int nVerts; // # of vertices in the input file
vector<int> dSequence; // Input degree sequence

void ReadInput(const char* path)
{
	ifstream inputStream(path);
	string readed; // readed part of the input string

	getline(inputStream, readed);	
	nVerts = stoi(readed); //string -> integer: records the value in "readed" to nVerts


	// for reading first n-1 entries on the second line
	for (int i = 1; i < nVerts; i++)
	{
		getline(inputStream, readed, ' ');
		
		dSequence.push_back(stoi(readed));
	}

	// for the last entry on the second line
	getline(inputStream, readed);
	dSequence.push_back(stoi(readed));

	
	cout << "nVerts: " << nVerts << endl;
	cout << "dSequence: ";
	for (auto it : dSequence)
		cout << it << " ";
	cout << endl;
}

// checks whether a degree sequence is graphical
bool CheckGraphical()
{
	// Implement graphicality controls from the paper

	return true;
}


// Runs HH algorithm to generate a graph
void HHAlgorithm()
{
	// Implement HH algorithm
}

// Runs Pairing Model to generate a graph
void PairingModel()
{
	// Implement PM algorithm
}

// Runs Sequential Algorithm to generate a graph
void SequentialAlgorithm()
{
	// Implement Sequential Algorithm
}

// To write a given graph in the described output format
void WriteOutput(const char* path, vector<vector<int>> adjList)
{
	ofstream outputStream(path); // Output stream for the given path

	int outputVerts = adjList.size();
	vector<int> outputSequence;
	for (auto it : adjList)
		outputSequence.push_back(it.size());
	sort(outputSequence.begin(), outputSequence.end(), greater<int>()); // Sorts the vector in decreasing order

	outputStream << outputVerts << endl;
	for (auto it : outputSequence)
		outputStream << it << " ";
	outputStream << endl;

	for (int i = 0; i < outputVerts; i++)
	{
		outputStream << i + 1 << " ";
		for (auto it : adjList[i])
			outputStream << it + 1 << " ";
		outputStream << endl;
	}

}

int main()
{
	const char* inputPath = "C:/Users/bugra/source/repos/IE456ProjectTutorial/IE456ProjectTutorial/Input.txt";
	ReadInput(inputPath);

	CheckGraphical();

	auto hh_begin = high_resolution_clock::now();
	HHAlgorithm();
	auto hh_end = high_resolution_clock::now();

	auto hh_duration = duration_cast<microseconds>(hh_end - hh_begin);
	double hh_time = double(hh_duration.count()) / 1000000; // 1 Second = 1000000 Milliseconds

	cout << "HHAlgorithm Runtime: " << hh_time << endl;

	PairingModel();
	SequentialAlgorithm();


	const char* outputPath = "Output.txt";
	vector<vector<int>> exampleAdjList(nVerts, vector<int>{});
	exampleAdjList[0] = { 1,2,4 }; // Indices starts from 0
	exampleAdjList[1] = { 0,2 }; // Indices starts from 0
	exampleAdjList[2] = { 0,1,3,4 }; // Indices starts from 0
	exampleAdjList[3] = { 2,4 }; // Indices starts from 0
	exampleAdjList[4] = { 0,3 }; // Indices starts from 0

	WriteOutput(outputPath, exampleAdjList);



	return 0;
}