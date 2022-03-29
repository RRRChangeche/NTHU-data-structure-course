#include <iostream>
#include "13_class.hpp"
using namespace std;

// default constructor
Rectangle::Rectangle()
{
    xLow = 0, yLow = 0;
    height = 1, width = 1;
}

// augmentation constructor
// Rectangle::Rectangle(int x, int y, int w, int h)
// {
//     xLow = x, yLow = y;
//     height = w, width = h;
// }
// Rectangle::Rectangle(int x=0, int y=0, int w=0, int h=0): 
Rectangle::Rectangle(int x, int y, int w, int h): 
xLow(x), yLow(y), width(w), height(h){}

// copy constructor
Rectangle::Rectangle(const Rectangle& _src){
    xLow = _src.xLow;
    yLow = _src.yLow;
    height = _src.height;
    width = _src.width;
}

// operator overloading 
bool Rectangle::operator==(const Rectangle& _rhs){
    if (this == &_rhs) return true; // 物件位址一樣的話回傳true
    if ((xLow == _rhs.xLow) && (yLow == _rhs.yLow) && (width == _rhs.width) && (height == _rhs.height)) return true;
    else return false;
}

Rectangle& Rectangle::operator=(const Rectangle& _rhs){
    if (this == &_rhs) return (*this);
    xLow = _rhs.xLow;
    yLow = _rhs.yLow;
    width = _rhs.width;
    height = _rhs.height;
    return (*this);
}

// destructor
Rectangle::~Rectangle()
{
    xLow = yLow = height = width = 0;
}

// I/O operator overloading 
ostream& operator<< (ostream& os, Rectangle& _rhs){
    os << "Posistion is " << _rhs.GetX() << " ";
    os << _rhs.GetY() << endl;
    os << "Height is " << _rhs.GetHeight() << endl;
    os << "Width is " << _rhs.GetWidth() << endl;
    return os;
}

int Rectangle::GetX() {return xLow;}
int Rectangle::GetY() {return yLow;}
int Rectangle::GetHeight() {return height;}
int Rectangle::GetWidth() {return width;}

int main(){

    Rectangle r, s;
    Rectangle*t = &s;

    if (r.GetHeight()*r.GetWidth() > t->GetHeight()* t->GetWidth()) cout << "r";
    else cout << "s ";
    cout << "has the greater area" << endl;

    // initialized using default constructor
    Rectangle r1;
    Rectangle* r2 = new Rectangle();

    // initialized using augmetation constructor
    Rectangle r3(1,3,6,6);
    Rectangle* r4 = new Rectangle(0,0,10,20);

    // initialized using copy constructor
    Rectangle r5(*r4); 

    // I/O operator overloading 
    cout << r1 << r2 << r3 << endl;
    return 0;
}