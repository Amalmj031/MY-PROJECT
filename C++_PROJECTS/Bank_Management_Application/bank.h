#include "Bank.h"
#include "Account.h"

using namespace std;

void bank::adminLogin()
{
    string username;
    string password;

    cout << "Enter Username : ";
    cin >> username;

    cout << "Enter Password : ";
    cin >> password;

    string file_username, file_password;

    ifstream fin("password.txt");
    if(!fin)
    {
        cout << "Unable to open file\n";
        return;
    }

    fin >> file_username;
    fin >> file_password;
    fin.close();

    if(file_username == username && file_password == password)
    {
        cout << "Login Successful\n" << endl;
        admin_menu();
    }
    else
    {
        cout << "Invalid Username or Password\n";
    }
}

void bank::admin_menu()
{
    int choice;

    do
    {
        cout << "\n";
        cout << "=========================================\n";
        cout << "           ADMIN MENU\n";
        cout << "=========================================\n";
        cout << " 1. Create Account\n";
        cout << " 2. Search Account\n";
        cout << " 3. Delete Account\n";
        cout << " 4. Display All Accounts\n";
        cout << " 5. Deposit Amount\n";
        cout << " 6. Withdraw Amount\n";
        cout << " 7. Transfer Money\n";
        cout << " 8. Update Account\n";
        cout << " 9. Save Data\n";
        cout << "10. Logout\n";
        cout << "=========================================\n";
        cout << "Enter Your Choice : ";

        cin >> choice;

        switch(choice)
        {
            case 1:
                createAccount();
                saveinto_file();
                break;

            case 2:
                searchAccount();
                break;

            case 3:
                deleteAccount();
                saveinto_file();
                break;

            case 4:
                displayAllAccounts();
                break;

            case 5:
                deposit();
                saveinto_file();
                break;

            case 6:
                withdraw();
                saveinto_file();
                break;

            case 7:
                transfer();
                saveinto_file();
                break;

            case 8:
                updateAccount();
                saveinto_file();
                break;

            case 9:
                saveinto_file();
                break;

            case 10:
                cout << "Logout Successful\n";
                break;

            default:
                cout << "Invalid Choice\n";
        }

    } while(choice != 10);
}

void bank::createAccount()
{
    Account a;
    a.createAccount();
    account.push_back(a);

    cout << "Account Created Successfully\n";
}

void bank::displayAllAccounts()
{
    if(account.empty())
    {
        cout << "\nNo Accounts Available.\n";
        return;
    }

    cout << "\n========== ACCOUNT DETAILS ==========\n";

    for(auto &x : account)
    {
        x.displayAccount();
    }
}

void bank::searchAccount()
{
    int no;

    cout << "Enter The Account Number\n";
    cin >> no;

    for(auto it = account.begin(); it != account.end(); ++it)
    {
        if(it->getacc_no() == no)
        {
            it->displayAccount();
            return;
        }
    }

    cout << "Account not found\n";
}

void bank::deleteAccount()
{
    int no;

    cout << "Enter The Account Number To Delete\n";
    cin >> no;

    for(auto it = account.begin(); it != account.end(); ++it)
    {
        if(it->getacc_no() == no)
        {
            account.erase(it);
            cout << "Account Deleted Successfully.\n";
            return;
        }
    }

    cout << "Account not found\n";
}

void bank::deposit()
{
    int no;
    double amount;

    cout << "Enter The Account Number To Deposit\n";
    cin >> no;

    cout << "Enter The Amount To Deposit\n";
    cin >> amount;

    if(amount <= 0)
    {
        cout << "Invalid Amount\n";
        return;
    }

    for(auto it = account.begin(); it != account.end(); ++it)
    {
        if(it->getacc_no() == no)
        {
            it->deposit_amount(amount);
            cout << "Amount Deposited Successfully\n";
            return;
        }
    }

    cout << "Account Not Found\n";
}

