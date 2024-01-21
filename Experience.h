#pragma once
#include <iostream>
#include <string>
#include "Employee.h"

class Experience : public Employee
{
private:
    int expInYear;
    string proSkill;

public:
    Experience(int _expInYear, string _proSkill, int _id, string _fullName, string _phone, string _email, EmployeeType _employeeType, const vector<Certificate *> &_certificates)
        : Employee(_id, _fullName, _phone, _email, _employeeType, _certificates), expInYear(_expInYear), proSkill(_proSkill) {}

    void setExpInYear(int _expInYear)
    {
        expInYear = _expInYear;
    }

    int getExpInYear() const
    {
        return expInYear;
    }

    void setProSkill(string _proSkill)
    {
        proSkill = _proSkill;
    }

    string getProSkill() const
    {
        return proSkill;
    }

    void showInfo() const
    {
        Employee::showInfo();
        cout << "Experience (in years): " << expInYear << endl;
        cout << "Professional Skill: " << proSkill << endl;
    }
};
