#include "Point.h"
#include "PointCloud.h"
#include<iostream>
#include<list>
#include<iterator>
using namespace std;
/**
* @file		: PointCloudTEST.cpp
* @Author	: Muzaffer Arda Uslu (usluarda58@gmail.com)
* @date		: 10 Aralik 2019, Sali
* @brief	: Bu kod parcacigi olusturulan PointCloud sinifinin dogru calisip calismadigini kontrol etmek amaciyla yazilmistir.
*/
int main() {
	PointCloud PC1, PC2, temp;
	Point *P1, *P2, *tempPoint;
	list<Point> P3, P4, _tempPoint;
	list<Point>::iterator iter;

	PC1.setpointNumber(1);
	PC2.setpointNumber(1);

	P1 = new Point[PC1.getpointNumber()];
	P2 = new Point[PC2.getpointNumber()];

	P1->setX(2);
	P1->setY(2);
	P1->setZ(2);

	P3.push_back(*P1);

	iter = P3.begin();
	cout << "P1-> " << iter->getX() << " " << iter->getY() << " " << iter->getZ() << endl;

	P2->setX(5);
	P2->setY(5);
	P2->setZ(5);

	P4.push_back(*P2);

	iter = P4.begin();
	cout <<"P2-> " << iter->getX() << " " << iter->getY() << " " << iter->getZ() << endl;


	PC1.setPoints(P3);
	PC2.setPoints(P4);

	temp = PC1 + PC2;
	
	_tempPoint = temp.getPoints();
	
	cout << "tempPoint" << endl;
	for (iter = _tempPoint.begin(); iter != _tempPoint.end(); iter++)
		cout << iter->getX() << " " << iter->getY() << " " << iter->getZ() << endl;

	system("pause");
}