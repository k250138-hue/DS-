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

    Node* getTail(Node* temp)
    {
        while (temp != NULL && temp->next != NULL)
        {
            temp = temp->next;
        }

        return temp;
    }

    Node* partition(Node* low, Node* high)
    {
        int pivot = high->score;
        Node* i = NULL;

        for (Node* j = low; j != high; j = j->next)
        {
            if (j->score > pivot)
            {
                if (i == NULL)
                {
                    i = low;
                }
                else
                {
                    i = i->next;
                }

                string tempName = i->name;
                i->name = j->name;
                j->name = tempName;

                int tempScore = i->score;
                i->score = j->score;
                j->score = tempScore;
            }
        }

        if (i == NULL)
        {
            i = low;
        }
        else
        {
            i = i->next;
        }

        string tempName = i->name;
        i->name = high->name;
        high->name = tempName;

        int tempScore = i->score;
        i->score = high->score;
        high->score = tempScore;

        return i;
    }

    void quickSort(Node* low, Node* high)
    {
        if (low != NULL && high != NULL && low != high)
        {
            Node* pivot = partition(low, high);

            if (pivot != low)
            {
                Node* temp = low;

                while (temp->next != pivot)
                {
                    temp = temp->next;
                }

                quickSort(low, temp);
            }

            if (pivot != high)
            {
                quickSort(pivot->next, high);
            }
        }
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
        quickSort(head, getTail(head));
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
// Quick sort