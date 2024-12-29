#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node() {
        this->next = nullptr;
    }
};

class SLL{
    public:
    Node* head;
    
    SLL() {
        head = nullptr;
    }
    
    void append(int data) {
        Node* newNode = new Node();
        newNode -> data = data;
        
        if (head == nullptr) {
            head = newNode;
            cout << data << " Inserted at last" << endl;
            return;
        }
        
        Node* temp = head;
        while (temp -> next != nullptr) {
            temp = temp -> next;
        }
        
        temp -> next = newNode;
        cout << data << " Inserted at last" << endl;
        }
        
    void display() {
        if (head == nullptr) {
            cout << "Empty" << endl;
        }
        else {
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp -> data << " -> ";
                temp = temp -> next;
            }
            cout << " NULL " << endl;
        }
    }
    
    void prepend(int data) {
        Node* newNode = new Node();
        newNode -> data = data;
        
        if (head == nullptr) {
            head = newNode;
            cout << data << " Inserted at first" << endl;
            return;
        }
        
        newNode -> next = head;
        head = newNode;
        cout << data << " Inserted at first" << endl;
        }
        
    void insert_after_a_value(int val, int data) {
        Node* newNode = new Node();
        newNode -> data = data;
        
        if (head == nullptr) {
            cout << val << " is not present and list is empty" << endl;
        }
        
        else if (head -> next == nullptr && head -> data == val) {
            head -> next = newNode;
            cout << data << "Inserted after " << val << endl; 
        }
        
        else {
            Node* temp = head;
            while (temp != nullptr && temp -> data != val) {
                temp = temp -> next;
            }
            if (temp == nullptr) {
                cout << "Val is not present" << endl;
            }
            else {
                newNode -> next = temp -> next;
                temp -> next = newNode;
                cout << data << " Inserted after " << val << endl; 
            }
        }
    }
    
    void delete_at_last() {
        if (head == nullptr) {
            cout << "List is empty and deletion can be performed " << endl;
        }
        else if (head -> next == nullptr) {
            cout << head -> data << " deleted successfully" << endl;
            head = nullptr;
        }
        else {
            Node* temp = head;
            while (temp -> next -> next != nullptr) {
                temp = temp -> next;
            }
            cout << temp -> next -> data << " is deleted " << endl;
            temp -> next = nullptr;
            
        }
    }
};

int main() {
    SLL list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(3);
    list.append(5);
    list.display();
    list.prepend(20);
    list.prepend(30);
    list.display();
    list.insert_after_a_value(1, 50);
    list.display();
    list.delete_at_last();
    list.delete_at_last();
    list.delete_at_last();
    list.display();
}