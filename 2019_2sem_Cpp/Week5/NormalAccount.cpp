#include "NormalAccount.h"

NormalAccount::NormalAccount(int ID, int money, char* name, int rate) : Account(ID,money,name), interRate(rate){}
void NormalAccount::Deposit(int money){
    int interest = money*interRate/100;
    Account::Deposit(money+interest);
}