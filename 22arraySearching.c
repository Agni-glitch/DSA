#include <stdio.h>

int binary_search(int arr[], int low, int high, int target) {
    if (high >= low) {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] > target)
            return binary_search(arr, low, mid - 1, target);
        return binary_search(arr, mid + 1, high, target);
    }
    return -1;
}
int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  
        }
    }
    return -1; 
}
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 30;
    int result = linear_search(arr, size, target);
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }
    target = 40;
    result = binary_search(arr, 0, size - 1, target);
    if (result == -1)
        printf("Element not found in the array\n");
    else
        printf("Element found at index %d\n", result);
    
    return 0;
}