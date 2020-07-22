#include "PointCloudGenerator.h"
#include "Transform.h"

/**
* @file					PointCloudGenerator.cpp
* @author				Gokhan Samet Albayrak  - Pýnar Kizilarslan--> e-mail: gokhanalbayrak43@gmail.com - pinarkzlarslan@gmail.com
* @date					3 Ocak 2020 Cuma
* @brief				Bu kod parcacigi uye fonksiyonlarin islemini yapar.
*/

/*
* @brief				: Bu fonksiyon sinifin yapici fonksiyonudur.
* @see main()			: Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
PointCloudGenerator::PointCloudGenerator()
{
	filterPipe = new FilterPipe();
}
/*
* @brief				: Bu fonksiyon sinifin yikici fonksiyonudur.
* @see main()			: Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
PointCloudGenerator::~PointCloudGenerator()
{

}
/*
* @brief				: Bu fonksiyon setleme islemini yapar.
* @param FilterPipe*	: Input olarak alinan FilterPipe pointeridir.
* @see main()			: Fonksiyonun hangi amacla cagirildigini inceleyiniz.
* @return				: Herhangi bir deger dondurmemektedir.
*/
void PointCloudGenerator::setFilterPipe(FilterPipe* fp)
{
	filterPipe = fp;
}
/*
* @brief				: Bu fonksiyon setleme islemini yapar.
* @param Transform 		: Input olarak alinan Transform nesnesidir.
* @see main()			: Fonksiyonun hangi amacla cagirildigini inceleyiniz.
* @return				: Herhangi bir deger dondurmemektedir.
*/
void PointCloudGenerator::setTransform(Transform t)
{
	transform = t;
}
