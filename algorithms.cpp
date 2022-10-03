#include <iostream>;
#include <windows.h>;
#include <conio.h>;

using std::cout;
using std::cin;
using std::endl;
using std::swap;
//using namespace std;

void RandInitialize(int arr[], const int size) {
	static size_t a = 1;
	srand(static_cast<unsigned>(time(nullptr) + a));
	for (int i = 0; i < size; ++i) {
		arr[i] = rand() % 90 + 10;
		cout << arr[i] << " ";
	}
	a += 5;
	cout << endl;
}

void Fibonacci(int n) {
	if (n >= 0) {
		int a1 = 0, a2 = 1, a3;
		if (n < 2) cout << n << endl;
		else {
			for (int i = 2; i <= n; ++i) {
				a3 = a1 + a2;
				a1 = a2;
				a2 = a3;
			}
			cout << a3 << endl;
		}
	}
	else cout << "Error! N < 0" << endl;
}
int FibonacciRecursion(int n) {
	return (n < 2) ? n : FibonacciRecursion(n - 1) + FibonacciRecursion(n - 2);
}

void Factorial(int n) {
	if (n >= 0) {
		int F = 1;
		for (int i = 1; i <= n; ++i)
			F *= i;
		cout << F << endl;
	}
	else cout << "Error! N < 0" << endl;
}
int FactorialRecursion(int n) {
	return (n == 1) ? 1 : n * FactorialRecursion(n - 1);
}

void StringReverse() {
	char string[] = "qwerty";
	cout << string << endl;
	int length = strlen(string);
	int i, j, x;
	for (i = 0, j = length - 1; i < j; ++i, j--) {
		x = string[i];
		string[i] = string[j];
		string[j] = x;
	}

	cout << string << endl;

}

//search algorithms
void LinearSearch(int arr[], const int size) {
	cout << "Enter the value you want to find: ";
	int value, x = 0;
	cin >> value;
	for (int i = 0; i < size; ++i) {
		if (arr[i] == value) {
			cout << "The array has you value! Index: " << ++i << endl;
			++x;
		}
	}
	if (x == 0)cout << "The array doesen't have you value!" << endl;
}
void BinarySearch(int arr[], const int size) {
	cout << "Enter the value you want to find: ";
	int value, x = 0;
	cin >> value;
	int first = 0;
	int last = size - 1;
	do {
		int middle = (first + last) / 2;
		if (value == arr[middle]) {
			cout << "The array has you value! Index: " << ++middle<< endl;
			++x;
			break;
		}
		else if (value < arr[middle])
			last = middle - 1;
		else if (value > arr[middle])
			first = middle + 1;
	} while (first <= last);

	if (x == 0)
		cout << "The array doesen't have you value!" << endl;
}

//sorting algorithms
void SelectionSort(int arr[], const int size) {
	for (int i = 0; i < size - 1; ++i)
		for (int j = i + 1; j < size; ++j)
			if (arr[j] < arr[i])
				swap(arr[j], arr[i]);

	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << endl;
}
void BubbleSort(int arr[], const int size) {
	for (int i = 0; i < size - 1; ++i)
		for (int j = size - 1; j > i; --j)
			if (arr[j] > arr[j - 1])
				swap(arr[j], arr[j - 1]);
	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << endl;
}
void InsertionSort(int arr[], const int size) {
	for (int i = 1; i < size; ++i) {
		int key = arr[i];
		int j;
		for (j = i - 1; j >= 0 && arr[j] > key; --j)
			arr[j + 1] = arr[j];
		arr[j + 1] = key;
	}
	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << endl;
}
void QuickSort(int arr[], int first, int last) {
	int i = first;
	int j = last;
	int middle = arr[(first + last) / 2];
	do {
		while (arr[i] < middle)
			i++;
		while (arr[j] > middle)
			j--;
		if (i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (i < last)
		QuickSort(arr, i, last);
	if (j > first)
		QuickSort(arr, first, j);
	//some problems with this sorting
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int size = 10;
	int arr[size];

	RandInitialize(arr, size);

	InsertionSort(arr, size);

	system("PAUSE");
	return 0;
}
