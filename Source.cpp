#include <iostream>
#include <string>
#include <fstream> // File reading/writing library
#include <vector> // For array storage
#include "maxHeap.h"
#include "node.h"

using namespace std;

int main() {

	ifstream Q2InputTXT;
	fstream Q2OutputTXT;

	Q2InputTXT.open("input-q2a2.txt");
	{

		// ====================== INPUT 
		// Opening up input file, reading it.
		// Int and string to hold data input of the .txt file
		int firstLineIn;
		vector<int> nodeNum;
		int numberOfNumbers;
		maxHeap Heap;

		Q2OutputTXT.open("output-q2a2.txt");

		if (Q2InputTXT.is_open())
		{
			// Storing the numbers
			Q2InputTXT >> numberOfNumbers;
			cout << numberOfNumbers << endl;

			for (int i = 0; i < numberOfNumbers; i++)
			{
				int temp;
				Q2InputTXT >> temp;
				nodeNum.push_back(temp);

				// print out each element in the vector
				for (int element : nodeNum) {

					Q2OutputTXT << element << " ";
				}

				Q2OutputTXT << endl;

				Heap.Insert(node(temp));

				// for each element in the heap print it out
				for (node p : Heap.heap) {

					Q2OutputTXT << p.num << " ";
				}

				Q2OutputTXT << endl;

			}

			for (int i = 0; i < nodeNum.size(); i++)
			{
				cout << nodeNum[i] << " ";
			}

		}


		else if (!Q2InputTXT.is_open())
		{
			cout << "Error, file not found." << endl;
			char errmsg[128];
			strerror_s(errmsg, 128, errno);
			printf("Error: %s\n", errmsg);
		}

	}

	// Close the files afterward.
	Q2InputTXT.close();
	Q2OutputTXT.close();

}