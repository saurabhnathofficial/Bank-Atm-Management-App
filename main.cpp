#include <iostream>  //Standard input/output in C++ (e.g., cout)
#include <conio.h>   //Console-specific input/output (non-standard)
#include <stdio.h>   //Standard C input/output (e.g., printf)
#include <fstream>   //File handling in C++
#include <windows.h> //Windows API for advanced system operations

using namespace std;

class bank
{
public:
    void menu();
    void atm_management();
    void bank_management();
};

void bank::menu()
{
p:
    system("CLS");
    int choice;
    char ch;
    string pin, password, email;
    cout << "\n\t\t\t\tBank & A Management System\n";
    cout << "\t\t\t==========================================" << endl;
    cout << "\t\t\t1. Bank Management\n";
    cout << "\t\t\t2. ATM Management\n";
    cout << "\t\t\t3. Exit\n";
    cout << "\t\t\t==========================================" << endl;
    cout << "\n\t\t\tEnter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        system("cls");
        // User Authentication
        cout << "\n\t\t\tLogin Account: \n";
        cout << "\n\t\t\t\tEnter your Email : ";
        cin >> email;
        cout << "\n\t\t\t\tEnter Pin Code : ";

        // Reading Pin code (length : 6) from user
        for (int i = 0; i < 6; i++)
        {
            ch = getch();
            pin += ch;
            cout << '*';
        }
        cout<<"\n";
        cout << "\n\t\t\t\tEnter Password : ";

        // Reading Password (length : 6) from user
        for (int i = 0; i < 6; i++)
        {
            ch = getch();
            password += ch;
            cout << '*';
        }
        cout<<"\n";
        // Authentication
        if (email == "admin@gmail.com" && pin == "123456" && password == "654321")
        {
            cout << "\n\t\t\t\tLogin Successful!";
            bank_management();
        }
        else
        {
            cout << "\n\t\t\t\tInvalid Login Credentials!";
        }
        break;

    case 2:
        atm_management();
        break;
    case 3:
        exit(0);
    default:
        cout << "\n\t\t\tInvalid choice. Please try again.\n";
    }
    getch();
    goto p;
}

void bank::atm_management()
{
// ATM Management
p:
    system("cls");
    int choice;
    cout << "\n\t\t\tATM Management\n";
    cout << "\t\t\t==========================================" << endl;
    cout << "\t\t\t1. User Login & Check Balance\n";
    cout << "\t\t\t2. Withdraw Money\n";
    cout << "\t\t\t3. Deposit Money\n";
    cout << "\t\t\t4. Go Back\n";
    cout << "\t\t\t==========================================" << endl;
    cout << "\n\t\t\tEnter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        // User Login & Check Balance
        break;
    case 2:
        // Withdraw Money
        break;
    case 3:
        // Deposit Money
        break;
    case 4:
        menu();
        break;
    default:
        cout << "\n\t\t\tInvalid choice. Please try again.\n";
    }
    getch();
    goto p;
}

void bank::bank_management()
{
// Bank Management
p:
    system("cls");
    int choice;
    cout << "\n\t\t\tBank Management\n";
    cout << "\t\t\t==========================================" << endl;
    cout << "\t\t\t1. New User\n";
    cout << "\t\t\t2. Existing User\n";
    cout << "\t\t\t3. Deposit Option\n";
    cout << "\t\t\t5. Withdraw Option\n";
    cout << "\t\t\t6. Transfer Option\n";
    cout << "\t\t\t7. Payment Option\n";
    cout << "\t\t\t7. Search User Record\n";
    cout << "\t\t\t8. Update User Record\n";
    cout << "\t\t\t9. Delete User\n";
    cout << "\t\t\t9. Show All Records\n";
    cout << "\t\t\t10. Go Back\n";

    cout << "\t\t\t==========================================" << endl;
    cout << "\n\t\t\tEnter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        // New User
        break;
    case 2:
        // Existing User
        break;
    case 3:
        // Deposit Option
        break;
    case 4:
        // Withdraw Option
        break;
    case 5:
        // Transfer Option
        break;
    case 6:
        // Payment Option
        break;
    case 7:
        // Search User Record
        break;
    case 8:
        // Update User Record
        break;
    case 9:
        // Delete User
        break;
    case 10:
        // Show All Records
        break;
    case 11:
        menu();
        break;
    default:
        cout << "\n\t\t\tInvalid choice. Please try again.\n";
    }
    getch();
    goto p;
}
int main()
{
    bank obj;
    obj.menu();
    return 0;
}