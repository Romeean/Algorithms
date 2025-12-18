
#include <iostream>

using namespace std;
//– INSERT(x, p, L).Вставити елемент x у позицію p у списку L.
 
//– LOCATE(x, L).Повертає позицію елемента x у списку L.

//– RETRIEVE(p, L).Повертає елемент, що стоїть в позиції p списку

//– DELETE(p, L).Цей оператор видаляє елемент у позиції р списку

//– NEXT(p, L), PREVIOUS(p, L).Ці функції повертають відповідно наступну й попередню позиції від позиції р у списку L.
 
//– MAKENULL(L).Ця функція робить список L порожнім.

//– FIRST(L).Ця функція повертає першу позицію в списку L.

//– PRINTLIST(L).Друкує елементи списку L у порядку їх розташування.


struct Node {
	int value;
	Node* nextNode;
};

struct List {
	Node* head;
};

void insert(int x, int position, List &List){
	if (position == 0) {
		Node* currentNode = List.head;
		Node* newNode = new Node{ x, nullptr };
		newNode->nextNode = currentNode;
		List.head = newNode;
		return;
	}
	
	Node* currentNode = List.head;
	int i = 0;
	while (currentNode != nullptr) {
		
		if (position - 1 == i) {
			Node* nodeNext = currentNode->nextNode;    // получаем ноду на элемент i + 1;
			Node* newNode = new Node{ x, nullptr };    // создаем новый элемент

			newNode->nextNode = currentNode->nextNode; // записываем для новой ноды ссылку на i + 1;
			currentNode->nextNode = newNode; 
			return;
		}
		currentNode = currentNode->nextNode;
		i++;
	}
	return;
}

int locate(int x ,List &List) {
	Node* currentNode= List.head;

	int i = 0;
	while(currentNode!= nullptr) {
		
		if (currentNode->value == x) {
			return i;
		}

		currentNode= currentNode->nextNode;
		i++;
	}

	return -1;
}

int retrive(int position, List& List) {
	Node* currentNode= List.head;
	int i = 0;
	while(currentNode!= nullptr){
		if (i == position) {
			return currentNode->value;
		}

		currentNode= currentNode->nextNode;
		i++;
	}

	return -1;
}

void remove(int position, List& List) {
	if (position == 0) {
		Node* currentNode = List.head;
		currentNode->nextNode = nullptr;

		delete currentNode;
		
	}
	
	Node* currentNode = List.head;

	int i = 0;
	while (currentNode != nullptr) {
		if (position - 1 == i) {
			Node* nodeToDelete = currentNode->nextNode;
			Node* nextNode = nodeToDelete->nextNode;

			currentNode->nextNode = nextNode;

			delete nodeToDelete;

		}
		currentNode = currentNode->nextNode;
	}
}

int next(int position, List& List) {
	Node* currentNode = List.head;

	int i = 0;
	while (currentNode != nullptr) {
		if (position + 1 == i) {
			return currentNode->value;
		}
		currentNode = currentNode->nextNode;
		i++;
	}

}

int previous(int position, List &List) {
	Node* currentNode = List.head;
	
	int i = 0;
	while(currentNode != nullptr) {
		if (position - 1 == i) {
			return currentNode->value;
		}
		i++;
	}

}

void makeNull(List &List) {
	Node* currentNode = List.head;

	int i = 0;
	while (currentNode != nullptr) {
		currentNode = nullptr;
		currentNode = currentNode->nextNode;
	}
}

int first(List &List) {
	return List.head->value;
}

void showList(List &List) {

	Node* currentNode = List.head;

	while (currentNode != nullptr) {
		cout << currentNode->value << " ";

		currentNode = currentNode->nextNode;
	}
}

int main()
{
	List List;
	return 0;
}

