#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <vector>
#include "Account.h"

using namespace std;

class bank
{
private:
    vector<Account> account;

public:
    bank() = default;

    // Admin Functions
    void adminLogin();
    void admin_menu();

    void createAccount();
    void searchAccount();
    void deleteAccount();
    void displayAllAccounts();

    void deposit();
    void withdraw();
    void transfer();

    void updateAccount();

    void saveinto_file();
    void loadData();
    void clear_data();
    void clear_saved_data();

    // Customer Functions
    void customerLogin();
    void customer_menu(vector<Account>::iterator it);
};

#endif
