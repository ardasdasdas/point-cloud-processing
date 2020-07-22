/**
* @file   RadiusOutlierFilter.h
* @Author Damla Dalgic  (damlabileydi@gmail.com)
* @date   December, 2019
*/
#include "PointCloud.h"
#include "Point.h"
#include"PointCloudFilter.h"
#include<list>
#include<iterator>
//!  A RadiusOutlierFilter class. 
class RadiusOutlierFilter:public PointCloudFilter
{
private:
	double radius;
public:
	//! A constructor. 
	RadiusOutlierFilter();
	//! A deconstructor. 
	~RadiusOutlierFilter();
	void setRadius(double);
	double getRadius() const;
	void filter(PointCloud& PC);
};

