#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
class Account{
    int accID; // 계좌 번호
    int balance; // 잔액
    char* cusName; // 고객 이름
public:
    Account(int ID, int money, char* name); // Constructor
    Account(const Account& account); // 복사생성자
    int getAccID() const; // getID
    virtual void Deposit(int money); // money 입금
    int Withdraw(int money); // money 출금, return money, 잔액 부족시 return 0;
    void ShowAccInfo() const; //Account 정보 출력
    ~Account(); //Destructor
};
#endif