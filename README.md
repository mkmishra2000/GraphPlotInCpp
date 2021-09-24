# GraphPlotInCpp
## How to plot various functions using cpp?

There are many ways exist for this task. But what is most efficient way in given constrain.
Here, answer of this question has given in term of simple steps.

## Steps
1. Download pbPlots.hpp, pbPlots.cpp, supportLib.cpp, and supportLip.hpp from [here](https://github.com/InductiveComputerScience/pbPlots/tree/master/Cpp)
2. For continuous plot 
'''
series->linearInterpolation = true;
'''
Check [cosin.cpp](https://github.com/mkmishra2000/GraphPlotInCpp/blob/main/cosine.cpp).
3. For discrete plot
'''
series->linearInterpolation = false;
'''
Check [tangent.cpp](https://github.com/mkmishra2000/GraphPlotInCpp/blob/main/tangent.cpp)
