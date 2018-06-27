#include"customer.h"

customer::customer()
{
  rentPeriod = 0;
  first = NULL;
  last = NULL;
  cID = 0;
}

customer::~customer()
{
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
}

void normal::display()
{
  cout << "Name:   " << first << " " << last << endl;
  cout << "Class:  Normal\n";
  cout << "ID:     " << cID << endl;
}

corps::corps(const char* newFirst, const char* newLast, int newID)
{
  first = new char[strlen(newFirst)+1];
  strcpy(first, newFirst);
  last = new char[strlen(newLast)+1];
  strcpy(last, newLast);
  cID = newID;
}


void corps::display()
{
  cout << "Name:   " << first << " " << last << endl;
  cout << "Class:  Corporation\n";
  cout << "ID:     " << cID << endl;
}

vips::vips(const char* newFirst, const char* newLast, int newID)
{
  first = new char[strlen(newFirst)+1];
  strcpy(first, newFirst);
  last = new char[strlen(newLast)+1];
  strcpy(last, newLast);
  cID = newID;
}


void vips::display()
{
  cout << "NAme:   " << first << " " << last << endl;
  cout << "Class:  VIP\n";
  cout << "ID:     " << cID << endl;
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
