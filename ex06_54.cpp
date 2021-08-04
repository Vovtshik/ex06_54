/*ex06_54.cpp*/

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <cstdlib>
using std::rand;
using std::srand;

#include <ctime>
using std::time;

int rollDice();
bool craps_game();

int main()
{
   int bankBalance = 1000;
   int bankBalance_max = 5000;
   int wager;
   //cout << "Enter your rate:\n";
   //cin >> wager;
   while(bankBalance > 0 && bankBalance <= bankBalance_max)
   { 
      cout << "Your balance: " << bankBalance << endl;
      cout << "Enter your rate:\n";
      cin >> wager;
      if(wager > bankBalance)
         continue;
      if(craps_game())
         bankBalance += wager;
      else
	 bankBalance -= wager;

      if(bankBalance <= 0)
      {
         cout << "You lost, lucky another time ...\n";
	 break;
      }
      else if(bankBalance >= bankBalance_max)
      {
         cout << "You won, congratulations!\n";
	 break;
      }
   }
   return 0;
}

bool craps_game()
{
   enum Status{CONTINUE, WON, LOST};

   int myPoint;
   Status gameStatus;

   srand(time(0));

   int sumOfDice = rollDice();

   switch(sumOfDice)
   {
      case 7:
      case 11:
         gameStatus = WON;
         break;
      case 2:
      case 3:
      case 12:
         gameStatus = LOST;
         break;
      default:
         gameStatus = CONTINUE;
         myPoint = sumOfDice;
         cout << "Point is "  << myPoint << endl;
         break;
   }

   while(gameStatus == CONTINUE)
   {
      sumOfDice = rollDice();

      if(sumOfDice == myPoint)
         gameStatus = WON;
      else
         if(sumOfDice == 7)
            gameStatus = LOST;
   }

   if(gameStatus == WON)
   {
      cout << "Player wins" << endl;
      return true;
   }
   else
   {
      cout << "Player loses" << endl;
      return false;
   }
}


int rollDice()
{
   int die1 = 1 + rand() % 6;
   int die2 = 1 + rand() % 6;

   int sum = die1 + die2;

   cout << "Player rolled " << die1 << " + " << die2
	<< " = " << sum << endl;
  
   return sum;
}

