#ifndef __BANKING_COMMON_H__
#define __BANKING_COMMON_H__

#include <iostream>
#include <string>
const int NAME_LEN=20; // 고객 이름 길이
enum{MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT}; //프로그램 사용자 선택 메뉴
enum{LEVEL_A=7, LEVEL_B=4, LEVEL_C=2}; //신용등급
enum{NORMAL=1, CREDIT=2}; //계좌 종류

#endif