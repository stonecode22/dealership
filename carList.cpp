#include"carList.h"

list::list()
{
  count = 0;
  head = NULL;
}

list::~list()
{
  while(head != NULL)
    {
      node* temp = head->next;
      delete head;
      head = temp;
    }
  count = 0;
}

int list::add(car newCar)
{
  return add(head, newCar);
}

int list::add(node* &head, car newCar)
{
  if(head == NULL)
    {
      node* newNode = new node;
      
      newNode->vehicle.setID(newCar.getID());
      newNode->vehicle.setStock(newCar.getStock());
      newNode->vehicle.setBrand(newCar.getBrand());
      newNode->vehicle.setName(newCar.getName());
      newNode->vehicle.setType(newCar.getType());
      newNode->vehicle.setRate(newCar.getRate());
      newNode->vehicle.setLuxury(newCar.getLuxury());
      newNode->vehicle.setAge(newCar.getAge());
      newNode->next = NULL;
      head = newNode;
      count++;
      return 1;
    }
  else
    {
      return add(head->next, newCar);
    }
}

int list::rem(int id)
{
  return rem(head, id);
}

int list::rem(node* &head, int id)
{
  if(head == NULL)
    {
      return 0;
    }
  else
    {
      if(id == head->vehicle.getID())
	{
	  node* temp = head->next;
	  delete head;
	  head = temp;
	  count--;
	  return 1;
	}
      else
	{
	  return rem(head->next, id);
	}
    }
}

int list::colCheck()
{
  return count;
}

void list::display()
{
  return display(head);
}

void list::display(node* head)
{
  if(head == NULL)
    {
      return;
    }
  else
    {
      node* temp = head;
      while(temp != NULL)
	{
	  temp->vehicle.displayAll();
	  temp = temp->next;
	}
    }
}

int list::rent(int carID)
{
  return rent(head, carID);
}

int list::rent(node* &head, int carID)
{
  if(head == NULL)
    {
      return -1;
    }
  else
    {
      if(carID == head->vehicle.getID())
	{
	  if(head->vehicle.getStock() == true)
	    {
	      if(head->vehicle.getLuxury() == false)
		{
		  return 1;
		}
	      else
		{
		  return 2;
		}
	    }
	  else
	    {
	      return 0;
	    }
	}
      else
	{
	  return rent(head->next, carID);
	}
    }
}

bool list::setStock(bool lux, int carID)
{
  return setStock(head, lux, carID);
}

bool list::setStock(node* &head, bool lux, int carID)
{
  if(head == NULL)
    {
      return false;
    }
  else
    {
      if(carID == head->vehicle.getID())
	{
	  head->vehicle.setStock(lux);
	  return lux;
	}
      else
	{
	  return setStock(head->next, lux, carID);
	}
    }
}
	  

int list::retID()
{
  if(head != NULL)
    {
      return head->vehicle.getID();
    }
  else
    {
      return -1;
    }
}

int list::retAge()
{
  if(head != NULL)
    {
      return head->vehicle.getAge();
    }
  else
    {
      return -1;
    }
}

char* list::retName()
{
  if(head != NULL)
    {
      return head->vehicle.getName();
    }
  else
    {
      return NULL;
    }
}

char* list::retBrand()
{
  if(head != NULL)
    {
      return head->vehicle.getBrand();
    }
  else
    {
      return NULL;
    }
}

char* list::retType()
{
  if(head != NULL)
    {
      return head->vehicle.getType();
    }
  else
    {
      return NULL;
    } 
}

float list::retRate()
{
  if(head != NULL)
    {
      return head->vehicle.getRate();
    }
  else
    {
      return -1;
    }
}

bool list::retLuxury()
{
  if(head != NULL)
    {
      return head->vehicle.getLuxury();
    }
  else
    {
      return false;
    }
}

bool list::retStock()
{
  if(head != NULL)
    {
      return head->vehicle.getStock();
    }
  else
    {
      return false;
    }
}
