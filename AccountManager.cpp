//
//  AccountManager.cpp
//  BankSystem
//
//  Created by 오민호 on 2017. 3. 10..
//  Copyright © 2017년 오민호. All rights reserved.
//

#include "AccountManager.hpp"
#include "NormalAccount.hpp"
#include "HighCreditAccount.hpp"


AccountManager::AccountManager():count(0) {
}

AccountManager::AccountManager(const AccountManager& copy) {
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
    int c = 0;
    std::cout << "[계좌종류선택]" <<std::endl;
    std::cout << "1.보통예금계좌 2.신용신뢰계좌" << std::endl;
    std::cout << "선택: ";
    std::cin >> c;
    
    if(c == MENU_SELECT::NORMAL) openNormalAccount();
    else if(c == MENU_SELECT::CREDIT) openHighCreditAccount();
    else std::cout << "잘못된 입력입니다." << std::endl;
}

void AccountManager::openNormalAccount() {
    int id = 0;
    char name[NAMESIZE] = "";
    int depoMoney = 0;
    int rate = 0;
    std::cout << "[보통예금계좌 개설]" << std::endl;
    std::cout << "계좌ID : "; std::cin >> id;
    std::cout << "이 름 : ";  std::cin >> name;
    std::cout << "입금액 : ";  std::cin >> depoMoney;
    std::cout << "이자율 : ";  std::cin >> rate;
    accounts[count++] = new NormalAccount(id, name, depoMoney, rate);
}

void AccountManager::openHighCreditAccount() {
    int id = 0;
    char name[NAMESIZE] = "";
    int depoMoney = 0;
    int rate = 0;
    int grade = 0;
    std::cout << "[신용신뢰계좌 개설]" << std::endl;
    std::cout << "계좌ID : "; std::cin >> id;
    std::cout << "이 름 : ";  std::cin >> name;
    std::cout << "입금액 : ";  std::cin >> depoMoney;
    std::cout << "이자율 : ";  std::cin >> rate;
    std::cout << "신용등급(1toA, 2toB, 3toC) : "; std::cin >> grade;
    if(grade > 3 || grade < 0) {
        std::cout << "부적절한 신용등급입니다." << std::endl;
        return;
    }
    accounts[count++] = new HighCreditAccount(id, name, depoMoney, rate, grade);
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
    
    for(int i = 0 ; i < count ; ++i) {
        if(accounts[i]->getAccountID() == id) {
            accounts[i]->deposit(money);
            return;
        }
    }
    std::cout << "유효하지 않은 ID 입니다." << std::endl;
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
            if(!accounts[i]->withdraw(money)) {
                std::cout << "잔액이 부족합니다." << std::endl;
                return;
            }
            std::cout << "출금 완료" << std::endl;
            return;
        }
    }
    std::cout << "유효하지 않은 ID 입니다." << std::endl;
}
