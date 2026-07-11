#include "Account.h"
#include <bits/stdc++.h>

void Account::createAccount()
{
    cout << "\n========== CREATE ACCOUNT ==========\n";
    cout << "Enter Account Number                 : ";
    cin >> accountNo;

    cin.ignore();
    cout << "Enter Customer Name                  : ";
    getline(cin, name);

    cout << "Enter Phone Number                   : ";
    getline(cin, phone);

    cout << "Enter Email                          : ";
    getline(cin, email);

    cout << "Enter Address                        : ";
    getline(cin, address);

    cout << "Enter Account Type (Savings/Current) : ";
    getline(cin, accountType);

    cout << "Enter Initial Balance                : ";
    cin >> balence;

    cout << "Create 4-digit PIN                   : ";
    cin >> pin;

    cout << "\nAccount Created Successfully!\n";
    cout << endl;
}

void Account::deposit()
{
    cout << "Enter The Amount To Deposit" << endl;
    double amount = 0.0;
    cin >> amount;
    balence += amount;
    cout << endl;
}

void Account::withdraw()
{
    cout << "Enter The Amount To Withdraw" << endl;
    double amount = 0.0;
    cin >> amount;

    if(amount <= balence)
    {
        balence -= amount;
    }
    else
    {
        cout << "Insufficient Balance" << endl;
    }

    cout << endl;
}

void Account::change_pin()
{
    int oldPin;

    cout << "Enter Current PIN: ";
    cin >> oldPin;

    if(oldPin == pin)
    {
        cout << "Enter New PIN: ";
        cin >> pin;
    }
    else
    {
        cout << "Incorrect PIN" << endl;
    }

    cout << endl;
}

void Account::show_balence()
{
    cout << " Balence = " << balence << endl;
    cout << endl;
}

void Account::displayAccount()
{
    cout << "accountNo   : " << accountNo << endl;
    cout << "name        : " << name << endl;
    cout << "phone       : " << phone << endl;
    cout << "email       : " << email << endl;
    cout << "address     : " << address << endl;
    cout << "accountType : " << accountType << endl;
    cout << "balance     : " << balence << endl;
    cout << "pin         : " << pin << endl;
    cout << endl;
}

int Account::getacc_no() const
{
    return accountNo;
}

double Account::deposit_amount(double amount)
{
    return balence += amount;
}

double Account::withdraw_amount(double amount)
{
    if(balence >= amount)
    {
        balence -= amount;
        return balence;
    }
    else
    {
        cout << "insufficent balence\n" << endl;
        return 0;
    }
}

void Account::modify_account()
{
    int choice;

    do
    {
        cout << "Enter the Option\n" << endl;
        cout << "1. Update Name\n";
        cout << "2. Update Mobile No.\n";
        cout << "3. Update Email\n";
        cout << "4. Update Address\n";
        cout << "5. Update Account Type\n";
        cout << "6. Log Out\n";

        cin >> choice;
        cin.ignore();

        switch(choice)
        {
            case 1:
                cout << "Enter The Name\n";
                name = "";
                getline(cin, name);
                break;

            case 2:
                cout << "Enter The Mobile No:\n";
                phone = "";
                getline(cin, phone);
                break;

            case 3:
                cout << "Enter The Email\n";
                email = "";
                getline(cin, email);
                break;

            case 4:
                cout << "Enter The Address\n";
                address = "";
                getline(cin, address);
                break;

            case 5:
                cout << "Enter The Account Type\n";
                accountType = "";
                getline(cin, accountType);
                break;

            case 6:
                cout << "Update Menu Closed\n";
                break;

            default:
                cout << "Invalid Choice\n";
                break;
        }

    } while(choice != 6);
}

void Account::save_data(ofstream &fout)
{
    fout << accountNo << '\n';
    fout << name << '\n';
    fout << phone << '\n';
    fout << email << '\n';
    fout << address << '\n';
    fout << accountType << '\n';
    fout << balence << '\n';
    fout << pin << '\n';
}

void Account::load_data(ifstream &fin)
{
    fin >> accountNo;
    fin.ignore();

    getline(fin, name);
    getline(fin, phone);
    getline(fin, email);
    getline(fin, address);
    getline(fin, accountType);

    fin >> balence;
    fin >> pin;
    fin.ignore();
}

int Account::get_pin()
{
    return pin;
}
