#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;
    
public:
    SinglyLinkedList() : head(nullptr) {}

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void deleteByValue(int value) {
        if (!head) return;

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->data != value) {
            temp = temp->next;
        }

        if (!temp->next) {
            cout << "Value " << value << " not found in the list." << endl;
            return;
        }


        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    void display() {
        if (!head) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    ~SinglyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SinglyLinkedList list;

    list.insertAtEnd(22);
    list.insertAtEnd(26);
    list.insertAtEnd(37);
    list.insertAtEnd(52);

    cout << "Initial list: ";
    list.display();

    cout << "Deleting node with value 22" << endl;
    list.deleteByValue(22);

    cout << "Updated list: ";
    list.display();

    cout << "Final list: ";
    list.display();

    return 0;
}