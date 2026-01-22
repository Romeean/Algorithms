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
		
		if (position == i) {
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

int locate(int x, List &List) {
	Node* currentNode = List.head;

	int i = 0;
	while(currentNode != nullptr) {
		
		if (currentNode->value == x) {
			return i;
		}

		currentNode = currentNode->nextNode;
		i++;
	}

	return -1;
}

int retrive(int position, List& List) {
	Node* currentNode = List.head;
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
		if (List.head == nullptr) return;
		
		Node* currentNode = List.head;
		List.head = List.head->nextNode;
		
		delete currentNode;
		return;
	}
	
	Node* currentNode = List.head;

	int i = 0;
	while (currentNode != nullptr) {
		if (position - 1 == i) {
			if (currentNode->nextNode == nullptr) return;

			Node* nodeToDelete = currentNode->nextNode;
			currentNode->nextNode = nodeToDelete->nextNode;


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

	return -1;
}

int previous(int position, List &List) {
	Node* currentNode = List.head;
	
	int i = 0;
	while(currentNode != nullptr) {
		if (position - 1 == i) {
			return currentNode->value;
		}
		i++;

		currentNode = currentNode->nextNode;
	}

	return -1;
}

void makeNull(List &List) {

	int i = 0;
	while (List.head != nullptr) {
		Node* currentNode = List.head;
		
		List.head = List.head->nextNode;
		delete currentNode;
	}

	return;
}

int first(List &List) {
	if (List.head != nullptr) {
		return List.head->value;
	};
	return -1;
}

void showList(List &List) {

	Node* currentNode = List.head;

	while (currentNode != nullptr) {
		cout << currentNode->value << " ";

		currentNode = currentNode->nextNode;
	}

	return;
}

int main()
{
	List list{ nullptr };

	while (true) {
		cout << "\n===== LIST MENU =====\n";
		cout << "1  - INSERT(x, p)\n";
		cout << "2  - DELETE(p)\n";
		cout << "3  - LOCATE(x)\n";
		cout << "4  - RETRIEVE(p)\n";
		cout << "5  - NEXT(p)\n";
		cout << "6  - PREVIOUS(p)\n";
		cout << "7  - FIRST()\n";
		cout << "8  - PRINTLIST()\n";
		cout << "9  - MAKENULL()\n";
		cout << "0  - EXIT\n";
		cout << "Choose: ";

		int choice;
		cin >> choice;

		if (choice == 0) break;

		if (choice == 1) {
			int x, p;
			cout << "Value x: ";
			cin >> x;
			cout << "Position p: ";
			cin >> p;
			insert(x, p, list);
		}
		else if (choice == 2) {
			int p;
			cout << "Position p: ";
			cin >> p;
			remove(p, list);
		}
		else if (choice == 3) {
			int x;
			cout << "Value x: ";
			cin >> x;
			cout << "Position: " << locate(x, list) << endl;
		}
		else if (choice == 4) {
			int p;
			cout << "Position p: ";
			cin >> p;
			cout << "Value: " << retrive(p, list) << endl;
		}
		else if (choice == 5) {
			int p;
			cout << "Position p: ";
			cin >> p;
			cout << "Next value: " << next(p, list) << endl;
		}
		else if (choice == 6) {
			int p;
			cout << "Position p: ";
			cin >> p;
			cout << "Previous value: " << previous(p, list) << endl;
		}
		else if (choice == 7) {
			cout << "First value: " << first(list) << endl;
		}
		else if (choice == 8) {
			cout << "List: ";
			showList(list);
			cout << endl;
		}
		else if (choice == 9) {
			makeNull(list);
			cout << "List cleared\n";
		}
		else {
			cout << "Invalid option\n";
		}
	}

	makeNull(list); 
	return 0;
}

