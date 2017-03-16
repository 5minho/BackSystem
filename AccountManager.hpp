//
//  AccountManager.hpp
//  BankSystem
//
//  Created by 오민호 on 2017. 3. 10..
//  Copyright © 2017년 오민호. All rights reserved.
//

#ifndef AccountManager_hpp
#define AccountManager_hpp

#include "Account.hpp"

#define ACCOUNT_MAX 100

namespace MENU_SELECT {
    enum {
        OPEN = 1,
        DEPO,
        WITH,
        PRINT,
        QUIT
    };
    
    enum {
        NORMAL = 1,
        CREDIT = 2
    };
}


class AccountManager {

private:
    Account* accounts[ACCOUNT_MAX];
    int count;

public:
    AccountManager();
    AccountManager(const AccountManager& copy);
    ~AccountManager();
    int Menu() const;
    void openAccount();
    void openNormalAccount();
    void openHighCreditAccount();
    void printAllAccount() const;
    void deposit();
    void withdraw();
};

#endif /* AccountManager_hpp */
