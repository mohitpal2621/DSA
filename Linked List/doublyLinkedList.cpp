#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* prev;
        Node* next;

        Node(int data) : data(data), prev(nullptr), next(nullptr) {} 
};

void insertAtHead(Node* &head, int key){
    Node *n = new Node(key);
    n->next = head;
    if(head != nullptr){
        head->prev = n;
    }
    head = n;
}

void insertAtTail(Node* &head, int key) {
    Node *n = new Node(key);
    Node *temp = head;

    if(head == nullptr){
        head = n;
        return; 
    }

    while(temp->next != nullptr) {
        temp = temp->next;
    }

    n->prev = temp;
    temp->next = n; 
}

void insertAtPos(Node* &head, int pos, int key) {
    Node* n = new Node(key);

    if(pos < 1) {
        cout << "Invalid Position." << endl;
        return;
    }

    if(pos == 1) {
        insertAtHead(head, key);
        return;
    }

    int count = 1;
    Node* temp = head;

    while(temp != nullptr && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        cout << "Position out of bounds." << endl;
        delete n;
        return;
    }

    n->prev = temp;
    n->next = temp->next;
    if(temp->next != nullptr)
        temp->next->prev = n;
    temp->next = n;
}

void deleteNode(Node* &head, int key) {
    Node* temp = head;
    if(temp != nullptr && temp->data == key) {
        head = temp->next;
        if(head != nullptr){
            head->prev = nullptr;
        }
        delete temp;
        return;
    }

    Node* prev = nullptr;

    while(temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == nullptr) {
        cout << "Key not found in the list." << endl;
        return;
    }

    prev->next = temp->next;
    if(temp->next != nullptr){
        temp->next->prev = prev;
    }

    delete temp;
}

void reverseList(Node* &head) {
    Node* current = head;
    Node* temp = nullptr;

    while(current != nullptr) {
        // swap the enxt and prev pointers
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        head = current;

        // Move to the next node in the original list
        current = current->prev; 
    }
}

void print(Node *head) {
    Node *temp = head;
    cout << "Forward: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    cout << "Backward: ";
    temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
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
