/**
* @file   PointCloudRecorder.cpp
* @author :	Pinar Kizilarslan  (pinarkzlarslan@gmail.com)
* @date :	December, 2019
* @brief :	Kamera dosyalarindan okunan, filtrelendikten sonraki nokta bulutlarini dosyaya yazmaya yarayan .cpp uzantisidir.
*/
#include "PointCloudRecorder.h"
#include "PointCloud.h"
/**
* @brief :	Yapici fonksiyon.
*/
PointCloudRecorder::PointCloudRecorder() {
	
}
/**
* @brief :	Yikici fonksiyon.
*/
PointCloudRecorder::~PointCloudRecorder() {
	//
}
/**
* @brief :	Kaydedilecek dosya adini duzenler.
* @param fileName :	kaydedilecek dosya adi
*/
void PointCloudRecorder::setfileName(string fileName) {
	this->fileName = fileName;
}
/**
* @brief :	Kaydedilecek dosya adini gösterir.
* @return :	dosya adini dondurur
		  --> fileName: dosya adi
*/
string PointCloudRecorder::getfileName() {
	return this->fileName;
}
/**
* @brief :	Filtrelenmis nokta bulutlarini dosyaya yazar.
* @param PC :	Filtrelenmis nokta bulutu
* @return :	true false dondurur
*/
bool PointCloudRecorder::save(const PointCloud &PC) {

	int size = PC.getpointNumber();
	ofstream recordFile;
	list<Point> P;
	P = PC.getPoints();
	recordFile.open(fileName + ".txt", ios::out | ios::app);
	list<Point>::iterator iter;

	if (recordFile.is_open()) {
		cout << "The file was opened. " << endl;
		for (iter = P.begin(); iter != P.end(); iter++) 
			recordFile << iter->getX() << " " << iter->getY() << " " << iter->getZ() << endl;
		return true;
	}
	else {
		cout << "Error opening file. " << endl;
		return false;
	}
	recordFile.close();
}