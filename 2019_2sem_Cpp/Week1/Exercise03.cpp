#include <iostream>

class FruitSeller{
private:
    int Apple_Price;
    int numOfApples;
    int myMoney;

public:
    void InitMembers(int price, int num, int money){
        Apple_Price = price;
        numOfApples = num;
        myMoney = money;
    }

    int SaleApples(int money){
        int num = money/Apple_Price;
        numOfApples -= num;
        myMoney += money;
        return num;
    }

    void showSalesResult(){
        printf("남은 사과 : %d\n", numOfApples);
        printf("판매 수익 : %d\n", myMoney);
    }
};

class FruitBuyer{
private:
    int myMoney;
    int numOfApples;

public:
    void InitMembers(int money){
        myMoney = money;
        numOfApples = 0;
    }
    void BuyApples(FruitSeller& seller, int money){
        numOfApples += seller.SaleApples(money);
        myMoney -= money;
    }
    void ShowBuyResult(){
        printf("현재 잔액 : %d\n", myMoney);
        printf("사과 개수 : %d\n", numOfApples);
    }
};

int main(){
    FruitSeller seller;
    seller.InitMembers(1000, 20, 0);

    FruitBuyer buyer;
    buyer.InitMembers(5000);
    buyer.BuyApples(seller, 2000);

    printf("-- 과일 판매자의 현황 --\n");
    seller.showSalesResult();

    printf("-- 과일 구매자의 현황 --\n");
    buyer.ShowBuyResult();
    return 0;
}