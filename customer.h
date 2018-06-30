#ifndef CUSTOMER_H
#define CUSTOMER_H

#include"car.h"

class customer

{
 public:
  customer();
  ~customer();
  virtual void display() = 0;

  char* setFirst(const char* newFirst);
  char* getFirst();
  char* setLast(const char* newLast);
  char* getLast();
  int setID(int newID);
  int getID();
  bool getPermission();
  int rent(int carID);
  int getCarType();
  
 protected:
  char* first;
  char* last;
  int cID;
  int* rentIDs;
  int rentSize;
  int rentPeriod;
  bool canBuyLuxury;
  int carType;
};

class normal : public customer
{
 public:
  normal(const char* first, const char* last, int cID);
  void display();
};

class corps : public customer
{
 public:
  corps(const char* first, const char* last, int cID);
  void display();
};

class vips : public customer
{
 public:
  vips(const char* first, const char* last, int cID);
  void display();
};

#endif
