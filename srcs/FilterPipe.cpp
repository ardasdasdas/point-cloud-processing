/**
* @file		: FilterPipe.cpp
* @Author	: Damla Dalgic (damlabileydi@gmail.com)
* @date		: December, 2019
* @brief    : Bu kod filtrelerden gecmesi gereken nokta bulutunun filtreleme islemini yapan siniftir.
*/
#include"FilterPipe.h"
/**
* @brief	 : Constructor fonksiyonu.
*/
FilterPipe::FilterPipe()
{
}
/**
* @brief	 : Destructor fonksiyonu.
*/
FilterPipe::~FilterPipe()
{
}
/**
* @brief : bu kod farkli tip filtreler ya da farkli parametrelere sahip ayni tip filtreler ekler.
* @param filter : filter degerini tanimlar.
*/
void FilterPipe::addFilter(PointCloudFilter *filter)
{
	filters.push_back(filter);
}
/**
* @brief : bu kod nokta bulutunu ekleme sirasina gore filtrelerden gecirip sonuç nokta bulutunu dondurur.
* @param pc : filter degerini tanimlar.
*/
void FilterPipe::filterOut(PointCloud &pc)
{
	for (int i = 0; i < filters.size(); i++)
	{
		filters[i]->filter(pc);
	}
}