#include<iostream>
#include<vector>
using namespace std;

void medianOfThree(vector<int> &arr, int start, int end){
    int mid = start + (end - start) / 2;
    
    // Sort start, mid, end
    if (arr[start] > arr[mid])
        swap(arr[start], arr[mid]);
    if (arr[start] > arr[end])
        swap(arr[start], arr[end]);
    if (arr[mid] > arr[end])
        swap(arr[mid], arr[end]);
    
    // Move median (arr[mid]) to the second-to-last position
    swap(arr[mid], arr[end - 1]);
}

int partition(vector<int> &arr, int start, int end){
    medianOfThree(arr, start, end);

    int pivot = arr[end - 1];  // Pivot element
    int i = start;  // i is taken as 0th element not -1st element unlike in quick sort

    for (int j = start; j < end - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[end - 1]);
    return i;
}

void quickSort(vector<int> &arr, int start, int end){
    if(start < end){
        int pi = partition(arr, start, end);
        quickSort(arr, start, pi - 1);
        quickSort(arr, pi + 1, end);
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5, 12, 4, 45, 23, 1, 34};
    int n = arr.size(); 
    
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, n - 1);
    
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}