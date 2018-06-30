#include"custLL.h"

lll::lll()
{
  head = NULL;
}

lll::~lll()
{
  
}
  
int lll::add(customer* p)
{
  return add(head, p);
}

int lll::add(circs* &h, customer* p)
{
  if(h == NULL)
    {
      circs* newCirc = new circs;
      newCirc->clist.add(p);
      newCirc->next = NULL;
      h = newCirc;
      return 0;
    }
  else
    {
      if(h->clist.getCount() < 3)
	{
	  h->clist.add(p);
	  return 1;
	}
      else
	{
	  return add(h->next, p);
	}
    }
}

int lll::rem(int id)
{
  return rem(head, id);
}

int lll::rem(circs* &h, int id)
{
  if(head == NULL)
    {
      return 0;
    }
  if(h->clist.rem(id) != 1)
    {
      return rem(head->next, id);
    }
  else
    {
      return 1;
    }
}

int lll::display()
{
  return display(head);
}

int lll::display(circs* head)
{
  if(head == NULL)
    {
      return 0;
    }
  else
    {
      head->clist.displayAll();
      display(head->next);
      return 1;
    }
}

int lll::rent(int carID, int custID)
{
  return rent(head, carID, custID);
}

int lll::rent(circs* &head, int carID, int custID)
{
  if(head == NULL)
    {
      cout << "No customer with ID #" << custID << endl;
      return 0;
    }
  else
    {
      if(head->clist.rent(carID, custID) != 1)
	{
	  return rent(head->next, carID, custID);
	}
      return 1;
    }
}

bool lll::checkLuxury(int custID)
{
  return checkLuxury(head, custID);
}

bool lll::checkLuxury(circs* &head, int custID)
{
  if(head == NULL)
    {
      return false;
    }
  else
    {
      if(head->clist.checkLuxury(custID) == false)
	{
	  return false;
	}
      else
	{
	  return true;
	}
    }
}
  
