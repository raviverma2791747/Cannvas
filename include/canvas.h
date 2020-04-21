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
    virtual void Draw() = 0;
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
        virtual void Draw();
};

class Ellipse : public Shape
{
public:
    Ellipse();
    Ellipse(Position position,Dimension dimension,Rgb base,Rgb border);
    ~Ellipse();
     virtual void Draw();
};

class Square : public Rectangle
{
  public:
       Square();
       Square(Position position,int Side,Rgb base,Rgb border);
      ~Square();
       virtual void Draw();
};

class Circle : public Ellipse
{
      public:
       Circle();
       Circle(Position position,int Radius,Rgb base,Rgb border);
      ~Circle();
       virtual void Draw();
};


class Canvas
{
    public:
        Canvas();
        Canvas(Dimension Resolution,Rgb base);
        virtual ~Canvas();
        Dimension resolution();
        void FillRectangle(Rectangle rect);
        void FillSquare(Square sqr);
        void FillEllipse(Ellipse ellip);
        void FillCircle(Circle circ);
        Rgb  operator[](int index);
        void Clear();
    protected:
    private:
        Rgb* Pixel;
        int  max_Pixel;
        Rgb base;
        Dimension Resolution;
        int rect_count;
};


void render(Canvas& c);
void render(Rectangle r);
void render(Ellipse e);

}
#endif // CANVAS_H
