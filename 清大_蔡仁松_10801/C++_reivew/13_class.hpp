#ifndef RECTANGLE_H
#define RECTANGLE_H
class Rectangle
{
/* Data encapsulation 封裝*/
private:
    /* data */
    int xLow, yLow, height, width;

/* Data Abstraction (Specification) 抽象化*/
public:
    Rectangle();  // default constructor
    Rectangle(int x, int y, int w, int h); // augmentation constructor
    Rectangle(const Rectangle& _src);
    ~Rectangle();   // destructor
    int GetX();
    int GetY();
    int GetHeight();
    int GetWidth();

    // operator overloading 
    bool operator==(const Rectangle&);
    Rectangle& operator=(const Rectangle&);
};
#endif