/**
* @file		: RadiusOutlierFilterTEST.cpp
* @Author	: Damla Dalgic (damlabileydi@gmail.com)
* @date		: December, 2019
* @brief    : Bu kod PROGRAMÝN test fonksiyonunu yerine getirir.
*/
#include "RadiusOutlierFilter.h"
#include "PointCloud.h"
#include "Point.h"
#include<iostream>
#include"DepthCamera.h"
using namespace std;
int main()
{
	RadiusOutlierFilter F;
	PointCloud PC;
	DepthCamera DC;;
	string str;
	int counter = 0, i = 0;
	cout << "Dosya adi girin: ";
	cin >> str;
	DC.setfileName(str);
	PC = DC.capture();

	F.filter(PC);
	
	list<Point> P;
	list<Point>::iterator iter;
	P = PC.getPoints();
	for (iter = P.begin(); iter != P.end(); iter++)
	{
		cout << i + 1 << ".  " << iter->getX() << " " << iter->getY() << " " << iter->getZ() << endl;
		counter++;
		i++;
	}
	cout << endl << counter << " points radius passed through filtering..." << endl;


	system("pause");
}