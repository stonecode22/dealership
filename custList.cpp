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
	  node* temp = rear->next;
	  delete rear;
	  rear = temp;
	}
    }
}

int cll::add(customer* p)
{
  return add(rear, p);
}

int cll::add(node* &rear, customer* p)
{
  if(rear == NULL)
    {
      node* newNode = new node;
      newNode->c->setFirst(p.getFirst());
      newNode->c->setLast(p.getLast());
      newNode->c->setID(p.getID());
      newNode->next = newNode;
      rear = newNode;
      return 1;
    }
  else
    {
      node* newNode = new node;
      newNode->c->setFirst(p.getFirst());
      newNode->c->setLast(p.getLast());
      newNode->c->setID(p.getID());
      newNode->next = rear->next;
      return 1;
    }
}

int cll::rem(int id)
{
  return rem(rear, id);
}

int cll::rem(node* &rear, int id)
{
  if(rear == NULL)
    {
      return -1;
    }
  else if(rear->next == rear)
    {
      if(id == rear->c->getID)
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
      node* temp = rear;
      do
	{
	  if(id == temp->c->getID())
	    {
	      node* save = temp->next;
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

void cll::display()
{
  return display(rear);
}

void cll::display(node* r);
{
  if(r == NULL || r->next == rear)
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
      display(r->next);
      return;
    }
}
	  
      
