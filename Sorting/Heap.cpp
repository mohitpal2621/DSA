#include<iostream>
#include<vector>
using namespace std;

int leftNode(int i){
    return (2*i) + 1;
}

int rightNode(int i){
    return (2*i) + 2;
}

void heapify(vector<int> &vec, int n, int node){
    int left = leftNode(node);
    int right = rightNode(node);

    int largest = node;

    if(left < n && vec[left] > vec[largest]){
        largest = left;
    }

    if(right < n && vec[right] > vec[largest]){
        largest = right;
    }

    if(largest != node){
        swap(vec[node], vec[largest]);
        heapify(vec, n, largest);
    }
}

void buildMaxHeap(vector<int> &vec){
    int n = vec.size();
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(vec, n, i);
    }
}

void heapSort(vector<int> &vec){
    int n = vec.size();
    buildMaxHeap(vec);
    for(int i = n - 1; i >= 0; i--){
        swap(vec[i], vec[0]);
        heapify(vec, i, 0);  // Important to accept the size parameter in heapify(), and passing i argument to heapify to eliminate(discard) the end node out of the heap after swapping
    }
}

void printArray(const vector<int> &vec){
    for(int n : vec){
        cout << n << " ";
    }
    cout << endl;
}

int main(){
    vector<int> vec{7, 4, 14, 2, 1, 8, 10, 3, 9, 16, 4};
    cout << "Original Array: " << endl;
    printArray(vec);

    heapSort(vec);

    cout << "Sorted Array: " << endl;
    printArray(vec);

    return 0;
}