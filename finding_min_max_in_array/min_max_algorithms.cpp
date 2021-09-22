// Linear Search Algorithm

#include<iostream>

using namespace std;

struct Pair {
	int min;
	int max;
};


struct Pair getMinMax_linearSearch(int arr[], int arrSize) {
	// Declare Variables
	struct Pair minmax;


	// Address the base case
	if (arrSize == 1) {
		minmax.min = arr[0];
		minmax.max = arr[0];
	}


	// Setup for for-loop
	if (arr[0] < arr[1]) {
		minmax.min = arr[0];
		minmax.max = arr[1];

	}
	else {
		minmax.min = arr[1];
		minmax.max = arr[0];		
	}


	// Execute for-loop
	for (int i = 2; i < arrSize; i++) {
		if (arr[i] < minmax.min) {
			minmax.min = arr[i];
		}
		else if (minmax.max < arr[i]) {
			minmax.max = arr[i];
		}
	}


	// Return the result
	return minmax;
}

struct Pair getMinMax_tournamentMethod(int arr[], int low, int high) {
	// Apply recursion
	struct Pair minmax, mml, mmr;
	int mid;

	// Address if there's only one element
	if (high == low) {
		// Means there's only one element in the array;.
		minmax.min = arr[low];
		minmax.max = arr[low];
		return minmax;
	}

	// Address if there are two elements
	if (low == high - 1) {
		if (arr[high] > arr[low]) {
			minmax.max = arr[high];
			minmax.min = arr[low];
		}
		else {
			minmax.max = arr[low];
			minmax.min = arr[high];
		}

		return minmax;
	}


	// Divide the array
	mid = (high + low) / 2;
	
	// Get max or minimum from each array
	mml = getMinMax_tournamentMethod(arr, low, mid);
	mmr = getMinMax_tournamentMethod(arr, mid + 1, high);


	// Compare the maximums of both arrays
	if (mmr.max > mml.max) {
		minmax.max = mmr.max;
	}
	else {
		minmax.max = mml.max;
	}
	
	// Compare the minimums of both arrays
	if (mmr.min > mml.min) {
		minmax.min = mml.min;
	}
	else {
		minmax.min = mmr.min;
	}

	return minmax;
}	

struct Pair getMinMax_compareInPairs(int arr[], int arrSize) {
	// Declaring the variables
	struct Pair minmax;
	int i;

	// If array has even number of elements then set the first two elements as mins and maxs; Set the index for loop start = 2
	if (arrSize % 2 == 0) {
		if (arr[0] < arr[1]) {
			minmax.max = arr[1];
			minmax.min = arr[0];
		}
		else {
			minmax.max = arr[0];
			minmax.min = arr[1];
		}
		i = 2;
	}

	// Else array has odd number of elements then set the first element as the min and max; Set the index for loop start = 1
	else {
		minmax.min = arr[0];
		minmax.max = arr[0];
	
		i = 1;
	}


	// Loop through the array -> Compare adjacent elements -> then compare each with minmax
	for (i; i < arrSize - 1; i+=2) {
		if (arr[i] < arr[i + 1]) {
			if (arr[i + 1] > minmax.max) {
				minmax.max = arr[i + 1];
			}
			
			if (arr[i] < minmax.min) {
				minmax.min = arr[i];
			}
		}
		else {
			if (arr[i] > minmax.max) {
				minmax.max = arr[i];
			}

			if (arr[i + 1] < minmax.min) {
				minmax.min = arr[i + 1];
			}
		}
	}

	return minmax;
}


int main() {
	int arr[] = {4, 2, 2, 1, 20, 19, 9};
	int arrSize = 7;

	cout << "Array: [";
	for (int i = 0; i < arrSize; i++) {
		if (i != arrSize - 1) {
			cout << arr[i] << ",  ";
		}
		else {
			cout << arr[i];
		}
	}
	cout << "] \n";


	// struct Pair result = getMinMax_linearSearch(arr, arrSize);
	// struct Pair result = getMinMax_tournamentMethod(arr, 0, arrSize - 1);
	struct Pair result = getMinMax_compareInPairs(arr, arrSize);

	cout << "The Maximum is: " << result.max << "\n";
	cout << "The Minimum is: " << result.min << "\n";



	return 0;
}