/**
* @file		: PointCloud.cpp
* @Author	: Muzaffer Arda Uslu (usluarda58@gmail.com)
* @date		: 5 Aralik 2019, Persembe
*/
#include "PointCloud.h"
/**
* @brief	 : Constructor fonksiyonu.
*/

PointCloud::PointCloud()
{
	pointNumber;
	/*points = new Point[pointNumber];*/
}
/**
* @brief	 : Destructor fonksiyonu.
*/
PointCloud::~PointCloud()
{
}
/**
* @brief	 : Bu fonksiyon PointCloud sinifinin icerisinde olan points nesnesine deger atama islemini yapar.
* @param	 : Bu fonksiyon icerisine Point* tipinde bir parametre alir.
*/
void PointCloud::setPoints(list<Point> P) {
	points = P;
}
/**
* @brief	 : Bu fonksiyon PointCloud sinifinin icerisindeki points degiskenini dondurur.
*/
list<Point> PointCloud::getPoints() const {
	return points;
}
/**
* @brief	 : Bu fonksiyon PointCLoud sinifinin icerisindeki PointNumber degiskenine atama islemi yapmamizi saglar.
* @param	 : Bu fonksiyon icerisine integer tipinde bir parametre alir.
*/
void PointCloud::setpointNumber(int pointNumber) {
	this->pointNumber = pointNumber;
}
/**
* @brief	 : Bu fonksiyon PointCloud sinifinin icerisindeki pointNumber degiskenini dondurur.
*/

int PointCloud::getpointNumber()const {
	return pointNumber;
}
/**
* @brief	 : Bu fonksiyon iki adet PointCloud nesnesini toplar ve sonucu dondurur.
* @param	 : Bu fonksiyon icerisine PointCloud tipinde bir parametre alir.
*/
PointCloud PointCloud::operator+(PointCloud PC) {
	list<Point> P1, P2, P3;
	list<Point>::iterator iter1, iter2;

	PointCloud temp;
	P1 = this->getPoints();
	P2 = PC.getPoints();
	temp.setpointNumber(P1.size() + P2.size());
	iter1 = P1.begin();
	iter2 = P2.begin();
	for (int i = 0; i < P1.size() + P2.size(); i++)
	{
		if (i < P1.size())
		{
			P3.push_back(*iter1++);
		}
		else
		{
			P3.push_back(*iter2++);
		}
	}
	temp.setPoints(P3);
	return temp;
}
/**
* @brief	 : Bu fonksiyon bir PointCloud nesnesini baska bir PointClouda atama islemini yapar.
* @param	 : Bu fonksiyon icerisine PointCloud tipinde bir parametre alir.
*/
void PointCloud::operator=(PointCloud *PC) {
	list<Point>::iterator iter;
	for (iter = this->points.begin(); iter != this->points.end(); iter++) {
		PC->points.push_back(*iter);
	}
}