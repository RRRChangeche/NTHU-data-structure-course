#include <iostream>
using namespace std;

class Shape{
    protected:
    int W, H;

    public:
    Shape(int a=0, int b=0){
        W = a;
        H = b;
    }
    virtual int area() = 0;
};

class Rectangle: public Shape{
    public:
    Rectangle(int a=0, int b=0): Shape(a,b){}
    int area(){
        return W*H;
    }
};

class Triangle: public Shape{
    public:
    Triangle(int a=0, int b=0): Shape(a,b){}
    int area(){
        return W*H/2;
    }
};

int main(){
    Rectangle r(10,20);
    Triangle t(10,20);

    cout << r.area() << endl;
    cout << t.area() << endl;
    return 0;
}