#include <iostream>
#include "PointCloudFilter.h"
#include "DepthCamera.h"
#include "PassThroughFilter.h"
#include "RadiusOutlierFilter.h"
#include "Point.h"
using namespace std;
/**
* @file					FilterPipeTest.cpp
* @author				Gokhan Samet Albayrak --> e-mail: gokhanalbayrak43@gmail.com
* @date					3 Ocak 2020 Cuma
*/
int main()
{
	FilterPipe fp;
	PointCloud pc,pc2;
	list<Point> p,p2;
	DepthCamera dc;

	PointCloudFilter* pcf = new PassThroughFilter();
	PointCloudFilter* pcf2 = new RadiusOutlierFilter();

	dc.setfileName("camera1.txt");
	pc = dc.capture();
	fp.addFilter(pcf2);
	fp.addFilter(pcf);
	fp.filterOut(pc);
	p = pc.getPoints();

	list<Point>::iterator iter1, iter2;
	int i = 0;
	cout << "For Camera-1 " << endl << endl;

	for (iter1 = p.begin();iter1 != p.end();iter1++)
	{
		cout << i + 1<< " -> "<< iter1->getX() << " " << iter1->getY() << " " << iter1->getZ() << endl;
		i++;
	}

	dc.setfileName("camera2.txt");
	pc2 = dc.capture();
	fp.addFilter(pcf2);
	fp.addFilter(pcf);
	fp.filterOut(pc2);
	p2 = pc2.getPoints();

	i = 0;
	cout << "\n\nFor Camera-2 " << endl << endl;
	for (iter2 = p2.begin(); iter2 != p2.end(); iter2++)
	{
		cout << i + 1 << " -> " << iter2->getX() << " " << iter2->getY() << " " << iter2->getZ() << endl;
		i++;
	}
	system("pause");
}