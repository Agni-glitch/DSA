#include <stdio.h>

int binary_search(int arr[], int low, int high, int target,int &comp) {
    if (high >= low) {
        int mid = (low + high) / 2;
        comp++;
        if (arr[mid] == target)
            return mid;
        comp++;
        if (arr[mid] > target)
            return binary_search(arr, low, mid - 1, target,comp);
        return binary_search(arr, mid + 1, high, target,comp);
    }
    return -1;
}
int linear_search(int arr[], int size, int target,int comp) {
    for (int i = 0; i < size; i++) {
        comp++;
        if (arr[i] == target) {
            return i;  
        }
    }
    return -1; 
}
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int comp=0;
    // int target = 30;
    // int result = linear_search(arr, size, target,comp);
    // if (result != -1) {
    //     printf("Element found at index %d\nNo of comparison: %d", result,comp);
    // } else {
    //     printf("Element not found in the array\n");
    // }
    int target = 40;
    int result = binary_search(arr, 0, size - 1, target,comp);
    if (result == -1)
        printf("Element not found in the array\n");
    else
        printf("Element found at index %d\nNo of comparison: %d", result,comp);
    
    return 0;
}