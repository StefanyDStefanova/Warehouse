#pragma once

#include <iostream>
#include <fstream>

#define SEARCH_ERROR		-1
#define SEARCH_NOT_FOUND	0
#define SEARCH_SUCCESS		1

struct Data {};

class Location
{
	unsigned int section;
	unsigned int shelf;
	unsigned int serialNumber;
	//da si naprawq defolten konstruktor kojto da iunicializira s 0

/*/private:
	void Initialize(unsigned int section, unsigned int shelf, unsigned int serialNumber);
	void Finalize();
	*/
	// added comment
};

class Warehouse
{
	char* name; //String mName -> ask Nora
	char* expirationDate; // Date mExpiry
	char* dateOfEntryIntoTheWarehouse; //Date mEntry
	char* nameOfManufacturer; //String mName;
	static size_t availableQuantity;
	Location locationWarehouse;

	char*  comment;

	Warehouse() = default;
	Warehouse(char* name, char* expirationDate, char* dateOfEntryIntoTheWarehouse, char* nameOfManufacturer, static size_t availableQuantity,Location locationWarehouse);
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