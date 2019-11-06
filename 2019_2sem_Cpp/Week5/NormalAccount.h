#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__
#include "Account.h"

class NormalAccount : public Account{
    int interRate; //이자율 %단위
public:
    NormalAccount(int ID, int money, char* name, int rate); // 원금 추가
    virtual void Deposit(int money); // 이자 추가
};
#endif