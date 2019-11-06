#include <string>
using namespace std;

enum{Risk_A = 1, Risk_B, Risk_C};

class Employee{
    string name;
public:
    Employee(string name);
    void PrintName(); // print name
    virtual void ShowInfo() = 0;
    virtual int getPay() = 0;
    virtual ~Employee(){};
};

class PermanentWorker : public Employee{
    int salary; // 월급
public:
    PermanentWorker(string name, int salary);
    int getPay(); // return salary
    void ShowInfo(); // print name, salary
};

class TemporaryWorker : public Employee{
    int workTime;
    int payPerHour;
public:
    TemporaryWorker(string name, int pay);
    void AddWorkTime(int workTime); // workTime추가
    int getPay(); // return workTime*payPerHour
    void ShowInfo(); // print name, workTime*payPerHour
};

class SalesWorker : public PermanentWorker{
    int salesResult;
    double bonusRatio;
public:
    SalesWorker(string name, int salary, double bonusRatio);
    void AddSalesResult(int salesResult); // 판매량 추가
    int getPay(); // return salary+salesResult*bonusRatio
    void ShowInfo(); // print name, salary + salesResult*bonusRatio
};

class ForeignSalesWorker : public SalesWorker{
    int riskLevel;
public:
    ForeignSalesWorker(string name, int salary, double bonusRatio, int riskLevel);
    int GetRiskPay(); // return 위험수당
    int getPay(); // return salary + 위험수당
    void ShowInfo(); // print name, salary, risk pay, salary+risk pay
};

class EmployeeHandler{
private:
    Employee** employee;
    const int maxSize;
    int size;

public:
    EmployeeHandler();
    void AddEmployee(Employee* emp);
    void ShowAllSalaryInfo(); // print 모든 Employee Information
    void ShowTotalSalary(); // print 총 지급할 월급액
    ~EmployeeHandler();
};