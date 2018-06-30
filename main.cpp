#include"dealer.h"

void carCreation(dealer* dealership, int carID);
void custCreation(dealer* dealership, int custID);
car carGen(dealer* dealership, int id);
//customer custGen(int id);

const int RANDOMCAR = 10;

int main()
{
  cll list;
  dealer dealership;
  char choice[30];
  int carID = 0;
  int custID = 1;
  bool repeat = true;
  srand(time(NULL));

  vips* vip = new vips("Adam", "Barkley", 100);
  list.add(vip);
  list.displayAll();
  delete vip;
  list.displayAll();

  for(int i = 1; i < RANDOMCAR+1; i++)
    {
      carID = i;
      dealership.addCar(carGen(&dealership, i));
    }
  
  cout << "Car Dealership\n";
  while(repeat == true)
    {
      cout << "ADD, REMOVE, DISPLAY, RENT, or QUIT\nEntry: ";
      cin.get(choice, 30, '\n');
      cin.ignore();
      
      for(int i = 0; i < strlen(choice); i++)
	{
	  choice[i] = toupper(choice[i]);
	}
      
      if(strcmp(choice, "ADD") == 0)
	{
	  int choice = 0;
	  cout << "Add a...\n[1] Car\n[2] Customer\nEntry: ";
	  cin >> choice;
	  cin.ignore();
	  
	  if(choice == 1)
	    {
	      carCreation(&dealership, carID);
	      carID++;
	    }
	  else if(choice == 2)
	    {
	      custCreation(&dealership, custID);
	      custID++;
	    }
	  else
	    {
	      cout << "Not a valid selection.\n";
	    }
	}
      else if(strcmp(choice, "REMOVE") == 0)
	{
	  int choice = 0;
	  cout << "Remove a...\n[1] Car\n[2] Client\nEntry: ";
	  cin >> choice;
	  cin.ignore();
	  if(choice == 1)
	    {
	      int remID = 0;
	      cout << "Enter car ID #: ";
	      cin >> remID;
	      cin.ignore();
	      dealership.remCar(remID);
	    }
	  else if(choice == 2)
	    {
	      int remID = 0;
	      cout << "Enter customer ID #: ";
	      cin >> remID;
	      cin.ignore();
	      dealership.remCust(remID);
	    }
	  else
	    {
	      cout << "Not a valid selection.\n";
	    }
	}
      else if(strcmp(choice, "DISPLAY") == 0)
	{
	  int choice = 0;
	  cout << "Display...\n[1] Inventory\n[2] Client list\nEntry: ";
	  cin >> choice;
	  cin.ignore();
	  
	  if(choice == 1)
	    {
	      cout << endl;
	      dealership.displayCars();
	      cout << endl;
	    }
	  else if(choice == 2)
	    {
	      cout << endl;
	      dealership.displayCustomers();
	      cout << endl;
	    }
	  else
	    {
	      cout << "Not a valid selection.\n";
	    }
	}
      else if(strcmp(choice, "RENT") == 0)
	{
	  int carID = 0;
	  int custID = 0;

	  cout << "Rent a car!\nEnter customer ID: ";
	  cin >> custID;
	  cin.ignore();
	  cout <<"\nEnter car ID: ";
	  cin >> carID;
	  cin.ignore();
	  dealership.rent(carID, custID);
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

void carCreation(dealer* dealership, int carID)
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
      cout << "[1] Luxury\n[2] Standard\nEntry: ";
      cin >> optLux;
      cin.ignore();
      cout << endl;
      
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
      cout << "[1] Sedan\n[2] SUV\n[3] Coupe\n[4] Truck\n[5] RV\n[6] Van\nEntry: ";
      cin >> carType;
      cin.ignore();
      cout << endl;
   
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
  cout << endl;
  carID++;
  car newCar(carID, carBrand, carName, recType, carRate, lux, carAge);
  dealership->addCar(newCar);
}

void custCreation(dealer* dealership, int custID)
{
  char first[30];
  char last[30];
  int type = 0;
  bool error = false;

  cout << "Enter customer's first name: ";
  cin.get(first, 30, '\n');
  cin.ignore();
  cout << "\nEnter customer's last name: ";
  cin.get(last, 30, '\n');
  cin.ignore();
  for(int i = 0; i < strlen(first); i++)
    {
      first[i] = toupper(first[i]);
    }
  for(int i = 0; i < strlen(last); i++)
    {
      last[i] = toupper(last[i]);
    }
  
  do
    {
      cout << "Customer is a...\n[1] Regular\n[2] Corporate\n[3] VIP\nEntry: ";
      cin >> type;
      cin.ignore();

      switch(type)
	{
	case 1:
	  {
	  normal* newReg = new normal(first, last, custID);
	  dealership->addCust(newReg);
	  break;
	  }
	case 2:
	  {
	  corps* newCorps = new corps(first, last, custID);
	  dealership->addCust(newCorps);
	  break;
	  }
	case 3:
	  {
	  vips* newVIP = new vips(first, last, custID);
	  dealership->addCust(newVIP);
	  break;
	  }
	default:
	  {
	  error = true;
	  cout << "Not a customer type. Try again.\n";
	  break;
	  }
	}
      cout << endl;
    }while(error == true);
}

car carGen(dealer* dealership, int carID)
{
  int wordCount = 0;
  int wordCount2 = 0;
  ifstream fileIn;

  fileIn.open("brand.txt");
  char brandName[30];
  char carName[30];

  if(fileIn)
    {
      fileIn >> brandName;
      fileIn.ignore();
    }
  while(!fileIn.eof() && fileIn)
    {
      wordCount++;
      fileIn >> brandName;
      fileIn.ignore();
    }
  fileIn.clear();
  fileIn.seekg(0, ios::beg);

  char** brandNameHolder;
  brandNameHolder = new char*[wordCount];
  wordCount = 0;

  if(fileIn)
    {
      fileIn >> brandName;
      fileIn.ignore();
    }
  while(!fileIn.eof() && fileIn)
    {
      brandNameHolder[wordCount] = new char[strlen(brandName)+1];
      strcpy(brandNameHolder[wordCount], brandName);
      wordCount++;
      fileIn >> brandName;
      fileIn.ignore();
    }
  fileIn.close();
  fileIn.clear();

  fileIn.open("car.txt");
  if(fileIn)
    {
      fileIn >> carName;
      fileIn.ignore();
    }
  while(!fileIn.eof() && fileIn)
    {
      wordCount2++;
      fileIn >> carName;
      fileIn.ignore();
    }
  fileIn.clear();
  fileIn.seekg(0, ios::beg);

  char** carNameHolder;
  carNameHolder = new char*[wordCount2];
  wordCount2 = 0;

  if(fileIn)
    {
      fileIn >> carName;
      fileIn.ignore();
    }
  while(!fileIn.eof() && fileIn)
    {
      carNameHolder[wordCount2] = new char[strlen(carName)+1];
      strcpy(carNameHolder[wordCount2], carName);
      wordCount2++;
      fileIn >> carName;
      fileIn.ignore();
    }
  fileIn.close();
  fileIn.clear();

  int brandIndex = rand() % wordCount;
  int carIndex = rand() % wordCount2;
  int givenID = carID;
  float rate = rand() % 100 + 20;
  bool recLux;
  int lux = rand() % 2 + 1;
  int age = rand() % 10 + 0;
  int type = rand() / int(RAND_MAX / 5);
  char recType[10];

  if(lux == 2)
    {
      recLux = true;
    }
  else
    {
      recLux = false;
    }
      
  switch(type)
    {
    case 0:
      strcpy(recType, "SEDAN");
      break;
    case 1:
      strcpy(recType, "SUV");
      break;
    case 2:
      strcpy(recType, "COUPE");
      break;
    case 3:
      strcpy(recType, "TRUCK");
      break;
    case 4:
      strcpy(recType, "RV");
      break;
    case 5:
      strcpy(recType, "VAN");
      break;
    default:
      break;
    }
  
  car newCar(givenID, brandNameHolder[brandIndex], carNameHolder[carIndex], recType, rate, recLux, age);
  return newCar;
}
