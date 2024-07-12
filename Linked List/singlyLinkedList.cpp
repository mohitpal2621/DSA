#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data): data(data), next(nullptr){};
};

void insertAtHead(Node* &head, int key) {
    Node *temp = new Node(key);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &head, int key) {
    Node *n = new Node(key);
    if(head == nullptr){
        head = n;
        return;
    }

    Node* temp = head;

    while(temp->next != nullptr){
        temp = temp->next;
    }

    temp->next = n;
}


void insertAtPos(Node* &head, int pos, int key) {
    if(pos == 1){
        insertAtHead(head, key);
        return;
    }

    int count = 1;
    Node *temp = head;

    while(count < pos - 1){
        temp = temp->next;
        count++;
    }
    
    Node* n = new Node(key);
    n->next = temp->next;
    temp->next = n;
}

void deleteNode(Node* &head, int key){
    Node* temp = head;

    if(temp != nullptr && temp->data == key){
        head = temp->next;
        delete temp;
        return;
    }

    Node* prev = nullptr;

    while(temp != nullptr && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    if(temp == nullptr) {
        cout << "Key not found in the list." << endl;
        return;
    }

    prev->next = temp->next;

    delete temp;
}

Node* searchNode(Node* head, int value) {
    Node* current = head;

    while (current != nullptr) {
        if (current->data == value) {
            return current; 
        }
        current = current->next;
    }

    return nullptr; 
}

void reverseList(Node* &head) {
    Node* prev = nullptr;
    Node* next = nullptr;

    while(head != nullptr){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    head = prev;
}

Node* swapPairs(Node* &head){
    if(!head || !head->next){
        return head;
    }

    Node* first = head;
    Node* second = first->next;

    first->next = swapPairs(second->next);

    second->next = first;

    head = second;
    
    return head;
}

void print(Node *head) {
    while(head != nullptr) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "nullptr" <<endl;
}

int main() {
    Node *head = nullptr;
    insertAtTail(head, 2);
    insertAtTail(head, 12);
    insertAtTail(head, 11);
    insertAtTail(head, 9);
    insertAtTail(head, 5);
    insertAtTail(head, 1);
    insertAtTail(head, 6);
    print(head);

    cout << endl;

    swapPairs(head);

    print(head);

    cout << endl;

    reverseList(head);

    print(head);

    cout << endl;

    deleteNode(head, 11);

    print(head);

    cout << endl;

    insertAtPos(head, 4, 20);

    print(head);


    return 0;
}