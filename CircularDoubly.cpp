#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class CircularDoublyLinkedList {
public:
    void AddLast(Node* &head, int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }
        Node* temp = head->prev;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = head;
        head->prev = newNode;
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
        head = head->next;
        head->prev = toDelete->prev;
        toDelete->prev->next = head;
        delete toDelete;
    }

    void DeleteLast(Node* &head) {
        if (head == nullptr) {
            return;
        }
        Node* toDelete = head->prev;
        head->prev = toDelete->prev;
        toDelete->prev->next = head;
        delete toDelete;
    }

    void AddFirst(Node* &head, int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        head = newNode;
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
        Node* current = head;
        do {
            swap(current->prev, current->next);
            current = current->prev;
        } while (current != head);
        head = head->prev;
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
            new_node->prev = current;
            if (current->next) {
                current->next->prev = new_node;
            }
            current->next = new_node;
        }
    }
};

int main() {
    CircularDoublyLinkedList cdll;
    Node* head = nullptr;

    int choice;
    do {
        cout << "\nCircular Doubly Linked List Operations\n";
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
                cdll.AddLast(head, val);
                break;
            }
            case 2:
                cout << "Circular Doubly Linked List: ";
                cdll.Display(head);
                break;
            case 3:
                cdll.DeleteFirst(head);
                cout << "First node deleted.\n";
                break;
            case 4:
                cdll.DeleteLast(head);
                cout << "Last node deleted.\n";
                break;
            case 5: {
                int val;
                cout << "Enter value to add at the beginning: ";
                cin >> val;
                cdll.AddFirst(head, val);
                break;
            }
            case 6: {
                int key;
                cout << "Enter key to search: ";
                cin >> key;
                if (cdll.Search(head, key)) {
                    cout << "Key found.\n";
                } else {
                    cout << "Key not found.\n";
                }
                break;
            }
            case 7:
                head = cdll.Reverse(head);
                cout << "List reversed.\n";
                break;
            case 8:
                if (cdll.DetectLoop(head)) {
                    cout << "Loop detected.\n";
                } else {
                    cout << "No loop detected.\n";
                }
                break;
            case 9:
                cout << "Number of nodes: " << cdll.CountNodes(head) << endl;
                break;
            case 10:
                cout << "Maximum value: " << cdll.MaxValue(head) << endl;
                break;
            case 11:
                cout << "Average: " << cdll.Average(head) << endl;
                break;
            case 12: {
                int val, index;
                cout << "Enter value to insert: ";
                cin >> val;
                cout << "Enter index to insert at: ";
                cin >> index;
                cdll.insertAt(head, val, index);
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
