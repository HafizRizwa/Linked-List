#include<iostream>
#include<fstream>
using namespace std;
class node
{
	public:
		int data;
		node* next;
		node(int val)
		{
			data=val;
			next=NULL;
		}
};
class singlylinkedlist
{
	public:
void AddLast(node* &head,int val)
{
	node* n=new node(val);
	if(head==NULL)
	{
		head=n;
		return;
	}
	node *temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=n;
}
void Display(node* head)
{
	node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
void DeleteFirst(node* &head)
{
	node* todelete=head;
	head=head->next;
	delete todelete;
}
void DeleteNode(node* &head,int val)
{
	if(head==NULL)
	{
		return;
	}
	if(head->next==NULL)
	{
		DeleteFirst(head);
		return;
	}
	node* temp=head;
	
	while(temp->next->data!=val)
	{
		temp=temp->next;
	}
	node* todelete=temp->next;
	temp->next=temp->next->next;
	delete todelete;
}

void DeleteLast(node* &head)
{
	node* temp=head;
	while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}
	node* todelete=temp->next;
	temp->next=NULL;
	delete todelete;
}

void AddFirst(node* &head,int val)
{
	node* n=new node(val);
	n->next=head;
	head=n;
}
bool search(node* head,int key)
{
	node* temp=head;
	while(temp!=NULL)
	{
		if(temp->data==key)
		{
			return true;
		}
		temp=temp->next;
	}
	return false;
}
node* reverse(node* &head)
{
	node* previousptr=NULL;
	node* currentptr=head;
	node* nextptr;
	while(currentptr!=NULL)
	{
		nextptr=currentptr->next;
		currentptr->next=previousptr;
		
		previousptr=currentptr;
		currentptr=nextptr;
	}
	return previousptr;
}
bool DetectLoop(node* &head)
{
	node* slow=head;
	node* fast=head;
	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
		
		if(fast==slow)
		{
			return true;
		}
	}
}
    int countNodes(node* &head) {
        int count = 0;
        node* current = head;
        while (current!=NULL) {
            ++count;
            current = current->next;
        }
        return count;
    }

    int max(node* head) {
        if (head==NULL) {
            return -1;
        }
        int max_value = head->data;
        node* current = head->next;
        while (current!=NULL) {
            if (current->data > max_value) {
                max_value = current->data;
            }
            current = current->next;
        }
        return max_value;
    }

    double average(node *head) {
        if (head==NULL) {
            return 0.0;
        }
        double total = 0.0;
        int count = 0;
        node* current = head;
        while (current!=NULL) {
            total =total + current->data;
            ++count;
            current = current->next;
        }
        return total / count;
    }
    node* middle(node* head)
    {
    	node* slow=head;
    	node* fast=head;
    	while(fast!=NULL && fast->next!=NULL)
    	{
    		slow=slow->next;
    		fast=fast->next->next;
		}
		return slow;
    	
	}
//   bool isPalindrome(node* &head) {
//       node* mid=middle(head);
//       node* last=reverse(mid->next);
//       node* start=head;
//       while(last!=NULL)
//       {
//
//         if(last->data!=start->data)
//         {
//         	return false;
//		 }
//		last=last->next;
//         start=start->next;
//         
//	   }
//	   return true;
//    }
    void SaveToFile(node* head) {
        ofstream file("linkedlist_data.txt");
        if (file.is_open()) {
            node* temp = head;
            while (temp != nullptr) {
                file << temp->data;
                temp = temp->next;
            }
            file.close();
            cout << "Linked list data saved to file.\n";
        } else {
            cout << "Unable to open the file.\n";
        }
    }

    bool IsPalindrome(node* head) {
        ifstream file("linkedlist_data.txt");
        if (file.is_open()) {
            int fileSize = 0;
            node* temp = head;
            while (temp != nullptr) {
                fileSize++;
                temp = temp->next;
            }

            file.seekg(0, ios::end);
            int fileLength = file.tellg();
            file.seekg(0, ios::beg);

            char* fileContent = new char[fileLength];

            file.read(fileContent, fileLength);
            file.close();

            int i = 0;
            int j = fileSize - 1;

            while (i < j) {
                if (fileContent[i] != fileContent[j]) {
                    delete[] fileContent;
                    return false;
                }
                i++;
                j--;
            }

            delete[] fileContent;
            return true;
        } else {
            cout << "Unable to open the file.\n";
            return false;
        }
    }
void makeCycle(node* &head,int pos)
{
	node* temp=head;
	node* startnode;
	
	int count=1;
	while(count==pos)
	{
		if(count=pos)
		{
			startnode=temp;
		}
		temp=temp->next;
		count++;
	}
	temp->next=startnode;
}
};
int main() {
    singlylinkedlist myList;
    node* head = nullptr;

    int choice;
    do {
        cout << "\n\n----- Doubly Linked List Menu -----\n";
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
        cout << "11. Find Max\n";
        cout << "12. Calculate Average\n";
        cout << "13. Check Palindrome\n";
        cout << "14. Make Cycle\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Enter value to add at the end: ";
                cin >> value;
                myList.AddLast(head, value);
                break;
            }
            case 2:
                cout << "List: ";
                myList.Display(head);
                break;
            case 3:
                myList.DeleteFirst(head);
                cout << "First node deleted.\n";
                break;
            case 4: {
                int value;
                cout << "Enter value to delete: ";
                cin >> value;
                myList.DeleteNode(head, value);
                break;
            }
            case 5:
                myList.DeleteLast(head);
                cout << "Last node deleted.\n";
                break;
            case 6: {
                int value;
                cout << "Enter value to add at the beginning: ";
                cin >> value;
                myList.AddFirst(head, value);
                break;
            }
            case 7: {
                int value;
                cout << "Enter value to search: ";
                cin >> value;
                if (myList.search(head, value)) {
                    cout << value << " found in the list.\n";
                } else {
                    cout << value << " not found in the list.\n";
                }
                break;
            }
            case 8:
                head = myList.reverse(head);
                cout << "List reversed.\n";
                break;
            case 9:
                if (myList.DetectLoop(head)) {
                    cout << "Loop detected in the list.\n";
                } else {
                    cout << "No loop detected in the list.\n";
                }
                break;
            case 10:
                cout << "Number of nodes: " << myList.countNodes(head) << endl;
                break;
            case 11:
                cout << "Max value: " << myList.max(head) << endl;
                break;
            case 12:
                cout << "Average: " << myList.average(head) << endl;
                break;
            case 13:
            	myList.SaveToFile(head);
                if (myList.IsPalindrome(head)) {
                    cout << "The list is a palindrome.\n";
                } else {
                    cout << "The list is not a palindrome.\n";
                }
                break;
            case 14: {
                int pos;
                cout << "Enter position to create a cycle: ";
                cin >> pos;
                myList.makeCycle(head, pos);
                cout << "Cycle added at position " << pos << ".\n";
                break;
            }
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
