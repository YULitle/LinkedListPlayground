#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <regex>
#include <iterator>

using namespace std;

class Node{
  public:
    int data;
    Node* next;
};

void printList(Node* n){
  while (n!=NULL){
    cout << n->data << endl;
    n = n->next;
  }
}

Node* findLast(Node* head_ref){
  Node* n = head_ref;
  while (n->next!=NULL){n=n->next;}
  return n;
}

void insertNode(Node** head_ref,int x){
  Node* new_node = new Node();
  new_node->data = x;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}
void appendList(Node* head_ref,int x){
  Node* f = findLast(head_ref);
  Node* new_node = new Node();
  new_node->data = x;
  new_node->next = NULL;
  f->next = new_node;
}

void eraseNodeByVal(Node* head_ref,int x){
  Node* f = head_ref;
  Node* l = f->next;
  do{f=f->next;l=l->next;}while(l->data!=x);
  f->next = l->next;
  delete l;
}

void afterNode(Node* node_ref,int x){
  Node* new_node = new Node();
  new_node->data = x;
  new_node->next = node_ref->next;
  node_ref->next = new_node;
}

void afterValue(Node* head_ref,int x,int y){
  Node* f = head_ref;
  while (f->data!=x){
    f=f->next;
  }
  afterNode(f,y);
}

int main() {
  Node* head = NULL;
  Node* second = NULL;
  Node* third = NULL;

  head = new Node();
  second = new Node();
  third = new Node();

  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = NULL;

  insertNode(&head,3);
  afterNode(second,4);
  appendList(head,10);
  printList(head);
  cout << endl << endl;
  eraseNodeByVal(head,2);
  printList(head);
  return 0;
}