#include<iostream> //Standard input/output in C++ (e.g., cout)
#include <conio.h> //Console-specific input/output (non-standard)
#include <stdio.h> //Standard C input/output (e.g., printf)
#include <fstream> //File handling in C++
#include <windows.h> //Windows API for advanced system operations

using namespace std;

class bank{
    public:
        void menu();
        void atm_management();
        void bank_management();
};

void bank::menu(){
    p:
    system("CLS");
    int choice;
    char ch;
    string pin, password, email;
    cout<<"\n\t\t\t\tBank Management System\n";
    cout<<"\t\t\t=========================================="<<endl;
    cout<<"\t\t\t1. ATM Management\n";
    cout<<"\t\t\t2. Bank Management\n";
    cout<<"\t\t\t3. Exit\n";
    cout<<"\t\t\t=========================================="<<endl;
    cout<<"\n\t\t\tEnter your choice: ";
    cin>>choice;
    
    switch(choice) {
        case 1: 
            // system("cls");
            //User Authentication
            cout<<"\n\n\t\tLogin Account: ";
            cout<<"\n\n\t\tEnter your Email : ";
            cin>>email;
            cout<<"\n\n\t\tEnter your Pin Code : ";

            //Reading Pic code (length : 6) from user
            for(int i=0; i<6; i++) {
                ch = getch();
                pin += ch;
                cout<<'*';
            }

            cout<<"\n\nt\tPassword : ";
            //Reading Password (length : 6) from user
            for (int i = 0; i < 6; i++)
            {
                ch = getch();
                password += ch;
                cout<<'*';
            }
            
            // Authentication
            if(email == "admin@gmail.com" && pin == "123456" && password == "admin123") {
                cout<<"\n\n\t\tLogin Successful!";
                bank_management();
            } else {
                cout<<"\n\n\t\tInvalid Login Credentials!";
            }
            break;

        case 2:
            atm_management();
            break;
        case 3: 
            exit(0);
        default:
            cout<<"\n\t\t\tInvalid choice. Please try again.\n";
    }
    getch();
    goto p;
}

void bank::atm_management(){
    //ATM Management code
}

void bank::bank_management(){
    //Bank Management code
}
int main()
{
    bank obj;
    obj.menu();
    return 0;
}