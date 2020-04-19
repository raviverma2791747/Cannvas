
#include "canvas.h"
#include<iostream>



using namespace paint;

Shape::Shape() :
    position{0,0},pixel(nullptr),dimension{0,0},base{0,0,0},border{0,0,0}
{

}

Shape::Shape(Position position,Dimension dimension,Rgb base,Rgb border):
    position(position),pixel(nullptr),dimension(dimension),base(base),border(border)
{
    pixel = new Rgb[Shape::dimension.Height*Shape::dimension.Width];
    for(int i=0; i<Shape::dimension.Height; i++)
    {
        for(int j=0; j<Shape::dimension.Width; j++)
        {
            if(i == 0 || i == Shape::dimension.Height)
            {
                pixel[i*dimension.Width + j] = Shape::border;
            }
            else if(j == 0 || j== Shape::dimension.Width)
            {
                pixel[i*dimension.Width + j] = Shape::border;
            }
            else
            {
                pixel[i*dimension.Width + j] = Shape::base;
            }
        }
    }
}

Shape::~Shape()
{
    if(pixel != nullptr)
    {
        for(int i=0; i<dimension.Height*dimension.Width; i++)
        {
            delete (pixel + i);
        }
    }
}

Dimension Shape::Resolution()
{
    return dimension;
}

Position Shape::Position_()
{
    return position;
}

Rgb Shape::operator[](int index)
{
   return pixel[index];
}

Rectangle::Rectangle() :
    Shape()
{

}

Rectangle::Rectangle(Position position,Dimension dimension,Rgb base,Rgb border):
    Shape(position,dimension,base,border)
{

}

Rectangle::~Rectangle()
{

}



Canvas::Canvas() :  Pixel(nullptr),max_Pixel(0),base{0,0,0},Resolution{0,0}
{

}

Canvas::Canvas(Dimension Resolution,Rgb base)
{
    Canvas::base = base;
    Canvas::Resolution = Resolution;
    max_Pixel = Resolution.Height * Resolution.Width;
    Pixel = new Rgb[max_Pixel];
    for(int i=0;i<max_Pixel;i++)
    {
        Pixel[i] =  base;
    }
}

Canvas::~Canvas()
{
    if(Pixel != nullptr)
    {
        for(int i=0;i<max_Pixel;i++)
        {
            delete (Pixel+i);
        }
    }
}

Dimension Canvas::resolution()
 {
     return Resolution;
 }


void Canvas::FillRectangle(Rectangle &rect)
{
    if(rect.Position_().X > this->Resolution.Width || rect.Position_().Y > this->Resolution.Height)
    {
        std::cout<<"ERROR : Rectangle Out of Range!\n";
    }
    else
    {
        for(int i=0;i<rect.Resolution().Height;i++)
        {
            for(int j=0;j<rect.Resolution().Width;j++)
            {
                Pixel[ rect.Position_().Y*Canvas::Resolution.Width + j +  rect.Position_().X + i*Canvas::Resolution.Width  ] = rect[i*rect.Resolution().Width + j];
            }
        }
        /*
        for(int i = 0 ; i < rect.Resolution().Height ; i++ )
        {
            for(int j = 0 ; j < rect.Resolution().Width; j++ )
            {
                Pixel[rect.Position_().Y*this->Resolution.Width + rect.Position_().X  ] = rect[i*rect.Resolution().Width + j];
            }
        }
        */
    }
}


void Canvas::DrawRectangle(Rectangle &rect)
{

}

Rgb  Canvas::operator[](int index)
{
    return Pixel[index];
}

void render()
{

}

/*void render(Canvas& c)
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
*/
