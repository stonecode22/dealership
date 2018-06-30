#ifndef CARLIST_H
#define CARLIST_H
#include"car.h"

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
  int rent(int carID);
  bool setStock(bool lux, int carID);
  
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
  int rent(node* &head, int carID);
  bool setStock(node* &head, bool lux, int carID);
  void display(node* head);
};

#endif
