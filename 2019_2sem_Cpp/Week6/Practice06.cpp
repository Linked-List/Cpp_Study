#include "Worker.h"

int main(){
    EmployeeHandler handler;

    PermanentWorker* per1 = new PermanentWorker("Kim",1000);
    handler.AddEmployee(per1);
    PermanentWorker* per2 = new PermanentWorker("Lee",1500);
    handler.AddEmployee(per2);

    TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
    alba->AddWorkTime(5);
    handler.AddEmployee(alba);

    SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
    seller->AddSalesResult(7000);
    handler.AddEmployee(seller);

    ForeignSalesWorker* fseller = new ForeignSalesWorker("Park", 1000, 0.1, Risk_B);
    fseller->AddSalesResult(7000);
    handler.AddEmployee(fseller);

    handler.ShowAllSalaryInfo();
    handler.ShowTotalSalary();
    return 0;
}