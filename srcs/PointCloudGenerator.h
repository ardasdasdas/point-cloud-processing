#pragma once
#include "Transform.h"
#include "FilterPipe.h"

/**
* @file					PointCloudGenerator.h
* @author				Gokhan Samet Albayrak  - Pýnar Kizilarslan--> e-mail: gokhanalbayrak43@gmail.com - pinarkzlarslan@gmail.com
* @date					3 Ocak 2020 Cuma
* @brief				Bu kod parcacigi kullanilacak olan uye fonksiyonlari  ve uyeleri tanimlar.
*/
class PointCloudGenerator
{
public:
	PointCloudGenerator();
	~PointCloudGenerator();

	virtual PointCloud capture() = 0;
	virtual PointCloud captureFor() = 0;
	void setFilterPipe(FilterPipe*);
	void setTransform(Transform);
private:
	Transform transform;
	FilterPipe* filterPipe;
};
