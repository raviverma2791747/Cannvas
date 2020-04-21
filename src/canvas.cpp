
#include "canvas.h"
#include<iostream>
#include<math.h>
//Using Win32 API
//Please  link libgdi32.a in linker settings for this below header file to work
#define _WIN32_WINNT 0x0500
#include<windows.h>


using namespace paint;

/*Abstract class shape*/
Shape::Shape() :
    position{0,0},pixel(nullptr),dimension{0,0},base{0,0,0},border{0,0,0}
{

}

Shape::Shape(Position position,Dimension dimension,Rgb base,Rgb border):
    position(position),dimension(dimension),base(base),border(border)
{

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


/*Derived class rectangle*/

Rectangle::Rectangle() :
    Shape()
{

}

Rectangle::Rectangle(Position position,Dimension dimension,Rgb base,Rgb border):
    Shape(position,dimension,base,border)
{
    this->pixel = new Rgb[this->dimension.Height*this->dimension.Width];
    for(int i=0; i<this->dimension.Height; i++)
    {
        for(int j=0; j<this->dimension.Width; j++)
        {
            if((i  == 0 || i == 1 )|| (i  == this->dimension.Height - 1 || i == this->dimension.Height - 2 ))
            {
                this->pixel[i*this->dimension.Width + j ] = this->border;
            }
            else if(( j == 0 || j== 1)||(j  == this->dimension.Width - 1 || j == this->dimension.Width - 2 ))
            {
                this->pixel[i*this->dimension.Width + j ] = this->border;
            }
            else
            {
                this->pixel[i*this->dimension.Width + j ] = this->base;
            }
        }
    }
}

Rectangle::~Rectangle()
{

}

void  Rectangle::Draw()
{
    render(*this);
}


/*Derieved class Ellipse*/

Ellipse::Ellipse() : Shape()
{


}

Ellipse::Ellipse(Position position,Dimension dimension,Rgb base,Rgb border) : Shape(position,dimension,base,border)
{
    this->pixel = new Rgb[this->dimension.Height*this->dimension.Width];
    const int centerx = this->dimension.Width/2;
    const int centery = this->dimension.Height/2;
    for(int i=0; i<this->dimension.Height; i++)
    {
        for(int j= 0; j<this->dimension.Width; j++)
        {
            if(pow(( j - centerx),2)/pow(centerx,2) + pow(( i - centery),2)/pow(centery,2)<0.85)
            {
                this->pixel[this->dimension.Width*i+j] = base;
            }
            else if(pow(( j - centerx),2)/pow(centerx,2) + pow(( i - centery),2)/pow(centery,2) <= 1)
            {
                this->pixel[this->dimension.Width*i+j] = border;
            }
            else
            {
                this->pixel[this->dimension.Width*i+j] = Rgb{255,255,255};
            }

        }
    }
}

Ellipse::~Ellipse()
{


}

void  Ellipse::Draw()
{
    const int centerx = this->dimension.Width/2;
    const int centery = this->dimension.Height/2;
    for(int i=0; i<this->dimension.Height; i++)
    {
        for(int j= 0; j<this->dimension.Width; j++)
        {
            if(pow(( j - centerx),2)/pow(centerx,2) + pow(( i - centery),2)/pow(centery,2)<=1)
            {
                continue;
            }
            else
            {
                this->pixel[this->dimension.Width*i+j] = Rgb{0,0,0};
            }

        }
    }
    render(*this);
}


/*Derived class Square*/
Square::Square() : Rectangle()
{

}

Square::Square(Position position,int Side,Rgb base,Rgb border) : Rectangle(position,Dimension{Side,Side},base,border)
{

}

Square::~Square()
{

}

void  Square::Draw()
{
    render(*this);
}

/*Derived class Circle*/
Circle:: Circle() : Ellipse()
{

}

Circle::Circle(Position position,int Radius,Rgb base,Rgb border):
    Ellipse(position,Dimension{2*Radius,2*Radius},base,border)
{

}


Circle:: ~Circle()
{

}

void Circle::Draw()
{
    const int centerx = this->dimension.Width/2;
    const int centery = this->dimension.Height/2;
    for(int i=0; i<this->dimension.Height; i++)
    {
        for(int j= 0; j<this->dimension.Width; j++)
        {
            if(pow(( j - centerx),2)/pow(centerx,2) + pow(( i - centery),2)/pow(centery,2)<=1)
            {
                continue;
            }
            else
            {
                this->pixel[this->dimension.Width*i+j] = Rgb{0,0,0};
            }

        }
    }

    render(*this);
}


/*Canvas class*/
Canvas::Canvas() :  Pixel(nullptr),max_Pixel(0),base{0,0,0},Resolution{0,0}
{

}

Canvas::Canvas(Dimension Resolution,Rgb base)
{
    Canvas::base = base;
    Canvas::Resolution = Resolution;
    max_Pixel = Resolution.Height * Resolution.Width;
    Pixel = new Rgb[max_Pixel];
    for(int i=0; i<max_Pixel; i++)
    {
        Pixel[i] =  base;
    }

}

Canvas::~Canvas()
{
    if(Pixel != nullptr)
    {
        for(int i=0; i<max_Pixel; i++)
        {
            delete (Pixel+i);
        }

    }
}

Dimension Canvas::resolution()
{
    return Resolution;
}


void Canvas::FillRectangle(Rectangle rect)
{
    if(rect.Position_().X > this->Resolution.Width || rect.Position_().Y > this->Resolution.Height)
    {
        std::cout<<"ERROR : Rectangle Out of Range!\n";
    }
    else
    {
        for(int i=0; i<rect.Resolution().Height; i++)
        {
            for(int j=0; j<rect.Resolution().Width; j++)
            {
                Pixel[ rect.Position_().Y*Canvas::Resolution.Width + j +  rect.Position_().X + i*Canvas::Resolution.Width  ] = rect[i*rect.Resolution().Width + j];
            }
        }
    }
}


void Canvas::FillEllipse(Ellipse ellip)
{
    if(ellip.Position_().X > this->Resolution.Width || ellip.Position_().Y > this->Resolution.Height)
    {
        std::cout<<"ERROR : Ellipse Out of Range!\n";
    }
    else
    {
        for(int i=0; i<ellip.Resolution().Height; i++)
        {
            for(int j=0; j<ellip.Resolution().Width; j++)
            {
                Pixel[ ellip.Position_().Y*Canvas::Resolution.Width + j + ellip.Position_().X + i*Canvas::Resolution.Width  ] = ellip[i*ellip.Resolution().Width + j];
            }
        }
    }
}

Rgb  Canvas::operator[](int index)
{
    return Pixel[index];
}

void Canvas::Clear()
{
    for(int i=0; i<max_Pixel; i++)
    {
        Pixel[i]= base;
    }
}

void Canvas::FillSquare(Square sqr)
{
    if(sqr.Position_().X > this->Resolution.Width || sqr.Position_().Y > this->Resolution.Height)
    {
        std::cout<<"ERROR : Square Out of Range!\n";
    }
    else
    {
        for(int i=0; i<sqr.Resolution().Height; i++)
        {
            for(int j=0; j<sqr.Resolution().Width; j++)
            {
                Pixel[ sqr.Position_().Y*Canvas::Resolution.Width + j + sqr.Position_().X + i*Canvas::Resolution.Width  ] = sqr[i*sqr.Resolution().Width + j];
            }
        }
    }
}

void Canvas::FillCircle(Circle circ)
{
    if(circ.Position_().X > this->Resolution.Width || circ.Position_().Y > this->Resolution.Height)
    {
        std::cout<<"ERROR : Circle Out of Range!\n";
    }
    else
    {
        for(int i=0; i<circ.Resolution().Height; i++)
        {
            for(int j=0; j<circ.Resolution().Width; j++)
            {
                Pixel[ circ.Position_().Y*Canvas::Resolution.Width + j + circ.Position_().X + i*Canvas::Resolution.Width  ] = circ[i*circ.Resolution().Width + j];
            }
        }
    }
}



/*Render or Paint function on screen*/
void paint::render(Canvas& c)
{
    HWND myconsole = GetConsoleWindow();
    HDC mydc = GetDC(myconsole);
    const int height  = c.resolution().Height;
    const int width  = c.resolution().Width;
    for(int i=0; i<height/8; i++)
    {
        for(int j=0; j<width; j++)
        {

            SetPixel(mydc,j,i,RGB(c[i*width + j ].Red,c[i*width + j ].Green,c[i*width + j ].Blue));
            SetPixel(mydc,j,i + height/8*1,RGB(c[height/8*1*width + i*width + j ].Red,c[height/8*1*width +i*width + j ].Green,c[height/8*1*width +i*width + j ].Blue));
            SetPixel(mydc,j,i + height/8*2,RGB(c[height/8*2*width + i*width + j ].Red,c[height/8*2*width +i*width + j ].Green,c[height/8*2*width +i*width + j ].Blue));
            SetPixel(mydc,j,i + height/8*3,RGB(c[height/8*3*width + i*width + j ].Red,c[height/8*3*width +i*width + j ].Green,c[height/8*3*width +i*width + j ].Blue));
            SetPixel(mydc,j,i + height/8*4,RGB(c[height/8*4*width + i*width + j ].Red,c[height/8*4*width +i*width + j ].Green,c[height/8*4*width +i*width + j ].Blue));
            SetPixel(mydc,j,i + height/8*5,RGB(c[height/8*5*width + i*width + j ].Red,c[height/8*5*width +i*width + j ].Green,c[height/8*5*width +i*width + j ].Blue));
            SetPixel(mydc,j,i + height/8*6,RGB(c[height/8*6*width + i*width + j ].Red,c[height/8*6*width +i*width + j ].Green,c[height/8*6*width +i*width + j ].Blue));
            SetPixel(mydc,j,i + height/8*7,RGB(c[height/8*7*width + i*width + j ].Red,c[height/8*7*width +i*width + j ].Green,c[height/8*7*width +i*width + j ].Blue));
        }
    }
    ReleaseDC(myconsole, mydc);
}

void paint::render(Rectangle r)
{
    HWND myconsole = GetConsoleWindow();
    HDC mydc = GetDC(myconsole);
    const int height  = r.Resolution().Height;
    const int width  = r.Resolution().Width;
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            SetPixel(mydc,j+600,i+200,RGB(r[i*width + j ].Red,r[i*width + j ].Green,r[i*width + j ].Blue));
        }
    }
    ReleaseDC(myconsole, mydc);
}

void paint::render(Ellipse e)
{
    HWND myconsole = GetConsoleWindow();
    HDC mydc = GetDC(myconsole);
    const int height  = e.Resolution().Height;
    const int width  = e.Resolution().Width;
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            SetPixel(mydc,j+600,i+200,RGB(e[i*width + j ].Red,e[i*width + j ].Green,e[i*width + j ].Blue));
        }
    }
    ReleaseDC(myconsole, mydc);
}
