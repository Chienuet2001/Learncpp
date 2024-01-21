#pragma once
#include <iostream>
#include <string>
#include "Employee.h"

class Fresher : public Employee
{
private:
    string graDate;
    string graRank;
    string education;

public:
    Fresher(string _graDate,string _graRank,string _education , int _id, string _fullName, string _phone, string _email, EmployeeType _employeeType, const vector<Certificate *> &_certificates)
        : Employee(_id, _fullName, _phone, _email, _employeeType, _certificates), graDate(_graDate), graRank(_graRank), education(_education) {}

    void setGraDate(string _graDate)
    {
        graDate = _graDate;
    }

    string getGraDate() const
    {
        return graDate;
    }

    void setGraRank(string _graRank)
    {
        graRank = _graRank;
    }

    string getGraRank() const
    {
        return graRank;
    }

    void setEducation(string _education)
    {
        education = _education;
    }

    string getEducation() const
    {
        return education;
    }

    void showInfo() const
    {
        Employee::showInfo();
        cout << "Graduation Date: " << graDate << endl;
        cout << "Graduation Rank: " << graRank << endl;
        cout << "Education: " << education << endl;
    }
};