//
//  main.cpp
//  BankSystem
//
//  Created by 오민호 on 2017. 3. 8..
//  Copyright © 2017년 오민호. All rights reserved.
// c style back system

#include <iostream>
#include <string.h>

#define NAMESIZE 20
#define MEMBERNUM 100

struct Member {
    int accountID;
    char name[NAMESIZE];
    int balance;
};

Member members[MEMBERNUM];
int memberCnt = 0;


int Menu() {
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

void openAccount() {
    char namebuf[MEMBERNUM] = "";
    std::cout << "[계좌개설]" << std::endl;
    std::cout << "계좌ID : ";
    std::cin >> members[memberCnt].accountID;
    std::cout << "이 름 : ";
    std::cin >> namebuf;
    strcpy(members[memberCnt].name, namebuf);
    std::cout << "입금액 : ";
    std::cin >> members[memberCnt].balance;
    memberCnt++;
}

void printAllAccount() {
    for(int i = 0 ; i < memberCnt ; ++i) {
        std::cout << "계좌ID: " << members[i].accountID << std::endl;
        std::cout << "이 름: " << members[i].name << std::endl;
        std::cout << "잔 액: " << members[i].balance << std::endl<<std::endl;
    }
}

void deposit() {
    int id = 0;
    int money = 0;
    std::cout << "[입   금]" << std::endl;
    std::cout << "계좌ID: ";
    std::cin >> id;
    std::cout << "입금액: ";
    std::cin >> money;
    
    for(int i = 0 ; i < memberCnt ; ++i) {
        if(members[i].accountID == id) members[i].balance += money;
    }
}

void withdraw() {
    int id = 0;
    int money = 0;
    std::cout << "[출   금]" << std::endl;
    std::cout << "계좌ID: ";
    std::cin >> id;
    std::cout << "출금액: ";
    std::cin >> money;
    
    for(int i = 0 ; i < memberCnt ; ++i) {
        if(members[i].accountID == id) members[i].balance -= money;
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    while(1) {
        int q = Menu();
        switch (q) {
            case 1:
                openAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                printAllAccount();
            default:
                break;
        }
        if(q == 5) break;
    }
    return 0;
}
