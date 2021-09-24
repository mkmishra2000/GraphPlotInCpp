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
	series->linearInterpolation = false;
	series->pointType = toVector(L"crosses");
    series->lineType = toVector(L"dashed");
	series->lineThickness = 2;
	series->color = CreateRGBColor(0.1, 0.5, 0.3);

	ScatterPlotSettings *settings = GetDefaultScatterPlotSettings();
	settings->width = 1200;
	settings->height = 800;
	settings->autoBoundaries = true;
	settings->autoPadding = true;
	settings->title = toVector(L"Tangent function");
	settings->xLabel = toVector(L"X axis");
	settings->yLabel = toVector(L"Y axis");
	settings->scatterPlotSeries->push_back(series);

	DrawScatterPlotFromSettings(imageRef, settings);
	

	vector<double> *pngData = ConvertToPNG(imageRef->image);
	

	WriteToFile(pngData, "OutputImages/tanplot1.png");
	

	DeleteImage(imageRef->image);

}

int main()
{
    
    vector<double> x_axis;
    vector<double> x_axis2;
    vector<double> y_axis;
    vector<double> y_axis2;

    double p=0;

    int i =0;
    for(i =0; i<28; i++){
        
        p = -(0.46*m_pi)+ (i*0.1);
        x_axis.insert(x_axis.end(), p);

        p = (0.54*m_pi) + (i*0.1);
        x_axis2.insert(x_axis2.end(), p);
    }


    for(int i =0; i<x_axis.size(); i++){
        y_axis.insert(y_axis.end(), tan(x_axis[i]));
        y_axis2.insert(y_axis2.end(), tan(x_axis2[i]));
    }

    for(i =0; i<y_axis2.size(); i++){
        x_axis.insert(x_axis.end(), x_axis2[i]);
        y_axis.insert(y_axis.end(), y_axis2[i]);
    }
    

    grapghPlot(x_axis, y_axis);
    

    return 0;
}