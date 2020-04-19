#ifndef CANVAS_H
#define CANVAS_H


namespace paint
{

struct Dimension
{
    int Height;
    int Width;
};

struct Rgb
{
    int Red;
    int Green;
    int Blue;
};

struct Position
{
    int X;
    int Y;
};


class Shape
{
public:
    Shape();
    Shape(Position position,Dimension dimension,Rgb base,Rgb border);
    virtual ~Shape();
    Dimension Resolution();
    Position Position_();
    Rgb operator[](int index);
protected:
    Position position;
    Rgb* pixel;
    Dimension dimension;
    Rgb base;
    Rgb border;
};

class Rectangle : public Shape
{
    public:
        Rectangle();
        Rectangle(Position position,Dimension dimension,Rgb base,Rgb border);
        ~Rectangle();
};


class Canvas
{
    public:
        Canvas();
        Canvas(Dimension Resolution,Rgb base);
        virtual ~Canvas();
        Dimension resolution();
        void FillRectangle(Rectangle &rect);
        void DrawRectangle(Rectangle &rect);
        Rgb  operator[](int index);

    protected:
    private:
        Rgb* Pixel;
        int  max_Pixel;
        Rgb base;
        Dimension Resolution;
};


//void render();

}
#endif // CANVAS_H
