#include"custList.h"

cll::cll()
{
  rear = NULL;
  last = NULL;
  count = 0;
}

cll::~cll()
{
  /*
  while(rear != NULL)
    {
      if(rear->next == rear)
	{
	  delete rear;
	  rear = NULL;
	}
      else
	{
	  nodeC* temp = rear->next;
	  delete rear;
	  rear = temp;
	}
    }
  */
}

int cll::add(customer* p)
{
  return add(rear, last, p);
}

int cll::add(nodeC* &r, nodeC* & l, customer* p)
{
  if(rear == NULL)
    {
      nodeC* newNode = new nodeC;
      if(p->getCarType() == 0)
	{
	  newNode->c = new normal(p->getFirst(), p->getLast(), p->getID());
	}
      else if(p->getCarType() == 1)
	{
	  newNode->c = new corps(p->getFirst(), p->getLast(), p->getID());
	}
      else
	{
	  newNode->c = new vips(p->getFirst(), p->getLast(), p->getID());
	}
      newNode->next = newNode;
      rear = newNode;
      last = newNode;
      count++;
      return 1;
    }
  else if(r->next == rear)
    {
      nodeC* newNode = new nodeC;
      if(p->getCarType() == 0)
	{
	  newNode->c = new normal(p->getFirst(), p->getLast(), p->getID());
	}
      else if(p->getCarType() == 1)
	{
	  newNode->c = new corps(p->getFirst(), p->getLast(), p->getID());
	}
      else
	{
	  newNode->c = new vips(p->getFirst(), p->getLast(), p->getID());
	}
      newNode->next = rear;
      r->next = newNode;
      last = newNode;
      count++;
      return 1;
    }
  else
    {
      return add(r->next, last, p);
    }
}

int cll::rem(int id)
{
  return rem(rear, last, id);
}

int cll::rem(nodeC* &r, nodeC* &l, int id)
{
  if(r == NULL)
    {
      return -1;
    }
  if(rear->next == rear)
    {
      if(id == rear->c->getID())
	{
	  delete rear;
	  rear = NULL;
	  last = NULL;
	  count--;
	  return 1;
	}
      else
	{
	  return 0;
	}
    }
  else
    {
      nodeC* temp = r;
      do
	{
	  if(id == (temp->next)->c->getID())
	    {
	      if(temp->next == last)
		{
		  temp->next = rear;
		  delete last;
		  last = temp;
		  count--;
		  return 1;
		}
	      else if(temp->next == rear)
		{
		  nodeC* save = rear->next;
		  temp->next = save;
		  delete rear;
		  rear = save;
		  count--;
		  return 1;
		}
	      else
		{
		  nodeC* save = temp->next;
		  temp->next = save->next;
		  delete save;
		  save = NULL;
		  count--;
		  return 1;
		}
	    }
	  else
	    {
	      temp = temp->next;
	    }
	}while(temp != rear);
    }
}

int cll::displayAll()
{
  return displayAll(rear);
}

int cll::displayAll(nodeC* r)
{
  if(r == NULL || r->next == rear)
    {
      if(r != NULL)
	{
	  r->c->display();
	  cout << endl;
	  return 1;
	}
      return 0;
    }
  else
    {
      r->c->display();
      cout << endl;
      displayAll(r->next);
    }
}

int cll::getCount()
{
  return count;
}

int cll::rent(int carID, int custID)
{
  return rent(rear, carID, custID);
}

int cll::rent(nodeC* &r, int carID, int custID)
{
  if(r == NULL || r->next == rear)
    {
      if(r != NULL)
	{
	  if(custID == r->c->getID())
	    {
	      r->c->rent(carID);
	      return 1;
	    }
	}
      return 0;
    }
  else
    {
      if(custID == r->c->getID())
	{
	  r->c->rent(carID);
	  return 1;
	}
      else
	{
	  return rent(r->next, carID, custID);
	}
    }
}
      
bool cll::checkLuxury(int custID)
{
  return checkLuxury(rear, custID);
}

bool cll::checkLuxury(nodeC* &r, int custID)
{
  if(r == NULL || r->next == rear)
    {
      if(r != NULL)
	{
	  if(custID == r->c->getID())
	    {
	      return r->c->getPermission();
	    }
	}
      return 0;
    }
  else
    {
      if(custID == r->c->getID())
	{
	  return r->c->getPermission();
	}
      else
	{
	  return checkLuxury(r->next, custID);
	}
    }
}
