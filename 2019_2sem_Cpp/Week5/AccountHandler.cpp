#include "AccountHandler.h"
#include "BankingCommonDecl.h"
#include "HighCreditAccount.h"
#include <iostream>

AccountHandler::AccountHandler():accNum(0){}
void AccountHandler::ShowMenu() const{
    std::cout << "1. 계좌개설" << std::endl;
    std::cout << "2. 입금" << std::endl;
    std::cout << "3. 출금" << std::endl;
    std::cout << "4. 계좌정보" << std::endl;
    std::cout << "5. 종료" << std::endl;
}
void AccountHandler::MakeAccount(){
    int sel=0;
    std::cout << "1. Make Normal Account" << std::endl;
    std::cout << "2. Make Credit Account" << std::endl;
    std::cin >> sel;
    switch(sel){
        case NORMAL:
            MakeNormalAccount();
            break;
        case CREDIT:
            MakeCreditAccount();
    }
}
void AccountHandler::DepositMoney(){
    int ID;
    int money;
    std::cout << "ID와 입금할 금액 입력 : ";
    std::cin >> ID >> money;
    for(int i=0;i<accNum;i++){
        if(accArr[i]->getAccID() == ID){
            accArr[i]->Deposit(money);
            std::cout << "입금 정상 처리 완료" << std::endl;
            return;
        }
    }
    std::cout << "[ERROR]금액이 잘못되었거나, ID를 찾을수 없습니다." <<std::endl;
}
void AccountHandler::WithdrawMoney(){
    int ID;
    int money;
    std::cout << "ID와 출금할 금액 입력 : ";
    std::cin >> ID >> money;
    for(int i=0;i<accNum;i++){
        if(accArr[i]->getAccID() == ID){
            accArr[i]->Withdraw(money);
            std::cout << "출금 정상 처리 완료" << std::endl;
            return;
        }
    }
    std::cout << "[ERROR]금액이 잘못되었거나, ID를 찾을수 없습니다." <<std::endl;
}

void AccountHandler::ShowAllAccInfo() const{
    std::cout << "=========전 계좌 정보=========\n";
    std::cout << "이름\tID\t잔액" << std::endl;
    for(int i=0;i<accNum;i++)
        accArr[i]->ShowAccInfo();
    std::cout << "=========출 력 완 료 =========\n\n";
}

AccountHandler::~AccountHandler(){
    for(int i=0;i<accNum;i++)
        delete accArr[i];
}

void AccountHandler::MakeNormalAccount(){
    int ID;
    char name[NAME_LEN];
    std::cout << "ID, 이름 입력 : ";
    std::cin >> ID >> name;
    NormalAccount* newAccount = new NormalAccount(ID,0,name,3);
    accArr[accNum++] = newAccount;
    std::cout << "Normal Account 생성 완료. 당신의 ID : " << ID << std::endl << std::endl;
}
void AccountHandler::MakeCreditAccount(){
    char name[NAME_LEN];
    int credit;
    int ID;
    std::cout << "ID, 이름과 신용등급(1~3) 입력 : ";
    std::cin >> ID >> name >> credit;
    if(credit == 1)
        credit = LEVEL_A;
    else if(credit == 2)
        credit = LEVEL_B;
    else
        credit = LEVEL_C;
    HighCreditAccount* newAccount = new HighCreditAccount(ID,0,name,3,credit);
    accArr[accNum++] = newAccount;
    std::cout << "Credit Account 생성 완료. 당신의 ID : " << ID << std::endl << std::endl;
}