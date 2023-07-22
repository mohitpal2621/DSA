#include<iostream>
#include<vector>

using namespace std;

void insertion(vector<int> &iv, int n){
    for(int i = 1; i < n; i++){
        int key = iv[i];
        int j = i - 1;

        while(j >= 0 && iv[j] > key){
            iv[j + 1] = iv[j];
            --j;
        } 
        iv[j + 1] = key;
    }
}

void printList(const vector<int> &iv){
    for(int e : iv){
        cout << e << " ";
    }
}

int main(){
    vector<int> iv = {500,210,412,623,214,483};
    // int num;
    // while(cin >> num){
    //     iv.push_back(num);
    // }
    cout << "Original Array: ";
    printList(iv);
    cout << endl;

    int n = iv.size();

    insertion(iv, n);
    
    cout << "Sorted Array: ";
    printList(iv);


    return 0;
}