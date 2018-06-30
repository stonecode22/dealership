#ifndef CAR_H
#define CAR_H

#include<iostream>
#include<iomanip>
#include<string.h>
#include<time.h>
#include<fstream>
#include<cstdlib>
using namespace std;

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

#endif
