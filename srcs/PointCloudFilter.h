#pragma once
#include "PointCloud.h"
/**
* @file					PointCloudFilter.h
* @author				Gokhan Samet Albayrak --> e-mail: gokhanalbayrak43@gmail.com 
* @date					3 Ocak 2020 Cuma
* @brief				Bu kod parcacigi kullanilacak olan uye fonksiyonlari  ve uyeleri tanimlar.
*/
class PointCloudFilter
{
public:
	PointCloudFilter();
	~PointCloudFilter();
	virtual void filter(PointCloud&)=0;
};

