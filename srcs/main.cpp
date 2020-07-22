#include"DepthCamera.h"
#include "PointCloudInterface.h"
#include<iostream>
#include<list>
using namespace std;
/**
* @file		: TEST.cpp
* @Author	: Muzaffer Arda Uslu (usluarda58@gmail.com)
* @date		: 30 Aralik 2019, Pazartesi
* @brief	: Bu kod parcaciginda oncelikle tum siniflardan bir veya birden fazla nesne olusturuldu ve hedeflenen ciktinin dogru bir sekilde olmasi icin
*			  sirasiyla her nesnenin gerekli olan fonksiyonu cagirildi ve gerekli islemler yaptirildi.
*/
int main(int argc, char *argv[]) {
	
	DepthCamera DC1, DC2;
	//DepthCamera *DC = new DepthCamera[argc - 1];
	PointCloudRecorder PCR;
	PointCloudInterface PCI;

	if (argv[1] == NULL)
	{
		exit(0);
	}
	string str1 = argv[1], str2 = argv[2];
	//for (int i = 1; i < argc; i++) {
	//	DC[i - 1].setfileName(argv[i]);
	//	PCI.addGenerator(&DC[i - 1]);
	//}

	DC1.setfileName(str1);
	DC2.setfileName(str2);

	PCI.addGenerator(&DC1);
	PCI.addGenerator(&DC2);
	PCI.setRecorder(&PCR);
	PCI.generate();
	PCI.record();

	system("pause");
}