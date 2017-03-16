//
//  NormalAccount.cpp
//  BankSystem
//
//  Created by 오민호 on 2017. 3. 14..
//  Copyright © 2017년 오민호. All rights reserved.
//

#include "NormalAccount.hpp"

NormalAccount::NormalAccount(int id, const char* name, int balance, int rate)
:Account(id, name, balance), rate(rate) {}

NormalAccount::~NormalAccount() {}

void NormalAccount::deposit(int money) {
    int interset = rate / 100.0 * this->getBalance();
    Account::deposit(money + interset);
}
