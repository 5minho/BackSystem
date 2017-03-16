//
//  HighCreditAccount.cpp
//  BankSystem
//
//  Created by 오민호 on 2017. 3. 14..
//  Copyright © 2017년 오민호. All rights reserved.
//

#include "HighCreditAccount.hpp"

HighCreditAccount::HighCreditAccount(int id, const char* name, int balance, int rate, int grade)
:Account(id, name, balance) {
    if(grade == 1) this->rate += CreditGrade::A;
    else if(grade == 2) this->rate += CreditGrade::B;
    else this->rate += CreditGrade::C;
}

HighCreditAccount::~HighCreditAccount() {}

void HighCreditAccount::deposit(int money) {
    int interset = rate / 100.0 * this->getBalance();
    Account::deposit(money + interset);
}
