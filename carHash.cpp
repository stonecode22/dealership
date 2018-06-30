#include"carHash.h"

hashT::hashT()
{
  size = 100; //initial size
  array = new list[size]; //makes the new hash
}

hashT::~hashT()
{
  delete[] array; //deletes hash table
}

int hashT::add(car vehicle)
{
  int index = hf(vehicle.getID()); //index chosen by hash function (based on car ID)
  if(array[index].colCheck() == 4) //if collisions = 4
    {
      list* arrayCpy;
      size = size*2; //double the size
      arrayCpy = new list[size]; //make a copy with double size

      //copy data from original to copy
      for(int i = 0; i < size/2; i++)
	{
	  list v = array[i];
	  int initID = v.retID();
	  while(initID != -1) //while there is a node ID
	    {
	      car newCar(v.retID(), v.retBrand(), v.retName(), v.retType(), v.retRate(), v.retLuxury(), v.retAge());
	      arrayCpy[hf(initID)].add(newCar);
	      v.rem(initID); //remove from old list
	      initID = v.retID(); //update initID
	    }
	}
      int index = hf(vehicle.getID());
      delete[] array; //delete old array
      array = arrayCpy; //make the copy the array of use
      array[index].add(vehicle); //add in vehicle
    }
  else //if list hasn't reached max collisions of 4
    {
      int index = hf(vehicle.getID());
      array[index].add(vehicle);
    }
  return 1;
}

int hashT::rem(int id)
{
  if(array[hf(id)].rem(id) == 0)
    {
      cout << "No car with that ID.\n";
    }
  return 1;
}

void hashT::display()
{
  for(int i = 0; i < size; i++)
    {
      array[i].display();
    }
}

int hashT::hf(int key)
{
  return key % size;
}
  
int hashT::checkSize()
{
  return size;
}

int hashT::rentCar(int carID)
{
  int index = hf(carID);
  return (array[index].rent(carID));
}

bool hashT::setCarStock(int carID, bool lux)
{
  int index = hf(carID);
  return (array[index].setStock(lux, carID));
}
