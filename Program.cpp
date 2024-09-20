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

// ������� ��� ���������� ������� �� ��� �����
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

// ������� ��� ������� ���� �����������
void merge(int arr[], int l, int m, int r) {
	int n1 = m - l + 1; // ������ ������ ����������
	int n2 = r - m; // ������ ������� ����������

	// ������� ��������� �������
	int* L = new int[n1];
	int* R = new int[n2];

	// �������� ������ �� ��������� �������
	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	// ������� ��� ������ � ������� �����������
	int i = 0, j = 0;
	int k = l; // ������ ��� ��������� ������� arr[]

	// ������� ��������� ������� ������� � arr[l..r]
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

	// �������� ���������� �������� L[], ���� ������� �������
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	// �������� ���������� �������� R[], ���� ������� �������
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
		int m = l + (r - l) / 2; // ������� �������� �������
		mergeSort(arr, l, m); // ���������� ��������� ����� �����
		mergeSort(arr, m + 1, r); // ���������� ��������� ������ �����
		merge(arr, l, m, r); // ������� ��������������� �����
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int arr1[] = {64, 34, 25, 12, 22, 11, 90};
	int arr2[] = {64, 34, 25, 12, 22, 11, 90};
	int arr3[] = {64, 34, 25, 12, 22, 11, 90};
	int n = sizeof(arr1) / sizeof(arr1[0]);

	cout << "�������� ������: ";
	for (int i = 0; i < n; i++) {
		cout << arr1[i] << " ";
	}
	cout << endl;

	bubbleSort(arr1, n);
	cout << "������ ����� ����������� ����������: ";
	for (int i = 0; i < n; i++) {
		cout << arr1[i] << " ";
	}
	cout << endl;

	quickSort(arr2, 0, n - 1);
	cout << "������ ����� ������� ����������: ";
	for (int i = 0; i < n; i++) {
		cout << arr2[i] << " ";
	}
	cout << endl;

	mergeSort(arr3, 0, n - 1);
	cout << "������ ����� ���������� ��������: ";
	for (int i = 0; i < n; i++) {
		cout << arr3[i] << " ";
	}
	cout << endl;

	return 0;
}