/**
* @file		: Point.cpp
* @Author	: Muzaffer Arda Uslu (usluarda58@gmail.com)
* @date		: 5 Aralik 2019, Persembe
*/
#include "Point.h"
#include<iostream>
#include<math.h>
using namespace std;
/**
* @brief	 : Constructor fonksiyonu.
*/
Point::Point()
{
}
/**
* @brief	 : Destructor fonksiyonu.
*/
Point::~Point()
{
}
/**
* @brief	 : Bu fonksiyon Point sinifinin icerisindeki x degiskenine atama islemi yapmamizi saglar.
* @param	 : Bu fonksiyon icerisine double tipinde bir parametre alir.
*/
void Point::setX(double x) {
	this->x = x;
}
/**
* @brief	 : Bu fonksiyon Point sinifinin icerisindeki x degiskenine erismemizi saglar.
*/
double Point::getX()const {
	return this->x;
}
/**
* @brief	 : Bu fonksiyon Point sinifinin icerisindeki y degiskenine atama islemi yapmamizi saglar.
* @param	 : Bu fonksiyon icerisine double tipinde bir parametre alir.
*/
void Point::setY(double y) {
	this->y = y;
}
/**
* @brief	 : Bu fonksiyon Point sinifinin icerisindeki y degiskenine erismemizi saglar.
*/
double Point::getY()const {
	return this->y;
}
/**
* @brief	 : Bu fonksiyon Point sinifinin icerisindeki z degiskenine atama islemi yapmamizi saglar.
* @param	 : Bu fonksiyon icerisine double tipinde bir parametre alir.
*/
void Point::setZ(double z) {
	this->z = z;
}
/**
* @brief	 : Bu fonksiyon Point sinifinin icerisindeki z degiskenine erismemizi saglar.
*/
double Point::getZ() const {
	return this->z;
}
/**
* @brief	 : Bu iki adet Point'in birbirine esit olup olmadigini kontrol eder. Esitse true, degilse false dondurur.
* @param	 : Bu fonksiyon icerisine Point tipinde bir parametre alir.
*/
bool Point::operator==(Point &P) const {
	if (this->x == P.x && this->y == P.y && this->z == P.z)
		return true;
	else
		return false;
}
/**
* @brief	 : Bu iki adet Point'in birbirine olan uzakligi hesaplar ve dondurur.
* @param	 : Bu fonksiyon icerisine &Point tipinde bir parametre alir.
*/
double Point::distance(const Point& P) const {
	double distance;
	distance = sqrt(pow(P.x - this->x, 2) + pow(P.y - this->y, 2) + pow(P.z - this->z, 2));
	return distance;
}