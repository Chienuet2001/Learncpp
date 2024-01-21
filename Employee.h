#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Certificate.h"
using namespace std;

enum EmployeeType
{
    EXPERIENCE = 0,
    FRESHER,
    INTERN
}; typedef EmployeeType Type;

class Employee
{
private:
    int id;
    string fullName;
    string birthDay;
    string phone;
    string email;
    Type employeeType;
    vector<Certificate *> certificates;

public:
    static int employeeCount;

    Employee(int _id, string _fullName, string _phone, string _email, EmployeeType _employeeType, const vector<Certificate *> &_certificates)
        : id(_id), fullName(_fullName), phone(_phone), email(_email), employeeType(_employeeType), certificates(_certificates)
    {
        employeeCount++;
    }

    int getID() const
    {
        return id;
    }

    void setID(int _id)
    {
        id = _id;
    }

    string getFullName() const
    {
        return fullName;
    }

    void setFullName(string _fullName)
    {
        fullName = _fullName;
    }

    string getBirthDay() const
    {
        return birthDay;
    }

    void setBirthDay(string _birthDay)
    {
        birthDay = _birthDay;
    }

    string getPhone() const
    {
        return phone;
    }

    void setPhone(string _phone)
    {
        phone = _phone;
    }

    string getEmail() const
    {
        return email;
    }

    void setEmail(string _email)
    {
        email = _email;
    }

    Type getEmployeeType() const
    {
        return employeeType;
    }

    void setEmployeeType(Type _employeeType)
    {
        employeeType = _employeeType;
    }

    virtual void showInfo() const
    {
        cout << "ID: " << id << endl;
        cout << "Full name: " << fullName << endl;
        cout << "Phone: " << phone << endl;
        cout << "Email: " << email << endl;
        switch (employeeType)
        {
        case EXPERIENCE:
            cout << "Employee Type: Experience" << endl;
            break;
        case FRESHER:
            cout << "Employee Type: Fresher" << endl;
            break;
        case INTERN:
            cout << "Employee Type: Intern" << endl;
            break;
        default:
            break;
        }
        cout << "List certificates: \n";
        for (auto &cer : certificates)
        {
            cout << "\tCertificate ID: " << cer->getID() << endl;
            cout << "\tCertificate Name: " << cer->getName() << endl;
            cout << "\tCertificate Rank: " << cer->getRank() << endl;
            cout << "\tCertificate Date: " << cer->getDate() << endl;
        }
    }
};

int Employee::employeeCount = 0;


// int main()
// {
//     // Tạo một danh sách các chứng chỉ
//     vector<Certificate*> certificates;
//     Certificate* certificate1 = new Certificate(1, "Certificate 1", "Rank 1", "2020-01-01");
//     certificates.push_back(certificate1);

//     // Tạo một nhân viên
//     Employee employee(1, "John Doe", "123456789", "john.doe@example.com", EXPERIENCE, certificates);

//     // Hiển thị thông tin nhân viên
//     employee.showInfo();

//     // Giải phóng bộ nhớ cho các chứng chỉ
//     for (auto cert : certificates)
//     {
//         delete cert;
//     }

//     return 0;
// }