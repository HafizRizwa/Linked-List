#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularSinglyLinkedList {
public:
    void AddLast(Node* &head, int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    void Display(Node* head) {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void DeleteFirst(Node* &head) {
        if (head == nullptr) {
            return;
        }
        Node* toDelete = head;
        while (toDelete->next != head) {
            toDelete = toDelete->next;
        }
        if (head->next == head) {
            head = nullptr;
        } else {
            toDelete->next = head->next;
            head = head->next;
        }
        delete toDelete;
    }

    void DeleteLast(Node* &head) {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == head) {
            head = nullptr;
        } else {
            prev->next = head;
        }
        delete temp;
    }

    void AddFirst(Node* &head, int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    bool Search(Node* head, int key) {
        if (head == nullptr) {
            return false;
        }
        Node* temp = head;
        do {
            if (temp->data == key) {
                return true;
            }
            temp = temp->next;
        } while (temp != head);
        return false;
    }

    Node* Reverse(Node* &head) {
        if (head == nullptr) {
            return nullptr;
        }
        Node* prev = nullptr;
        Node* current = head;
        Node* nextNode = nullptr;
        do {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        } while (current != head);
        head->next = prev;
        head = prev;
        return head;
    }

    bool DetectLoop(Node* &head) {
        if (head == nullptr) {
            return false;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }

    int CountNodes(Node* &head) {
        int count = 0;
        if (head == nullptr) {
            return count;
        }
        Node* temp = head;
        do {
            ++count;
            temp = temp->next;
        } while (temp != head);
        return count;
    }

    int MaxValue(Node* head) {
        if (head == nullptr) {
            return -1;
        }
        int max_value = head->data;
        Node* temp = head->next;
        do {
            if (temp->data > max_value) {
                max_value = temp->data;
            }
            temp = temp->next;
        } while (temp != head);
        return max_value;
    }

    double Average(Node* head) {
        if (head == nullptr) {
            return 0.0;
        }
        double total = 0.0;
        int count = 0;
        Node* temp = head;
        do {
            total = total + temp->data;
            ++count;
            temp = temp->next;
        } while (temp != head);
        return total / count;
    }

    void insertAt(Node* &head, int value, int index) {
        if (index == 0) {
            AddFirst(head, value);
        } else {
            Node* new_node = new Node(value);
            Node* current = head;
            for (int i = 0; i < index - 1; ++i) {
                if (!current) {
                    cout << "Index out of range" << endl;
                    return;
                }
                current = current->next;
            }
            new_node->next = current->next;
            current->next = new_node;
        }
    }
};

int main() {
    CircularSinglyLinkedList csll;
    Node* head = nullptr;

    int choice;
    do {
        cout << "\nCircular Singly Linked List Operations\n";
        cout << "1. Add Last\n";
        cout << "2. Display\n";
        cout << "3. Delete First\n";
        cout << "4. Delete Last\n";
        cout << "5. Add First\n";
        cout << "6. Search\n";
        cout << "7. Reverse\n";
        cout << "8. Detect Loop\n";
        cout << "9. Count Nodes\n";
        cout << "10. Max Value\n";
        cout << "11. Average\n";
        cout << "12. Insert At\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int val;
                cout << "Enter value to add: ";
                cin >> val;
                csll.AddLast(head, val);
                break;
            }
            case 2:
                cout << "Circular Singly Linked List: ";
                csll.Display(head);
                break;
            case 3:
                csll.DeleteFirst(head);
                cout << "First node deleted.\n";
                break;
            case 4:
                csll.DeleteLast(head);
                cout << "Last node deleted.\n";
                break;
            case 5: {
                int val;
                cout << "Enter value to add at the beginning: ";
                cin >> val;
                csll.AddFirst(head, val);
                break;
            }
            case 6: {
                int key;
                cout << "Enter key to search: ";
                cin >> key;
                if (csll.Search(head, key)) {
                    cout << "Key found.\n";
                } else {
                    cout << "Key not found.\n";
                }
                break;
            }
            case 7:
                head = csll.Reverse(head);
                cout << "List reversed.\n";
                break;
            case 8:
                if (csll.DetectLoop(head)) {
                    cout << "Loop detected.\n";
                } else {
                    cout << "No loop detected.\n";
                }
                break;
            case 9:
                cout << "Number of nodes: " << csll.CountNodes(head) << endl;
                break;
            case 10:
                cout << "Maximum value: " << csll.MaxValue(head) << endl;
                break;
            case 11:
                cout << "Average: " << csll.Average(head) << endl;
                break;
            case 12: {
                int val, index;
                cout << "Enter value to insert: ";
                cin >> val;
                cout << "Enter index to insert at: ";
                cin >> index;
                csll.insertAt(head, val, index);
                break;
            }
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 0);

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
