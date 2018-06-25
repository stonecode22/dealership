#include"custList.h"

cll::cll()
{
  rear = NULL;
}

cll::~cll()
{
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
}

int cll::add(customer* p)
{
  return add(rear, p);
}

int cll::add(nodeC* &rear, customer* p)
{
  if(rear == NULL)
    {
      nodeC* newNode = new nodeC;
      newNode->c->setFirst(p->getFirst());
      newNode->c->setLast(p->getLast());
      newNode->c->setID(p->getID());
      newNode->next = newNode;
      rear = newNode;
      return 1;
    }
  else
    {
      nodeC* newNode = new nodeC;
      newNode->c->setFirst(p->getFirst());
      newNode->c->setLast(p->getLast());
      newNode->c->setID(p->getID());
      newNode->next = rear->next;
      return 1;
    }
}

int cll::rem(int id)
{
  return rem(rear, id);
}

int cll::rem(nodeC* &rear, int id)
{
  if(rear == NULL)
    {
      return -1;
    }
  else if(rear->next == rear)
    {
      if(id == rear->c->getID())
	{
	  delete rear;
	  rear = NULL;
	  return 1;
	}
      else
	{
	  return 0;
	}
    }
  else
    {
      nodeC* temp = rear;
      do
	{
	  if(id == temp->c->getID())
	    {
	      nodeC* save = temp->next;
	      delete temp;
	      temp = save;
	      return 1;
	    }
	  else
	    {
	      temp = temp->next;
	    }
	}while(temp != rear);
      if(temp == rear)
	{
	  return 0;
	}
    }
}

void cll::displayAll()
{
  return displayAll(rear);
}

void cll::displayAll(nodeC* r)
{
  if(r == NULL || r->next == r)
    {
      if(r != NULL)
	{
	  r->c->display();
	  cout << endl;
	}
      return;
    }
  else
    {
      r->c->display();
      displayAll(r->next);
      return;
    }
}
	  
      
