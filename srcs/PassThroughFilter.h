#pragma once
#include "PointCloud.h"
#include "PointCloudFilter.h"
#include <string>
/**
* @file					PassThroughFilter.h
* @author				Gokhan Samet Albayrak --> e-mail: gokhanalbayrak43@gmail.com
* @date					13 Ekim 2019 Cuma
* @brief				Bu kod parcacigi filtremelemede kullanilacak olan uye fonksiyonlari tanimlar.
*/
using namespace std;
class PassThroughFilter:public PointCloudFilter
{
private:
	double upperLimitX, lowerLimitX;
	double upperLimitY, lowerLimitY;
	double upperLimitZ, lowerLimitZ;
public:
	//! A constructor. 
	PassThroughFilter();
	//! A destructor. 
	~PassThroughFilter();
	//! A sample function. 
	void filter(PointCloud&);
	//! A sample function. 

	void set_ux(double);
	void set_uy(double);
	void set_uz(double);
	void set_lx(double);
	void set_ly(double);
	void set_lz(double);

	double get_ux();
	double get_uy();
	double get_uz();
	double get_lx();
	double get_ly();
	double get_lz();

};

