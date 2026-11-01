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

    int getMax()
    {
        if (head == NULL)
            return 0;

        int max = head->score;
        Node* temp = head->next;

        while (temp != NULL)
        {
            if (temp->score > max)
                max = temp->score;

            temp = temp->next;
        }

        return max;
    }

    void reverseList()
    {
        Node* prev = NULL;
        Node* current = head;
        Node* nextNode = NULL;

        while (current != NULL)
        {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        head = prev;
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

    void radixSort()
    {
        int max = getMax();
        int place = 1;

        while (max / place > 0)
        {
            Node* bucketHead[10] = {NULL};
            Node* bucketTail[10] = {NULL};

            Node* temp = head;

            while (temp != NULL)
            {
                Node* nextNode = temp->next;
                temp->next = NULL;

                int digit = (temp->score / place) % 10;

                if (bucketHead[digit] == NULL)
                {
                    bucketHead[digit] = temp;
                    bucketTail[digit] = temp;
                }
                else
                {
                    bucketTail[digit]->next = temp;
                    bucketTail[digit] = temp;
                }

                temp = nextNode;
            }

            head = NULL;
            Node* tail = NULL;

            for (int i = 0; i < 10; i++)
            {
                if (bucketHead[i] != NULL)
                {
                    if (head == NULL)
                    {
                        head = bucketHead[i];
                        tail = bucketTail[i];
                    }
                    else
                    {
                        tail->next = bucketHead[i];
                        tail = bucketTail[i];
                    }
                }
            }

            place = place * 10;
        }

        reverseList();
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

list.radixSort();

cout << "\nSorted Linked List (Descending):\n";
list.display();
    return 0;
}