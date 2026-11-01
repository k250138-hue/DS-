#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d) : data(d), next(nullptr) {}
};

class Singly
{
public:
    Node *head;
    Singly() : head(nullptr) {}

    void push_back(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    void print_list(Node * head)
    {
        Node *temp = head;
        if(temp==NULL){
            return;
        }
        cout << temp->data << " ";
        print_list(temp->next);

        cout << temp->data << " ";
        
              
    }
    int search(Node*head,int key,int pos){
        if(head==NULL){
            return -1;
        }
        if(head->data==key){
            return pos;
        }
        return search(head->next,key,pos+1);
    }

};

int main()
{
    Singly list;
    list.push_back(4);
    list.push_back(1);
    list.push_back(5);
    list.push_back(3);
    list.push_back(2);

    list.print_list(list.head);
    return 0;
}