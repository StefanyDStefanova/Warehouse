#ifndef __DATE_H
#define __DATE_H

#include <fstream>

struct Date
{
	unsigned int mDay;
	unsigned int mMonth;
	unsigned int mYear;

	void readDate(std::ifstream&);
	void readDateBinary(std::ifstream& in);
	void writeDate(std::ostream&);
	void writeDateBinary(std::ofstream& out);

	bool isLeapYear(unsigned short year);
	bool isValid(unsigned int day, unsigned int month, unsigned int year);

	void copyFrom(const Date& other);

public:
	Date();
	Date(unsigned int day, unsigned int month, unsigned int year);
	Date(const Date&);
	Date& operator=(const Date&);

	bool setDate(unsigned int day, unsigned int month, unsigned int year);
};


#endif