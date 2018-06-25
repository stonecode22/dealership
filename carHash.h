#ifndef CARHASH_H
#define CARHASH_H

#include"carList.h"

class hashT
{
 public:
  hashT();
  ~hashT();
  int add(car vehicle);
  int rem(int id);
  void display();
  int checkSize();

 private:
  int hf(int key);
  list* array;
  int size;
};

#endif
