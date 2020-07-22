/**
*	@file	:	Transform.h
*	@author	:	Berkay Gonenc Goksal->berkaygg@hotmail.com
*	@date	:	12.12.2019
*	@brief	:	Transform classi icin uye fonksiyonlar tanimlandi.
*/
#pragma once
#include "PointCloud.h"
#include<Eigen/Dense>
class Transform
{
private:
	
	Eigen::Vector3d angles;
	Eigen::Vector3d trans;
	Eigen::Matrix4d transMatrix;

public:
	Transform();
	~Transform();
	void setAngles(double,double,double);
	void setTrans(double,double,double);
	Eigen::Matrix4d getTransMatrix();
	void setTransMatrix(Eigen::Matrix4d);
	double *getAngles();
	double *getTrans();
	void setRotation(double ang[]);
	void setRotation(Eigen::Vector3d ang);
	void setTranslation(double tr[]);
	void setTranslation(Eigen::Vector3d tr);
	list<Point> doTransform(list<Point> p);
	PointCloud doTransform(PointCloud pc);
};

