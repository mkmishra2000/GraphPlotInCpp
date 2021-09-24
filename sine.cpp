#include "pbPlots.hpp"
#include "supportLib.hpp"
#include <iostream> 
#include <vector> 
#include <math.h>

#define m_pi 3.141

using namespace std;

void grapghPlot(vector<double> x_axis, vector<double> y_axis)
{

    RGBABitmapImageReference *imageRef = CreateRGBABitmapImageReference();

    DrawScatterPlot(imageRef, 600, 400, &x_axis, &y_axis);
	

	vector<double> *pngData = ConvertToPNG(imageRef->image);
	

	WriteToFile(pngData, "OutputImages/plot2.png");
	

	DeleteImage(imageRef->image);

}

int main()
{
    
    vector<double> x_axis;
    vector<double> y_axis;

    double p=0;

    int i =0;
    for(i =0; i<100 ; i++){
        
        p = -(2*m_pi)+ (i*0.10);
        x_axis.insert(x_axis.end(), p);
    }


    for(int i =0; i<x_axis.size(); i++){
        y_axis.insert(y_axis.end(), sin(x_axis[i]));
    }

    grapghPlot(x_axis, y_axis);
    

    return 0;
}