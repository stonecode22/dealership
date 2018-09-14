/*
*  Title: Car Rental Dealership Registry
*
*  User can add customers and cars into the registry and
*  can link customers to cars (rent) based on their customer
*  status (Regular, Corp. Customer, VIP)
*
*  @author Stone Yang
*  @version v2.0
*
*/
#include"dealer.h"

void carCreation(dealer* dealership, int carID); //function creates a car
void custCreation(dealer* dealership, int custID); //enters a customer
car carGen(dealer* dealership, int id);

const int RANDOMCAR = 10; //number of randomly generated cars at program launch

int main()
{
  dealer dealership;
  char choice[30];
  int carID = 0;
  int custID = 1;
  bool repeat = true;
  srand(time(NULL)); //for random generator

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

//entry of a car into the inventory
void carCreation(dealer* dealership, int carID)
{
  char carBrand[30]; //name of company
  char carName[30]; //name of car
  int carType = 0; //type of car
  char recType[10]; //store name based on carType "int" selection
  float carRate = 0; //rate of $ to rent
  int carAge = 0; //age of car
  int optLux; //luxury or not, based on this int, store in bool "lux"
  bool lux; //is car luxury?
  bool error = false; //becomes true when there's an error/wrong input
  
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
    }while(error == true); //if does not choose 1 or 2, repeat until valid
  
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
  car newCar(carID, carBrand, carName, recType, carRate, lux, carAge); //creates car object
  dealership->addCar(newCar); //calls the dealership class function "addCar" to, well, add the newly generated car
}

//entry of a person into the customer list
void custCreation(dealer* dealership, int custID)
{
  char first[30]; //first name
  char last[30]; //last name
  int type = 0; //Normal or upper status
  bool error = false; //if error, will become true

  cout << "Enter customer's first name: ";
  cin.get(first, 30, '\n');
  cin.ignore();
  cout << "\nEnter customer's last name: ";
  cin.get(last, 30, '\n');
  cin.ignore();
  //capitalize all to ignore case sensitivity
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

      //after inputting type
      switch(type)
	{
	case 1: //create a normal customer
	  {
	  normal* newReg = new normal(first, last, custID);
	  dealership->addCust(newReg);
	  break;
	  }
	case 2: //create a corp. customer
	  {
	  corps* newCorps = new corps(first, last, custID);
	  dealership->addCust(newCorps);
	  break;
	  }
	case 3: //create a VIP customer
	  {
	  vips* newVIP = new vips(first, last, custID);
	  dealership->addCust(newVIP);
	  break;
	  }
	default: //else print error and repeat
	  {
	  error = true;
	  cout << "Not a customer type. Try again.\n";
	  break;
	  }
	}
      cout << endl;
    }while(error == true);
}

//random car generator, for testing (using file inputs)
car carGen(dealer* dealership, int carID)
{
  int wordCount = 0; //first wordCount to read the brand name file
  int wordCount2 = 0; //read the car name file
  ifstream fileIn; //file input

  fileIn.open("brand.txt"); //open car brand file
  char brandName[30]; //will store brand name
  char carName[30]; //will store car name

  //when file is open and exists, begin inputting 
  if(fileIn)
    {
      fileIn >> brandName;
      fileIn.ignore();
    }
  while(!fileIn.eof() && fileIn) //loop until end of file
    {
      wordCount++;
      fileIn >> brandName;
      fileIn.ignore();
    }
  fileIn.clear();
  fileIn.seekg(0, ios::beg); //reset from beginning

  //wordCount acts as a check first for the number of words, then works in the 2nd part, below here
  char** brandNameHolder; //holds all the brand names in a 2d array
  brandNameHolder = new char*[wordCount]; //object is created for this
  wordCount = 0; //reset wordCount back to 0

  //repeat process, but now store the data
  if(fileIn)
    {
      fileIn >> brandName;
      fileIn.ignore();
    }
  while(!fileIn.eof() && fileIn)
    {
      brandNameHolder[wordCount] = new char[strlen(brandName)+1];
      strcpy(brandNameHolder[wordCount], brandName); //String copy into 2d array
      wordCount++;
      fileIn >> brandName;
      fileIn.ignore();
    }
  fileIn.close();
  fileIn.clear();

  //repeat process for the car file
  
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

  //parameters needed to create a car object, using random generators
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
  
  car newCar(givenID, brandNameHolder[brandIndex], carNameHolder[carIndex], recType, rate, recLux, age); //create the new car
  return newCar; //return the car, going straight into an add function for the dealership
}
