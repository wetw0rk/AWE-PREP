/* Create a program that asks the user to enter an integer, waits for them to input an integer,
   then tells them what 2 times that number is. The program should produce the following output
   (assume I entered 4 as input):

   Enter an integer: 4
   Double that number is: 8 */

#include <iostream>

int main()
{
  int userNum = { 0x00 };

  std::cout << "Enter an integer: ";
  std::cin >> userNum;

  std::cout << "Double " << userNum << " is: " << (userNum * 2) << '\n';

  /* Modify the solution to the "best solution" program above so that it outputs like
     this (assuming user input 4):

     Enter an integer: 4
     Double 4 is: 8
     Triple 4 is: 12 */

  std::cout << "Triple " << userNum << " is: " << (userNum * 3) << '\n';

  return 0;
}
