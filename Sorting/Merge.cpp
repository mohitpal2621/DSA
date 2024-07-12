#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr, const int &left, const int &mid, const int &right){
    // cout << left << " " << mid << " " << right << endl;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L1(n1), L2(n2);
    
    for(int i = 0; i < n1; i++){
        L1[i] = arr[left + i];
    }
    for(int j = 0; j < n2; j++){
        L2[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2){
        if(L1[i] <= L2[j]){
            arr[k] = L1[i];
            i++;
        } else{
            arr[k] = L2[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = L1[i];
        i++; k++;
    }
    while(j < n2){
        arr[k] = L2[j];
        j++; k++;
    }
}

void mergeSort(vector<int> &arr, const int &begin, const int &end){
    if(begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}

void printArray(const vector<int> &arr, const int &n){
    for(auto i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    vector<int> vec{12, 15, 6, 13, 7, 1, 10};
    int n = vec.size();

    cout << "Original array : " << endl;
    printArray(vec, n);

    mergeSort(vec, 0, n - 1);

    cout << "Sorted array : " << endl;
    printArray(vec, n);

    return 0;

}