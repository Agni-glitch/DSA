#include <iostream>
using namespace std;
void bubbleSort(int* arr, int n, int& comparisonCount) {
    comparisonCount = 0;
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            comparisonCount++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}
void insertionSort(int* arr, int n, int& comparisonCount) {
    comparisonCount = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisonCount++;
            arr[j + 1] = arr[j];  
            j--;
        }
        arr[j + 1] = key;
        if (j >= 0) {
            comparisonCount++;
        }
    }
}
void selectionSort(int* arr, int n, int& comparisonCount) {
    comparisonCount = 0;
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for(int j=i+1; j<n; j++) {
            comparisonCount++;
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
            swap(arr[i], arr[minIndex]);
        }
    }
}
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int* arr = new int[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int comparisonCount = 0;
    bubbleSort(arr, n, comparisonCount);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Number of comparisons: " << comparisonCount << endl;
    delete[] arr;
    return 0;
}