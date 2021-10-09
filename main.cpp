//  CONTACT MANAGEMENT;
#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include <iomanip> 
#include<vector>
using namespace std;

class AddressBook
{
     string name[10][10];
     double contactNum;

     public:
     int sizeOfName = name[10][10].size();
     int sizeOfNum = sizeof(sizeOfNum);

//        USE CHAR 2D ARRAY FOR NAME INSTEAD OF STRING ARRAY 

     void getNameAndNumber(string userName,double userNum)
     {
          for (int i = 0; i < sizeOfName; i++)
          {
               for (int j = 0; j < sizeOfName; j++)
               {
                    name[i][j] = userName[j];
               }
               
          }
          
          
          // name = userName;
          contactNum = userNum;
     }
     void putNameAndNumber()
     {
          cout << "Your name is : " << name << endl;
          cout << "Your Contact number is " << contactNum << endl;
     }
};
int main()
//   PROBLEM IN STORING NAME INSIDE CLASS
{
     system("cls");
     int decision = 0;
     int opt;
     AddressBook userOne;
     string newName;
     double contactNumber;
     while (decision != 1)
     {
           cout << setw (25);
          cout << "\t\t\t\t\t\t****| CONTACT MANAGEMENT |****" << endl << endl;
          cout << "Choose an option.." << endl;
          cout << "1 : Add new contact." << endl; 
          cout << "2 : View all contacts." << endl;
          cout << "3 : Delete a contacts." << endl;
          cout << "4 : Search a contact by Name." << endl;
          cout << "5 : Search a contact by Phone Number." << endl;
          cout << "6 : End Program. " << endl;

          cout << endl << "Your option : ";
          cin >> opt;
          cout << endl;

          switch (opt)
          {

/*   Case 1 : for adding new contact to our phone book we have called a public function
*    which will store the name and number as private in class. */
          case 1:
               cout << "Enter your Name." << endl;
               getline (cin, newName);
               cin.ignore(256, '\n'); 

               cout << "Enter contact Number." <<endl;
               cin >> contactNumber;
               
               
               userOne.getNameAndNumber(newName, contactNumber);
               cout << endl << "Contact added successfully !!" << endl;
               break;
          
          case 2:
               userOne.putNameAndNumber();
               break;

          case 6:
               cout << "Program ended successfully!!" << endl;
               decision++;
               break;

/*   if the user enters any number except 1 to 6, the below statements will be printed.
*    getch will pause the screen and wait till user presses any key to restart the program. */
          default:

               cout << "You have not entered the correct option!!" << endl;
               cout << "Please enter a number between 1 to 6." << endl;
               cout << "Press any key to continue..." << endl;
               getch();
/*   if user enters a wrong value and if the value is not an integer the switch case will misbehave
*/
               system("cls");
               break;
          }
         
     }
     
}