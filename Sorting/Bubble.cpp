#include<iostream>
#include<vector>
using namespace std;

void bubble(vector<int> &vec, int n){
    bool swapped;

    for(int i = 0; i < n - 1; i++){
        swapped = false;
        for(int j = 0; j < n - i - 1; j++){
            if(vec[j] > vec[j+1]){
                swap(vec[j], vec[j+1]);
                swapped = true;
            }
        }

        if(!swapped){
            break;
        }
    }
}

void printList(const vector<int> &iv){
    for(int e : iv){
        cout << e << " ";
    }
}

int main(){
    vector<int> vec = {12, 15, 10 ,1, 8, 15, 3, 11};
    
    cout << "Original Array: ";
    printList(vec);
    cout << endl;

    int n = vec.size();

    bubble(vec, n);
    
    cout << "Sorted Array: ";
    printList(vec);


    return 0;
}