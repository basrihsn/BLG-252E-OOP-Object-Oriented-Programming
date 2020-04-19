/*
   In this program sample linked list operations can be applied.
   Whole program is written based on OOP terminology.
*/
#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node * next;
		Node * head;
		~Node();
};

Node::~Node()
{
	Node * iter = this->head;
	while(this->head != NULL){
		Node * iter = this->head;
		this->head = this->head->next;
		delete iter;
	}
}

void printList(Node * head)
{
	if(head == NULL){
		cout << "List is empty..." << endl;
		return;
	}
	Node * iter = head;
	while(iter != NULL){
		cout << iter->data << " ";
		iter = iter->next;
	}
	cout << endl;
}

Node* insert_head(Node* head, int data)
{
	Node * temp = new Node();
	temp->data = data;
	temp->next = head;
	head = temp;
	return head;
}

void insert_after_given_node(Node * given, int data)
{
	Node * temp = new Node();
	temp->data = data;
	temp->next = given->next;
	given->next = temp;
}

Node* insert_last(Node*head, int data)
{
	Node * temp = new Node();
	temp->data = data;
	temp->next = NULL;
	Node * iter = head;
	while(iter->next != NULL){
		iter = iter->next;
	}
	iter->next = temp;
	return head;
}

void nodeInfo(Node * head, int key)
{
	int i = 1;
	while(head != NULL){
		if(i == key){
			cout << i << ". node address = " << head << endl;
			cout << i << ". node data = " << head->data << endl;
			cout << i << ". node's next's address " << head->next << "\n\n";
		}
		head = head->next;
		i++;
	}
}

int count(Node * head)
{
	int counter = 0;
	while(head != NULL){
		counter++;
		head = head->next;
	}
	return counter;
}

bool search(Node * head, int key)
{
	if(head == NULL){
		cout << "List is empty..." << endl;
		return false;
	}
	while(head != NULL){
		if(head->data != key)
			head = head->next;
		else{
			return true;
		}
	}
}

int main()
{
	int choice, data;
	Node * head = NULL;
	
	while(1){
		cout << "LINKED LIST OPERATIONS PROGRAM... \n";
		cout << "1. Add node head of the list \n";
		cout << "2. Add node end of the list \n";
		cout <<	"3. Print list \n";
		cout << "4. Number of nodes in list \n";
		cout << "5. Information of node (if exist) \n";
		cout << "6. Exit \n";
		cout << "Choice: ";
		cin >> choice;
		cin.clear();
		switch(choice){
			case 1:
				cout << "Enter the number: ";
				cin >> data;
				cin.clear();
				head = insert_head(head, data);
				break;
			case 2:
				cout << "Enter the number: ";
				cin >> data;
				cin.clear();
				head = insert_last(head, data);
				break;
			case 3:
				printList(head);
				break;
			case 4:
				cout << "In list there are " << count(head) << " nodes." << endl;
				break;
			case 5:
				cout << "Which node's information do you want?: ";
				cin >> data;
				cin.clear();
				nodeInfo(head, data);
				break;
			case 6:
				exit(1);
				break;
			default:
				cout << "Wrong choice..." << endl;
		}
	}
	
	system("pause");
	return 0;
}
