#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

void insert(Node* head, int val) {
    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }

    Node* newNode = new Node(val);
    curr->next = newNode;
    newNode->prev = curr;
}

void insertAfterValue(Node* head, int afterVal, int val) {
    Node* curr = head;

    while (curr != nullptr && curr->data != afterVal) {
        curr = curr->next;
    }

    if (curr == nullptr) {
        cout << "value not found" << endl;
        return;
    }

    Node* newNode = new Node(val);
    newNode->next = curr->next;
    newNode->prev = curr;

    if (curr->next != nullptr) {
        curr->next->prev = newNode;
    }
    curr->next = newNode;
}

void deleteByValue(Node* &head, int val) {
    Node* curr = head;

    while (curr != nullptr && curr->data != val) {
        curr = curr->next;
    }

    if (curr == nullptr) {
        cout << "value not found" << endl;
        return;
    }

    if (curr->prev != nullptr) {
        curr->prev->next = curr->next;
    } else {
        head = curr->next;
    }

    if (curr->next != nullptr) {
        curr->next->prev = curr->prev;
    }

    delete curr;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main() {
    Node* head = new Node(5);

    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    insert(head, 50);

    insertAfterValue(head, 30, 35);
    deleteByValue(head, 50);

    display(head);

    return 0;
}
