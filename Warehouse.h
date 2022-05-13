#ifndef	WAREHOUSE_H
#define WAREHOUSE_H

#include "Location.h"
#include "Data.h"

#include <iostream>
#include <fstream>

class Warehouse
{
	
public:

	Warehouse() = default;
	Warehouse(char* newName, Date newmExpirationData, Date newmDateOfEntryIntoTheWarehouse, char* newNameOfManufacturer, Location newLocationWarehouse, char* newComment);
	Warehouse(const Warehouse& other);
	~Warehouse();

	Warehouse& operator=(const Warehouse& other);

	friend std::ostream& operator<< (std::ostream& out, const Warehouse& p);
	friend std::istream& operator>> (std::istream& in, Warehouse& p);


	char* getName()const;
	Date getExpirationDate() const;
	Date getDateOfEntryIntoTheWarehouse() const;
	char* getNameOfManufacturer() const;
	//static size_t getAvailabeQuantity() const;
	Location getLocationWarehouse() const;
	char* getComment() const;

	void setName(char* newName);
	void setExpirationDate(Date newExpirationDate);
	void setDateOfEntryIntoTheWarehouse(Date newDateOfEntryIntoTheWarehouse);
	void setNameOfManufacturer(char* newNameOfManufacturer);
	//static size_t getAvailabeQuantity() const;
	void setLocationWarehouse(Location newLocationWarehouse);
	void setComment(char* newComment);

	//методи за обработка на срока на годност
	friend int getExpYear(const Warehouse& p);
	friend int getExpMonth(const Warehouse& p);
	friend int getExpDay(const Warehouse& p);
	friend bool isExpiring(const Warehouse& p);

	//методи за обработка на местоположението
	friend int getSection(const Warehouse& p);
	friend int getShelf(const Warehouse& p);
	friend int getNumber(const Warehouse& p);
	friend Location newLocation(const Warehouse& p);



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
	bool writeProductByWarehouse(const Warehouse& aWarehouse);

	bool read(char* pBuffer, size_t uSize);
	char* readString();
	bool readProductByWarehouse(Warehouse& aWarehouse);

	void copyWarehouseData(const Warehouse& other);
	void erase();

private:
	std::fstream m_fstream;

private:
	char* name; //String mName -> ask Nora
	//char* expirationDate; // Date mExpiry
	//char* dateOfEntryIntoTheWarehouse; //Date mEntry

	Date mExpirationData;
	Date mDateOfEntryIntoTheWarehouse;
	char* nameOfManufacturer; //String mName;
	static size_t availableQuantity;
	Location locationWarehouse;

	char* comment;
};


class Warehouse {
{	// revition(const Date& date, uint32_t productId=Product::ANY_PRODUCT_ID)//towa e kogato iskam wsichki produkti 
	// pri newaliden product da izwejda wsichki produkti
	// kazwame potrebitelq da wywede 0 za wsichki

public:
	Warehouse() = default;
	~Warehouse() = default;

	Warehouse(const Warehouse&) = delete;//iztriwam copy konstruktora 	zabranqwam kopiraneto 
	Warehouse& operator=(const Warehouse&) = delete;//triq operator =

public:
	//metodite po zadanie


private:
	ProductsTable productsTable;
	MovementsTable movementsTable;
	//LocationsTable locationTable;
};

Warehouse warehouse; // globalna promenliwa
// da se konwertira id ot str do uint32_t
warehouse.revition(Date(strDate), id)
#endif

