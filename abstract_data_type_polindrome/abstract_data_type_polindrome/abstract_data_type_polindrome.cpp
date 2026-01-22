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


int getStackLength(Stack& stack) {
  int length = 0;
  Node* currentNode = stack.head;

  while (currentNode != nullptr) {
    length++;

    currentNode = currentNode->nextNode;
  }


  return length;
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
  int length = getStackLength(stack);

  for (int i = 0; i < length; i++) {
    
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

int main()
{
  int choice = -1;
  cout << "1. Write polindrome" << endl;
  cout << "2. Exit" << endl;

  while (true) {
    cin >> choice;
    switch (choice) {
      case 1: {
        vector<string> data;
        Stack* stack = new Stack{ nullptr };

        int count;
        cout << "How many words do you want to check for palindromes?";
        cin >> count;

        cout << "Okay, write them all: " << endl;

        for (int i = 0; i < count; i++) {
          
          string currentWord;
          cin >> currentWord;
          data.push_back(currentWord);
          cout << i + 1 << " out of " << count << endl;
        }

        for (int i = 0; i < data.size(); i++) {
          Node* node = new Node{ data[i], nullptr };
          Node* currentNode = stack->head;
          node->nextNode = currentNode;
          stack->head = node;
        }

        polindrome(*stack);

        break;
      }
      case 2: {
        return 0;
      }
      default: {
        cout << "unknown command, try again." << endl;
        break;
      }
    }
  }
  
  
  return 0;
}
