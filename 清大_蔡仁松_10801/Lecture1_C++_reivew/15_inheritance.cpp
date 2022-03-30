#include <iostream>
#include <algorithm>
using namespace std;

class Point{

};

// Base class (abstract type)
class Polygon{
public:
    Polygon(){
        m_VN = 0;
        mp_V = NULL;
    }
    ~Polygon(){
        delete [] mp_V;
        mp_V = NULL;
    }

    double CalArea(){return 0.0;}
    bool isConvex(){return true;}
    int vtxNum(){return m_VN;}

protected:
    int m_VN;
    Point* mp_V;
};

// Derived class
/*
    class Triangle: public Polygon
    the "public" here is access specifier,
    inherits all the non-private members (data and functions)
    from base class
*/
class Triangle:public Polygon{
public:
    Triangle(){
        m_VN = 3;
        mp_V = new Point[m_VN];
    }
    ~Triangle(){}
    double CalArea(){return 0.0;};
};

class Rectangle:public Polygon{
public:
    Rectangle(){
        m_VN = 4;
        mp_V = new Point[m_VN];
    }
    ~Rectangle(){}
    double CalArea(){return 0.0;};
};

// Contructor example
class Base{
public:
    Base(){
        cout << "Base's constructor!" << endl;
    }

    virtual const char* getName(){ return "Name: Base";}
};

class ChildA: public Base{
public:
    ChildA(){
        cout << "ChildA's constructor!" << endl;
    }
    virtual const char* getName(){ return "Name: ChildA";}
};

class ChildB: public Base{
public:
    ChildB(){
        cout << "ChildB's constructor!" << endl;
    }
    virtual const char* getName(){ return "Name: ChildB";}
};

// Polymorphism using virtual function keyword
void processObj(Base* obj){
    cout << obj->getName() << endl;
}


int main(){
    // constructor example
    Base* b = new Base;
    ChildA* cA = new ChildA;
    ChildB* cB = new ChildB;

    // polymorphism example
    processObj(b);
    processObj(cA);
    processObj(cB);

    return 0;
}