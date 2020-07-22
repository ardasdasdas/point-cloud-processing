/**
* @file		: PointCloud.h
* @Author	: Muzaffer Arda Uslu (usluarda58@gmail.com)
* @date		: 5 Aralik 2019, Persembe
*/
#pragma once
#include "Point.h"
#include<list>
#include<iterator>

using namespace std;
//PointCLoud sinifi
class PointCloud
{
private:
	int pointNumber; 
	list<Point> points;
public:
	PointCloud();
	~PointCloud();
	void setPoints(list<Point>);
	void setpointNumber(int);
	int getpointNumber() const;
	list<Point> getPoints() const;
	PointCloud operator+(PointCloud PC);
	void operator=(PointCloud *PC);
};