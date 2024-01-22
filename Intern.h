#pragma once
#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;

class Intern : public Employee
{
private:
    string major;
    int semester;
    string uniName;

public:
    Intern(string _major, int _semester, string _uniName, int _id, string _fullName, string _phone, string _email, EmployeeType _employeeType, const vector<Certificate *> &_certificates)
        : Employee(_id, _fullName, _phone, _email, _employeeType, _certificates), major(_major), semester(_semester), uniName(_uniName) {}

    ~Intern() {}

    void setMajor(string _major)
    {
        major = _major;
    }
    string getMajor() const
    {
        return major;
    }

    void setSemester(int _semester)
    {
        semester = _semester;
    }
    int getSemester() const
    {
        return semester;
    }

    void setUniName(string _uniName)
    {
        uniName = _uniName;
    }
    string getUniName() const
    {
       return uniName;
    }

    void showInfo() const
    {
        Employee::showInfo();
        cout << "Major: " << major << endl;
        cout << "Semester: " << semester << endl;
        cout << "University Name: " << uniName << endl;
    }

};

/*
int main()
{
    Certificate cert1("1", "Certificate 1", "Rank 1", "2022-01-01");
    Certificate cert2("2", "Certificate 2", "Rank 2", "2022-02-01");
    // Create a vector of certificates
    vector<Certificate> certificates;
    
    certificates.push_back(cert1);
    certificates.push_back(cert2);

    // Create an Intern object
    Intern intern("Computer Science", 2, "ABC University", 1, "Dang Quoc Hung", "123456789", "john.doe@example.com", EmployeeType::INTERN, certificates);

    // Display Intern's information
    intern.showInfo();

    // Test getter and setter methods
    intern.setMajor("Information Technology");
    intern.setSemester(3);
    intern.setUniName("XYZ University");

    cout << "Updated Information:" << endl;
    intern.showInfo();

    return 0;
}

*/