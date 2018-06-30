#include"dealer.h"

dealer::dealer()
{

}

dealer::~dealer()
{

}

void dealer::addCar(car newCar)
{
  table.add(newCar);
}

void dealer::remCar(int id)
{
  table.rem(id);
}

void dealer::displayCars()
{
  table.display();
}

void dealer::addCust(customer* newCustomer)
{
  circList.add(newCustomer);
}

void dealer::remCust(int id)
{
  circList.rem(id);
}

void dealer::displayCustomers()
{
  circList.display();
}

void dealer::rent(int carID, int custID)
{
  int retID = table.rentCar(carID);
  if(retID == -1)
    {
      cout << "No car with ID " << carID << "." << endl;
      return;
    }
  else if(retID == 0)
    {
      cout << "Car is rented by somebody else. Choose another car.\n";
      return;
    }
  else if(retID == 1)
    {
      if(circList.rent(carID, custID) == 1)
	{
	  table.setCarStock(carID, false);
	  cout << "Transaction complete.\n";
	}
      else
	{
	  cout << "Transaction failed.\n";
	}
      return;
    }
  else if(retID == 2)
    {
      if(circList.checkLuxury(custID) == true)
	{
	  if(circList.rent(carID, custID) == 1)
	    {
	      table.setCarStock(carID, false);
	      cout << "Transaction complete.\n";
	    }
	  else
	    {
	      cout << "Transaction failed.\n";
	    }
	  return;
	}
      else
	{
	  cout << "Customer #" << custID << " is not a Corporate Customer nor a VIP who cannot buy luxury vehicles.\n";
	  return;
	}
    }
  
}
  
