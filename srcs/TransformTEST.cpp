/**
*	@file	:	TransformTEST.cpp
*	@author	:	Berkay Gonenc Goksal->berkaygg@hotmail.com
*	@date	:	12.12.2019
*	@brief	:	Bu kod parcacigi Transform classinin fonksiyonlarini test eder.
*/
#include <iostream>
#include <list>
#include <iterator>
#include <Eigen/Dense>
#include"Transform.h"
using namespace std;
int main()
{
	list<Point> A, C, temp;
	Point p1, *p2 = new Point[2];
	list<Point>::iterator iter;
	Transform T;
	PointCloud D;
	Eigen::Matrix4d testMatrix;
	p1.setX(150);
	p1.setY(150);
	p1.setZ(-50);
	A.push_back(p1);
	


	D.setpointNumber(2);
	T.setAngles(0, 0, -90.0);
	T.setTrans(100, 500, 50);
	double *ang, *tr;
	ang = T.getAngles();
	tr = T.getTrans();
	//Aci degerlerimiz duzgun atandi mi diye kontrol edildi.
	for (int i = 0; i < 3; i++) {
		cout << *(ang + i) << endl;
	}
	cout << "---------------------------" << endl;
	//Trans x,y,z degerlerimiz duzgun atandi mi diye kontrol edildi.
	for (int i = 0; i < 3; i++)
	{
		cout << *(tr + i) << endl;
	}
	cout << "---------------------------" << endl;
	T.setRotation(T.getAngles());//Rotasyon matrisi olusturuldu.
	T.setTranslation(T.getTrans());//Donusum matrisi olusturuldu.
	int k = 0;
	testMatrix = T.getTransMatrix();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) {
			cout << testMatrix(i, j) << " ";//Donusum matrisi duzgun sekilde olusturuldu mu diye kontrol edildi.
		}
		cout << endl;
	}
	cout << "---------------------------" << endl;
	
	A = T.doTransform(A);//Point donusumu yapiliyor mu diye kontrol edildi.
	iter = A.begin();
	cout << "C " << iter->getX() << " " << iter->getY() << " " << iter->getZ() << endl;
	cout << "---------------------------" << endl;
	p2[0].setX(150);
	p2[0].setY(150);
	p2[0].setZ(-50);
	
	p2[1].setX(2);
	p2[1].setY(5);
	p2[1].setZ(1);
	temp.push_back(*p2);

	for (int i = 0; i < 2; i++)//PointCloud donusumu yapildi mi diye kontrol edildi
	{
		D.setPoints(temp);
		T.doTransform(D);
	}
	system("pause");
}