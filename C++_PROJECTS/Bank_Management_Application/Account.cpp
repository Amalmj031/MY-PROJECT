#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <fstream>
#include <bits/stdc++.h>

using namespace std;

class Account
{
private:
    int accountNo{};
    string name{};
    string phone{};
    string email{};
    string address{};
    string accountType{};
    double balence{};
    int pin{};

public:
    Account() = default;

    void createAccount();

    int getacc_no() const;
    int get_pin() const;

    double deposit_amount(double amount);
    double withdraw_amount(double amount);

    void deposit();
    void withdraw();
    void change_pin();
    void show_balence();
    void displayAccount();
    void modify_account();

    void save_data(ofstream &fout);
    void load_data(ifstream &fin);
};

#endif
