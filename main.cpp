//
//  main.cpp
//  BankSystem
//
//  Created by 오민호 on 2017. 3. 8..
//  Copyright © 2017년 오민호. All rights reserved.
// c style back system

#include "AccountManager.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    AccountManager manager;
    bool running = true;
    while(running) {
        int q = manager.Menu();
        switch (q) {
            case MENU_SELECT::OPEN:
                manager.openAccount();
                break;
            case MENU_SELECT::DEPO:
                manager.deposit();
                break;
            case MENU_SELECT::WITH:
                manager.withdraw();
                break;
            case MENU_SELECT::PRINT:
                manager.printAllAccount();
                break;
            case MENU_SELECT::QUIT:
                running = false;
            default:
                break;
        }
    }
    return 0;
}
