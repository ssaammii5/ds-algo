#include<bits/stdc++.h>
using namespace std;
//Singly Linked List

class Node {
public:
    int data;
    Node *next;
};

//inserting at the front
void front(Node **head, int sentData) {
    Node *newNode = new Node();

    newNode->data = sentData;
    newNode->next = *head;

    *head = newNode;
}

//inserting after a specific node(both are correct)
/*void insertAfter(Node *prevNode, int sentData) {
    if (prevNode == NULL) {
        cout << "Not possible!" << endl;
        return;
    }

    Node *newNode = new Node();
    newNode->data = sentData;
    newNode->next = prevNode->next;

    prevNode->next = newNode;

}*/


void insertAfter(Node **prevNode, int sentData) {
    if (prevNode == NULL) {
        cout << "Not possible!" << endl;
        return;
    }

    Node *newNode = new Node();
    newNode->data = sentData;
    Node *temp = *prevNode;
    newNode->next = temp->next;

    temp->next = newNode;

}

//inserting at the last
void append(Node **head, int sentData) {
    Node *newNode = new Node();
    newNode->data = sentData;
    newNode->next = NULL;

    Node *last = *head;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
    return;
}

//deleting node of linked list
void deleteNode(Node **head, int key) {
    Node *temp = *head;
    Node *prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        delete temp;
        return;
    }

    else {
        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            return;
        }
        prev->next = temp->next;
        delete temp;
    }
}


//printing values of linked list
void printList(Node *node) {
    while (node != NULL) {
        cout << " " << node->data;
        node = node->next;
    }
}

int main(void) {
    Node *head = NULL;

    append(&head, 6);

    append(&head, 1);
    append(&head, 9);
    front(&head, 10);
    insertAfter(&head->next->next, 152);
    deleteNode(&head, 6);
    printList(head);
    
    //output 10 1 152 9

    //end
}