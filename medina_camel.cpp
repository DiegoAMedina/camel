//Name: Nicholas Rosas, Diego Medina
//Date: 11-10-15
//Description: Camel Game
//Our enhancement was to subtract the distance of the natives, from the user’s distance
//when he entered, “moderate speed” or “full speed.” Making the game more realistic
//as the natives distance from the user not only depends on their distance alone
//but the distance and speed of the user.

#include <iostream> //cin cout
#include <cctype> //toupper
#include <cstdlib> // random
#include <ctime> //random
using namespace std;

char menuSelection();
//Precondition:No precondition
//Postcondition:Displays the menu selection available for the user.

void drinkCanteen(int& thirst, int& drinks);
//Precondition:2 variables passed in must be of type int.
//Postcondition:If the variable drinks is equal to zero than it displays “no more drinks left”
// if the variable drinks has more than zero, then it subtracts one from it
// and makes the thirst variable equal to zero.

void moderateSpeed(int& thirst, int& camel, int& miles, int& natDist, bool deadWeight);
//Precondition:3 variables passed in must be ints and the final variable of type bool.
//Postcondition:Thirst and Camel variable receive an increase of one.
//NatDist variable receives a random number from 7 - 14 inclusive
//and is subtracted from their distance total.
//If the Deadweight variable is true then distance is divided by 2, and thirst increments by one.
//Displays the miles traveled.

void fullSpeed(int& thirst, int& camel, int& miles, int& natDist, bool deadWeight);
//Precondition:3 variables passed in must be ints and the final variable of type bool.
//Postcondition:Thirst increments by one. Camel receives a random integer from 1 - 3 inclusive.
//NatDist variable receives a random number from 7 - 14 inclusive
//and is subtracted from their distance total.
//If the Deadweight variable is true then distance is divided by 2, and thirst increments by one.
//Displays the miles traveled.

void stopNight(int& camel, int& natDist);
//Precondition:2 variables passed in must be of type int.
//Postcondition:Camel is set to zero. NatDist variable receives a random number from 7 - 14 inclusive.
//Display “the camel is happy”.

void statusCheck(int miles, int drinks, int nativeDist);
//Precondition:3 varianbles passed in must be of type int.
//Postcondition:Display the miles traveled, drinks in canteen left and the natives distance.

void checkForOasis(int& thirst, int& camel, int& can);
//Precondition:3 variables passed in must be of type int.
//Postcondition:Gives the user a 20% chance of finding an oasis
//Set by a random number generator from 1 - 20 inclusive
//if the random number lands on 7, then the user found the oasis.
//if found, display found the oasis, set thirst and camel equal to zero and set can to 5
//else do nothing.

//********************************************************************************************************
int main()
{
	srand( time( 0 ) );

	bool done = false;

	int milesTraveled = 0;
	int thirst = 0;
	int camelTired = 0;
	int nativesDistance = -20;
	int canteen = 3;
	bool camelDied = false;
	
	char choice;
	
	

	cout << "Welcome to Camel!" << endl
         << "You have stolen a camel to make your way across the great Mobi desert." << endl
         << "The natives want their camel back and are chasing you down!" << endl
         << "Survive your desert trek and out run the natives." << endl;

	while(!done)
{
	choice = menuSelection();
	
		switch( choice )
		{
			case 'A': drinkCanteen(thirst, canteen);
				break;
			case 'B': moderateSpeed(thirst,camelTired,milesTraveled,nativesDistance, camelDied);
				break;
			case 'C': fullSpeed(thirst,camelTired,milesTraveled,nativesDistance, camelDied);
				break;
			case 'D': stopNight(camelTired, nativesDistance);
				break;
			case 'E': statusCheck(milesTraveled, canteen, nativesDistance);
				break;
			case 'Q': done = true;
				break;
			default: cout << "Some error occurred\n";
				break;
		}

		checkForOasis(thirst, camelTired, canteen);

	
		if (thirst > 4 && thirst <= 6)
			cout << "You are thirsty." << endl;
			
		if(thirst > 6)
		{
			cout << "You died of thirst\n";
			done = true;
		}
		
		if(camelTired > 5 && camelTired <= 8)
			cout << "Your camel is getting tired\n";
			
		if(camelTired > 8)
		{
			cout << "Your camel died\n";
			camelDied = true;
		}
			
		if(nativesDistance >= 0)
		{
			cout << "The natives have caught up\n";
			done = true;
		}
		
		else if(nativesDistance >= -15)
			cout << "The natives are getting close!\n";
			
		if(milesTraveled >= 200)
		{
			cout << "You have outran the natives!\n";
			done = true;
		}
			




}




return 0;
}
//********************************************************************************************************
char menuSelection()
{
	char choice;
	cout << "\n\n"
	       << "A. Drink from your canteen." << endl
   	       << "B. Ahead moderate speed." << endl
   	       << "C. Ahead full speed." << endl
   	       << "D. Stop for the night." << endl
   	       << "E. Status check." << endl
   	       << "Q. Quit\n\n";

	cout << "Enter the letter of your choice: ";
	cin >> choice;
	choice = toupper(choice);

	while( (choice < 'A') || (choice > 'E') && (choice != 'Q') )
	{
		cout << "Error, enter either [A, B, C, D, E, or Q] : ";
		cin >> choice;
		choice = toupper(choice);
	}
	
	return choice;
}

void statusCheck(int miles, int drinks, int nativeDist)
{
	cout << "Miles traveled: " << miles << endl
	       << "Drinks in canteen: " << drinks << endl
	       << "The natives are " << nativeDist * -1 << " miles behind you.\n";
	return;
} // end statusCheck

void stopNight(int& camel, int& natDist)
{
	camel = 0;

	natDist = (rand() & 8) + 7;
	cout << "The camel is happy!!\n";
}

void fullSpeed(int& thirst, int& camel, int& miles, int& natDist, bool deadWeight)
{
	int distance = (rand() % 11) + 10;
	miles += distance;

thirst ++;

camel = (rand() % 3) + 1;

	if(deadWeight)
	{
		distance = distance / 2;
		thirst++;
	}

	natDist += (rand() & 8) + 7;
	natDist -= distance;

	cout << "Miles traveled: " << miles << endl;

 return;
}

void moderateSpeed(int& thirst, int& camel, int& miles, int& natDist, bool deadWeight)
{
	int distance;
	distance = (rand() % 8) + 5 ;
	miles += distance;

    	thirst ++;

    	camel++;

	if(deadWeight)
	{
		distance = distance / 2;
		thirst++;
	}

	natDist += (rand() & 8) + 7;
	natDist -= distance;

	cout << "Miles traveled: " << miles << endl;

 return;
}

void drinkCanteen(int& thirst, int& drinks)
{
	if( drinks == 0 )
	{
		cout << "There are no more drinks left." << endl;
		return;
	}

	drinks--;
	thirst = 0;

	return;
}

void checkForOasis(int& thirst, int& camel, int& can)
{
	const int found = 7;
	int chance = (rand() % 20) + 1;

	if(chance == found)
	{
		cout << "You found an oasis!!!\n";
		thirst = 0;
		camel = 0;
		can = 5;
	}
	return;
}




