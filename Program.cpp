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

// Функция для разделения массива на две части
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

// Функция для слияния двух подмассивов
void merge(int arr[], int l, int m, int r) {
	int n1 = m - l + 1; // Размер левого подмассива
	int n2 = r - m; // Размер правого подмассива

	// Создаем временные массивы
	int* L = new int[n1];
	int* R = new int[n2];

	// Копируем данные во временные массивы
	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	// Индексы для левого и правого подмассивов
	int i = 0, j = 0;
	int k = l; // Индекс для основного массива arr[]

	// Сливаем временные массивы обратно в arr[l..r]
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

	// Копируем оставшиеся элементы L[], если таковые имеются
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	// Копируем оставшиеся элементы R[], если таковые имеются
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
		int m = l + (r - l) / 2; // Находим середину массива
		mergeSort(arr, l, m); // Рекурсивно сортируем левую часть
		mergeSort(arr, m + 1, r); // Рекурсивно сортируем правую часть
		merge(arr, l, m, r); // Сливаем отсортированные части
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int arr1[] = {64, 34, 25, 12, 22, 11, 90};
	int arr2[] = {64, 34, 25, 12, 22, 11, 90};
	int arr3[] = {64, 34, 25, 12, 22, 11, 90};
	int n = sizeof(arr1) / sizeof(arr1[0]);

	cout << "Исходный массив: ";
	for (int i = 0; i < n; i++) {
		cout << arr1[i] << " ";
	}
	cout << endl;

	bubbleSort(arr1, n);
	cout << "Массив после пузырьковой сортировки: ";
	for (int i = 0; i < n; i++) {
		cout << arr1[i] << " ";
	}
	cout << endl;

	quickSort(arr2, 0, n - 1);
	cout << "Массив после быстрой сортировки: ";
	for (int i = 0; i < n; i++) {
		cout << arr2[i] << " ";
	}
	cout << endl;

	mergeSort(arr3, 0, n - 1);
	cout << "Массив после сортировки слиянием: ";
	for (int i = 0; i < n; i++) {
		cout << arr3[i] << " ";
	}
	cout << endl;

	return 0;
}