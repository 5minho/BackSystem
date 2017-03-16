//
//  Account.cpp
//  BankSystem
//
//  Created by 오민호 on 2017. 3. 10..
//  Copyright © 2017년 오민호. All rights reserved.
//

#include "Account.hpp"

Account::Account() {}
Account::Account(int id, const char* name, int balance): accountID(id), balance(balance) {
    size_t len = strlen(name) + 1;
    this->name = new char[len];
    strcpy(this->name, name);
}

Account::Account(const Account& copy): accountID(copy.accountID), balance(copy.balance) {
    this->name = new char[strlen(copy.name) + 1];
    strcpy(this->name, copy.name);
}

Account::~Account() {
    std::cout<< "delete " << this->name << std::endl;
    delete this->name;
}

int Account::getAccountID() const{
    return accountID;
}

char* Account::getName() const{
    return name;
}

int Account::getBalance() const{
    return balance;
}

void Account::printAccount() const{
    std::cout << "계좌ID: " << accountID << std::endl;
    std::cout << "이 름: " << name << std::endl;
    std::cout << "잔 액: " << balance << std::endl<<std::endl;
}

void Account::deposit(int money) {
    this->balance += money;
}

bool Account::withdraw(int money) {
    if(money > this->balance) return false;
    this->balance -= money;
    return true;
}
