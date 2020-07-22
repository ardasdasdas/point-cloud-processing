/**
* @file   PointCloudRecorder.h
* @author :	Pinar Kizilarslan  (pinarkzlarslan@gmail.com)
* @date :	December, 2019
* @brief :	Kamera dosyalarindan okunan, filtrelendikten sonraki nokta bulutlarini dosyaya yazar.
*/
#pragma once
#include "PointCloud.h"
#include "Point.h"
#include "DepthCamera.h"
#include<iostream>
#include <fstream>
#include <string>
using namespace std;

class PointCloudRecorder {
private:
	string fileName;
public:
	PointCloudRecorder();
	~PointCloudRecorder();

	void setfileName(string fileName);
	string getfileName();
	bool save(const PointCloud &PC);
};