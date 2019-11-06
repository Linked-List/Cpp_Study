#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount{
    int specialRate;// special 추가 이자
public:
    HighCreditAccount(int ID, int money, char* name, int rate, int special); // 원금, 이자 추가
    virtual void Deposit(int money); // special 이자 추가
};
#endif