void bank::withdraw()
{
    int no;
    double amount;

    cout << "Enter The Account Number To Withdraw\n";
    cin >> no;

    for(auto it = account.begin(); it != account.end(); ++it)
    {
        if(it->getacc_no() == no)
        {
            cout << "Enter The Amount To Withdraw\n";
            cin >> amount;

            if(amount <= 0)
            {
                cout << "Invalid Amount\n";
                return;
            }

            it->withdraw_amount(amount);
            cout << "Amount Withdraw Successfully\n";
            return;
        }
    }

    cout << "Account Not Found\n";
}

void bank::updateAccount()
{
    int acc = 0;

    cout << "Enter the account number to modify\n";
    cin >> acc;

    for(auto it = account.begin(); it != account.end(); ++it)
    {
        if(it->getacc_no() == acc)
        {
            it->modify_account();
            saveinto_file();
            return;
        }
    }

    cout << "Account Not Found\n";
}

void bank::transfer()
{
    int acc1 = 0;
    int acc2 = 0;

    cout << "Enter Your Account No.\n";
    cin >> acc1;

    for(auto it = account.begin(); it != account.end(); ++it)
    {
        if(it->getacc_no() == acc1)
        {
            cout << "Enter The Account No. To Transfer\n";
            cin >> acc2;

            for(auto itt = account.begin(); itt != account.end(); ++itt)
            {
                if(itt->getacc_no() == acc2)
                {
                    int amount;

                    cout << "Enter The Amount To Transfer\n";
                    cin >> amount;

                    itt->deposit_amount(amount);
                    it->withdraw_amount(amount);

                    saveinto_file();
                    return;
                }
            }

            cout << "The Receiver Account Not Found\n";
            return;
        }
    }

    cout << "Account Not Found\n";
}

void bank::saveinto_file()
{
    ofstream fout("bank_data.txt");

    for(auto it = account.begin(); it != account.end(); ++it)
    {
        it->save_data(fout);
    }

    fout.close();

    cout << "Data Saved Successfully\n";
}

void bank::loadData()
{
    ifstream fin("bank_data.txt");

    if(!fin)
    {
        cout << "No previous data found.\n";
        return;
    }

    account.clear();

    while(fin.peek() != EOF)
    {
        Account a;
        a.load_data(fin);
        account.push_back(a);
    }

    fin.close();

    cout << account.size() << " Accounts Loaded Successfully.\n";
}

void bank::customerLogin()
{
    int acc;
    int pin;

    cout << "Enter Account Number : ";
    cin >> acc;

    cout << "Enter PIN : ";
    cin >> pin;

    for(auto it = account.begin(); it != account.end(); ++it)
    {
        if(it->getacc_no() == acc && it->get_pin() == pin)
        {
            cout << "Login Successful\n";
            customer_menu(it);
            return;
        }
    }

    cout << "Invalid Account Number or PIN\n";
}

void bank::customer_menu(vector<Account>::iterator it)
{
    int choice;

    do
    {
        cout << "\n========== CUSTOMER MENU ==========\n";
        cout << "1. Show Balance\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Transfer\n";
        cout << "5. Change PIN\n";
        cout << "6. Update Profile\n";
        cout << "7. Display Account\n";
        cout << "8. Logout\n";

        cout << "Enter Choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                it->show_balence();
                break;

            case 2:
                it->deposit();
                saveinto_file();
                break;

            case 3:
                it->withdraw();
                saveinto_file();
                break;

            case 4:
                transfer();
                saveinto_file();
                break;

            case 5:
                it->change_pin();
                saveinto_file();
                break;

            case 6:
                it->modify_account();
                saveinto_file();
                break;

            case 7:
                it->displayAccount();
                break;

            case 8:
                cout << "Logout Successful\n";
                break;

            default:
                cout << "Invalid Choice\n";
        }

    } while(choice != 8);
}
