#include<iostream>
#include<vector>
#include<string>
#include<chrono>
#include<fstream>
#include<algorithm>
using namespace std;
using namespace chrono;

int nVerts; // # Vertices in the input sequence
vector<int> dSequence; // Input Degree Sequence


// Function for reading a given input path
void ReadInput(const char * inputPath) 
{
	ifstream input_stream(inputPath);
	string readed;

	// Read the first line
	getline(input_stream, readed);
	cout << readed << endl;
	nVerts = stoi(readed);
	// Read n-1 degrees on the second line
	for (int i = 1; i < nVerts; i++)
	{
		getline(input_stream, readed, ' ');
		cout << readed << " ";
		dSequence.push_back(stoi(readed));
	}
	// Read the last degree in the sequence
	getline(input_stream, readed);
	cout << readed << endl;
	dSequence.push_back(stoi(readed));


	cout << "nVerts: " << nVerts << endl;
	for (auto it : dSequence)
		cout << it << " ";
	cout << endl;
}

// Function to check whether a given input is graphical
bool CheckGraphicality()
{
	return true;
}

void HHAlgorithm()
{
	// Implement the recursive application of Havel-Hakimi Theorem here
}


void PairingModel()
{
	// Implement the Pairing Model (Section 3.2) here
}

void SequentialAlgorithm()
{
	// Implement the sequential algorithm (Section 4) here

}

void writeOutput(vector<vector<int>> adjacency_list)
{
	ofstream output_stream("Output.txt");
	int nVerts = adjacency_list.size();
	output_stream << nVerts << endl;
	vector<int> outputSequence;
	for (auto it : adjacency_list)
		outputSequence.push_back(it.size());
	sort(outputSequence.begin(), outputSequence.end(), greater<int>());
	for (auto it : outputSequence)
		output_stream << it << " ";
	output_stream << endl;
	for (int i = 0; i < nVerts; i++)
	{
		output_stream << i + 1 << " ";
		for (auto it : adjacency_list[i])
			output_stream << it +1 << " ";
		output_stream << endl;
	}	
}

int main()
{
	const char * inputPath = "Input.txt"; // path of the given input
	string inputName = "Example";
	ReadInput(inputPath);
	
	//check the input
	bool isGraphical = CheckGraphicality();

	if (isGraphical)
	{
		//run hh algorithm, record time
		auto hh_begin = high_resolution_clock::now();
		HHAlgorithm();
		auto hh_end = high_resolution_clock::now();

		auto pm_begin = high_resolution_clock::now();
		PairingModel();
		auto pm_end = high_resolution_clock::now();

		auto sa_begin = high_resolution_clock::now();
		SequentialAlgorithm();
		auto sa_end = high_resolution_clock::now();

		auto hh_duration = duration_cast<microseconds>(hh_end - hh_begin);
		double hh_time = double(hh_duration.count()) / 1000000;

		auto pm_duration = duration_cast<microseconds>(pm_end - pm_begin);
		double pm_time = double(pm_duration.count()) / 1000000;

		auto sa_duration = duration_cast<microseconds>(sa_end - sa_begin);
		double sa_time = double(sa_duration.count()) / 1000000;

		ofstream runtime_stream("Runtimes.txt");
		runtime_stream << inputName << " " << isGraphical << " " << hh_time << " " << pm_time << " " << sa_time << endl;
	}
	else
	{
		ofstream runtime_stream("Runtimes.txt");
		runtime_stream << inputName << " " << isGraphical << " NA NA NA" << endl;

	}

	vector<vector<int>> example_list(nVerts, vector<int>{});
	example_list[0] = { 1,2,4 };
	example_list[1] = { 0, 2 };
	example_list[2] = { 0,1,3,4 };
	example_list[3] = { 2,4 };
	example_list[4] = { 0,3 };

	writeOutput(example_list);



	return 0;
}
