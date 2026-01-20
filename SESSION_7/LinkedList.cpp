#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* next;
    int data;

    Node(int val){
        next = nullptr;
        data = val;
    }
};

void insert(Node* head, int num){
    Node* temp = head;
    while(temp != nullptr && temp->next != nullptr){
        temp = temp->next;
    }

    temp->next = new Node(num);
}

void insertAtPos(Node* head, int posVal, int val){
    Node* temp = head;

    while(temp != nullptr && temp->data != posVal){
        temp = temp->next;
    }

    if(temp != nullptr){
        Node* nextToNext = temp->next;
        temp->next = new Node(val);
        temp->next->next = nextToNext;
    }else{
        cout<<"position not found"<<endl;
    }

}

void deleteAtVal(Node* head, int posVal){
    Node* temp = head;

    while(temp != nullptr && temp->next != nullptr && temp->next->data != posVal){
        temp = temp->next;
    }

    if(temp != nullptr){
        temp->next = temp->next->next;
    }
    else{
        cout<<"position value not found"<<endl;
    }
}

int main(){
    Node* head = new Node(5);
    Node* temp = head;

    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    insert(head, 50);

    insertAtPos(head, 30, 35);
    deleteAtVal(head, 50);
    

    while(temp != nullptr){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}