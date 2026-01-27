#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct Node {
  string value;
  Node* nextNode;
};

struct Stack {
  Node* head;
};


void push(Stack& stack, const string& value) {
  
  Node* node = new Node{value, nullptr};
  Node* currentNode = stack.head;
  node->nextNode = currentNode;
  stack.head = node;

  return;
}


bool isPolidrome(const string& value) {
  if (value.size() == 0) return false;
  
  int left = 0;
  int right = value.size() - 1;

  while (left < right) {
    if (value[left] != value[right]) return false;

    left++;
    right--;
  }

  return true;
}

void polindrome(Stack &stack) {
  if (stack.head == nullptr) return;

  Node* currentNode = stack.head;
  
  while (currentNode != nullptr) {
    bool result = isPolidrome(currentNode->value);
    
    if (!result) {
      cout << currentNode->value << " isn't a palindrome" << endl;
    }
    else {
      cout << currentNode->value << " is a palindrome" << endl;
    }

    currentNode = currentNode->nextNode;
  }
  return;
}

void clearStack(Stack* stack) {
  Node* currentNode = stack->head;
  
  while (currentNode != nullptr) {
    Node* next = currentNode->nextNode;
    delete currentNode;
    currentNode = next;
  }
  
  delete stack;
}

int main()
{
  int choice = -1;

  while (true) {
    cout << "\n1. Write polindrome " << endl;
    cout << "2. Exit" << endl;

    if (!(cin >> choice)) {
      cout << "\nUnknown command " << endl;

      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }

    switch (choice) {
      case 1: {
        Stack* stack = new Stack{ nullptr };

        int count;
        cout << "How many words do you want to check for palindromes?: ";

        while(!(cin >> count)){
          cout << "It is not a int value! Try again: ";

          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Okay, write them all: " << endl;

        for (int i = 0; i < count; i++) {
          
          string currentWord;
          cin >> currentWord;
          push(*stack, currentWord);
          cout << i + 1 << " out of " << count << endl;
        }
       

        polindrome(*stack);

        
        clearStack(stack);
        break;
      }
      case 2: {
        return 0;
      }
      default: {
   
        break;
      }
    }
  }
  
  
  return 0;
}
