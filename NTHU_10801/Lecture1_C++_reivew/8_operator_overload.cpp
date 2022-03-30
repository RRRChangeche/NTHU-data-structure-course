#include <iostream>
using namespace std;

class Ferrari{
    public:
    int W =10, H = 5, L = 20;
    char* model = "250 GTO";
};

ostream& operator << (ostream &os, const Ferrari &obj){
    os << "*******************" << endl;
    os << "Ferrari " << obj.model << endl;
    os << "W = " << obj.W << endl;
    os << "H = " << obj.H << endl;
    os << "L = " << obj.L << endl;
    os << "*******************" << endl; 
}

int main(){

    Ferrari mycar;
    // mycar.model = "250 GTO";
    cout << "Car info:" << endl;
    cout << mycar << endl;
    return 0;
}