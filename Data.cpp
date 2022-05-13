#include "Data.h"
#include <iostream>

void Date::copyFrom(const Date& other)
{
	this->mYear = other.mYear;
	this->mMonth = other.mMonth;
	this->mDay = other.mDay;
}

Date::Date()
{
	this->mYear = 1900;
	this->mMonth = 1;
	this->mDay = 1;
}

Date::Date(unsigned int day, unsigned int month, unsigned int year)
{
	this->mYear = year;
	this->mMonth = month;
	this->mDay = day;
}

Date::Date(const Date& other)
{
	copyFrom(other);
}

Date& Date::operator=(const Date& other)
{
	if (this != &other)
	{
		copyFrom(other);
	}

	return *this;
}
void Date::readDate(std::ifstream& in) 
{
	// dd.MM.YYYY
	in >> this->mDay;
	in >> this->mMonth;
	in >> this->mYear;

}

void Date::readDateBinary(std::ifstream& in)
{
	in.read((char*)&this->mDay, sizeof(int));
	in.read((char*)&this->mMonth, sizeof(int));
	in.read((char*)&this->mYear, sizeof(int));
}

void Date::writeDate(std::ostream& out) 
{
	out << this->mDay << "." << this->mMonth << "." << this->mYear <<std::endl;
}

void Date::writeDateBinary(std::ofstream& out) 
{

	out.write((char*)&this->mDay, sizeof(int));
	out.write((char*)&this->mMonth, sizeof(int));
	out.write((char*)&this->mYear, sizeof(int));

}

bool Date::isLeapYear(unsigned short year)
{
	return ((year % 400) || ((year % 4 == 0) && (year % 100 != 0)));
}

bool Date::isValid(unsigned int day, unsigned int month, unsigned int year)
{
    if (month > 12 || day > 31)
        return 0;

    unsigned short validDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (isLeapYear(year)) {
        validDays[1]++;
    }

    if (day > validDays[month - 1])
        return 0;

    return 1;
}


