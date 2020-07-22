/**
* @file		: DepthCamera.cpp
* @Author	: Muzaffer Arda Uslu (usluarda58@gmail.com)
* @date		: 6 Aralik 2019, Cuma
*/
#include "DepthCamera.h"
#define PI 3.14159265

using namespace std;
/**
* @brief	 : Constructor fonksiyonu.
*/
DepthCamera::DepthCamera()
{
}
/**
* @brief	 : Destructor fonksiyonu.
*/
DepthCamera::~DepthCamera()
{
}
/**
* @brief	 : Bu fonksiyon DepthCamera sinifinin icerisindeki setfileName degiskenine atama islemi yapmamizi saglar.
* @param	 : Bu fonksiyon icerisine string tipinde bir parametre alir.
*/
void DepthCamera::setfileName(string fileName)  {
	this->fileName = fileName;
}
/**
* @brief	 : Bu fonksiyon DepthCamera sinifinin icerisindeki setfileName degiskenini dondurur.
*/
string DepthCamera::getfileName()const {
	return this->fileName;
}
/**
* @brief	 : Bu fonksiyon camera(sayi).txt dosyalarinin icerisindeki noktalari okur ve bir Point listesinin icerisine atar.
*			 Noktalari atadigi Point listesi de bir PointCloud nesnesinin icerisine atar ve o PointCloud nesnesini dondurur.
*/
PointCloud DepthCamera::capture() {
	ifstream read_file;
	PointCloud PC;
	Point P;
	list<Point> P1;
	string str = this->fileName;

	read_file.open(str, ios::in);
	int counter = 0;
	double tmp;


	while (!read_file.eof())
	{
		read_file >> tmp;
		P.setX(tmp);
		read_file >> tmp;
		P.setY(tmp);
		read_file >> tmp;
		P.setZ(tmp);
		counter++;
		P1.push_back(P);
	}
	PC.setPoints(P1);
	PC.setpointNumber(counter);
	read_file.close();
	return PC;
}
/**
* @brief	 : Bu fonksiyon camera(sayi).txt dosyalarinin icerisindeki noktalari okur ve bir Point nesnesinin icerisine atar. Daha sonra filtrelerden gecirir, transform eder ve
*			  yeni degerleri PointCloud nesnesinin icerisine atar ve o PointCloud nesnesini dondurur.
*/
PointCloud DepthCamera::captureFor() {
	int counter = 0;
	ifstream read_file;
	PointCloud PC;
	Point P;
	list<Point> P1, _P1, _P2;
	string str = this->fileName;
	FilterPipe FP;
	RadiusOutlierFilter ROF;
	PassThroughFilter PTF;
	Transform T;
	list<Point>::iterator iter1, iter2;

	FP.addFilter(&ROF);
	
	read_file.open(str, ios::in);

	double tmp;

	while (!read_file.eof())
	{
		read_file >> tmp;
		P.setX(tmp);
		read_file >> tmp;
		P.setY(tmp);
		read_file >> tmp;
		P.setZ(tmp);
		counter++;
		P1.push_back(P);
	}
	list<Point> temp;
	PC.setpointNumber(counter);
	PC.setPoints(P1);

	if (fileName == "camera1.txt") {
	
		FP.addFilter(&PTF);
		FP.filterOut(PC);

		T.setAngles(0, 0, -90.0*PI/180);
		T.setTrans(100, 500, 50);
		T.setRotation(T.getAngles());
		T.setTranslation(T.getTrans());
	}
	else if (fileName == "camera2.txt") {
		PTF.set_ux(500);
		PTF.set_uy(500);

		FP.addFilter(&PTF);
		FP.filterOut(PC);

		T.setAngles(0, 0, 90.0*PI/180);
		T.setTrans(550, 150, 50);
		T.setRotation(T.getAngles());
		T.setTranslation(T.getTrans());
	}
	P1 = PC.getPoints();
	
	PC = T.doTransform(PC);

	PC.setpointNumber(PC.getpointNumber());

	read_file.close();
	return PC;
}