#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) 
	{
		data=val;
		next=NULL;
		prev=NULL;
	}
};
class DoublyLinkedList {
public:
    void AddLast(Node* &head, int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void Display(Node* head) {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void DeleteFirst(Node* &head) {
        if (head == nullptr) {
            return;
        }
        Node* toDelete = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete toDelete;
    }

    void DeleteNode(Node* &head, int val) {
        if (head == nullptr) {
            return;
        }
        if (head->next == nullptr) {
            DeleteFirst(head);
            return;
        }
        Node* temp = head;

        while (temp->next->data != val) {
            temp = temp->next;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        if (temp->next != nullptr) {
            temp->next->prev = temp;
        }
        delete toDelete;
    }

    void DeleteLast(Node* &head) {
        if (head == nullptr) {
            return;
        }
        if (head->next == nullptr) {
            DeleteFirst(head);
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        Node* toDelete = temp->next;
        temp->next = nullptr;
        delete toDelete;
    }

    void AddFirst(Node* &head, int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    }

    bool Search(Node* head, int key) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    Node* Reverse(Node* &head) {
        Node* current = head;
        Node* temp = nullptr;
        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp != nullptr) {
            head = temp->prev;
        }
        return head;
    }

    bool DetectLoop(Node* &head) {
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
        Node* current = head;
        while (current != nullptr) {
            ++count;
            current = current->next;
        }
        return count;
    }

    int MaxValue(Node* head) {
        if (head == nullptr) {
            return -1;
        }
        int max_value = head->data;
        Node* current = head->next;
        while (current != nullptr) {
            if (current->data > max_value) {
                max_value = current->data;
            }
            current = current->next;
        }
        return max_value;
    }

    double Average(Node* head) {
        if (head == nullptr) {
            return 0.0;
        }
        double total = 0.0;
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            total = total + current->data;
            ++count;
            current = current->next;
        }
        return total / count;
    }
        void insertAt(Node* head,int value, int index) {
        if (index == 0) {
            AddFirst(head,value);
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
    DoublyLinkedList dll;
    Node* head = NULL;

    int choice;
    do {
        cout << "\nDoubly Linked List Operations\n";
        cout << "1. Add Last\n";
        cout << "2. Display\n";
        cout << "3. Delete First\n";
        cout << "4. Delete Node\n";
        cout << "5. Delete Last\n";
        cout << "6. Add First\n";
        cout << "7. Search\n";
        cout << "8. Reverse\n";
        cout << "9. Detect Loop\n";
        cout << "10. Count Nodes\n";
        cout << "11. Max Value\n";
        cout << "12. Average\n";
        cout << "13. Insert At\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int val;
                cout << "Enter value to add: ";
                cin >> val;
                dll.AddLast(head, val);
                break;
            }
            case 2:
                cout << "Doubly Linked List: ";
                dll.Display(head);
                break;
            case 3:
                dll.DeleteFirst(head);
                cout << "First node deleted.\n";
                break;
            case 4: {
                int val;
                cout << "Enter value to delete: ";
                cin >> val;
                dll.DeleteNode(head, val);
                break;
            }
            case 5:
                dll.DeleteLast(head);
                cout << "Last node deleted.\n";
                break;
            case 6: {
                int val;
                cout << "Enter value to add at the beginning: ";
                cin >> val;
                dll.AddFirst(head, val);
                break;
            }
            case 7: {
                int key;
                cout << "Enter key to search: ";
                cin >> key;
                if (dll.Search(head, key)) {
                    cout << "Key found.\n";
                } else {
                    cout << "Key not found.\n";
                }
                break;
            }
            case 8:
                head = dll.Reverse(head);
                cout << "List reversed.\n";
                break;
            case 9:
                if (dll.DetectLoop(head)) {
                    cout << "Loop detected.\n";
                } else {
                    cout << "No loop detected.\n";
                }
                break;
            case 10:
                cout << "Number of nodes: " << dll.CountNodes(head) << endl;
                break;
            case 11:
                cout << "Maximum value: " << dll.MaxValue(head) << endl;
                break;
            case 12:
                cout << "Average: " << dll.Average(head) << endl;
                break;
            case 13: {
                int val, index;
                cout << "Enter value to insert: ";
                cin >> val;
                cout << "Enter index to insert at: ";
                cin >> index;
                dll.insertAt(head, val, index);
                break;
            }
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 0);
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
