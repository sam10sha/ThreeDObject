#include <iostream>

#include "Pixel.h"
#include "ThreeDObject.h"

using std::cout;
using std::endl;

using ThreeD::Pixel;
using ThreeD::ThreeDObject;

int main(int argc, char** argv)
{
    Pixel DefaultPixel;
    ThreeDObject<Pixel> TDObj(2, 2, 2, &DefaultPixel);
    
    Pixel Setting;
    
    Setting.R = 100;
    Setting.G = 50;
    Setting.B = 84;
    TDObj[0][0][0] = Setting;
    TDObj[0][0][1] = Setting;
    TDObj[0][1][0] = Setting;
    
    Setting.R = 100;
    Setting.G = 50;
    Setting.B = 84;
    TDObj[0][1][1] = Setting;
    TDObj[1][0][0] = Setting;
    TDObj[1][0][1] = Setting;
    
    Setting.R = 54;
    Setting.G = 163;
    Setting.B = 72;
    TDObj[1][1][0] = Setting;
    TDObj[1][1][1] = Setting;
	TDObj[2][1][1] = Setting;
	TDObj[2][5][1] = Setting;
	
	cout << "R: " << TDObj[0][1][1].R << endl;
	cout << "G: " << TDObj[0][1][1].G << endl;
	cout << "B: " << TDObj[0][1][1].B << endl;
	
	cout << "R: " << TDObj[1][1][1].R << endl;
	cout << "G: " << TDObj[1][1][1].G << endl;
	cout << "B: " << TDObj[1][1][1].B << endl;
    
    return 0;
}
