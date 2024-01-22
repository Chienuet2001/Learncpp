#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "Employee.h"
#include "Intern.h"
#include "Fresher.h"
#include "Experience.h"

class Manager
{
private:
    vector<Employee *> employees;

public:
    Manager() {}
    ~Manager() {}
 
    void add(Employee &e)
    {
        employees.push_back(&e);
    }

    void remove(int id)
    {
        int pos = -1;
        for (size_t i = 0; i < employees.size(); i++)
        {
            if (employees[i]->getID() == id)
            {
                pos = i;
                break;
            }
        }

        if (pos != -1)
        {
            employees.erase(employees.begin() + pos);
            cout << "Employee with ID " << id << " has been removed." << endl;
        }
        else
        {
            cout << "Employee with ID " << id << " not found." << endl;
        }
    }

    void edit()
    {
        
    } 

    void showAllEmployee() const
    {
        for (auto &ee : employees)
        {
            ee->showInfo();
        }
    }

    void showAllIntern() const
    {
        for (auto &ee : employees)
        {
            if (ee->getEmployeeType() == Type::INTERN)
            {
                ee->showInfo();
            }
            
        }
    }

    void showAllFresher() const
    {
        for (auto &ee : employees)
        {
            if (ee->getEmployeeType() == Type::FRESHER)
            {
                ee->showInfo();
            }
            
        }
    }

    void showAllExp() const
    {
        for (auto &ee : employees)
        {
            if (ee->getEmployeeType() == Type::EXPERIENCE)
            {
                ee->showInfo();
            }
            
        }
    }

    bool isValidPhoneNumber(const string& phoneNumber)
    {
        regex pattern("(\\+84|0)\\d{9,10}");
        return regex_match(phoneNumber,pattern);
    }
    bool IsValidDateOfBirth(const std::string& dateOfBirth) {
        regex pattern("\\d{2}/\\d{2}/\\d{4}");
        if (!regex_match(dateOfBirth, pattern)) 
        {
            return false;
        }
        int day, month, year;
        sscanf(dateOfBirth.c_str(), "%d/%d/%d", &day, &month, &year);

        if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900) 
        {
            return false;
        }
        
        if ((day == 31) && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11)) 
        {
            return false;
        }

        if (month == 2) 
        {
            bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
            if ((day > 29) || (day == 29 && !isLeapYear)) 
            {
                return false;
            }
        }

        return true;
    }
    bool IsValidEmail(const string& email) 
    {
        regex emailRegex("[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}");
        return regex_match(email, emailRegex);
    }

    #include <regex>

    bool IsValidName(const string& name) 
    {
        regex nameRegex("[A-Za-z\\s]+");
        return regex_match(name, nameRegex);
    }
};

