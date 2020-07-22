/**
* @file   FilterPipe.h
* @Author Damla Dalgic  (damlabileydi@gmail.com)
* @date   December, 2019
*/
#include<vector>
#include"PointCloudFilter.h"
//!  A FilterPipe class. 
class FilterPipe {
	vector<PointCloudFilter*> filters;
public:
	//! A constructor.
	FilterPipe();
	//! A deconstructor. 
	~FilterPipe();
	void addFilter(PointCloudFilter *filter);
	void filterOut(PointCloud &pc);
};
