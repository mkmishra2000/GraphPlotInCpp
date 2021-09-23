#include "pbPlots.hpp"
#include "supportLib.hpp"
#include <iostream> 
#include <vector> 
#include <math.h>

#define m_pi 3.141

using namespace std;

int main()
{
    RGBABitmapImageReference *imageRef = CreateRGBABitmapImageReference();

    vector<double> x_axis {-3,-2.5, -2,-1.5, -1,-0.5, 0, 0.5, 1, 1.5, 2,2.5, 3};
    vector<double> y_axis;

    cout<< "X and Y defination started"<<endl;

    for(int i =0; i<x_axis.size(); i++){
        y_axis.insert(y_axis.end(), sin(x_axis[i]) );
    }

   
   

    DrawScatterPlot(imageRef, 600, 400, &x_axis, &y_axis);
	
    cout<< "PNG"<<endl; 

	vector<double> *pngData = ConvertToPNG(imageRef->image);
	
    cout<< "Write into file"<<endl;

	WriteToFile(pngData, "OutputImages/plot2.png");
	
    cout<< "Delete img"<<endl;

	DeleteImage(imageRef->image);

    cout<< "Check image"<<endl;

    return 0;
}