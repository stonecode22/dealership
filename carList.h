#pragma
#include"dealer.h"

struct node
{
  car vehicle;
  node* next;
};

class list
{
 public:
  list();
  ~list();
  int add(car newCar);
  int rem(int id);
  int colCheck();
  void display();

  //return to hash table
  int retID();
  int retAge();
  char* retName();
  char* retBrand();
  char* retType();
  float retRate();
  bool retLuxury();
  bool retStock();
  
 private:
  node* head;
  int count;
  int add(node* &head, car newCar);
  int rem(node* &head, int id);
  void display(node* head);
};
