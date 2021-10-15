#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
#include<filesystem>

#define MAXSIZE 10

int inputCount = 0;
using namespace std;

class AddressBook
{
private:
     static string firstName[MAXSIZE], lastName[MAXSIZE];     
     static string contactNum[MAXSIZE];

public:
     void getNameAndNumber(string fName, string lName, string userNum);
     void putNameAndNumber();
     void searchNumber(int s);
     void deleteContact(string dName, string dSurname);
     void makeFile();
     friend ofstream & operator<<(ofstream &printFile, AddressBook &refClass);
};

string AddressBook::firstName[]={""};
string AddressBook::lastName[]={""};
string AddressBook::contactNum[]={""};

int main()
{
     int decision = 0;
     int opt;
     AddressBook user;

     while (decision != 1)
     {
          system("cls");
          cout << "\t\t\t\t****| CONTACT MANAGEMENT |****" << endl << endl;
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
                    /*        
                    P01 - TAKE SINGLE STRING AS INPUT
                    P02 - CONTACT AS INTEGER
                    P03 - SEPARATE FUNC FOR VALUES
                    P04 - USE BUILT-IN FUNC FOR SEARCHING (AT) (IN)
                    P05 - EXISTING NAME OF CONTACT
                    P06 - SEPARATE FUNC FOR DEFAULT LINES
                    P07 - STRING SENSITIVITY INDEPENDENT
                    P08 - << OVERLOADING FUNCTION DECLARATIONS
                    P09 - CHECK EXISTING FILE NAMES IN DIRECTORY
                    */
               {
                         string firstName, lastName;
                         string contactNumber;

                         cout << "Enter First Name." << endl;
                         cin >> firstName;
                         cout << "\nEnter Last Name." << endl;
                         cin >> lastName;

                         cout << "\nEnter contact Number." <<endl;
                         cin >> contactNumber;

                         user.getNameAndNumber(firstName, lastName, contactNumber);
                         cout << "Press any key to continue.." <<endl;
                         getch();
               }
               break;
          
          case 2:
          // VIEW ALL CONTACTS
               user.putNameAndNumber();
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
               user.searchNumber(search);
               cout << "Press any key to continue.." <<endl;
               getch();
               break;

          case 4:
          // MAKE A FILE OF SAVED CONTACTS
               user.makeFile();
               cout << "Press any key to continue..." << endl;
               getch();
               break;

          case 5:
          // DELETE A CONTACT.
               {
                    string delName, delSurname;

                    cout << "Enter first name of the person." << endl;
                    cin >> delName;
                    cout << "Enter last name of the person." << endl;
                    cin >> delSurname;
                    
                    user.deleteContact(delName, delSurname);
                    cout<< "Contact deleted Successfully !!" << endl;
                    cout << "Press any key to continue..." << endl;
                    getch();
               }
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
/*   if user enters a wrong value and if the value is not an integer the switch case will misbehave */
               system("cls");
               break;
          }         
     }
}

void AddressBook::getNameAndNumber(string fName, string lName, string userNum)
{    
     for(int i = 0; i < MAXSIZE; i++)
     {
          if (contactNum[i] == "EMPTY")
          {
               firstName[i] = fName;
               lastName[i] = lName;
               contactNum[i] = userNum;
               cout << endl << "Contact added successfully !!" << endl;
               break;
          }
          else if(inputCount == MAXSIZE)
          {
               cout << "STORAGE FULL !!" << endl;
               cout << "Delete some contacts to add more." << endl;   
               break;  
          }
          else{
               firstName[inputCount] = fName;
               lastName[inputCount] = lName;
               contactNum[inputCount] = userNum;
               inputCount++;
               cout << "cout after incr " << inputCount << endl;
               cout << endl << "Contact added successfully !!" << endl;
               break;
          }
     }    
}

void AddressBook::putNameAndNumber()
{
     for (int i = 0; i < MAXSIZE; i++)
     {
          cout << i+1 << " : Name = " << firstName[i] << " " << lastName[i] <<  ", Contact Number = " << contactNum[i] <<  "\n";
     }
}
    
void AddressBook::searchNumber(int s)
{
     if (s == 1)
     {
          string fname, lname;
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

void AddressBook::deleteContact(string dName, string dSurname)
{
     for (int i = 0; i < MAXSIZE; i++)
     {
          if (dName == firstName[i] && dSurname == lastName[i])
          {
               firstName[i] = "EMPTY";          
               lastName[i] = "";   
               contactNum[i] = "EMPTY";
          }
     }
}


void AddressBook::makeFile()
{
     int checkFileName = 0;
     ofstream printFile;

     string fileName;
     cout << "Enter file Name.\n";
     cin >> fileName;
     int isFileExists(string, int);

     while (checkFileName == 0)
     {
          if (isFileExists(fileName,checkFileName))
          {
               int fileOpt;
               cout << "\nThe name of the file already exists!!\n";
               cout << "1: Rewrite data.\n";
               cout << "2: Create a file with another name.\n";

               cout << endl << "Your option : ";
               cin >> fileOpt;
               if (fileOpt == 1)
               {
                    printFile.open(fileName, ios::trunc);
                    for (int i = 0; i < MAXSIZE; i++)
                    {
                         printFile << firstName[i] << " " << lastName[i] << "\t" << contactNum[i] << endl;
                    }
                    cout << "\nData has been re-written in " << fileName << ".\n";
                    checkFileName++;
               }
               else
               {
                    cout << "Enter new file name.\n";
                    cin >> fileName;
                    isFileExists(fileName,checkFileName);
                    printFile.open(fileName, ios::trunc);
                    for (int i = 0; i < MAXSIZE; i++)
                    {
                         printFile << firstName[i] << " " << lastName[i] << "\t" << contactNum[i] << endl;
                    }
                    cout <<"File Created !!\n"; 
                    checkFileName++;
               }
          }
          else
          {
               printFile.open(fileName, ios::trunc);
               AddressBook obj;

               for (int i = 0; i < MAXSIZE; i++)
               {
                    if (contactNum[i]=="EMPTY")
                         continue;
                    printFile << firstName[i] << " " << lastName[i] << "\t" << contactNum[i] << endl;
               }
               cout <<"File Created !!\n";
               checkFileName++;
          }
     }    

     printFile.close();
}

int isFileExists(string name, int checkFileName)
{
     if (name == "TEXT.txt" || name == "hello.txt" || name == "hello1.txt" || name == "hello2.txt" )
     {    
          return 1; // return if true
     }
     else
     {
          checkFileName++;
          return 0; // return if false
     }
}

// ofstream & operator<<(ofstream &printFile, AddressBook &refClass)
// {
//      for (int i = 0; i < MAXSIZE; i++)
//      {
//           printFile << refClass.firstName[i] << " " << refClass.lastName[i] << "\t" << refClass.contactNum[i];
//      }
//      return printFile;
// }