#ifndef	WAREHOUSE_H
#define WAREHOUSE_H

#include "Location.h"
#include <iostream>
#include <fstream>

class Warehouse
{
	char* name; //String mName -> ask Nora
	char* expirationDate; // Date mExpiry
	char* dateOfEntryIntoTheWarehouse; //Date mEntry
	char* nameOfManufacturer; //String mName;
	static size_t availableQuantity;
	Location locationWarehouse;

	char* comment;

	Warehouse() = default;
	Warehouse(char* name, char* expirationDate, char* dateOfEntryIntoTheWarehouse, char* nameOfManufacturer, static size_t availableQuantity, Location locationWarehouse);
	Warehouse(const Warehouse& source);
	~Warehouse();

	Warehouse& operator=(const Warehouse& source);

	// checks if the file is open
	bool isOpen() const { return m_fstream.is_open(); }

	bool open(const char* pszFileName);
	void close();

	// create the product 
	bool add(const Warehouse& product);
	// search the product
	int search(unsigned int auID, Warehouse& foundProduct);

private:

	bool write(const char* pData, size_t uSize);
	bool writeString(const char* psz);
	bool writeWarehouse(const Warehouse& aWarehouse);

	bool read(char* pBuffer, size_t uSize);
	char* readString();
	bool readWarehouse(Warehouse& aWarehouse);

private:
	std::fstream m_fstream;
};

#endif