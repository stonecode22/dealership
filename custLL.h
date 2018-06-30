#ifndef CUSTLL_H
#define CUSTLL_H

#include"custList.h"

struct circs
{
  cll clist;
  circs* next;
};

class lll
{
 public:
  lll();
  ~lll();
  int add(customer* p);
  int rem(int id);
  int display();
  int rent(int carID, int custID);
  bool checkLuxury(int custID);
 private:
  int add(circs* &head, customer* p);
  int rem(circs* &head, int id);
  int display(circs* head);
  int rent(circs* &head, int carID, int custID);
  bool checkLuxury(circs* &head, int custID);
  circs* head;
};

#endif
