#ifndef CUSTLL_H
#define CUSTLL_H

#include"custList.h"

class lll
{
 public:
  lll();
  ~lll();
  int add(customer* p);
  int rem(int id);
  int display();
 private:
  int add(nodeC* &head, customer* p);
  int rem(nodeC* &head, int id);
  int display(nodeC* head);
};

#endif
