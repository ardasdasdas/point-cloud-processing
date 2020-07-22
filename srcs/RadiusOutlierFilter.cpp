/**
* @file		: RadiusOutlierFilter.cpp
* @Author	: Damla Dalgic (damlabileydi@gmail.com)
* @date		: December, 2019
* @brief    : Bu kod radius degerine gore nokta bulutunda filtreleme yapar.
*/
#include "RadiusOutlierFilter.h"
#include<iostream>
using namespace std;
/**
* @brief	 : Constructor fonksiyonu.
*/
RadiusOutlierFilter::RadiusOutlierFilter()
{
	radius = 25;
}
/**
* @brief	 : Destructor fonksiyonu.
*/
RadiusOutlierFilter::~RadiusOutlierFilter()
{
}
/**
* @brief : bu kod yaricap degerini alir.
* @param radius : yaricap degerini tanimlar.
*/
void RadiusOutlierFilter::setRadius(double radius)
{
	this->radius = radius;
}
/**
* @brief : bu kod yaricap degerini dondurur.
* @return :
		  --> radius : yaricap verilerini dondurur.
*/
double RadiusOutlierFilter::getRadius() const
{
	return radius;
}
/**
* @brief : Bu kod nokta bulutunu alir ve filtrelenmis halini dondurur. Nokta bulutundaki her bir nokta icin tek tek islem yapilir. Noktaya, radius degerinden daha yakin baska bir nokta yok ise, bu nokta nokta bulutundan cikarilir.
* @param PC : PC referans olarak atanmistir.
*/
void RadiusOutlierFilter::filter(PointCloud &PC)
{
	list<Point> ptr1, ptr2;
	list<Point>::iterator iter;
	list<Point>::iterator iter2;
	int counter1 = 0;

	ptr1 = PC.getPoints();

	for (iter=ptr1.begin();iter!=ptr1.end();iter++)
	{
		for (iter2 = ptr1.begin(); iter2 != ptr1.end(); iter2++ )
		{
			if (iter->distance(*iter2) < radius && iter != iter2)
			{
				ptr2.push_back(*iter);
				counter1++;
				break;
			}
		}
	}

	PC.setpointNumber(counter1);
	PC.setPoints(ptr2);
}
