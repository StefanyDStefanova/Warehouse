#include "Warehouse.h"

Warehouse::Warehouse(char* newName, Date newmExpirationData, Date newmDateOfEntryIntoTheWarehouse, char* newNameOfManufacturer, size_t newAvailableQuantity, Location newLocationWarehouse, char* newComment)
{
	setName(newName);
	setExpirationDate(newmExpirationData);
	setDateOfEntryIntoTheWarehouse(newmDateOfEntryIntoTheWarehouse);
	setNameOfManufacturer(newNameOfManufacturer);
	//? dali trqbwa -> availableQuantity;
	setLocationWarehouse(newLocationWarehouse);
	setComment(newComment);
}

Warehouse::Warehouse(const Warehouse& other)
{
	copyWarehouseData(other);
}

Warehouse::~Warehouse()
{
	erase();
}

Warehouse& Warehouse::operator=(const Warehouse& other)
{
	if (this != &other)
	{
			erase();
			copyWarehouseData(other);
	}

	return *this;
}

char* Warehouse::getName() const
{
	return name;
}

Date Warehouse::getExpirationDate() const
{
	return mExpirationData;
}

Date Warehouse::getDateOfEntryIntoTheWarehouse() const
{
	return mDateOfEntryIntoTheWarehouse;
}

char* Warehouse::getNameOfManufacturer() const
{
	return nameOfManufacturer;
}

Location Warehouse::getLocationWarehouse() const
{
	return locationWarehouse;
}

char* Warehouse::getComment() const
{
	return comment;
}

void Warehouse::copyWarehouseData(const Warehouse& other)
{	
	const int nameLength = strlen(other.name) + 1;
	this->name = new char[nameLength];
	strcpy(this->name, other.name);

	mExpirationData = other.mExpirationData;
	mDateOfEntryIntoTheWarehouse = other.mDateOfEntryIntoTheWarehouse;

	const int nameOfManufacturerLength = strlen(other.nameOfManufacturer) + 1;
	this->nameOfManufacturer = new char[nameOfManufacturerLength];
	strcpy(this->nameOfManufacturer, other.nameOfManufacturer);

	locationWarehouse = other.locationWarehouse;

	comment = other.comment;
}

void Warehouse::erase()
{
	delete[] this->name;
	delete[] this->nameOfManufacturer;
}

std::ostream& operator<<(std::ostream& out, const Warehouse& p)
{
	out << "Name of product is: " << p.name << std::endl;
	/*out << "Expiration data is: " << p.mExpirationData << std::endl;
	out << "Date of entry into the warehouse is: " << p.mDateOfEntryIntoTheWarehouse << std::endl;*/
	return out;
}

std::istream& operator>>(std::istream& is, Warehouse& p)
{
	std::cout << "Name of product is: " << p.name;
	is >> p.name;
	/*std::cout << "Expiration data is: " << p.mExpirationData;
	is >> p.mExpirationData;*/
	return is;
}
