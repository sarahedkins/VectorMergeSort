// Given a list of unsorted lists and their size, return the sorted lists.

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

// function prototypes
vector<int> mergeSort(vector<int> origVect);
vector<int> merge(vector<int> l, vector<int> r);

int main() {

	// declarations & initialization
	vector<int> testing;
	int j = 10; // used to fill vector
	vector<int> sortedVector;
	ifstream infile;
	string filename = "unsorted.txt";
	vector<int> aVector;
	int lengthOfList = 0;
	int holdInt = 0;
	int i = 0; // iterator
	int numLists = 1; // keeps track of number of lists in input file

	// open file and check that it opens
	infile.open("unsorted.txt");
	if (!infile) {
		cout << "Error opening " << filename;
		system("pause");
		return 0;
	}

	// loop in the unsorted lists & print sorted lists
	while (!infile.eof()){
		i = 0;
		infile >> lengthOfList; // first int is the length of the following unsorted list
		aVector.resize(lengthOfList);
		while (lengthOfList != 0) {
			infile >> aVector[i];
			lengthOfList--;
			i++;
		}
		// print out unsorted vectors
		cout << endl << "Unsorted Vector #" << numLists <<  " is: ";
		for (int k = 0; k < aVector.size(); k++) {
			cout << aVector[k] << " ";
		}

		// sort
		sortedVector = mergeSort(aVector);

		// print sorted vector
		cout << endl << "Sorted Vector #" << numLists << " is: ";
		for (int k = 0; k < sortedVector.size(); k++){
			cout << sortedVector[k] << " ";
		}
		numLists++;
		cout << endl;
	}

	system("pause");
	return 0;
} // end of main

// function defintions
vector<int> mergeSort(vector<int> origVect) {
	int size = origVect.size();
	int half = size / 2;
	vector<int> left;
	vector<int> right;

	// base case to end recursion
	if (size <= 1)
		return origVect;

	// divide origVect into 2 smaller vectors
		for (int i = 0; i < half; i++) {
			left.push_back(origVect[i]);
			right.push_back(origVect[half + i]);
		}
	// account for uneven original vectors by making right vector one elem longer
		if ((size % 2) != 0)
			right.push_back(origVect.back());

	// recursive calls, creating smaller and smaller sublists
	left = mergeSort(left);
	right = mergeSort(right);

	// merge sublists and return a sorted list
	return merge(left, right);
}

vector<int> merge(vector<int> l, vector<int> r) {
	int i = 0;
	int j = 0;
	int k = 0;
	int size = l.size() + r.size();  // size of new, sorted vector
	vector<int> sorted(size, 0); // initialize sorted to zeros

	for (i = 0; i < size; i++){
		if (j < l.size() && k < r.size()){  // if l and r both still have elements to compare
			if (l[j] <= r[k]) {
				sorted[i] = l[j];
				j++;
			}
			else {
				sorted[i] = r[k];
				k++;
			}
		}
		else if (j < l.size()) { // if l still has elements left
			sorted[i] = l[j];
			j++;
 			}
		else {
			sorted[i] = r[k]; // or if r still has elements left
			k++;
		}
	}
	return sorted;
}
