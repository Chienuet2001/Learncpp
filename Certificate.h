#pragma once
#include <string>
using namespace std;

class Certificate
{
private:
    string ID;
    string Name;
    string Rank;
    string Date;

public:
    Certificate(string _ID, string _Name, string _Rank, string _Date)
        : ID(_ID), Name(_Name), Rank(_Rank), Date(_Date) {}

    void setID(string _ID)
    {
        ID = _ID;
    }

    string getID() const
    {
        return ID;
    }

    void setName(string _Name)
    {
        Name = _Name;
    }

    string getName() const
    {
        return Name;
    }

    void setRank(string _Rank)
    {
        Rank = _Rank;
    }

    string getRank() const
    {
        return Rank;
    }

    void setDate(string _Date)
    {
        Date = _Date;
    }

    string getDate() const
    {
        return Date;
    }
};