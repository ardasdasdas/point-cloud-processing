/**
* @file :	PointCloudInterface.cpp
* @author :	Pinar Kizilarslan - Gokhan Samet Albayrak --> e-mail: pinarkzlarslan@gmail.com - gokhanalbayrak43@gmail.com
* @date :	3 Ocak 2020 Cuma
* @brief :	Bu kod parcacigi uye fonksiyonlarin islemini yapar.
*/
#include "PointCloudInterface.h"
/**
* @brief :	Yapici fonksiyon.
*/
PointCloudInterface::PointCloudInterface() {

}
/**
* @brief :	Yikici fonksiyon.
*/
PointCloudInterface::~PointCloudInterface() {

}
/**
* @brief :	Bu fonksiyon parametre olarak aldigimizi sona ekler.
* @param generators :	generate edilecek kisim
*/
void PointCloudInterface::addGenerator(PointCloudGenerator* generators) {
	this->generators.push_back(generators);
}
/**
* @brief :	Bu fonksiyon kaydedilecek kismi duzenler.
* @param recorder :	kaydedilecek kisim
*/
void PointCloudInterface::setRecorder(PointCloudRecorder* recorder) {
	this->recorder = recorder;
}
/**
* @brief :	Bu fonksiyon uyesinde bulunan tum nesnelerden captureFor fonksiyonu caðrilarak nokta bulutlari saglar.
* @return :	true false dondurur
*/
bool PointCloudInterface::generate() {
	for (int i = 0; i < generators.size(); i++)	{
		patch = generators[i]->captureFor();
		pointCloud = pointCloud + patch;
	}
	return true;
}
/**
* @brief :Bu fonksiyon pointCloud icindeki noktalari dosyaya kaydeder.
* @return :	true false dondurur
*/
bool PointCloudInterface::record() {
	recorder->setfileName("lastPoints");
	recorder->save(pointCloud);
	return true;
}