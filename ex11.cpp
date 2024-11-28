#include<iostream>
using namespace std;


enum Employeetype{
    FULLTIME,
    PARTTIME,
    CONTRACTOR
};

string getEmployeeTypeName(enum Employeetype type){
    switch (type){
        case 0:
            return "FULLTIME";
        case 1:
            return "PARTIME";
        case 2:
            return "CONTRACTOR";
        default:
            cout<<"employee type does not match the standard one";
            return NULL;
    }
}

union PaymentInfo{
    float monthlySalary;
    int hourlyRate;
    double contractAmount;
};

struct Employee{
    int id; 
    string name; 
    Employeetype type; 
    PaymentInfo payment;
};

void addEmployee(Employee* EmployeeTab, int& n, int id, string name, Employeetype type, PaymentInfo payment){


    //started with employee type as it may issues,(user can enter a number higher than 2)
    switch(type){
        case 0:
            EmployeeTab[n].payment.monthlySalary = payment.monthlySalary;
            break;        
        case 1:
            EmployeeTab[n].payment.hourlyRate = payment.hourlyRate;
            break;
        case 2:
            EmployeeTab[n].payment.contractAmount = payment.contractAmount;
            break;
        default:
            cout<<"employee type does not match the standard types";
            return ;
    }
    EmployeeTab[n].id = id;
    EmployeeTab[n].name = name;
    EmployeeTab[n].type = type;
    n++;
}

void displayEmployeeInfo(struct Employee employee){
    cout<<"emplyee id is: "<<employee.id<<endl;
    cout<<"emplyee name is: "<<employee.name<<endl;
    cout<<"emplyee Employeetype is: "<<getEmployeeTypeName(employee.type)<<endl;
    switch(employee.type){
        case 0:
            cout<<"emplyee payment is: "<<employee.payment.monthlySalary<<endl;
            break;
        case 1:
            cout<<"emplyee payment is: "<<employee.payment.hourlyRate<<endl;
            break;
        case 2:
            cout<<"emplyee payment is: "<<employee.payment.contractAmount<<endl;
            break;
        default:
            cout<<"employee type does not match the standard one";
            return;
    }
}

int main(){
    struct Employee employeetab[6];
    int n = 0;
    int i = 0;
    union PaymentInfo tmp_payment;

    tmp_payment.monthlySalary = 200000;
    addEmployee(employeetab,n,0,"Yaqub Qomarudin Dibizah",FULLTIME,tmp_payment);
    
    tmp_payment.monthlySalary = 60000;
    addEmployee(employeetab,n,1,"Khalid Kashmiri",FULLTIME,tmp_payment);

    tmp_payment.monthlySalary = 120000;
    addEmployee(employeetab,n,2,"Khidir Karawitah",FULLTIME,tmp_payment);

    tmp_payment.contractAmount = 500000;
    addEmployee(employeetab,n,3,"Ismail Ahmad Khan Nabawi",CONTRACTOR,tmp_payment);

    tmp_payment.hourlyRate = 80000;
    addEmployee(employeetab,n,4,"Utsman Abdul Jalil Shisha",PARTTIME,tmp_payment);

    tmp_payment.monthlySalary = 400000;
    addEmployee(employeetab,n,5,"Muhammad Sumbul",FULLTIME,tmp_payment);    

    
    while(i < 6){
        displayEmployeeInfo(employeetab[i]);
        cout<<endl;
        i++;
    }

    return 0;
}