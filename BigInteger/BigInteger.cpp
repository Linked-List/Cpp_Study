#include "BigInteger.h"
#include <iostream>

BigInteger::BigInteger():sign(false){}

BigInteger::BigInteger(std::string num){
    if(num[0] == '-'){
        sign = true;
        num.erase(0,1);
    }else if(num[0] == '+'){
        sign = false;
        num.erase(0,1);
    }else
        sign = false;

    for(int i=num.length()-1;i>=0;i--)
        value.push_back(num[i]-'0');

    if(value.size()==1 && value[0]==0 && sign==true) // 0통일
        sign = false;
}
BigInteger::BigInteger(long long num){
    if(num<0){
        sign = true;
        num *= -1;
    }else{
        sign = false;
    }

    do{
        value.push_back(num%10);
        num/=10;
    }while(num != 0);

    if(value.size()==1 && value[0]==0 && sign==true) // 0통일
        sign = false;
}

bool BigInteger::operator<(BigInteger op2){
    if(sign ^ op2.sign) // 부호가 반대인경우
        return sign==false ? false : true;
    if(value.size() != op2.value.size())
        return (value.size()<op2.value.size())^sign;
    else // 길이가 같은경우
        for(int i=value.size()-1;i>=0;i++)
            if(value[i] != op2.value[i])
                return (value[i] < op2.value[i])^sign;
    return false;
}

bool BigInteger::operator>(BigInteger op2){
    if(sign ^ op2.sign) // 부호가 반대인경우
        return sign==true ? false : true;
    if(value.size() != op2.value.size())
        return (value.size()<op2.value.size())&sign;
    else // 길이가 같은경우
        for(int i=value.size()-1;i>=0;i++)
            if(value[i] != op2.value[i])
                return (value[i] > op2.value[i])^sign;
    return false;
}

bool BigInteger::operator==(BigInteger op2){
    if(sign ^ op2.sign)
        return false;
    if(value.size() != op2.value.size())
        return false;
    for(int i=value.size()-1;i>=0;i--)
        if(value[i] != op2.value[i])
            return false;
    return true;
}

bool BigInteger::operator!=(BigInteger op2){
    return !operator==(op2);
}

BigInteger BigInteger::operator+(BigInteger op2){
    BigInteger result;
    if(sign ^ op2.sign){
        // 절대값이 더 큰쪽에서 작은쪽으로 뺀다.
        // 부호는 절대값이 큰쪽으로 따라간다.
        bool absComp; // op2가 더 큰지
        if(sign == true){
            BigInteger tmp = *(this);
            tmp.sign = false;
            absComp = tmp<op2;
        }else{
            BigInteger tmp = op2;
            tmp.sign = false;
            absComp = *(this)<tmp;
        }

        if(absComp){ // op2쪽이 절댓값이 크다.
            result.sign = op2.sign;
            int borrow=0;
            int i=0;
            for(;i<value.size();i++){
                int tmp = op2.value[i]-value[i]-borrow;
                if(tmp<0){
                    tmp = 10+tmp;
                    borrow = 1;
                }else
                    borrow = 0;
                result.value.push_back(tmp);
            }
            for(;i<op2.value.size();i++){
                int tmp = op2.value[i]-borrow;
                if(tmp<0){
                    tmp = 10+tmp;
                    borrow = 1;
                }else
                    borrow = 0;
                result.value.push_back(tmp);
            }
            if(borrow)
                result.sign = !(result.sign);
            if(*(result.value.end()-1)==0)
                result.value.pop_back();
        }
        else{ // op1쪽이 절댓값이 크다.
            result.sign = sign;
            int borrow=0;
            int i=0;
            for(;i<op2.value.size();i++){
                int tmp = value[i]-op2.value[i]-borrow;
                if(tmp<0){
                    tmp = 10+tmp;
                    borrow = 1;
                }else
                    borrow = 0;
                result.value.push_back(tmp);
            }
            for(;i<value.size();i++){
                int tmp = value[i]-borrow;
                if(tmp<0){
                    tmp = 10+tmp;
                    borrow = 1;
                }else
                    borrow = 0;
                result.value.push_back(tmp);
            }
            if(*(result.value.end()-1)==0)
                result.value.pop_back();
        }

    }else{ // 부호가 같은 경우
        result.sign = sign;
        int i=0;
        int carry = 0;
        for(;i<value.size() && i<op2.value.size();i++){
            int tmp = value[i] + op2.value[i] + carry;
            result.value.push_back(tmp%10);
            carry = tmp/10;
        }

        if(value.size() > op2.value.size())
            for(;i<value.size();i++){
                int tmp = value[i]+carry;
                result.value.push_back(tmp%10);
                carry = tmp/10;
            }
        else if(op2.value.size() > value.size())
            for(;i<op2.value.size();i++){
                int tmp = op2.value[i]+carry;
                result.value.push_back(tmp%10);
                carry = tmp/10;
            }
        if(carry != 0)
            result.value.push_back(carry);
    }
    return result;
}

BigInteger BigInteger::operator-(BigInteger op2){
    if(op2 != 0)
        op2.sign = !op2.sign;
    return operator+(op2); // A-B = A + (-B) 로 처리
}

BigInteger BigInteger::operator*(BigInteger op2){
    BigInteger result(0);

    // 0은 조기처리
    if(*(this)==0 || op2==0)
        return BigInteger(0);

    for(int i=0;i<op2.value.size();i++){
        BigInteger tmp;
        int carry=0;

        if(op2.value[i] == 0) // 0나오면 그냥 무시
            continue;

        for(int j=0;j<i;j++)
            tmp.value.push_back(0);

        for(int j=0;j<value.size();j++){
            int tmp2 = value[j]*op2.value[i] + carry;
            if(tmp2 > 9)
                carry = tmp2/10;
            else
                carry = 0;
            tmp.value.push_back(tmp2%10);
        }
        if(carry != 0)
            tmp.value.push_back(carry);
        result = result + tmp;
    }
    result.sign = sign^op2.sign;
    return result;
}

std::ostream& operator<<(std::ostream& out, const BigInteger num){
    if(num.sign)
        out << "-";
    for(auto i=num.value.rbegin();i!=num.value.rend();i++)
        out << static_cast<int>(*i);
    return out;
}