#ifndef DEALER_H
#define DEALER_H

#include"custLL.h"
#include"carHash.h"

class dealer
{
 public:
  dealer();
  ~dealer();
  void addCar(car newCar);
  void remCar(int id);
  void displayCars();
  void addCust(customer* newCustomer);
  void remCust(int id);
  void rent(int carID, int custID);
  void returnCar(int carID, int custID);
  void displayCustomers();
 private:
  hashT table;
  lll circList;  
};

#endif
