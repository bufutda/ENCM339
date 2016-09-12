// Lab10List.cpp
// ENCM 339 Fall 2015 Lab 10 Exercise A

#include <iostream>
using std::cout; using std::endl;

typedef int ItemType;

class Lab10List {
public:
  Lab10List() : headM(0) { }
  ~Lab10List() {
    std::cerr << "Warning: Proper dtor not coded for Lab10List class.\n";
  }
  Lab10List(const Lab10List& src);
  Lab10List& operator =(const Lab10List& rhs);

  void insert(const ItemType& new_item);
  // PROMISES: Adds a copy of new_item to list such that the list remains
  // ordered from smallest to largest.

  void remove(const ItemType& the_item);
  // PROMISES: If the_item is not in the list, list is unchanged.
  // Otherwise, removes one copy of the_item from the list such that
  // the list remains ordered from smallest to largest.
  
  void print_on_cout() const;
  // PROMISES: Prints list contents on a single line on std::cout.
  
private:
  struct Node {
    ItemType item;
    Node *next;
  };
  Node *headM;
};

// The copy ctor and copy assignment operator are not implemented.
// That would be a problem if an attempt were made to copy a
// Lab10List object!

void Lab10List::insert(const ItemType& new_item)
{
  Node *new_node = new Node;
  new_node->item = new_item;
  Node **p = &headM;
  while (*p != 0 && (*p)->item < new_item)
    p = &((*p)->next);
  new_node->next = *p;

  // point one

  *p = new_node;
}

void Lab10List::remove(const ItemType& the_item)
{
  Node **p = &headM;
  while (*p != 0 && (*p)->item < the_item)
    p = &((*p)->next);
  if (*p != 0 && (*p)->item == the_item) {
    Node *delete_me = *p;
    *p = delete_me->next;
    delete delete_me;
  }
}

void Lab10List::print_on_cout() const
{
  if (headM == 0)
    cout << "  [empty list]" << endl;
  else {
    for (const Node *p = headM; p != 0; p = p->next)
      cout << "  " << p->item;
    cout << endl;
  }
}

int main()
{
  Lab10List x;
  x.insert(200);
  cout << "After 1 call to insert ..." << endl;
  x.print_on_cout();
  x.insert(100);
  x.insert(400);
  x.insert(300);
  cout << "After 3 more calls to insert ..." << endl;
  x.print_on_cout();

  x.remove(99);
  x.remove(250);
  x.remove(401);
  cout << "After 3 calls to remove that should have no effect ..." << endl;
  x.print_on_cout();
  x.remove(300);
  x.remove(100);
  cout << "After 2 more calls to remove ..." << endl;
  x.print_on_cout();
  x.remove(400);
  x.remove(200);
  cout << "After another 2 calls to remove ..." << endl;
  x.print_on_cout();

  return 0;
}
