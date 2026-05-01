#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int noMhs;
    Node *next;
    Node *prev;
};

class DoubleLinkedList
{
private:
    Node *START;

public:
    DoubleLinkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\nEnter the roll number of the student: ";
        cin >> nim;

        // Step 1: Allocate memory
        Node *newNode = new Node();

        // Step 2: Assign value
        newNode->noMhs = nim;

        // Step 3: Insert di awal jika kosong / lebih kecil
        if (START == NULL || nim <= START->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "\nDuplicate number not allowed" << endl;
                return;
            }

            newNode->next = START;

            if (START != NULL)
                START->prev = newNode;

            newNode->prev = NULL;
            START = newNode;
            return;
        }

        // Step 4: Cari posisi
        Node *current = START;
        while (current->next != NULL && current->next->noMhs < nim)
        {
            current = current->next;
        }
