/**
*	@file	:	Transform.cpp
*	@author	:	Berkay Gonenc Goksal->berkaygg@hotmail.com | Muzaffer Arda Uslu -> usluarda58@gmail.com
*	@date	:	29.12.2019
*	@brief	:	Bu kod parcacigi Transform classinin fonksiyonlarini aciklar.
*/
#include "Transform.h"
#include <math.h>
#include<iostream>
using namespace std;
double rotationmatrix[3][3];
/**
*	@brief	:	Constructor fonksiyonu.
*/
Transform::Transform()
{
}
/**
*	@brief	:	Destructor fonksiyonu.
*/
Transform::~Transform()
{
}
/**
*	@brief			:	Transform nesnesi icin acilari duzenleyen bir fonksiyon.
*	@param	angle1	:	Birinci aci.
*	@param	angle2	:	Ikinci aci.
*	@param	angle3	:	Ucuncu aci.
*/
void Transform::setAngles(double angle1,double angle2,double angle3)
{
	using namespace Eigen;
	angles(0) = angle1;
	angles(1) = angle2;
	angles(2) = angle3;
}
/**
*	@brief			:	Transform nesnesi icin trans dizisi icerisine koordinant sisteminin orijininin base koordinant 
*						sisteminin orijinine olan uzakligini verilen degerler ile düzenleyen bir fonksiyon.
*	@param	transx	:	Birinci aci.
*	@param	transy	:	Ikinci aci.
*	@param	transz	:	Ucuncu aci.
*/
void Transform::setTrans(double transx,double transy,double transz) 
{
	using namespace Eigen;
	trans(0) = transx;
	trans(1) = transy;
	trans(2) = transz;
}
/**
*	@brief			:	Acilarimizi elde ettigimiz fonksiyon.
*	@return			:	Angles dizisi. Yani aci verilerimiz.
*/
double *Transform::getAngles()
{
	double *angles = new double[3];
	angles[0] = this->angles(0);
	angles[1] = this->angles(1);
	angles[2] = this->angles(2);

	return angles;
}
/**
*	@brief			:	Trans dizimizdeki x y z degerini elde ettigimiz fonksiyon.
*	@return			:	Trans dizisi.
*/
double *Transform::getTrans()
{
	double *trans = new double[3];
	trans[0] = this->trans(0);
	trans[1] = this->trans(1);
	trans[2] = this->trans(2);

	return trans;
}
/**
*	@brief			:	Bu fonksiyon Transform nesnemizin icindeki aci degerlerini alarak rotasyon matrisimizi olusturuyor.
*	@param	ang[]	:	Acilarimizin icerisinde oldugu dizi.	
*/
void Transform::setRotation(double ang[])
{
	rotationmatrix[0][0] = cos(ang[2])*cos(ang[1]);
	rotationmatrix[0][1] = (cos(ang[2])*sin(ang[1])*sin(ang[0])) - (sin(ang[2])*cos(ang[0]));
	rotationmatrix[0][2] = (cos(ang[2])*sin(ang[1])*cos(ang[0])) + (sin(ang[2])*sin(ang[0]));
	rotationmatrix[1][0] = sin(ang[2])*cos(ang[1]);
	rotationmatrix[1][1] = (sin(ang[2])*sin(ang[1])*sin(ang[0])) + (cos(ang[2])*cos(ang[0]));
	rotationmatrix[1][2] = (sin(ang[2])*sin(ang[1])*cos(ang[0])) - (cos(ang[2])*sin(ang[0]));
	rotationmatrix[2][0] = -sin(ang[1]);
	rotationmatrix[2][1] = cos(ang[1])*sin(ang[0]);
	rotationmatrix[2][2] = cos(ang[1])*cos(ang[0]);
}
/**
*	@brief			:	Bu fonksiyon Transform nesnemizin icindeki aci degerlerini alarak rotasyon matrisimizi olusturuyor.
*	@param	ang		:	Acilarimizin icerisinde oldugu dizi.
*/
void Transform::setRotation(Eigen::Vector3d ang)
{
	rotationmatrix[0][0] = cos(ang(2))*cos(ang(1));
	rotationmatrix[0][1] = (cos(ang(2))*sin(ang(1))*sin(ang(0))) - (sin(ang(2))*cos(ang(0)));
	rotationmatrix[0][2] = (cos(ang(2))*sin(ang(1))*cos(ang(0))) + (sin(ang(2))*sin(ang(0)));
	rotationmatrix[1][0] = sin(ang(2))*cos(ang(1));
	rotationmatrix[1][1] = (sin(ang(2))*sin(ang(1)*sin(ang(0))) + (cos(ang(2))*cos(ang(0))));
	rotationmatrix[1][2] = (sin(ang(2))*sin(ang(1))*cos(ang(0))) - (cos(ang(2))*sin(ang(0)));
	rotationmatrix[2][0] = -sin(ang(1));
	rotationmatrix[2][1] = cos(ang(1))*sin(ang(0));
	rotationmatrix[2][2] = cos(ang(1))*cos(ang(0));
}
/**
*	@brief			:	Bu fonksiyon Transform nesnemizin icindeki trans x, y, z degerlerini alarak donusum matrisimizi olusturuyor.
*	@param	tr		:	Trans x, y, z degerlerinin icerisinde oldugu dizi.
*/
void Transform::setTranslation(Eigen::Vector3d tr)
{
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			this->transMatrix(x, y) = rotationmatrix[x][y];//Donusum matrisimizin sol ust uclusu rotasyon matrisimiz oldugundan bu atamalar yapiliyor.
		}
	}
	this->transMatrix(3, 0) = 0;//Kalan degerler ataniyor.
	this->transMatrix(3, 1) = 0;
	this->transMatrix(3, 2) = 0;
	this->transMatrix(3, 3) = 1;
	this->transMatrix(0, 3) = tr(0);//Trans dizisinden x,y,z degerleri ataniyor.
	this->transMatrix(1, 3) = tr(1);
	this->transMatrix(2, 3) = tr(2);
}
/**
*	@brief			:	Bu fonksiyon Transform nesnemizin icindeki trans x, y, z degerlerini alarak donusum matrisimizi olusturuyor.
*	@param	tr[]	:	Trans x, y, z degerlerinin icerisinde oldugu dizi.
*/
void Transform::setTranslation(double tr[])
{
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			this->transMatrix(x, y) = rotationmatrix[x][y];//Donusum matrisimizin sol ust uclusu rotasyon matrisimiz oldugundan bu atamalar yapiliyor.
		}
	}
	this->transMatrix(3, 0) = 0;//Kalan degerler ataniyor.
	this->transMatrix(3, 1) = 0;
	this->transMatrix(3, 2) = 0;
	this->transMatrix(3, 3) = 1;
	this->transMatrix(0, 3) = tr[0];//Trans dizisinden x,y,z degerleri ataniyor.
	this->transMatrix(1, 3) = tr[1];
	this->transMatrix(2, 3) = tr[2];
}
/**
*	@brief			:	Trans Matrisini dondurur.
*	@return			:	Trans Matrisi.
*/
Eigen::Matrix4d Transform::getTransMatrix() {
	return transMatrix;
}
/**
*	@brief					:	TransMatrix uyemize atama islemi yapmamizi saglar.
*	@param	transMatrix		:	4x4'luk matris.
*/
void Transform::setTransMatrix(Eigen::Matrix4d transMatrix) {
	this->transMatrix = transMatrix;
}
/**
*	@brief			:	Bu fonksiyon arguman olarak bir Point alarak bu Pointi base koordinant sistemine gore x,y,z degerlerini donusturur.
*	@param	p		:	Donusturulme islemi yapilacak Point.
*	@return			:	Donusturulmus Point.
*/
list<Point> Transform::doTransform(list<Point> p)
{
	list<Point> transformedpoint;
	list<Point>::iterator iter;
	Point temp;
	Eigen::Vector4d pointb, pointa, tempMatrix;
	iter = p.begin();

	for (iter = p.begin(); iter != p.end(); iter++)
	{
		pointb(0) = iter->getX();
		pointb(1) = iter->getY();
		pointb(2) = iter->getZ();
		pointb(3) = 1;
		tempMatrix = transMatrix * pointb;
		temp.setX(tempMatrix(0));
		temp.setY(tempMatrix(1));
		temp.setZ(tempMatrix(2));

		transformedpoint.push_back(temp);
	}

	return transformedpoint;
}
/**
*	@brief			:	Bu fonksiyon arguman olarak bir PointCloud alarak bu PointCloudun icersindeki Pointleri base koordinant sistemine gore donusturur.
*	@param	pc		:	Donusturulme yapilacak PointCloud.
*	@return			:	Donusturulmus PointCloud.
*/
PointCloud Transform::doTransform(PointCloud pc)
{
	PointCloud transformedpc;
	list<Point> P;
	P = pc.getPoints();
	transformedpc.setPoints(doTransform(P));//Once donusum yapilacak PointCloudun noktalarina erisildi. Sonra bu noktalar icin donusum yapildi. Ardindan donusturulmus noktalar bir PointClouda atandý.
	
	return transformedpc;
}