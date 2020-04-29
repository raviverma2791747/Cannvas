#include <iostream>
#include "include\canvas.h"
#include<stdlib.h>

using namespace std;


int main()
{
    int choice = 0;
    while(choice != 6)
    {
        cout<<"=============================================================\n";
        cout<<"                   MAIN MENU                                 \n";
        cout<<"=============================================================\n";
        cout<<"[1]Draw a Rectangle\n";
        cout<<"[2]Draw an Ellipse\n";
        cout<<"[3]Draw a Square\n";
        cout<<"[4]Draw a Circle\n";
        cout<<"[5]Draw Multiple Shapes\n";
        cout<<"[6]exit\n";
        cout<<"::";
        cin>>choice;
        switch(choice)
        {
        case 1:
        {
            paint::Rgb colorBase;
            paint::Rgb colorBorder;
            paint::Dimension dimension;
            cout<<"Enter Base color of rectangle\n";
            cout<<"i.e Red is 255 0 0 Green 0 255 0 Blue 0 0 255\n";
            cout<<"::";
            cin>>colorBase.Red>>colorBase.Green>>colorBase.Blue;
            cout<<"Enter Border color of rectangle \n";
            cout<<"i.e Red is 255 0 0 Green 0 255 0 Blue 0 0 255\n";
            cout<<"::";
            cin>>colorBorder.Red>>colorBorder.Green>>colorBorder.Blue;
            cout<<"Enter Height and Width of Rectangle i.e Height 50  Width 100\n";
            cout<<"::";
            cin>>dimension.Height>>dimension.Width;
            paint::Rectangle R(paint::Position{0,0},dimension,colorBase,colorBorder);
            R.Draw();
            cout<<"Press any Key to continue\n";
            cin.get();
            cin.get();
        }
        break;

        case 2:
        {
            paint::Rgb colorBase;
            paint::Rgb colorBorder;
            paint::Dimension dimension;
            cout<<"Enter Base color of Ellipse\n";
            cout<<"i.e Red is 255 0 0 Green 0 255 0 Blue 0 0 255\n";
            cout<<"::";
            cin>>colorBase.Red>>colorBase.Green>>colorBase.Blue;
            cout<<"Enter Border color of Ellipse \n";
            cout<<"i.e Red is 255 0 0 Green 0 255 0 Blue 0 0 255\n";
            cout<<"::";
            cin>>colorBorder.Red>>colorBorder.Green>>colorBorder.Blue;
            cout<<"Enter Height and Width of Ellipse i.e Height 50  Width 100\n";
            cout<<"::";
            cin>>dimension.Height>>dimension.Width;
            paint::Ellipse E(paint::Position{0,0},dimension,colorBase,colorBorder);
            E.Draw();
            cout<<"Press any Key to continue\n";
            cin.get();
            cin.get();
        }
        break;

        case 3:
        {
            paint::Rgb colorBase;
            paint::Rgb colorBorder;
            int side = 0;
            cout<<"Enter Base color of Square\n";
            cout<<"i.e Red is 255 0 0 Green 0 255 0 Blue 0 0 255\n";
            cout<<"::";
            cin>>colorBase.Red>>colorBase.Green>>colorBase.Blue;
            cout<<"Enter Border color of Square \n";
            cout<<"i.e Red is 255 0 0 Green 0 255 0 Blue 0 0 255\n";
            cout<<"::";
            cin>>colorBorder.Red>>colorBorder.Green>>colorBorder.Blue;
            cout<<"Enter Side of Square i.e Side 100\n";
            cout<<"::";
            cin>>side;
            paint::Square S(paint::Position{0,0},side,colorBase,colorBorder);
            S.Draw();
            cout<<"Press any Key to continue\n";
            cin.get();
            cin.get();
        }
        break;


        case 4:
        {
            paint::Rgb colorBase;
            paint::Rgb colorBorder;
            int radius = 0;
            cout<<"Enter Base color of Circle\n";
            cout<<"i.e Red is 255 0 0 Green 0 255 0 Blue 0 0 255\n";
            cout<<"::";
            cin>>colorBase.Red>>colorBase.Green>>colorBase.Blue;
            cout<<"Enter Border color of Circle \n";
            cout<<"i.e Red is 255 0 0 Green 0 255 0 Blue 0 0 255\n";
            cout<<"::";
            cin>>colorBorder.Red>>colorBorder.Green>>colorBorder.Blue;
            cout<<"Enter Radius of Circle i.e Radius 50\n";
            cout<<"::";
            cin>>radius;
            paint::Circle C(paint::Position{0,0},radius,colorBase,colorBorder);
            C.Draw();
            cout<<"Press any Key to continue\n";
            cin.get();
            cin.get();
        }
        break;

        case 5:
        {
            paint::Dimension dimensionCanvas;
            paint::Rgb colorCanavsBase;
            int sub_choice = 0;
            cout<<" Enter the Height and Width of Canvas\n";
            cout<<"i.e Height 480 Width 720\n";
            cout<<"::";
            cin>>dimensionCanvas.Height>>dimensionCanvas.Width;
            cout<<"Enter the Base color of Canvas\n";
            cout<<"i.e Red is 255 0 0 Green is 0 255 0 Blue is 0 0 255\n";
            cout<<"::";
            cin>>colorCanavsBase.Red>>colorCanavsBase.Green>>colorCanavsBase.Blue;
            paint::Canvas c(dimensionCanvas,colorCanavsBase);
            while(sub_choice != 6)
            {
                cout<<"[1]Add a Rectangle\n";
                cout<<"[2]Add an Ellipse\n";
                cout<<"[3]Add a Square\n";
                cout<<"[4]Add a Circle\n";
                cout<<"[5]Paint or Render on Screen\n";
                cout<<"[6]Exit\n";
                cout<<"::";
                cin>>sub_choice;
                switch(sub_choice)
                {
                case 1:
                {
                    paint::Position rectPosition;
                    paint::Dimension rectDimension;
                    paint::Rgb rectBasecolor;
                    paint::Rgb rectBorderColor;
                    cout<<"Enter the position of Rectangle\n";
                    cout<<"Note position of rectangle must be within :"<<dimensionCanvas.Height <<"Height and"<<dimensionCanvas.Width<<"Width \n";
                    cout<<"i.e X 10 Y 20\n";
                    cout<<"::";
                    cin>>rectPosition.X>>rectPosition.Y;
                    cout<<"Enter the Dimension of Rectangle\n";
                    cout<<"i.e Height and Width\n";
                    cout<<"::";
                    cin>>rectDimension.Height>>rectDimension.Width;
                    cout<<"Enter the Base color of Rectangle\n";
                    cout<<"i.e Red is 255 0 0 Green 0 255 0 Blue 0 0 255\n";
                    cout<<"::";
                    cin>>rectBasecolor.Red>>rectBasecolor.Green>>rectBasecolor.Blue;
                    cout<<"Enter the Border color of Rectangle\n";
                    cout<<"i.e Red is 255 0 0 Green 0 255 0 Blue 0 0 255\n";
                    cout<<"::";
                    cin>>rectBorderColor.Red>>rectBorderColor.Green>>rectBorderColor.Blue;
                    paint::Rectangle R(rectPosition,rectDimension,rectBasecolor,rectBasecolor);
                    c.FillRectangle(R);
                }
                break;

                case 2:
                {
                    paint::Position ellipPosition;
                    paint::Dimension ellipDimension;
                    paint::Rgb ellipBasecolor;
                    paint::Rgb ellipBorderColor;
                    cout<<"Enter the position of Ellipse\n";
                    cout<<"Note position of Ellipse must be within :"<<dimensionCanvas.Height <<"Height and"<<dimensionCanvas.Width<<"Width \n";
                    cout<<"i.e X 10 Y 20\n";
                    cout<<"::";
                    cin>>ellipPosition.X>>ellipPosition.Y;
                    cout<<"Enter the Dimension of Ellipse\n";
                    cout<<"i.e Height and Width\n";
                    cout<<"::";
                    cin>>ellipDimension.Height>>ellipDimension.Width;
                    cout<<"Enter the Base color of Ellipse\n";
                    cout<<"i.e Red is 255 0 0 Green 0 255 0 Blue 0 0 255\n";
                    cout<<"::";
                    cin>>ellipBasecolor.Red>>ellipBasecolor.Green>>ellipBasecolor.Blue;
                    cout<<"Enter the Border color of Ellipse\n";
                    cout<<"i.e Red is 255 0 0 Green 0 255 0 Blue 0 0 255\n";
                    cout<<"::";
                    cin>>ellipBorderColor.Red>>ellipBorderColor.Green>>ellipBorderColor.Blue;
                    paint::Ellipse E(ellipPosition,ellipDimension,ellipBasecolor,ellipBorderColor);
                    c.FillEllipse(E);
                }
                break;

                case 3:
                {
                    paint::Position sqrPosition;
                    int side=0;
                    paint::Rgb sqrBasecolor;
                    paint::Rgb sqrBorderColor;
                    cout<<"Enter the position of Square\n";
                    cout<<"Note position of Square must be within :"<<dimensionCanvas.Height <<"Height and"<<dimensionCanvas.Width<<"Width \n";
                    cout<<"i.e X 10 Y 20\n";
                    cout<<"::";
                    cin>>sqrPosition.X>>sqrPosition.Y;
                    cout<<"Enter the Side of Square\n";
                    cout<<"i.e Side\n";
                    cout<<"::";
                    cin>>side;
                    cout<<"Enter the Base color of Square\n";
                    cout<<"i.e Red is 255 0 0 Green 0 255 0 Blue 0 0 255\n";
                    cout<<"::";
                    cin>>sqrBasecolor.Red>>sqrBasecolor.Green>>sqrBasecolor.Blue;
                    cout<<"Enter the Border color of Square\n";
                    cout<<"i.e Red is 255 0 0 Green 0 255 0 Blue 0 0 255\n";
                    cout<<"::";
                    cin>>sqrBorderColor.Red>>sqrBorderColor.Green>>sqrBorderColor.Blue;
                    paint::Square S(sqrPosition,side,sqrBasecolor,sqrBorderColor);
                    c.FillSquare(S);
                }
                break;

                case 4:
                {
                    paint::Position circPosition;
                    int radius=0;
                    paint::Rgb circBasecolor;
                    paint::Rgb circBorderColor;
                    cout<<"Enter the position of Circle\n";
                    cout<<"Note position of Circle must be within :"<<dimensionCanvas.Height <<"Height and"<<dimensionCanvas.Width<<"Width \n";
                    cout<<"i.e X 10 Y 20\n";
                    cout<<"::";
                    cin>>circPosition.X>>circPosition.Y;
                    cout<<"Enter the Radius of Circle\n";
                    cout<<"i.e Radius\n";
                    cout<<"::";
                    cin>>radius;
                    cout<<"Enter the Base color of Circle\n";
                    cout<<"i.e Red is 255 0 0 Green 0 255 0 Blue 0 0 255\n";
                    cout<<"::";
                    cin>>circBasecolor.Red>>circBasecolor.Green>>circBasecolor.Blue;
                    cout<<"Enter the Border color of Circle\n";
                    cout<<"i.e Red is 255 0 0 Green 0 255 0 Blue 0 0 255\n";
                    cout<<"::";
                    cin>>circBorderColor.Red>>circBorderColor.Green>>circBorderColor.Blue;
                    paint::Circle C(circPosition,radius,circBasecolor,circBorderColor);
                    c.FillCircle(C);
                }
                break;

                case 5:
                    system("cls");
                    for(int i=0; i<5; i++)
                    {

                        paint::render(c);
                    }
                    cin.get();
                    cin.get();
                    system("cls");
                    sub_choice = 6;
                    break;


                case 6:
                    cout<<"Press any key to continue\n";
                    cin.get();
                    break;

                default:
                    cout<<"Invalid Choice PLease try again!\n";
                    cout<<"Press any Key to continue\n";
                    cin.get();
                }
            }
        }
        break;

        case 6:
            cout<<"Press any key to continue\n";
            cin.get();
            exit(0);
            break;

        default:
            cout<<"Invalid Choice PLease try again!\n";
            cout<<"Press any Key to continue\n";
            cin.get();
        }
        system("cls");
    }
    return 0;
}
