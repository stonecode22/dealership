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
  int displayAll();
 private:
  int add(nodeC* &rear, nodeC* &last, customer* p);
  int rem(nodeC* &rear, nodeC* &last, int id);
  int displayAll(nodeC* rear);
  nodeC* rear;
  nodeC* last;
  int count;
};

#endif
