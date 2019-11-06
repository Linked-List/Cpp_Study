#include <iostream>
#include "Worker.h"

Employee::Employee(string name) : name(name){}
void Employee::PrintName(){
    cout << "Name : " << name << endl;
}

PermanentWorker::PermanentWorker(string name, int salary) : salary(salary), Employee(name){}
int PermanentWorker::getPay(){
    return salary;
}
void PermanentWorker::ShowInfo(){
    PrintName();
    cout << "Pay : " << salary << endl;
}

TemporaryWorker::TemporaryWorker(string name, int pay) : Employee(name), payPerHour(pay), workTime(0){}
void TemporaryWorker::AddWorkTime(int workTime){
    this->workTime += workTime;
}
int TemporaryWorker::getPay(){
    return workTime*payPerHour;
}
void TemporaryWorker::ShowInfo(){
    PrintName();
    cout << "Pay : " << workTime*payPerHour << endl;
}

SalesWorker::SalesWorker(string name, int salary, double bonusRatio) : PermanentWorker(name, salary), bonusRatio(bonusRatio), salesResult(0){}
void SalesWorker::AddSalesResult(int salesResult){
    this->salesResult += salesResult;
}
int SalesWorker::getPay(){
    return PermanentWorker::getPay()+salesResult*bonusRatio;
}
void SalesWorker::ShowInfo(){
    PrintName();
    cout << "Pay : " << getPay() << endl;
}

ForeignSalesWorker::ForeignSalesWorker(string name, int salary, double bonusRatio, int riskLevel):SalesWorker(name,salary,bonusRatio), riskLevel(riskLevel){}
int ForeignSalesWorker::GetRiskPay(){
    int riskPay = SalesWorker::getPay(); // ±Þ¿©
    switch(riskLevel){
    case Risk_A:
        riskPay = riskPay*0.3;
        break;
    case Risk_B:
        riskPay = riskPay*0.2;
        break;
    case Risk_C:
        riskPay = riskPay*0.1;
        break;
    }
    return riskPay;
}
int ForeignSalesWorker::getPay(){
    return SalesWorker::getPay()+GetRiskPay();
}
void ForeignSalesWorker::ShowInfo(){
    int salary = SalesWorker::getPay();
    int riskPay = getPay();

    PrintName();
    cout << "Pay : " << salary << endl;
    cout << "Risk Pay : " << riskPay << endl;
    cout << "Total Pay : " << salary+riskPay << endl;
}

EmployeeHandler::EmployeeHandler() : maxSize(100), size(0){
    employee = new Employee*[100];
}
EmployeeHandler::~EmployeeHandler(){
    for(int i=0;i<size;i++)
        delete employee[i];
    delete[] employee;
}
void EmployeeHandler::AddEmployee(Employee* emp){
    employee[size++] = emp;
    cout << "Employee Addition Complete." << endl;
}
void EmployeeHandler::ShowAllSalaryInfo(){
    cout << "----------Employee Information-----------" << endl;
    for(int i=0;i<size;i++)
        employee[i]->ShowInfo();
    cout << "-----------------END---------------------" << endl;
}
void EmployeeHandler::ShowTotalSalary(){
    int totalMoney = 0;
    for(int i=0;i<size;i++)
        totalMoney += employee[i]->getPay();
    cout << "Total Pay Amount : " << totalMoney << endl;
}