#include "Purchases.hpp"

Purchases::Purchases()
{
}

Purchases::~Purchases()
{
}

bool Purchases::checkAge(Date birthdate, std::string ageRating)
{
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    std::vector<int> ;

    int currentYear = timePtr->tm_year + 1900;
    int currentMonth = timePtr->tm_mon + 1;
    int currentDay = timePtr->tm_mday;
    int age;
    
    if (this->_birthdate.month == 11)
    {
        if (currentMonth == this->_birthdate.month && currentDay >= this->_birthdate.day)
        {
            age = currentYear - this->_birthdate.year;
        }

        else if (currentMonth == this->_birthdate.month && currentDay < this->_birthdate.day)
        {
            age = currentYear - this->_birthdate.year - 1;
        }
        
        else if (currentMonth < this->_birthdate.month)
        {
            age = currentYear - this->_birthdate.year - 1;
        }
        
    }
    
    else
    {
        if (currentMonth == this->_birthdate.month && currentDay < this->_birthdate.day)
        {
            age = currentYear - this->_birthdate.year - 1;
        }
        
        else if (currentMonth > this->_birthdate.month)
        {
            age = currentYear - this->_birthdate.year;
        }
        
        else if (currentMonth == this->_birthdate.month && currentDay >= this->_birthdate.day)
        {
            age = currentYear - this->_birthdate.year;
        }

        else if (currentMonth < this->_birthdate.month)
        {
            age = currentYear - this->_birthdate.year - 1;
        }
        
    }
    
    
    
    if (age >= std::stoi(ageRating))
    {
        return true;
    }
    
    else
    {
        return false;
    }
}