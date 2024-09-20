#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

// A function for splitting an array into two parts
int partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (arr[j] <= pivot) {
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	int temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;

	return (i + 1);
}

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

// Function for merging two subarrays
void merge(int arr[], int l, int m, int r) {
	int n1 = m - l + 1; // The size of the left subarray
	int n2 = r - m; // The size of the right subarray

	// Creating temporary arrays
	int* L = new int[n1];
	int* R = new int[n2];

	// Copying data to temporary arrays
	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	// Indexes for the left and right subarrays
	int i = 0, j = 0;
	int k = l; // Index for the main array arr[]

	// Merging temporary arrays back into arr[l..r]
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of L[], if there are any
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of R[], if there are any
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
	delete[] L;
	delete[] R;
}

void mergeSort(int arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2; // Finding the middle of the array
		mergeSort(arr, l, m); // Recursively sort the left part
		mergeSort(arr, m + 1, r); // Recursively sort the right part
		merge(arr, l, m, r); // Merge the sorted parts
	}
}

int main() {

	int arr1[] = {64, 34, 25, 12, 22, 11, 90};
	int arr2[] = {64, 34, 25, 12, 22, 11, 90};
	int arr3[] = {64, 34, 25, 12, 22, 11, 90};
	int n = sizeof(arr1) / sizeof(arr1[0]);

	cout << "Original array: ";
	for (int i = 0; i < n; i++) {
		cout << arr1[i] << " ";
	}
	cout << endl;

	bubbleSort(arr1, n);
	cout << "Array after bubble sorting: ";
	for (int i = 0; i < n; i++) {
		cout << arr1[i] << " ";
	}
	cout << endl;

	quickSort(arr2, 0, n - 1);
	cout << "Array after quick sorting: ";
	for (int i = 0; i < n; i++) {
		cout << arr2[i] << " ";
	}
	cout << endl;

	mergeSort(arr3, 0, n - 1);
	cout << "Array after merge sorting: ";
	for (int i = 0; i < n; i++) {
		cout << arr3[i] << " ";
	}
	cout << endl;

	return 0;
}