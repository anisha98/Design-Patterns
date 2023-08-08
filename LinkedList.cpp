#include<iostream>
using namespace std;

struct Node{    
    public:
        int data;
        Node * next; // For double linked list we create a another pointer Node * prev;
        Node(int val){
            this->data=val;
            this->next=NULL;
        }
};

void insertAtHead(Node * &node, int val){
    // Create a new node with a value = val
    Node * n = new Node(val);
    n->next = node;
    node = n;
    
    cout << "The value: " << val <<" inserted at the head" << endl;
};

void insertAtTail(Node * &node, int val){
    // Create a new node with a value = val
    Node * n = new Node(val);

    if(node == NULL) //if the linked list is empty then create a new head and tail nodes
    {
        node = n;
    }
    else
    {
        //Traverse to the last element in the linkedList
        Node * temp = node;
        while(temp->next != NULL){
            temp = temp->next;
        }
        
        /* Insert the newNode as the last one */
        temp->next = n;

    }
    cout << "The value: " << val <<" inserted at the tail" << endl;
};

// Display the LinkedList
void display(Node * n){
    Node * temp = n;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
};

int main(){
    
    Node * node = NULL;

    for(int i = 1 ; i < 5; i++){
        insertAtHead(node,i);
    }

    display(node);

    for(int i = 5 ; i < 10; i++){
        insertAtTail(node,i);
    }


    display(node);

    
    return 0;
}