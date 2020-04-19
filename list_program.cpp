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
		cout << "Listede eleman yok" << endl;
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
			cout << i << ". node'un adresi = " << head << endl;
			cout << i << ". node'un verisi = " << head->data << endl;
			cout << i << ". node'un bagli oldugu node'un adresi " << head->next << "\n\n";
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
		cout << "Liste bos..." << endl;
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
		cout << "LISTE ISLEMLERI PROGRAMI... \n";
		cout << "1. Listenin basina eleman ekle \n";
		cout << "2. Listenin sonuna eleman ekle \n";
		cout <<	"3. Listeyi ekrana bastir \n";
		cout << "4. Listedeki eleman sayisi \n";
		cout << "5. Istenen dugumun bilgisi(varsa) \n";
		cout << "6. Cikis \n";
		cout << "Seciminiz: ";
		cin >> choice;
		cin.clear();
		switch(choice){
			case 1:
				cout << "Eklemek istediginiz sayiyi giriniz: ";
				cin >> data;
				cin.clear();
				head = insert_head(head, data);
				break;
			case 2:
				cout << "Eklemek istediginiz sayiyi giriniz: ";
				cin >> data;
				cin.clear();
				head = insert_last(head, data);
				break;
			case 3:
				printList(head);
				break;
			case 4:
				cout << "Listede " << count(head) << " eleman vardir." << endl;
				break;
			case 5:
				cout << "Hangi dugumun bilgisini istiyorsunuz?: ";
				cin >> data;
				cin.clear();
				nodeInfo(head, data);
				break;
			case 6:
				exit(1);
				break;
			default:
				cout << "Yanlis secim" << endl;
		}
	}
	
	system("pause");
	return 0;
}
