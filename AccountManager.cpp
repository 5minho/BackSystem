//
//  AccountManager.cpp
//  BankSystem
//
//  Created by 오민호 on 2017. 3. 10..
//  Copyright © 2017년 오민호. All rights reserved.
//

#include "AccountManager.hpp"


AccountManager::AccountManager():count(0) {
}

AccountManager::~AccountManager() {
    for(int i = 0 ; i < this->count ; ++i) {
        delete accounts[i];
    }
}

int AccountManager::Menu() const {
    int n = 0;
    std::cout << "-----Menu-----" << std::endl;
    std::cout << "1. 계좌개설" << std::endl;
    std::cout << "2. 입 금" << std::endl;
    std::cout << "3. 출 금" << std::endl;
    std::cout << "4. 계좌정보 전체 출력" << std::endl;
    std::cout << "5. 프로그램 종료" << std::endl;
    std::cout << "선택 : ";
    std::cin >> n;
    std::cout << std::endl;
    return n;
}

void AccountManager::openAccount() {
    int id = 0;
    char name[NAMESIZE] = "";
    int depoMoney = 0;
    std::cout << "[계좌개설]" << std::endl;
    std::cout << "계좌ID : ";
    std::cin >> id;
    std::cout << "이 름 : ";
    std::cin >> name;
    //getchar();
    std::cout << "입금액 : ";
    std::cin >> depoMoney;
    accounts[count++] = new Account(id, name, depoMoney);
}

void AccountManager::printAllAccount() const {
    for(int i = 0 ; i < count ; ++i)
        accounts[i]->printAccount();
}


void AccountManager::deposit() {
    int id = 0;
    int money = 0;
    std::cout << "[입   금]" << std::endl;
    std::cout << "계좌ID: ";
    std::cin >> id;
    std::cout << "입금액: ";
    std::cin >> money;
    
    for(int i = 0 ; i < count ; ++i)
        if(accounts[i]->getAccountID() == id) {
            accounts[i]->deposit(money);
            break;
        }
    
}

void AccountManager::withdraw() {
    int id = 0;
    int money = 0;
    std::cout << "[출   금]" << std::endl;
    std::cout << "계좌ID: ";
    std::cin >> id;
    std::cout << "출금액: ";
    std::cin >> money;
    
    for(int i = 0 ; i < count ; ++i) {
        if(accounts[i]->getAccountID() == id) {
            if(!accounts[i]->withdraw(money))
                std::cout << "잔액이 부족합니다." << std::endl;
            break;
        }
    }
}
