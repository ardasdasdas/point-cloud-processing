/**
* @file :	PointCloudInterface.h
* @author :	Pýnar Kizilarslan - Gokhan Samet Albayrak --> e-mail: pinarkzlarslan@gmail.com - gokhanalbayrak43@gmail.com
* @date :	3 Ocak 2020 Cuma
* @brief :	Bu kod parcacigi kullanýcýlar icin bir arayuz olusturur.
*/
#pragma once
#include"PointCloud.h"
#include"PointCloudGenerator.h"
#include"PointCloudRecorder.h"
#include<vector>
using namespace std;
class PointCloudInterface {
	PointCloud pointCloud;
	PointCloud patch;
	vector<PointCloudGenerator*> generators;
	PointCloudRecorder* recorder;
public:
	PointCloudInterface();
	~PointCloudInterface();
	void addGenerator(PointCloudGenerator*);
	void setRecorder(PointCloudRecorder*);
	bool generate();
	bool record();
};