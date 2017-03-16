//
//  Account.hpp
//  BankSystem
//
//  Created by 오민호 on 2017. 3. 10..
//  Copyright © 2017년 오민호. All rights reserved.
//

#ifndef Account_hpp
#define Account_hpp

#include <iostream>
#include <cstring>


#define NAMESIZE 20
#define MEMBERNUM 100

class Account {
private:
    int accountID;
    char* name;
    int balance;
public:
    Account();
    Account(int id, const char* name, int balance);
    Account(const Account& copy);
    virtual ~Account();
    int getAccountID() const;
    char* getName() const ;
    int getBalance() const;
    void printAccount() const;
    virtual void deposit(int money);
    bool withdraw(int money);
};




#endif /* Account_hpp */
