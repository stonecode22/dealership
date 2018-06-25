#ifndef CUSTOMER_H
#define CUSTOMER_H

#include"dealer.h"
class customer
{
 public:
  customer();
  ~customer();
  //  int returnCar(int cID);
  //  int rentStandard(int cID);
  virtual void display() = 0;

  char* setFirst(const char* newFirst);
  char* getFirst();
  char* setLast(const char* newLast);
  char* getLast();
  int setID(int newID);
  int getID();
  
 protected:
  char* first;
  char* last;
  int cID;
  int rentPeriod;
};

class normal : public customer
{
 public:
  normal(const char* first, const char* last, int cID);
  int rentPeriod;
  void display();
};

class corps : public customer
{
 public:
  corps(const char* first, const char* last, int cID);
  //  int rentLuxury(int id);
  int rentPeriod;
  void display();
};

class vips : public customer
{
 public:
  vips(const char* first, const char* last, int cID);
  //  int rentLuxury(int id);
  int rentPeriod;
  void display();
};

#endif
