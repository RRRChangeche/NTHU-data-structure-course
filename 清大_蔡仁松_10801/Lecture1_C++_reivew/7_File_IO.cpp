#include <iostream>
#include <fstream>
using namespace std;

int main(){
    // out put file 
    ofstream outFile("7_File_IO_Out.out", ios::out);
    if(!outFile){
        cout << "Can not open 7_File_IO_Out.out" << endl;
        return 1;
    }

    int n = 50; float f = 20.3;
    outFile << "n: " << n << endl;
    outFile << "f: " << f << endl;

    // input file 
    ifstream inFile("7_File_IO_Out.out", ios::in);
    if(!inFile){
        cout << "Can not open 7_File_IO_Out.out" << endl;
        return 1;
    }

    int x;
    while(!inFile.eof()){
        inFile >> x;
        cout << x << endl;
    }
    return 0;
}