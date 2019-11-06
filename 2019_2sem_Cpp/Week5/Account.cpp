#include "Account.h"
#include "BankingCommonDecl.h"
#include <iostream>

Account::Account(int ID, int money, char* name) : accID(ID), balance(money){
    cusName = new char[NAME_LEN];
    int i=0;
    while(name[i] != '\0'){
        cusName[i] = name[i];
        i++;
    }
    cusName[i] = 0;
}
Account::Account(const Account& account) : Account(account.accID,account.balance,account.cusName){}
int Account::getAccID() const{
    return accID;
}
void Account::Deposit(int money){
    balance+=money;
}
int Account::Withdraw(int money){
    if(balance < money)
        return 0;
    balance-=money;
    return money;
}
void Account::ShowAccInfo() const{
    std::cout << cusName << "\t" << accID << "\t" << balance << std::endl;
}
Account::~Account(){
    delete cusName;
}