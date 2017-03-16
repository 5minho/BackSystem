//
//  NormalAccount.hpp
//  BankSystem
//
//  Created by 오민호 on 2017. 3. 14..
//  Copyright © 2017년 오민호. All rights reserved.
//

#ifndef NormalAccount_hpp
#define NormalAccount_hpp

#include "Account.hpp"

class NormalAccount : public Account {
private:
    int rate;
public:
    NormalAccount(int id, const char* name, int balance, int rate);
    virtual ~NormalAccount();
    virtual void deposit(int money);
};

#endif /* NormalAccount_hpp */
