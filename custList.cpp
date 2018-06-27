#include"custList.h"

cll::cll()
{
  rear = NULL;
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
  return add(rear, p);
}

int cll::add(nodeC* &rear, customer* p)
{
  if(rear == NULL)
    {
      nodeC* newNode = new nodeC;
      newNode->c = p;
      newNode->next = newNode;
      rear = newNode;
      count++;
      return 1;
    }
  else
    {
      nodeC* newNode = new nodeC;
      newNode->c = p;
      newNode->next = rear->next;
      rear->next = newNode;
      count++;
      return 1;
    }
}

int cll::rem(int id)
{
  return rem(rear, id);
}

int cll::rem(nodeC* &r, int id)
{
  if(r == NULL || r->next == rear)
    {
      cout << "e1\n";
      if(r != NULL)
	{
	  if(id == r->c->getID())
	    {
	      nodeC* temp = rear->next;
	      if(r == rear)
		{
		  delete r;
		  r = NULL;
		  count--;
		  return 1;
		}
	      else
		{
		  delete r;
		  r = temp;
		  count--;
		  return 1;
		}
	    }
	  return -1;
	}
    }
  else
    {
      cout << "e2\n";
      if(id == r->c->getID())
	{
	  cout << "match\n";
	  nodeC* save = r->next;
	  if(r == rear)
	    {
	      cout << "rear\n";
	      delete rear;
	      cout <<"seg1\n";
	      rear = save;
	      cout << "seg2\n";
	      count--;
	      return 1;
	    }
	  else
	    {
	      cout << "r\n";
	      delete r;
	      r = NULL;
	      r = save;
	      count--;
	      return 1;
	    }
	}
      else
	{
	  cout << "trav\n";
	  rem(r->next, id);
	}
    }
}

void cll::displayAll()
{
  return displayAll(rear);
}

void cll::displayAll(nodeC* r)
{
  cout << "er3\n";
  if(r == NULL || r->next == rear)
    {
      if(r != NULL)
	{
	  r->c->display();
	  cout << endl;
	}
    }
  else
    {
      cout << "er4\n"; //ERROR, on 2 nodes, the 2nd one goes here (wrong!)
      if(r == rear)
	{
	  cout << "head\n";
	}
      r->c->display();
      cout << endl;
      cout << "it's over\n";
      displayAll(r->next);
    }
}
	  
      
