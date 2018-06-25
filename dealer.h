#ifndef DEALER_H
#define DEALER_H

#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

/*
class dealer
{
 public:
  dealer();
  ~dealer();
  void addCar(car newCar);
  bool remCar(int id);
 private:
  hashT ha;
  list list;
};
*/

class car
{
 public:
  car();
  car(int id, const char* brand, const char* name, const char* type, float rate, bool luxury, int age);
  ~car();
  void displayAll();

  //for list
  int getID();
  int setID(int newID);
  bool getStock();
  bool setStock(bool newStock);
  int getAge();
  int setAge(int newAge);
  char* getType();
  char* setType(char* newType);
  char* getName();
  char* setName(char* newName);
  char* getBrand();
  char* setBrand(char* newBrand);
  bool getLuxury();
  bool setLuxury(bool newLuxury);
  float getRate();
  float setRate(float newRate);

 protected:
  int id;
  bool stock;
  int age;
  char* type;
  char* name;
  char* brand;
  bool luxury;
  float rate;
};

//customer class

/*
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
*/

#endif
