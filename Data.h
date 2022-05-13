#include "Product.h"
#ifndef __DATE_H
#define __DATE_H

#include <fstream>

cstdint int64_t and uint32_t
string std::string

YYYYMMDD

struct Date
{

	// 20220508
	uint32_t value;

	Date(const std::string& strDate)
	{
		//to do 
		//"08-05-2022"-> 20220508 
		// da se hwyrlqt greshki
	}

	bool operator<=(const Date& other) const
	{
		return value <= other;
	}

	//<,>,=
};

stream << date;

struct Product 
{
	constexpr unsigned int	INVALID_PRODUCT_ID = 0;
	constexpr unsigned int	ANY_PRODUCT_ID = 0;

	Product() = default;
	Product(unsigned int id_, const std::string& name_)
		: id(id_)
		, name(name_) 
	{
	}

	~Product() = default;

	unsigned int getId() const 
	{ 
		return id; 
	}

	inline void Product::copyDatas(const Product& other)
	{
		name = other.name;
		expirationDate = other.expirationDate;
		entranceDate = other.entranceDate;
		producer = other.producer;
		unit = other.unit;
		quantity = other.quantity;
		location = other.location;
		comment = other.comment;
	}

	std::string getName() const
	{
		return name;
	}


	// to do
	//ostream << this 
	//istream >> this

	(ostream& o)
	{  
		o << id;
		o << name;
	}
private:

	unsigned int id{ INVALID_PRODUCT_ID};
	std::string name;

};

//products.dat
class ProductsTable
{
	//dobawqne
	//tyrsene po ime koeto wryshta rweferenciq kym id

		// da naprawq ot id da namira ime


	unsigned int lookupProductId(const std::string& findName)
	{
		Product product;
		// da se pozicioniram w nachaloto na file 
		//while(dokato ne swyrshi faila )
		// {
		// stream>>product;
			if(findName==product.getName())
				 return product.getId();
		// }
		// ako ne namerim product 
		return Product::INVALID_PRODUCT_ID;
	}

	std::string lookutProductName(unsigned int id)
	{

	}

private:
	fstream stream;

	

};

struct Quantity
{
	Quantity() = default;

	Quantity(const std::string& strQuantity)
	{
		// podawa se -> "1.234"
		//maham zapetaq->	"1234"
		value = std::stoll();
		//prowerka dali e 0 dali e walidno chislo
		// i da throw exeption
		std::invalid_argument();
 
	}

	int64_t operator() const
	{
		return value;
	}

	Quantity& operator+(const Quantity& other)
	{
		value += other;
		return *this;
	}

	Quantity& operator-(const Quantity& other)
	{
		value -= other;
		return *this;
	}

	std::string toString() const
	{
		//0.001
		// "1234"
		std::string strValue = std::to_string(value);
		//to do да се обработи с точка, да има 3 знака след запетаята ид а обработе - и да слагам 0
		//1=0.001
		//-1234=-1.234
	}

private:

	//1234= 1.234

	int64_t value{0};

};

struct Movement
{
	bool wasted;// ako e brakuwan ne se razgleda/ dobawq i t.n

	uint32_t productId;

	Date operationDate; // wlqzal/ izlqzal

	Quantity quantity;// с + заприхождаване с - изписване

	Date expirationDate;

	Location location;

	//nomer na partida, swoboden tekst
	std::string batch;  

};

struct ProductQuantity
{
	uint32_t productId{0};
	Quantity quantity;

	ProductQuantity() = default;

	// ako mi podadAT 0 ZNACHI ISKAT WSICHKI


};
//obhodam movements
//za wseki procheten red imam id i name
//wlizame s tekushta data i srawnqwame 
// imame std::vector<ProductQuantity> productsArray;
// dali ima takuw produkt wyw wectora ako 
// nqma 
// ako go nqma go daobawqme s kolichestwo 

std::vector<ProductQuantity> productsArray;
Movement mov;
stream >> mov;

if (da syotwetswa po data )
{
	if (go ima wyw productsArray)
	{
		
	}
}
// {doamti, 5, neshto,9}
//wliza neshto 1
// dobawqme go wyw wektora
//{doamti, 5, neshto,10}

//movements.dat 

struct ProductNameQuantity 
{
	std::string productName;
	Quantity quantity;

	ProductQuantity() = default;
};

class MovementsTable
{
	//shte raboti s movements.dat

	//predefinirane na >> i <<
	//dobawqne i tyrsene na product na syshtiq princip kato za produkta
	//


	//kostruktora trqbwa da gi otwarq awtomatichno

private:
	fstream stream;

};

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