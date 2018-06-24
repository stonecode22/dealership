#include "dealer.h"

struct node
{
  customer c;
  node* next;
};

class cll
{
 public:
  cll();
  ~cll();
  int add(customer person);
  int rem(int id);
  void displayAll();
 private:
  int add(node* &rear, customer p);
  int rem(node* &rear, int id);
  void displayAll(node* rear);
  node* rear;
};
