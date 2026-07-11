#include <iostream>
#include "Account.h"
#include "Bank.h"

using namespace std;

int main()
{
    bank b;

    // Load all saved accounts automatically
    b.loadData();

    int choice;

    do
    {
        cout << "\n";
        cout << "=========================================\n";
        cout << "      BANK MANAGEMENT SYSTEM\n";
        cout << "=========================================\n";
        cout << "1. Admin Login\n";
        cout << "2. Customer Login\n";
        cout << "3. Exit\n";
        cout << "=========================================\n";
        cout << "Enter Your Choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                b.adminLogin();
                break;

            case 2:
                b.customerLogin();
                break;

            case 3:
                cout << "\nThank You for Using Bank Management System.\n";
                break;

            default:
                cout << "\nInvalid Choice! Please Try Again.\n";
        }

    } while(choice != 3);

    return 0;
}
