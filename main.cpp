#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

using namespace std;

class AddressBook
{
     string firstName, lastName;
     string contactNum;

     public:
     int sizeOfName;
     int sizeOfNum = sizeof(sizeOfNum); 


     void getNameAndNumber(string fName, string lName, string userNum)
     {
          firstName = fName;
          lastName = lName;
          contactNum = userNum;
     }
     void putNameAndNumber()
     {
          cout << "Your name is : " << firstName<< " " << lastName << ".\n";
          cout << "Your Contact number is " << contactNum << endl;
     }
};
int main()
{
     // system("cls");
     int decision = 0;
     int opt;
     AddressBook userOne;
     string firstName, lastName;
     string contactNumber;

     while (decision != 1)
     {
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
               cout << "Enter First Name." << endl;
               cin >> firstName;
               cout << "\nEnter Last Name." << endl;
               cin >> lastName;

               cout << "\nEnter contact Number." <<endl;
               cin >> contactNumber;
               
               userOne.getNameAndNumber(firstName, lastName, contactNumber);
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