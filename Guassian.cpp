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

    double xsa[] = {20.1, 7.1, 16.1, 14.9, 16.7, 8.8, 9.7, 10.3, 22, 16.2, 12.1, 10.3, 14.5, 12.4, 9.6, 12.2, 10.8, 14.7, 19.7, 11.2, 10.1, 11, 12.2, 9.2, 23.5, 9.4, 15.3, 9.6, 11.1, 5.3, 7.8, 25.3, 16.5, 12.6, 12, 11.5, 17.1, 11.2, 12.2, 10.6, 19.9, 14.5, 15.5, 17.4, 8.4, 10.3, 10.2, 12.5, 16.7, 8.5, 12.2};
	vector<double> xs(xsa, xsa+sizeof(xsa)/sizeof(double));
	double ysa[] = {31.5, 18.9, 35, 31.6, 22.6, 26.2, 14.1, 24.7, 44.8, 23.2, 31.4, 17.7, 18.4, 23.4, 22.6, 16.4, 21.4, 26.5, 31.7, 11.9, 20, 12.5, 18, 14.2, 37.6, 22.2, 17.8, 18.3, 28, 8.1, 14.7, 37.8, 15.7, 28.6, 11.7, 20.1, 30.1, 18.2, 17.2, 19.6, 29.2, 17.3, 28.2, 38.2, 17.8, 10.4, 19, 16.8, 21.5, 15.9, 17.7};
	vector<double> ys(ysa, ysa+sizeof(ysa)/sizeof(double));

    ScatterPlotSeries *series = GetDefaultScatterPlotSeriesSettings();
	series->xs = &x_axis;
	series->ys = &y_axis;
	series->linearInterpolation = true;
	series->pointType = toVector(L"crosses");
    series->lineType = toVector(L"solid");
	series->lineThickness = 3;
	series->color = CreateRGBColor(0.8, 0.5, 0.3);


	ScatterPlotSettings *settings = GetDefaultScatterPlotSettings();
	settings->width = 1200;
	settings->height = 800;
	settings->autoBoundaries = true;
	settings->autoPadding = true;
	settings->title = toVector(L"Gaussian function");
	settings->xLabel = toVector(L"X axis");
	settings->yLabel = toVector(L"Y axis");
	settings->scatterPlotSeries->push_back(series);


	DrawScatterPlotFromSettings(imageRef, settings);
	

	vector<double> *pngData = ConvertToPNG(imageRef->image);
	

	WriteToFile(pngData, "OutputImages/Gaussian.png");
	

	DeleteImage(imageRef->image);

}

int main()
{
    cout <<"... Gaussian world ..."<< endl;
    double mu, var;

    cout <<"Enter the mean value ..."<< endl;
    cin>>mu;

    cout <<"Enter the variance value ..."<< endl;
    cin>>var;

    vector<double> x_axis;
    vector<double> y_axis;

    double p=0;
    double q=0;

    int i =0;
    for(i =0; i<800*var; i++){
        
        p = (mu-(4*var))+ (i*0.01);
        x_axis.insert(x_axis.end(), p);

    }

    vector<double> A;
    vector<double> B;

    for(i=0; i<x_axis.size(); i++){
        p = 1/sqrt(2*m_pi*var);
        q = pow((x_axis[i]-mu), 2.0)/(2*var);
        A.insert(A.end(), p);
        B.insert(B.end(), q);
    }


    for(int i =0; i<x_axis.size(); i++){
        y_axis.insert(y_axis.end(), A[i]*exp(-1*B[i]));
    }

    

    grapghPlot(x_axis, y_axis);
    

    return 0;
}