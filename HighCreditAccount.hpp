//
//  HighCreditAccount.hpp
//  BankSystem
//
//  Created by 오민호 on 2017. 3. 14..
//  Copyright © 2017년 오민호. All rights reserved.
//

#ifndef HighCreditAccount_hpp
#define HighCreditAccount_hpp

#include "Account.hpp"

namespace CreditGrade {
    enum {
        A = 7,
        B = 4,
        C = 2
    };
}


class HighCreditAccount :public Account{
private:
    int rate;
public:
    HighCreditAccount(int id, const char* name, int balance, int rate, int grade);
    virtual ~HighCreditAccount();
    virtual void deposit(int money);
};

#endif /* HighCreditAccount_hpp */
