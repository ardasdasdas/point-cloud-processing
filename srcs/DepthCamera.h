/**
* @file		: DepthCamera.h
* @Author	: Muzaffer Arda Uslu (usluarda58@gmail.com)
* @date		: 6 Aralik 2019, Cuma
*/
#pragma once
#include<iostream>
#include "Point.h"
#include "PointCloud.h"
#include "Transform.h"
#include "FilterPipe.h"
#include "PointCloudFilter.h"
#include "PassThroughFilter.h"
#include "PointCloudGenerator.h"
#include "RadiusOutlierFilter.h"
#include<fstream>
#include<iostream>
#include<string>
#include<list>
#include<iterator>
using namespace std;
//DepthCamera sinifi
class DepthCamera
	:public PointCloudGenerator
{
private:
	string fileName;
public:
	DepthCamera();
	~DepthCamera();
	void setfileName(string fileName);
	string getfileName() const;
	PointCloud capture();
	PointCloud captureFor();
};

