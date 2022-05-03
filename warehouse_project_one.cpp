#pragma once

#include <iostream>
#include <fstream>

#define SEARCH_ERROR		-1
#define SEARCH_NOT_FOUND	0
#define SEARCH_SUCCESS		1

class Location
{
	unsigned int section;
	unsigned int shelf;
	unsigned int serialNumber;

	Location() = default;
	Location(unsigned int section, unsigned int shelf, unsigned int serialNumber);
	Location(const Location& source);
	~Location();

	Location& operator=(const Location& source);

private:
	void Initialize(unsigned int section, unsigned int shelf, unsigned int serialNumber);
	void Finalize();

};

class Warehouse
{
	char* name;
	char* expirationDate;
	char* dateOfEntryIntoTheWarehouse;
	char* NameOfManufacturer;
	static size_t availableQuantity;
	Location locationWarehouse;

	char*  comment;

	Warehouse() = default;
	Warehouse(char* name, char* expirationDate, char* dateOfEntryIntoTheWarehouse, char* NameOfManufacturer, static size_t availableQuantity,Location locationWarehouse);
	Warehouse(const Warehouse& source);
	~Warehouse();

	Warehouse& operator=(const Warehouse& source);

	// checks if the file is open
	bool IsOpen() const { return m_fstream.is_open(); }

	bool Open(const char* pszFileName);
	void Close();

	// create the product 
	bool Add(const Warehouse& product);
	// search the product
	int Search(unsigned int auID, Warehouse& foundProduct);

private:

	bool Write(const char* pData, size_t uSize);
	bool WriteString(const char* psz);
	bool WriteWarehouse(const Warehouse& aWarehouse);

	bool Read(char* pBuffer, size_t uSize);
	char* ReadString();
	bool ReadWarehouse(Warehouse& aWarehouse);

private:
	std::fstream m_fstream;
};