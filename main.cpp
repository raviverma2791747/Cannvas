#include <iostream>
#include "include\canvas.h"
#define _WIN32_WINNT 0x0500
#include<windows.h>

using namespace std;
using namespace paint;

void render(Canvas& c)
{
    HWND myconsole = GetConsoleWindow();
    HDC mydc = GetDC(myconsole);
    const int height  = c.resolution().Height;
    const int width  = c.resolution().Width;
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {

            SetPixel(mydc,j,i,RGB(c[i*width + j ].Red,c[i*width + j ].Green,c[i*width + j ].Blue));
        }
    }
    ReleaseDC(myconsole, mydc);
}

int main()
{
    paint::Canvas c(paint::Dimension{480,720},Rgb{255,255,255});
    paint::Rectangle r(paint::Position{50,50},paint::Dimension{50,50},paint::Rgb{255,0,0},paint::Rgb{255,0,0});
    paint::Rectangle g(paint::Position{100,100},paint::Dimension{50,50},paint::Rgb{0,0,255},paint::Rgb{0,0,255});
    paint::Rectangle b(paint::Position{300,100},paint::Dimension{50,100},paint::Rgb{0,255,0},paint::Rgb{0,255,0});
    c.FillRectangle(r);
    c.FillRectangle(g);
    c.FillRectangle(b);
    render(c);
    return 0;
}
