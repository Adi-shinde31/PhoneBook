#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <filesystem>
#include <direct.h>

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
     friend istream & operator>>(istream &in, AddressBook &c1);
     friend ostream & operator<<(ostream &out, AddressBook &c1);
};

string AddressBook::firstName[] = {""};
string AddressBook::lastName[] = {""};
string AddressBook::contactNum[] = {""};

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
          case 1:
               {
                    string firstName, lastName;
                    string contactNumber;

                    cout << "Enter First Name." << endl;
                    cin >> firstName;
                    cout << "\nEnter Last Name." << endl;
                    cin >> lastName;

                    cout << "\nEnter contact Number." << endl;
                    cin >> contactNumber;

                    user.getNameAndNumber(firstName, lastName, contactNumber);
                    cout << "Press any key to continue.." << endl;
                    getch();
                    break;
               }

          case 2:
               user.putNameAndNumber();
               cout << "Press any key to continue.." << endl;
               getch();
               break;

          case 3:
               int search;
               cout << "How do you want to search your contact ?" << endl << endl;
               cout << "1 : Search by Name." << endl;
               cout << "2 : Search by Number." << endl;
               cout << endl << "Your option : ";

               cin >> search;
               user.searchNumber(search);
               cout << "Press any key to continue.." << endl;
               getch();
               break;

          case 4:
               user.makeFile();
               cout << "Press any key to continue..." << endl;
               getch();
               break;

          case 5:
               {
                    string delName, delSurname;

                    cout << "Enter first name of the person." << endl;
                    cin >> delName;
                    cout << "Enter last name of the person." << endl;
                    cin >> delSurname;

                    user.deleteContact(delName, delSurname);
                    cout << "\nContact deleted Successfully !!" << endl;
                    cout << "Press any key to continue..." << endl;
                    getch();
               }
               break;

          case 6:
               cout << "Program ended successfully!!" << endl;
               decision++;
               break;

          default:
               cout << "You have not entered the correct option!!" << endl;
               cout << "Please enter a number between 1 to 6." << endl;
               cout << "Press any key to continue..." << endl;
               getch();
               break;
          }
     }
}

void AddressBook::getNameAndNumber(string fName, string lName, string userNum)
{
     for (int i = 0; i < MAXSIZE; i++)
     {
          if (contactNum[i] == "EMPTY")
          {
               firstName[i] = fName;
               lastName[i] = lName;
               contactNum[i] = userNum;
               cout << endl << "Contact added successfully !!" << endl;
               return ;
               break;
          }
     }
     if (inputCount == MAXSIZE)
     {
          cout << "STORAGE FULL !!" << endl;
          cout << "Delete some contacts to add more." << endl;
          // break;
     }
     else
     {
          for (int i = 0; i < MAXSIZE; i++)    
          {
               if (contactNum[i] != "EMPTY")
               {
                    firstName[inputCount] = fName;
                    lastName[inputCount] = lName;
                    contactNum[inputCount] = userNum;
                    break;
               }
          }
          cout << endl << "Contact added successfully !!" << endl;
          inputCount++;
     }
}

void AddressBook::putNameAndNumber()
{
     for (int i = 0; i < MAXSIZE; i++)
     {
          cout << i + 1 << " : Name = " << firstName[i] << " " << lastName[i] << ", Contact Number = " << contactNum[i] << "\n";
     }
}

void AddressBook::searchNumber(int s)
{
     if (s == 1)
     {
          string fname, lname;
          cout << "\nEnter first name of the person." << endl;
          cin >> fname;
          cout << "Enter last name of the person." << endl;
          cin >> lname;

          for (int i = 0; i < MAXSIZE; i++)
          {
               if (fname == firstName[i] && lname == lastName[i])
               {
                    cout << endl << contactNum[i] << " is the Contact number of " << firstName[i] << " " << lastName[i] << ".\n";
                    break;
               }
          }
     }
     else if (s == 2)
     {
          string num;
          cout << "\nEnter contact number of the person." << endl;
          cin >> num;

          for (int i = 0; i < MAXSIZE; i++)
          {
               if (num == contactNum[i])
               {
                    cout << endl << firstName[i] << " " << lastName[i] << " is the Name of the Contact number " << contactNum[i] << ".\n";
                    break;
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
               break;
          }
     }
}

void AddressBook::makeFile()
{
     int checkFileName = 0;
     string fileName;
     string path = "c:/CodeHere/";
     int isFileExists(string, int);
     AddressBook userCopy;

     ofstream printFile(path);
     ofstream savedFileNames("data.txt", ios::app);

     cout << "Enter file Name.\n";
     cin >> fileName;

     while (checkFileName == 0)
     {
          if (isFileExists(fileName, checkFileName))
          {
               int fileOpt;
               cout << "\nThe name of the file already exists!!\n";
               cout << "1: Rewrite data.\n";
               cout << "2: Create a file with another name.\n";

               cout << endl << "Your option : ";
               cin >> fileOpt;

               if (fileOpt == 1)
               {
                    path.append(fileName);
                    printFile.open(path, ios::trunc);
                    printFile << userCopy;

                    cout << "\nData has been re-written in " << path << ".\n";
                    checkFileName++;
               }
               else
               {
                    cout << "Enter new file name.\n";
                    cin >> fileName;

                    if (!(isFileExists(fileName, checkFileName)))
                    {
                         _mkdir("c:/CodeHere");
                         path.append(fileName);
                         savedFileNames << fileName << endl;
                         printFile.open(path, ios::trunc);
                         printFile << userCopy;
                         cout << "\nFile has been created at "<< path << ".\n";
                         checkFileName++;
                    }
               }
          }
          else
          {
               _mkdir("c:/CodeHere");
               path.append(fileName);
               savedFileNames << fileName << endl;
               printFile.open(path, ios::trunc);
               printFile << userCopy;
               cout << "\nFile has been created at "<< path << ".\n";
               checkFileName++;
          }
     }

     printFile.close();
     savedFileNames.close();
}

int isFileExists(string name, int checkFileName)
{
     ifstream checkFile("data.txt");
     string txtfile;
     int i = 0;
     int count = 0;
     while (i != MAXSIZE)
     {
          checkFile >> txtfile;

          if (name == txtfile)
          {
               return 1;
               count++;
               break;
          }
          i++;
     }
     if (count == 1)
     {
          checkFileName++;
          return 0;
     }

     checkFile.close();
     return 0;
}

ostream & operator<<(ostream &out, AddressBook &c1)
{
     for (int i = 0; i < MAXSIZE; i++)
     {
          if (c1.contactNum[i] == "EMPTY")
               continue;
          out << c1.firstName[i] << " " << c1.lastName[i] << "\t" << c1.contactNum[i] << endl;
     }
     return out;
}