#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string name;
    int score;
    Node* next;

    Node(string n, int s)
    {
        name = n;
        score = s;
        next = NULL;
    }
};

class SinglyLinkedList
{
private:
    Node* head;

    Node* getMiddle(Node* start)
    {
        Node* slow = start;
        Node* fast = start->next;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    Node* merge(Node* left, Node* right)
    {
        Node* result = NULL;
        Node* tail = NULL;

        while (left != NULL && right != NULL)
        {
            Node* selected;

            if (left->score >= right->score)
            {
                selected = left;
                left = left->next;
            }
            else
            {
                selected = right;
                right = right->next;
            }

            if (result == NULL)
            {
                result = selected;
                tail = selected;
            }
            else
            {
                tail->next = selected;
                tail = selected;
            }
        }

        if (left != NULL)
        {
            tail->next = left;
        }
        else if (right != NULL)
        {
            tail->next = right;
        }

        return result;
    }

    Node* mergeSort(Node* start)
    {
        if (start == NULL || start->next == NULL)
        {
            return start;
        }

        Node* mid = getMiddle(start);
        Node* right = mid->next;

        mid->next = NULL;

        Node* leftHalf = mergeSort(start);
        Node* rightHalf = mergeSort(right);

        return merge(leftHalf, rightHalf);
    }

public:
    SinglyLinkedList()
    {
        head = NULL;
    }

    void insert(string name, int score)
    {
        Node* newNode = new Node(name, score);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node* temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    void display()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->name << "(" << temp->score << ") -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    void sort()
    {
        head = mergeSort(head);
    }
};

int main()
{
    SinglyLinkedList list;

    string name;
    int score;

    for (int i = 0; i < 8; i++)
    {
        cout << "Enter player name: ";
        cin >> name;

        cout << "Enter player score: ";
        cin >> score;

        list.insert(name, score);
    }

    cout << "\nOriginal Linked List:\n";
    list.display();

    list.sort();

    cout << "\nSorted Linked List (Descending):\n";
    list.display();

    return 0;
}
// Merge sort