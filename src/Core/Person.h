#pragma once
#include <iostream>
#include <string>

class Person
{
private:

    std::string _FirstName;
    std::string _LastName;
    std::string _Email;
    std::string _Phone;

public:

    Person(std::string FirstName, std::string LastName, std::string Email, std::string Phone)
    {

        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }

    void SetFirstName(std::string FirstName) { _FirstName = FirstName; }
    std::string GetFirstName() { return _FirstName; }

    void SetLastName(std::string LastName) { _LastName = LastName; }
    std::string GetLastName() { return _LastName; }

    void SetEmail(std::string Email) { _Email = Email; }
    std::string GetEmail() { return _Email; }

    void SetPhone(std::string Phone) { _Phone = Phone; }
    std::string GetPhone() { return _Phone; }

    std::string FullName() { return _FirstName + " " + _LastName; }
};

