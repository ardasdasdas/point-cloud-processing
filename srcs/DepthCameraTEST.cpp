#include "DepthCamera.h"
#include "Point.h"
#include "PointCloud.h"
#include<fstream>
#include<iostream>
#include<string>
#include<iterator>
#include<list>

using namespace std;
/**
* @file		: DepthCameraTEST.cpp
* @Author	: Muzaffer Arda Uslu (usluarda58@gmail.com)
* @date		: 6 Aralik 2019, Cuma
* @brief	: Bu kod parcacigi olusturulan DepthCamera sinifinin dogru calisip calismadigini kontrol etmek amaciyla yazilmistir.
*/
int main() {
	DepthCamera DC;
	string str;
	PointCloud PC;
	list<Point> P1;
	list<Point>::iterator iter;
	cout << "Dosya adi girin: ";
	cin >> str;
	DC.setfileName(str);
	PC = DC.capture();
	/*Point *P = new Point[PC.getpointNumber()];
	P = PC.getPoints();*/
	//cout << PC.getpointNumber();

	P1 = PC.getPoints();
	
	for (iter = P1.begin(); iter != P1.end(); iter++)
		cout << iter->getX() << " " << iter->getY() << " " << iter->getZ() << endl;

	system("pause");
}