#include <iostream>
using namespace std;

namespace first{
    int x = 10;
    int y = 20;
}

namespace second{
    double x = 1.2345;
    double y = 2.4567;
}

int main(){
    using first::x;
    using second::y;
    std::cout << x << endl;
    std::cout << y << endl;
    std::cout << second::x << endl;
    std::cout << second::y << endl;
    return 0;
}