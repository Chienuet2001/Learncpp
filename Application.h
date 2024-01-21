#pragma once
#include <iostream>
#include <string>
#include "Manager.h"

using namespace std;

class App
{
private:
    Manager manager;

public:
    vector<Certificate*> EnterCertificates() 
    {
        vector<Certificate*> certificates;
        
        int certificateCount;
        cout << "Enter the number of certificates: ";
        cin >> certificateCount;
        cin.ignore();

        for (int i = 0; i < certificateCount; i++) {
            string certificateID, certificateName, certificateRank, certificateDate;
            cout << "Enter certificate ID: ";
            getline(cin, certificateID);
            cout << "Enter certificate name: ";
            getline(cin, certificateName);
            cout << "Enter certificate rank: ";
            getline(cin, certificateRank);
            cout << "Enter certificate date: ";
            getline(cin, certificateDate);

            Certificate* certificate = new Certificate(certificateID, certificateName, certificateRank, certificateDate);
            certificates.push_back(certificate);
        }

        return certificates;
    }

    void AddEmp()
    {
        int choice;
        cout << "0 - Experience, 1 - Fresher, 2 - Intern \n";
        cout << "Enter type employee: ";
        cin >> choice;
        if (static_cast<Type>(choice) == Type::EXPERIENCE)
        {
            int id, expInYear;
            string fullName, dateOfBirth, phone, email, proSkill;
            vector<Certificate *> certificates;

            try 
            {
                cout << "Enter ID: ";
                cin >> id;
                cin.ignore();

                cout << "Enter full name: ";
                getline(cin, fullName);
                if (!manager.IsValidName(fullName)) 
                {
                    throw "Invalid name";
                }

                cout << "Enter date of birth: ";
                getline(cin, dateOfBirth);
                if (!manager.IsValidDateOfBirth(dateOfBirth)) 
                {
                    throw "Invalid date of birth";
                }

                cout << "Enter phone: ";
                getline(cin, phone);
                if (!manager.isValidPhoneNumber(phone)) 
                {
                    throw "Invalid phone";
                }

                cout << "Enter email: ";
                getline(cin, email);
                if (!manager.IsValidEmail(email)) 
                {
                    throw "Invalid email";
                }

                cout << "Enter professional skill: ";
                getline(cin, proSkill);

                cout << "Enter years of experience: ";
                cin >> expInYear;
                cin.ignore();

                certificates = EnterCertificates();
                Experience *experience = new Experience(expInYear, proSkill, id, fullName, phone, email, EmployeeType::EXPERIENCE, certificates);
                manager.add(*experience);
            }
            catch (const char* e) 
            {
                cout << "Error: " << e << endl;
            }
        }

        else if (static_cast<Type>(choice) == Type::FRESHER)
        {
            int id;
            string fullName, dateOfBirth, phone, email;
            vector<Certificate *> certificates;

            try 
            {
                cout << "Enter ID: ";
                cin >> id;
                cin.ignore();

                cout << "Enter full name: ";
                getline(cin, fullName);
                if (!manager.IsValidName(fullName)) 
                {
                    throw "Invalid name";
                }

                cout << "Enter date of birth: ";
                getline(cin, dateOfBirth);
                if (!manager.IsValidDateOfBirth(dateOfBirth)) 
                {
                    throw "Invalid date of birth";
                }

                cout << "Enter phone: ";
                getline(cin, phone);
                if (!manager.isValidPhoneNumber(phone)) 
                {
                    throw "Invalid phone";
                }

                cout << "Enter email: ";
                getline(cin, email);
                if (!manager.IsValidEmail(email)) 
                {
                    throw "Invalid email";
                }
                
                string graduationDate, graduationRank, education;
                cout << "Enter Graduation Date: ";
                cin >> graduationDate;
                cout << "Enter Graduation Rank: ";
                cin >> graduationRank;
                cout << "Enter Education: ";
                cin.ignore();
                getline(cin, education);

                certificates = EnterCertificates();
                Fresher* fresher = new Fresher(graduationDate,graduationRank,education,id,fullName,phone,email,Type::FRESHER,certificates);
                manager.add(*fresher);
                
            }

            catch (const char* e) 
            {
                cout << "Error: " << e << endl;
            }
        }

        else if (static_cast<Type>(choice) == Type::INTERN)
        {
            int id, semester;
            string fullName, dateOfBirth, phone, email, major, uniName;
            vector<Certificate *> certificates;

            try
            {
                cout << "Enter ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter full name: ";
                getline(cin, fullName);
                if (manager.IsValidName(fullName) == false)
                {
                    throw "Invalid name";
                }
                
                cout << "Enter date of birth: ";
                getline(cin, dateOfBirth);
                if (manager.IsValidDateOfBirth(dateOfBirth) == false)
                {
                    throw "Invalid date of birth";
                }
                

                cout << "Enter phone: ";
                getline(cin, phone);
                if (manager.isValidPhoneNumber(phone) == false)
                {
                    throw "Invalid phone";
                }
                
                cout << "Enter email: ";
                getline(cin, email);
                if (manager.IsValidEmail(email) == false)
                {
                    throw "Invalid email";
                }

                cout << "Enter major: ";
                getline(cin, major);

                cout << "Enter semester: ";
                cin >> semester;

                cin.ignore();
                cout << "Enter university name: ";
                getline(cin, uniName);

                certificates = EnterCertificates();
                
                Intern *intern = new Intern(major, semester, uniName, id, fullName, phone, email, EmployeeType::INTERN, certificates);
                manager.add(*intern);
            }

            catch (const char* e)
            {
                cout<<"Error: "<<e << endl;
            }
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
        
    }
    
    void remove()
    {
        int id;
        cout<<"Nhap id can xoa";
        cin>>id;
        manager.remove(id);
    }

    void run()
    {
        int choice;
        while (true)
        {
            cout<<"------------------------------------------------"<<endl;
            cout << "0 - ADD \n1 - PRINT ALL \n2 - PRINT INTERN \n3 - PRINT FRESHER" << endl;
            cout << "4 - PRINT EXPERIENCE \n5 - EDIT \n6 - REMOVE"<<endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 0:
            {
                AddEmp();
                break;
            }
            case 1:
                manager.showAllEmployee();
                break;
            case 2:
                manager.showAllIntern();
                break;
            case 3:
                manager.showAllFresher();
                break;
            case 4:
                manager.showAllExp();
                break;
            case 5:
                manager.edit();
            case 6:
                remove();
            default:
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
};