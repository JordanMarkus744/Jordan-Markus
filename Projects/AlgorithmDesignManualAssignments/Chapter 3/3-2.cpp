/*
[3] Write a program to reverse the direction of a given singly-linked list. In other
words, after the reversal all pointers should now point backwards. Your algorithm
should take linear time.
*/

#include <iostream>
#include <stack>

struct Node{
    int val;
    Node* next;
};

class LinkedList{
    Node* head;
    Node* tail;
    public:

    LinkedList() : head(nullptr), tail(nullptr) {}

    LinkedList(int num){
        Node* node = new Node();
        node->val = num;
        node->next = nullptr;
        if (head){
            tail->next = node;
            tail = tail->next;
            if (head->next == nullptr){
                head->next = tail;
            }
        }
        else{
            head = node;
            tail = node;
        }
    }

    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp; // Delete each node
        }
        head = nullptr; // Set head to null after deleting all nodes
    }

    void addNode(Node* node){
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    void addNode(int num){
        Node* node = new Node();
        node->val = num;
        node->next = nullptr;

        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    Node* getHead(){
        return head;
    }

    void setHead(Node* node){
        head = node;
        tail = node;
    }


    void Print(){
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->val;
            if (temp->next != nullptr) {
                std::cout << ", ";
            }
            temp = temp->next;
        }
        std::cout << "\n\n";
    }
};

LinkedList reverse(LinkedList& list){
    LinkedList reversed;
    std::stack<Node*> nodeStack;
    Node* head = list.getHead();
    Node* temp = head;
    while(temp != nullptr){
        nodeStack.push(temp);
        temp = temp->next;
    }

    
    temp = nodeStack.top();
    temp->next = nullptr;
    reversed.setHead(temp);
    nodeStack.pop();
    while(!nodeStack.empty()){
        temp->next = nodeStack.top();
        temp = temp->next;
        temp->next = nullptr;
        reversed.addNode(temp);
        nodeStack.pop();
    }
    temp->next = nullptr;
    return reversed;
}

int main(){
    LinkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);
    list.addNode(5);
    list.Print();

    LinkedList rev = reverse(list);
    rev.Print();

    return 0;
}