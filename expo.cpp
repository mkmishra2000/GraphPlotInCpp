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

    ScatterPlotSeries *series = GetDefaultScatterPlotSeriesSettings();
	series->xs = &x_axis;
	series->ys = &y_axis;
	series->linearInterpolation = true;
	series->pointType = toVector(L"crosses");
    series->lineType = toVector(L"solid");
	series->lineThickness = 2;
	series->color = CreateRGBColor(0.5, 0.5, 0.3);

	ScatterPlotSettings *settings = GetDefaultScatterPlotSettings();
	settings->width = 1200;
	settings->height = 800;
	settings->autoBoundaries = true;
	settings->autoPadding = true;
	settings->title = toVector(L"eponential function");
	settings->xLabel = toVector(L"X axis");
	settings->yLabel = toVector(L"Y axis");
	settings->scatterPlotSeries->push_back(series);

	DrawScatterPlotFromSettings(imageRef, settings);
	

	vector<double> *pngData = ConvertToPNG(imageRef->image);
	

	WriteToFile(pngData, "OutputImages/expoplot2.png");
	

	DeleteImage(imageRef->image);

}

int main()
{
    
    vector<double> x_axis;
    vector<double> y_axis;

    double p=0;

    int i =0;
    for(i =0; i<80; i++){
        
        p = -(4)+ (i*0.1);
        x_axis.insert(x_axis.end(), p);

    }


    for(int i =0; i<x_axis.size(); i++){
        y_axis.insert(y_axis.end(), exp(-1*x_axis[i]));
    }

    

    grapghPlot(x_axis, y_axis);
    

    return 0;
}