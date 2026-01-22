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

  vector<string> data = { "404", "1232", "jidg", "apa", "souidhghsiouhg", "09213582095" };
  Stack* stack = new Stack{ nullptr };

  for (int i = 0; i < data.size(); i++) {
    push(*stack, data[i]);
  }

  polindrome(*stack);
  

  


  delete stack;
  return 0;
}
