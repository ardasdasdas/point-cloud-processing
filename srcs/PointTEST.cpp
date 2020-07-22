#include<iostream>
#include"Point.h"
using namespace std;
/**
* @file		: PointCloudTEST.cpp
* @Author	: Muzaffer Arda Uslu (usluarda58@gmail.com)
* @date		: 12 Aralik 2019, Persembe
* @brief	: Bu kod parcacigi olusturulan Point sinifinin dogru calisip calismadigini kontrol etmek amaciyla yazilmistir.
*/
int main() {

	Point P1, P2;
	P1.setX(1);
	P1.setY(2);
	P1.setZ(3);

	P2.setX(4);
	P2.setY(5);
	P2.setZ(6);

	cout << "P1 x->" << P1.getX() << " y->" << P1.getY() << " z->" << P1.getZ() << endl;
	cout << "P2 x->" << P2.getX() << " y->" << P2.getY() << " z->" << P2.getZ() << endl;

	if (P1 == P2)
		cout << "Point nesneleri ayni!" << endl;
	else
		cout << "Point nesneleri ayni degil!" << endl;

	cout << "P1 ve P2 arasindaki uzaklik -> " << P1.distance(P2) << endl;

	system("pause");
}