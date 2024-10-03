#include <iostream>
using namespace std;

// Node class definition
struct Node {
public:
    int data;    
    Node* next;
    Node* previous;

    Node(int value) 
    {
        data = value;
        next = nullptr;
        previous = nullptr;
    }
};

// LinkedList class definition
struct LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    // Method to insert a new node at the end of the list
    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void pushatfront(int value)
    {
        Node* node = new Node(value);
        node->next = head;
        head = node;
    }
    void pushatend(int value)
    {
        Node* node = new Node(value);
        Node* temp = head;
        if (head == nullptr) {
            head = node;  // If list is empty, make the new node the head
        }
        else
        {
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = node;
        }
    }

    void addBeforeNode(int key, int value)
    {
        Node* temp = head;
        while ((temp->next)->data != key)
        {
            temp = temp->next;
        }
        Node* node = new Node(value);
        node->next = temp->next;
        temp->next = node;
    }

    void addAfterNode(int key, int value)
    {
        Node* temp = head;
        while (temp->data != key)
        {
            temp = temp->next;
        }
        Node* node = new Node(value);
        node->next = temp->next;
        temp->next = node;
    }


    // Method to display the contents of the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;  // Indicate the end of the list
    }
    void popfront()
    {
        Node* temp = head;
        if (head == nullptr) {
            cout << "List is empty ";
        }
        else
        {
            head = temp->next;
            temp->next = nullptr;
            delete temp;
        }
    }
    void popEnd()
    {
        Node* temp = head;
        if (head == nullptr) {
            cout << "List is empty ";
        }
        else
        {
            while ((temp->next)->next != nullptr)
            {
                temp = temp->next;
            }
            Node* pop_node = temp->next;
            temp->next = nullptr;
            delete pop_node;
        }
    }
    void popNode(int key)
    {
        Node* temp = head;
        if (head == nullptr) {
            cout << "List is empty ";
        }
        else
        {
            while ((temp->next)->data != key)
            {
                temp = temp->next;
            }
            Node* pop_node = temp->next;
            temp->next = (temp->next)->next;
            pop_node = nullptr;
            delete pop_node;
        }
    }
    void reverse_node() {
        Node* temp = head;
        if (head == nullptr) {
            cout << "List is empty";  // If list is empty, make the new node the head
        }
        else
        {
            Node* tail;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
        }
        }

    };

    int main() {
        // Create a linked list
        LinkedList list;

        list.append(1177);
        list.append(1179);
        list.append(1181);
        list.append(1183);

        list.pushatfront(5);
        //
        //list.pushatend(40);
        //
        //list.addBeforeNode(40, 15);

        //list.addAfterNode(5, 25);

        list.display();
        cout << endl << "After deletion" << endl;

        //list.popfront();

        //list.popEnd();

        //list.popNode(1181);

        list.display();

    }

