#ifndef CUSTLIST_H
#define CUSTLIST_H

#include "customer.h"

struct nodeC
{
  customer* c;
  nodeC* next;
};

class cll
{
 public:
  cll();
  ~cll();
  int add(customer* person);
  int rem(int id);
  void displayAll();
 private:
  int add(nodeC* &rear, customer* p);
  int rem(nodeC* &rear, int id);
  void displayAll(nodeC* rear);
  nodeC* rear;
};

#endif
