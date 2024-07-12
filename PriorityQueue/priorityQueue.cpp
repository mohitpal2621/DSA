#include<iostream>
#include<vector>
using namespace std;

class MaxPriorityQueue{
    private: 
        vector<int> heap;

        void siftUp(int index);
        void siftDown(int index);
        void swap(int &a, int &b);

    public:
        MaxPriorityQueue() = default;

        void insert(int key);
        int extractMax();
        int getMax() const;
        void increaseKey(int i, int key);
        bool isEmpty() const;
        int size() const;
};

// In case of insertion to the end of array, siftUp is needed to maintain the heapify property
void MaxPriorityQueue::siftUp(int index){ 
    while(index > 0 && heap[index] > heap[(index-1) / 2]){
        swap(heap[index], heap[(index-1) / 2]);
        index = (index - 1) / 2;
    }
}

void MaxPriorityQueue::siftDown(int index){ // Equivalent to the Max-Heapify function to maintain the heap property for the given index subtree
    int maxIndex = index;

    int leftChild = 2*index + 1;
    if(leftChild < heap.size() && heap[leftChild] > heap[maxIndex]){
        maxIndex = leftChild;
    }

    int rightChild = 2*index + 2;
    if(rightChild < heap.size() && heap[rightChild] > heap[maxIndex]){
        maxIndex = rightChild;
    }

    if(index != maxIndex){
        swap(heap[index], heap[maxIndex]);
        siftDown(maxIndex);
    }
}

void MaxPriorityQueue::swap(int &a, int &b){
    int temp = a;
    a = b; 
    b = temp;
}

void MaxPriorityQueue::insert(int key){
    heap.push_back(key);
    siftUp(heap.size() - 1);    // siftup used in insertion case, as a new element is appended at the end, and may violate the heap propery of the heap
}

int MaxPriorityQueue::extractMax() {
    if(heap.empty()){
        throw runtime_error("Priority queue is empty!");
    }

    int result = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    siftDown(0);    //To Max-Heapify according to the original Heapify algorithm

    return result;
}

int MaxPriorityQueue::getMax() const {
    if(heap.empty()){
        throw runtime_error("Priority queue is empty!");
    }

    return heap[0];
}

void MaxPriorityQueue::increaseKey(int i, int key){
    if (i < 0 || i >= heap.size()) {
        throw runtime_error("Index out of bounds");
    }
    
    if(key < heap[i]){
        throw runtime_error("New key is smaller than the current key for the selected");
    }
    
    heap[i] = key;
    
    siftUp(i);
}

bool MaxPriorityQueue::isEmpty() const {
    return heap.empty();
}

int MaxPriorityQueue::size() const {
    return heap.size();
}

int main(){
    MaxPriorityQueue pq;

    pq.insert(3);
    pq.insert(5);
    pq.insert(1);
    pq.insert(10);
    pq.insert(2);
    pq.insert(15);

    cout << "Max element: " << pq.getMax() << endl;

    cout << "Size: " << pq.size() << endl;

    cout << "Extracted element: " << pq.extractMax() << endl;

    cout << "Size: " << pq.size() << endl;

    cout << "Max element after max extraction: " << pq.getMax() << endl;

    pq.increaseKey(4, 20);

    cout << "Size: " << pq.size() << endl;

    cout << "Max element after increasing Key: " << pq.getMax() << endl;

    return 0;
}