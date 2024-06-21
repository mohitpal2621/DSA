#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int> &arr, int start, int end){
    int pivot = arr[end];

    int i = start - 1;

    for(int j = start; j < end; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i+1], arr[end]);

    return i+1;
}

void quickSort(vector<int> &arr, int start, int end){
    if(start < end){
        int p = partition(arr, start, end);
        quickSort(arr, start, p - 1);
        quickSort(arr, p + 1, end);
    }
}

void printArray(const vector<int> &arr, const int &n){
    for(auto i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    vector<int> vec{9,3,4,2,1,8,10,2};
    int n = vec.size();
    
    cout << "Original array : " << endl;
    printArray(vec, n);

    quickSort(vec, 0, n - 1);

    cout << "Sorted array : " << endl;
    printArray(vec, n);

}