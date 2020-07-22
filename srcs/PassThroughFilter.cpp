#include "PassThroughFilter.h"
#include<iostream>
#include<list>
#include<iterator>

/**
* @file					PassThroughFilter.cpp
* @author				Gokhan Samet Albayrak --> e-mail: gokhanalbayrak43@gmail.com
* @date					13 Ekim 2019 Cuma
* @brief				Bu kod parcacigi PassThroughFilter.h daki fonksiyonlarin isleyisini icerir.
*/
using namespace std;
/*
* @brief				: Bu fonksiyon filtreleme islemini yapar.
* @param PointCloud& 	: Input olarak alinan PointCloud nesnesidir.
* @see main()			: Fonksiyonun hangi amacla cagirildigini inceleyiniz.
* @return				: Herhangi bir deger dondurmemektedir.
*/
void PassThroughFilter::filter(PointCloud& pc)
{
	list<Point> ptr1, ptr2;
	list<Point>::iterator iter;

	int count = 0;

	ptr1 = pc.getPoints();

	for (iter = ptr1.begin(); iter != ptr1.end(); iter++)
	{
		if (iter->getX() >= lowerLimitX && iter->getX() <= upperLimitX && iter->getY() >= lowerLimitY && iter->getY() <= upperLimitY && iter->getZ() >= lowerLimitZ && iter->getZ() <= upperLimitZ)
		{
			ptr2.push_back(*iter);
			count++;
		}
	}
	pc.setpointNumber(count);
	pc.setPoints(ptr2);
}
/*
* @brief				: Bu fonksiyon lowerX'in atama islemini yapar.
* @param double 		: Input olarak alinan double bir parametredir.
* @see main()			: Fonksiyonun hangi amacla cagirildigini inceleyiniz.
* @return				: Herhangi bir deger dondurmemektedir.
*/
void PassThroughFilter::set_lx(double lx)
{
	lowerLimitX = lx;
}
/*
* @brief				: Bu fonksiyon lowerY'nin atama islemini yapar.
* @param double 		: Input olarak alinan double bir parametredir.
* @see main()			: Fonksiyonun hangi amacla cagirildigini inceleyiniz.
* @return				: Herhangi bir deger dondurmemektedir.
*/
void PassThroughFilter::set_ly(double ly)
{
	lowerLimitY = ly;
}
/*
* @brief				: Bu fonksiyon lowerZ'nin atama islemini yapar.
* @param double 		: Input olarak alinan double bir parametredir.
* @see main()			: Fonksiyonun hangi amacla cagirildigini inceleyiniz.
* @return				: Herhangi bir deger dondurmemektedir.
*/
void PassThroughFilter::set_lz(double lz)
{
	lowerLimitZ = lz;
}
/*
* @brief				: Bu fonksiyon upperX'in atama islemini yapar.
* @param double 		: Input olarak alinan double bir parametredir.
* @see main()			: Fonksiyonun hangi amacla cagirildigini inceleyiniz.
* @return				: Herhangi bir deger dondurmemektedir.
*/
void PassThroughFilter::set_ux(double ux)
{
	upperLimitX = ux;
}
/*
* @brief				: Bu fonksiyon upperY'nin atama islemini yapar.
* @param double 		: Input olarak alinan double bir parametredir.
* @see main()			: Fonksiyonun hangi amacla cagirildigini inceleyiniz.
* @return				: Herhangi bir deger dondurmemektedir.
*/
void PassThroughFilter::set_uy(double uy)
{
	upperLimitY = uy;
}
/*
* @brief				: Bu fonksiyon upperZ'nin atama islemini yapar.
* @param double 		: Input olarak alinan double bir parametredir.
* @see main()			: Fonksiyonun hangi amacla cagirildigini inceleyiniz.
* @return				: Herhangi bir deger dondurmemektedir.
*/
void PassThroughFilter::set_uz(double uz)
{
	upperLimitZ = uz;
}
/*
* @brief				: Bu fonksiyon lowerX'in dondurme islemini yapar.
* @see main()			: Fonksiyonun hangi amacla cagirildigini inceleyiniz.
* @return				: Double deger dondurur.
*/
double PassThroughFilter::get_lx()
{
	return lowerLimitX;
}
/*
* @brief				: Bu fonksiyon lowerY'nin dondurme islemini yapar.
* @see main()			: Fonksiyonun hangi amacla cagirildigini inceleyiniz.
* @return				: Double deger dondurur.
*/
double PassThroughFilter::get_ly()
{
	return lowerLimitY;
}
/*
* @brief				: Bu fonksiyon lowerZ'nin dondurme islemini yapar.
* @see main()			: Fonksiyonun hangi amacla cagirildigini inceleyiniz.
* @return				: Double deger dondurur.
*/
double PassThroughFilter::get_lz()
{
	return lowerLimitZ;
}
/*
* @brief				: Bu fonksiyon upperX'in dondurme islemini yapar.
* @see main()			: Fonksiyonun hangi amacla cagirildigini inceleyiniz.
* @return				: Double deger dondurur.
*/
double PassThroughFilter::get_ux()
{
	return upperLimitX;
}
/*
* @brief				: Bu fonksiyon upperY'nin dondurme islemini yapar.
* @see main()			: Fonksiyonun hangi amacla cagirildigini inceleyiniz.
* @return				: Double deger dondurur.
*/
double PassThroughFilter::get_uy()
{
	return upperLimitY;
}
/*
* @brief				: Bu fonksiyon upperZ'nin dondurme islemini yapar.
* @see main()			: Fonksiyonun hangi amacla cagirildigini inceleyiniz.
* @return				: Double deger dondurur.
*/
double PassThroughFilter::get_uz()
{
	return upperLimitZ;
}
/*
* @brief				: Bu fonksiyon yapici fonksiyondur.
* @see main()			: Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/

PassThroughFilter::PassThroughFilter()
{
	lowerLimitX = 0;
	upperLimitX = 400;
	lowerLimitY = 0;
	upperLimitY = 400;
	lowerLimitZ = -45;
	upperLimitZ = 45;	
}
/*
* @brief				: Bu fonksiyon yikici fonksiyondur.
* @see main()			: Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
PassThroughFilter::~PassThroughFilter()
{

}
