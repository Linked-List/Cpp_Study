#include "HighCreditAccount.h"

HighCreditAccount::HighCreditAccount(int ID, int money, char* name, int rate, int special): NormalAccount(ID,money,name,rate), specialRate(special){}
void HighCreditAccount::Deposit(int money){
    int specialInterest = money*specialRate/100;
    NormalAccount::Deposit(money+specialInterest);
}