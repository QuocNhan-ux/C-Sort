#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <random>

using namespace std;

vector<int> generateRandomArray(int size) {

    vector<int> numbers;
    
    for(int i = 1; i <= size; i++) {
        numbers.push_back(i);
    }

    random_device rd; 
    mt19937 generator(rd());
    shuffle(numbers.begin(), numbers.end(), generator);

    return numbers;
}

void printArray(const vector<int>& array) {

    for( int num : array) {
        cout << num << " ";
    }
    cout << endl;
}

void insertionSort(vector<int>& array) {
    
    int size = array.size();

    for( int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;

        // shift larger elements to the right
        while ( j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;

        cout << "After pass: " << i << ": ";
        printArray(array);
    }
}

int main() {

    int size = 10;

    vector<int> array = generateRandomArray(size);

    cout << "Random Array: ";
    printArray(array);

    insertionSort(array);

    return 0;
}