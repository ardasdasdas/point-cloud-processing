/**
* @file   PointCloudRecorderTEST.h
* @author :	Pinar Kizilarslan (pinarkzlarslan@gmail.com)
* @date :	December, 2019
* @brief :	PointCloudRecorder sinifinin test islemidir.
*/
#include "DepthCamera.h"
#include "Point.h"
#include "PointCloud.h"
#include "PointCloudRecorder.h"
#include "RadiusOutlierFilter.h"
#include<fstream>
#include<iostream>
#include<string>
using namespace std;
int main() {
	PointCloudRecorder PLC;
	PointCloud PC;
	DepthCamera DC;
	string str1, str2;
	RadiusOutlierFilter ROF;

	cout << "Enter Camera Name: ";
	cin >> str1;
	DC.setfileName(str1);

	cout << "Enter the filename you want to save: ";
	cin >> str2;
	PLC.setfileName(str2);

	PC = DC.capture();
	ROF.filter(PC);
	PLC.save(PC);

	system("pause");
}