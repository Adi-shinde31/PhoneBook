#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

#define MAXSIZE 10

using namespace std;

class AddressBook
{
     string firstName[MAXSIZE], lastName[MAXSIZE];     
     string contactNum[MAXSIZE];

     public:
     void getNameAndNumber(string fName, string lName, string userNum);
     void putNameAndNumber();
     void searchNumber(int s);
     void deleteContact();
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
          system("cls");
          cout << "\t\t\t\t\t\t****| CONTACT MANAGEMENT |****" << endl << endl;
          cout << "Choose an option..\n" << endl;
          cout << "1 : Add new contact." << endl;  
          cout << "2 : View all contacts." << endl;
          cout << "3 : Search a contact." << endl;
          cout << "4 : Make a file of saved contacts." << endl;
          cout << "5 : Delete a contacts." << endl;
          cout << "6 : End Program. " << endl;

          cout << endl << "Your option : ";
          cin >> opt;
          cout << endl;

          switch (opt)
          {

/*   Case 1 : for adding new contact to our phone book we have called a public function
*    which will store the name and number as private in class. */
          case 1:
          // NEW CONTACT
          /*        P01 - TAKE SINGLE STRING AS INPUT
                    P02 - CONTACT AS INTEGER
                    P03 - SEPARATE FUNC FOR VALUES
                    P04 - FILE I/O FOR STORING DATA
                    P05 - INITIALIZING STATIC DATA MEMBER
                    P06 - CLEAR TERMINAL FREQUENTLY  
                    P07 - USE BUILT-IN FUNC FOR SEARCHING (AT) (IN)
                    */
               system("cls");
               cout << "Enter First Name." << endl;
               cin >> firstName;
               cout << "\nEnter Last Name." << endl;
               cin >> lastName;

               cout << "\nEnter contact Number." <<endl;
               cin >> contactNumber;
               
               userOne.getNameAndNumber(firstName, lastName, contactNumber);
               cout << endl << "Contact added successfully !!" << endl;
               cout << "Press any key to continue.." <<endl;
               getch();
               break;
          
          case 2:
          // VIEW ALL CONTACTS
               userOne.putNameAndNumber();
               cout << "Press any key to continue.." <<endl;
               getch();
               break;
 
          case 3:
          // SEARCH A CONTACT
               int search;
               cout << "How do you want to search your contact ?\n" << endl;
               cout << "1 : Search by Name." << endl; 
               cout << "2 : Search by Number." << endl;
               cout << endl << "Your option : ";
               
               cin >> search;
               userOne.searchNumber(search);
               cout << "Press any key to continue.." <<endl;
               getch();

               break;
          case 4:
          // MAKE A FILE OF SAVED CONTACTS

               break;
          case 5:
          // DELETE A CONTACT.
          //   transfer of control bypasses initialization of: -- variable 
               // string delContact;
               char delContact;
               cout << "Which Number or Name you want to delete ?" << endl;
               
               break;
          case 6:
          // EXIT PROGRAM
               cout << "Program ended successfully!!" << endl;
               decision++;
               break;

          default:
/*   if the user enters any NUMBER except 1 to 6, the statement below will be printed.
*    getch will pause the screen and wait untill user presses any key to restart the program. */
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


void AddressBook::getNameAndNumber(string fName, string lName, string userNum)
{
     for (int i = 0; i < 1; i++)
     {
          firstName[i] = fName;
          lastName[i] = lName;
          contactNum[i] = userNum;
     }
}

void AddressBook::putNameAndNumber()
{
     for (int i = 0; i < 1; i++)
     {
          cout << "Your name is : " << firstName[i]<< " " << lastName[i] << ".\n";
          cout << "Your Contact number is " << contactNum[i] << endl;
     }
}
    
void AddressBook::searchNumber(int s)
{
     if (s == 1)
     {
          string fname, lname;
          string num;
          cout << "Enter first name of the person." << endl;
          cin >> fname;
          cout << "Enter last name of the person." << endl;
          cin >> lname;
          
          for (int i = 0; i < MAXSIZE; i++)
          {
               if (fname == firstName[i] && lname == lastName[i])
               {
                    cout << endl << contactNum[i] << " is the Contact number of " << firstName[i] << " " << lastName[i] << ".\n";
               }
          }
     }
     else if(s == 2)
     {
          string num;
          cout << "Enter contact number of the person." << endl;
          cin >> num;
          for (int i = 0; i < MAXSIZE; i++)
          {
               if (num == contactNum[i])
               {
                    cout << endl << firstName[i] << " " << lastName[i] << " is the Name of the Contact number " << contactNum[i] <<".\n";
               }
          }
     }
     else
     {
          cout << "Enter a valid Number.\n";
          cout << "Press any key to continue..." << endl;
          getch();
          system("cls");
     }
}

void AddressBook::deleteContact()
{

}