#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

vector <int> generateRandomArray(int size) {
	
	vector<int> numbers;

	//fill the vector with numbers 1 through "size"
	for (int i = 1; i <=size; i++) {
		numbers.push_back(i);
	}

	// Create a random number generator
	random_device rd;
	mt19937 generator(rd());

	// randomly shuffle the numbers
	shuffle(numbers.begin(), numbers.end(), generator);

	return numbers;
}

void printArray(vector<int>& arr) {

	for (int num : arr) {
		cout << num << " ";
	}
	cout << endl;
}

void bubbleSort(vector<int>& arr) {

	int size = arr.size();
	
	// Repeat passes through the array
	for (int i = 0; i < size - 1; i++) {
		
		// compare adjacent elements
		for (int j = 0; j < size - i - 1; j++) {
			
			//swap if they are in the wrong order
			if (arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
			}
		}
		
		// print array after this pass
		cout << "After Pass " << i + 1 << ": ";
		printArray(arr);
	}
}



int main() {

	int userInput;
	cout << "*Bubble Sort Example*" << endl;
	cout << "Enter the size of the random Array: "; 
	cin >> userInput;

	int size = userInput;

	vector<int> arr = generateRandomArray(size);

	cout << "Random Array: ";
	printArray(arr);

	bubbleSort(arr);

	return 0;

}
