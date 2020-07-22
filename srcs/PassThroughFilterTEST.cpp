#include "DepthCamera.h"
#include "PointCloud.h"
#include "PassThroughFilter.h"
#include<iostream>
#include<string>
#include<list>
#include<iterator>

using namespace std;
/**
* @file					PassThroughFilterTEST.cpp
* @author				Gokhan Samet Albayrak --> e-mail: gokhanalbayrak43@gmail.com
* @date					13 Ekim 2019 Cuma
* @brief				Bu kod parcacigi filtrelemenin test fonksiyonudur. Bu test fonksiyonu .txt olarak alinan dosyalardaki noktalardan uygun olmayanlari cikartir.
*/
int main() {
	PassThroughFilter pass;
	PointCloud pc1, pc2;
	DepthCamera c;
	list<Point> temp;
	list<Point>::iterator iter;

	string str = "camera1.txt";
	c.setfileName(str);
	pc1 = c.capture();
	pass.filter(pc1);

	int i = 0;
	temp = pc1.getPoints();
	cout << "\n\nFor camera1.txt" << endl << endl << endl;

	for (iter = temp.begin(); iter != temp.end(); iter++)
	{
		cout << i + 1 << " -> " << iter->getX() << " " << iter->getY() << " " << iter->getZ() << endl;
		i++;
	}

	string str2 = "camera2.txt";
	c.setfileName(str2);
	pc2 = c.capture();

	pass.set_ux(500);
	pass.set_uy(500);

	pass.filter(pc2);

	list<Point> p;

	p = pc2.getPoints();

	i = 0;
	cout << "\n\nFor camera2.txt\n\n";
	for (iter = temp.begin(); iter != temp.end(); iter++)
	{
		cout << i + 1 << " -> " << iter->getX() << " " << iter->getY() << " " << iter->getZ() << endl;
		i++;
	}
	system("pause");
}