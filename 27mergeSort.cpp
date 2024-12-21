#include <iostream>
using namespace std;
void merge(int* arr,int low,int mid,int high){
    int* newArr = new int[high-low+1];
    int i = low;
    int j = mid+1;
    int k = 0;
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            newArr[k++] = arr[i++];
        }else{
            newArr[k++] = arr[j++];
        }
    }
    while(i<=mid){
        newArr[k++] = arr[i++];
    }
    while(j<=high){
        newArr[k++] = arr[j++];
    }
    for(int i=low;i<=high;i++){
        arr[i] = newArr[i-low];
    }
    delete[] newArr;
}
void mergeSort(int* arr,int low,int high){
    if(low<high){
        int mid = (low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}