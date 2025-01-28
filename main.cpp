#include <iostream>  //Standard input/output in C++ (e.g., cout)
#include <conio.h>   //Console-specific input/output (non-standard)
#include <stdio.h>   //Standard C input/output (e.g., printf)
#include <fstream>   //File handling in C++
#include <windows.h> //Windows API for advanced system operations

using namespace std;

class bank
{
private:
    int pin;
    string id, password, name, fname, address, phone;
    float balance;

public:
    void menu();
    void atm_management();
    void bank_management();
    void new_user();
    void already_user();
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
        cout << "\n";
        cout << "\n\t\t\t\tEnter Password : ";

        // Reading Password (length : 6) from user
        for (int i = 0; i < 6; i++)
        {
            ch = getch();
            password += ch;
            cout << '*';
        }
        cout << "\n";
        // Authentication
        if (email == "admin@gmail.com" && pin == "123456" && password == "654321")
        {
            cout << "\n\t\t\t\tLogin Successful!";
            bank_management();
        }
        else
        {
            cout << "\n\t\t\t\tInvalid Login Credentials! \t(Press Enter for Home)";
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
    cout << "\t\t\t10. Show All Records\n";
    cout << "\t\t\t11. Go Back\n";

    cout << "\t\t\t==========================================" << endl;
    cout << "\n\t\t\tEnter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        // New User
        new_user();
        break;
    case 2:
        // Existing User
        already_user();
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
void bank::new_user()
{
p:
    system("cls");

    fstream file; // file handling
    int tpin;
    string tname, tfname, tpassword, taddress, tphone, tid; // temp variables
    float tbalance;

    cout << "\n\n\t\t\t==========================================" << endl;
    cout << "\t\t\t Add New User";

    cout << "\n\t\t\tEnter ID: ";
    cin >> tid;
    cout << "\n\t\t\tEnter Name: ";
    cin >> tname;
    cout << "\n\t\t\tFather Name: ";
    cin >> tfname;
    cout << "\n\t\t\tAddress: ";
    cin >> taddress;
    cout << "\n\t\t\tPin Code (6 Digit): ";
    cin >> tpin;
    cout << "\n\t\t\tPassword (6 Digit): ";
    cin >> tpassword;
    cout << "\n\t\t\tPhone No.: ";
    cin >> tphone;
    cout << "\n\t\t\tBalance: ";
    cin >> tbalance;

    // Open the file in read mode to check if the user already exists
    file.open("bank.txt", ios::in);
    if (!file.is_open())
    {
        cout << "\n\t\t\tError: Unable to open the file for reading!";
        return;
    }

    string id, name, fname, address, phone, password;
    int pin;
    float balance;
    bool exists = false;

    // Check for existing user
    while (file >> id >> name >> fname >> address >> pin >> password >> phone >> balance)
    {
        if (tid == id)
        {
            cout << "\n\t\t\tUser already exists!";
            file.close();
            getch();
            goto p;
        }
    }
    file.close();

    // Open the file in append mode to add a new user
    file.open("bank.txt", ios::app);
    if (!file.is_open())
    {
        cout << "\n\t\t\tError: Unable to open the file for writing!";
        return;
    }

    file << tid << " " << tname << " " << tfname << " " << taddress << " " << tpin
         << " " << tpassword << " " << tphone << " " << tbalance << "\n";
    file.close();

    cout << "\n\t\t\tUser added successfully!";
    cout << "\n\n\t\t\t==========================================" << endl;
}

void bank::already_user()
{
    system("cls");
    fstream file;
    string fid;
    bool found = false;

    cout << "\n\t\t\t\tAlready User Account" << endl;
    file.open("bank.txt", ios::in);
    if (!file.is_open())
    {
        cout << "\n\t\t\t\tError: Unable to open the file!";
        return;
    }

    cout << "\n\t\t\t\tEnter User ID: ";
    cin >> fid;

    string id, name, fname, address, phone, password;
    int pin;
    float balance;

    while (file >> id >> name >> fname >> address >> pin >> password >> phone >> balance)
    {
        if (fid == id)
        {
            system("cls");
            cout << "\n\t\t\t\tUser Found!";
            cout << "\n\n\t\t\t****************************************";
            cout << "\n\n\t\t\t\tUser ID: " << id;
            cout << "\n\t\t\t\tName: " << name;
            cout << "\n\t\t\t\tFather's Name: " << fname;
            cout << "\n\t\t\t\tAddress: " << address;
            cout << "\n\t\t\t\tPin Code: " << pin;
            cout << "\n\t\t\t\tPhone No.: " << phone;
            cout << "\n\t\t\t\tBalance: " << balance;
            cout << "\n\n\t\t\t****************************************";
            cout << "\nt\t\t\t\t(Press Enter to GoBack)";
            found = true;
            break;
        }
    }

    file.close();

    if (!found)
    {
        cout << "\n\t\t\t\tUser Not Found!";
    }

    getch();
}

int main()
{
    bank obj;
    obj.menu();
    return 0;
}