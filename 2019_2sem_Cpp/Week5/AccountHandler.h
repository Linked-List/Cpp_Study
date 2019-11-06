#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__
#include "Account.h"

class AccountHandler{
    Account* accArr[100]; // Account 저장을 위한 객체 포인터 배열
    int accNum; // 저장된 Account 갯수 
public:
    AccountHandler();
    void ShowMenu() const; //메뉴출력
    void MakeAccount(); //계좌 개설
    void DepositMoney(); // 입금
    void WithdrawMoney(); // 출금
    void ShowAllAccInfo() const; //Show Account
    ~AccountHandler();
protected:
    void MakeNormalAccount(); // Make a Normal Account
    void MakeCreditAccount(); // Make a Credit Accoutn
};
#endif