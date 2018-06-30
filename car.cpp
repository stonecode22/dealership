#include"carHash.h"

car::car()
{
  id = 0;
  stock = true;
  age = 0;
  type = NULL;
  name = NULL;
  brand = NULL;
  luxury = false;
  rate = 0;
}

car::car(int newId, const char* newBrand, const char* newName, const char* newType, float newRate, bool newLux, int newAge)
{
  id = newId;
  type = new char[strlen(newType)+1];
  strcpy(type, newType);
  name = new char[strlen(newName)+1];
  strcpy(name, newName);
  brand = new char[strlen(newBrand)+1];
  strcpy(brand, newBrand);
  rate = newRate;
  luxury = newLux;
  age = newAge;
  stock = true;
}

car::~car()
{
  id = 0;
  luxury = false;
  stock = false;
  rate = 0;
  age = 0;
}

void car::displayAll()
{
  cout << "Brand:       " << brand << endl;
  cout << "Name:        " << name << endl;
  cout << "Class:       ";
  if(luxury == true)
    {
      cout << "Luxury\n";
    }
  else
    {
      cout << "Standard\n";
    }
  cout << "Type:        " << type << endl;
  cout << "Model ID:    " << id << endl;
  cout << "Daily rate:  " << fixed << setprecision(2) << rate << endl;
  cout << "Age (Years): ";
  if(age == 0)
    {
      cout << "NEW\n";
    }
  else
    {
      cout << age << endl;
    }
  cout << "Stock:       ";
  if(stock == false)
    {
      cout << "Not available\n\n";
    }
  else
    {
      cout << "Available\n\n";
    }
}

int car::getID()
{
  return id;
}

int car::setID(int newID)
{
  id = newID;
  return id;
}

bool car::getStock()
{
  return stock;
}

bool car::setStock(bool newStock)
{
  stock = newStock;
  return stock;
}

int car::getAge()
{
  return age;
}

int car::setAge(int newAge)
{
  age = newAge;
  return age;
}

char* car::getType()
{
  return type;
}

char* car::setType(char* newType)
{
  type = new char[strlen(newType)+1];
  strcpy(type, newType);
  return type;
}

char* car::getName()
{
  return name;
}

char* car::setName(char* newName)
{
  name = new char[strlen(newName)+1];
  strcpy(name, newName);
  return name;
}

char* car::getBrand()
{
  return brand;
}

char* car::setBrand(char* newBrand)
{
  brand = new char[strlen(newBrand)+1];
  strcpy(brand, newBrand);
  return brand;
}

bool car::getLuxury()
{
  return luxury;
}

bool car::setLuxury(bool newLuxury)
{
  luxury = newLuxury;
  return luxury;
}

float car::getRate()
{
  return rate;
}

float car::setRate(float newRate)
{
  rate = newRate;
  return rate;
}
