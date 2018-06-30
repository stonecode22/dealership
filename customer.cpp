#include"customer.h"

customer::customer()
{
  rentSize = 1;
  rentIDs = new int[rentSize];
  rentIDs[0] = 0;
  canBuyLuxury = false;
  rentPeriod = 0;
  first = NULL;
  last = NULL;
  cID = 0;
  carType = 0;
}

customer::~customer()
{
  rentSize = 0;
  rentPeriod = 0;
  cID = 0;
}

normal::normal(const char* newFirst, const char* newLast, int newID)
{
  first = new char[strlen(newFirst)+1];
  strcpy(first, newFirst);
  last = new char[strlen(newLast)+1];
  strcpy(last, newLast);
  cID = newID;
  carType = 0;
}

void normal::display()
{
  cout << "Name:   " << first << " " << last << endl;
  cout << "Class:  Normal\n";
  cout << "ID:     " << cID << endl;
  cout << "Rented: ";
  for(int i = 0; i < rentSize-1; i++)
    {
      if(rentIDs[i] != 0)
	cout << rentIDs[i] << ", ";
    }
  cout << endl;
}

corps::corps(const char* newFirst, const char* newLast, int newID)
{
  first = new char[strlen(newFirst)+1];
  strcpy(first, newFirst);
  last = new char[strlen(newLast)+1];
  strcpy(last, newLast);
  cID = newID;
  canBuyLuxury = true;
  carType = 1;
}

void corps::display()
{
  cout << "Name:   " << first << " " << last << endl;
  cout << "Class:  Corporation\n";
  cout << "ID:     " << cID << endl;
  cout << "Rented: ";
  for(int i = 0; i < rentSize-1; i++)
    {
      if(rentIDs[i] != 0)
	cout << rentIDs[i] << ", ";
    }
  cout << endl;
}

vips::vips(const char* newFirst, const char* newLast, int newID)
{
  first = new char[strlen(newFirst)+1];
  strcpy(first, newFirst);
  last = new char[strlen(newLast)+1];
  strcpy(last, newLast);
  cID = newID;
  canBuyLuxury = true;
  carType = 2;
}

void vips::display()
{
  cout << "Name:   " << first << " " << last << endl;
  cout << "Class:  VIP\n";
  cout << "ID:     " << cID << endl;
  cout << "Rented: ";
  for(int i = 0; i < rentSize-1; i++)
    {
      if(rentIDs[i] != 0)
	cout << rentIDs[i] << ", ";
    }
  cout << endl;
}

char* customer::setFirst(const char* newFirst)
{
  first = new char[strlen(newFirst)+1];
  strcpy(first, newFirst);
  return first;
}

char* customer::getFirst()
{
  return first;
}

char* customer::setLast(const char* newLast)
{
  last = new char[strlen(newLast)+1];
  strcpy(last, newLast);
  return last;
}

char* customer::getLast()
{
  return last;
}

int customer::setID(int newID)
{
  cID = newID;
  return cID;
}

int customer::getID()
{
  return cID;
}

bool customer::getPermission()
{
  return canBuyLuxury;
}

int customer::rent(int carID)
{
  for(int i = 0; i < rentSize+1; i++)
    {
      if(i < rentSize && rentIDs[i] == '\0')
	{
	  rentIDs[i] = carID;
	}
    }
  rentSize++;
  return carID;
}

int customer::getCarType()
{
  return carType;
}
