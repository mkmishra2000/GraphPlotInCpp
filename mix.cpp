#include "pbPlots.hpp"
#include "supportLib.hpp"
#include <iostream> 
#include <vector> 
#include <math.h>

#define m_pi 3.141

using namespace std;

void grapghPlot(vector<double> x1_axis, vector<double> y1_axis, vector<double> x2_axis, vector<double> y2_axis)
{

    RGBABitmapImageReference *imageRef = CreateRGBABitmapImageReference();


    ScatterPlotSeries *series = GetDefaultScatterPlotSeriesSettings();
	series->xs = &x1_axis;
	series->ys = &y1_axis;
	series->linearInterpolation = true;
	series->pointType = toVector(L"crosses");
    series->lineType = toVector(L"solid");
	series->lineThickness = 3;
	series->color = CreateRGBColor(0.8, 0.5, 0.3);

    ScatterPlotSeries *series2 = GetDefaultScatterPlotSeriesSettings();
	series2->xs = &x2_axis;
	series2->ys = &y2_axis;
	series2->linearInterpolation = true;
	series2->pointType = toVector(L"crosses");
    series2->lineType = toVector(L"solid");
	series2->lineThickness = 3;
	series2->color = CreateRGBColor(0.3, 0.5, 0.3);



	ScatterPlotSettings *settings = GetDefaultScatterPlotSettings();
	settings->width = 1200;
	settings->height = 800;
	settings->autoBoundaries = true;
	settings->autoPadding = true;
	settings->title = toVector(L"Gaussian functions");
	settings->xLabel = toVector(L"X axis");
	settings->yLabel = toVector(L"Y axis");
	settings->scatterPlotSeries->push_back(series);
    settings->scatterPlotSeries->push_back(series2);


	DrawScatterPlotFromSettings(imageRef, settings);
	

	vector<double> *pngData = ConvertToPNG(imageRef->image);
	

	WriteToFile(pngData, "OutputImages/mix.png");

	

	DeleteImage(imageRef->image);

}

int main()
{
    cout <<"... Gaussian world ..."<< endl;
    double mu1, var1, mu2, var2, var;

    cout <<"Enter the mean value ..."<< endl;
    cin>>mu1;

    cout <<"Enter the variance value ..."<< endl;
    cin>>var1;
    

    cout <<"Enter the mean value ..."<< endl;
    cin>>mu2;

    cout <<"Enter the variance value ..."<< endl;
    cin>>var2;

    var = (var1+var2)/2;

    vector<double> x1_axis;
    vector<double> y1_axis;
    vector<double> x2_axis;
    vector<double> y2_axis;

    double p=0;
    double q=0;

    int i =0;
    for(i =0; i<800*var; i++){
        
        p = (mu1-(4*var))+ (i*0.01);
        x1_axis.insert(x1_axis.end(), p);

    }

    for(i =0; i<800*var; i++){
        
        p = (mu2-(4*var))+ (i*0.01);
        x2_axis.insert(x2_axis.end(), p);

    }


    vector<double> A;
    vector<double> B;
    vector<double> C;
    vector<double> D;

    for(i=0; i<x1_axis.size(); i++){
        p = 1/sqrt(2*m_pi*var1);
        q = pow((x1_axis[i]-mu1), 2.0)/(2*var1);
        A.insert(A.end(), p);
        B.insert(B.end(), q);
    }

     for(i=0; i<x2_axis.size(); i++){
        p = 1/sqrt(2*m_pi*var2);
        q = pow((x2_axis[i]-mu2), 2.0)/(2*var2);
        C.insert(C.end(), p);
        D.insert(D.end(), q);
    }


    for(int i =0; i<x1_axis.size(); i++){
        y1_axis.insert(y1_axis.end(), A[i]*exp(-1*B[i]));
    }

    for(int i =0; i<x2_axis.size(); i++){
        y2_axis.insert(y2_axis.end(), C[i]*exp(-1*D[i]));
    }

    

    grapghPlot(x1_axis, y1_axis, x2_axis, y2_axis);
    

    return 0;
}