#include<iostream>
using namespace std;

//defining singly-linked list node
class SinglyLinkedListNode {
public: //public
    int data;  //int datatype
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
    }
};

//defining Function to insert a node at the head of the linked list
SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    
    if (llist == nullptr) {
        //if the list is empty, the new node becomes the head
        return newNode;
    } else {
        //inserting the new node before the current head
        newNode->next = llist;
        return newNode;
    }
}

//function to print the linked list
void printLinkedList(SinglyLinkedListNode* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

//Function to create a linked list by taking user input
SinglyLinkedListNode* createLinkedList() {
    int n, data;
    cout << "Enter the number of elements to be inserted at the head: ";
    cin >> n;

    SinglyLinkedListNode* head = nullptr;
//for loop for element insertion
    for (int i = 0; i < n; i++) {
        cout << "Enter the element to be inserted: ";
        cin >> data;
        head = insertNodeAtHead(head, data);
    }
//retun head
    return head;
}

int main() {
    //Create linked list based on user input
    SinglyLinkedListNode* head = createLinkedList();

    // Output the linked list after insertion
    cout << "Linked List after insertion: ";
    printLinkedList(head);
//return
    return 0;
}

