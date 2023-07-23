#include<iostream>
#include<vector>

using namespace std;

void selection(vector<int> &iv, int n){
    int i, j, minInd;
    
    for(i = 0; i < (n - 1); i++){
        
        minInd = i;
        
        for(j = i + 1; j < n; j++){
            if(iv[minInd] > iv[j])
                minInd = j;
        }

        if(minInd != i){
            swap(iv[minInd], iv[i]);
        }
    }
}

void printList(const vector<int> &iv){
    for(int e : iv){
        cout << e << " ";
    }
}

int main(){
    vector<int> iv = {500,210,412,623,214,483};
    
    cout << "Original Array: ";
    printList(iv);
    cout << endl;

    int n = iv.size();

    selection(iv, n);
    
    cout << "Sorted Array: ";
    printList(iv);


    return 0;
}