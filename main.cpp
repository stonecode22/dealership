#include"carHash.h"
#include"custList.h"

int main()
{
  corps* c1 = new corps("Glenn", "Woods", 121);
  vips* c2 = new vips("Adam", "Sander", 201);
  normal* c3 = new normal("Bob", "Ross", 1337);
  cll people;
  people.add(c1);
  people.add(c2);
  people.add(c3);
  people.rem(121);
  people.rem(201);
  /*  people.displayAll();
  cout << "\n\n";
  people.rem(121);
  cout << "gg\n";
  people.displayAll();
  */
  hashT table;
  char choice[30];
  int id = 0;
  bool repeat = true;
  
  cout << "\nHash (CARS)\n";
  while(repeat == true)
    {
      cout << "ADD, REMOVE, DISPLAY, or QUIT\nEntry: ";
      cin.get(choice, 30, '\n');
      cin.ignore();
      
      for(int i = 0; i < strlen(choice); i++)
	{
	  choice[i] = toupper(choice[i]);
	}
      
      if(strcmp(choice, "ADD") == 0)
	{
	  char carBrand[30];
	  char carName[30];
	  int carType = 0;
	  char recType[10];
	  float carRate = 0;
	  int carAge = 0;
	  int optLux;
	  bool lux;
	  bool error = false;
	  
	  do
	    {
	      cout << "Luxury or Standard?\n";
	      cout << "[1] Luxury\n[2] Standard\n";
	      cin >> optLux;
	      cin.ignore();
	      
	      if(optLux == 1 || optLux == 1)
		{
		  lux = true;
		  error = false;
		}
	      else if(optLux == 2 || optLux == 2)
		{
		  lux = false;
		  error = false;
		}
	      else
		{
		  cout << "Not a valid selection.\n";
		  error = true;
		}
	    }while(error == true);

	  cout << "Enter vehicle brand: ";
	  cin.get(carBrand, 30, '\n');
	  cin.ignore();
	  for(int i = 0; i < strlen(carBrand); i++)
	    {
	      carBrand[i] = toupper(carBrand[i]);
	    }
	  cout << "Enter vehicle name: ";
	  cin.get(carName, 30, '\n');
	  cin.ignore();
	  for(int i = 0; i < strlen(carName); i++)
	    {
	      carName[i] = toupper(carName[i]);
	    }
	  do
	    {
	      cout << "Vehicle type?\n";
	      cout << "[1] Sedan\n[2] SUV\n[3] Coupe\n[4] Truck\n[5] RV\n[6] Van\n";
	      cin >> carType;
	      cin.ignore();
	      
	      switch(carType)
		{
		case 1:
		  strcpy(recType, "SEDAN");
		  break;
		case 2:
		  strcpy(recType, "SUV");
		  break;
		case 3:
		  strcpy(recType, "COUPE");
		  break;
		case 4:
		  strcpy(recType, "TRUCK");
		  break;
		case 5:
		  strcpy(recType, "RV");
		  break;
		case 6:
		  strcpy(recType, "VAN");
		  break;
		default:
		  cout << "Invalid selection, try again\n";
		  error = true;
		  break;
		}
	    }while(error == true);
	      
	  cout << "Enter Rate: ";
	  cin >> carRate;
	  cin.ignore();
	  cout << "\nEnter Age: ";
	  cin >> carAge;
	  cin.ignore();
	  id++;
	  car newCar(id, carBrand, carName, recType, carRate, lux, carAge);
	  table.add(newCar);
	}
      else if(strcmp(choice, "REMOVE") == 0)
	{
	  int carID = 0;
	  cout << "Enter car ID #: ";
	  cin >> carID;
	  cin.ignore();
	  table.rem(carID);
	}
      else if(strcmp(choice, "DISPLAY") == 0)
	{
	  cout << endl;
	  table.display();
	  cout << endl;
	}
      else if(strcmp(choice, "QUIT") == 0)
	{
	  repeat = false;
	}
      else
	{
	  cout << "Not a command, try again.\n";
	}
    }	  
  return 0;
}
