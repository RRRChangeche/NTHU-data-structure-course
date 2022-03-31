#include <iostream>
using namespace std;

#define MaxDegree 10
class Term;

class Polynomial{
public:
    Polynomial(){};
    ~Polynomial();

    // member function
    Polynomial Add(Polynomial poly);
    Polynomial Mult(Polynomial poly);    
    float Eval(float x);
    void NewTerm(float c, int exp);

    // member data
    int degree;
    float coef[MaxDegree+1];

private:
    Term* termArray;
    int capacity;   // size of termArray
    int terms;  // number of nonzero terms
};

// 2nd representation of polynomial
class Term{ 
    friend Polynomial;
public: 
    float coef;
    int exp;
};


// implementation
Polynomial Polynomial::Add(Polynomial b){
    // return sum of polynomial *this and b
    Polynomial c;
    int aPos=0, bPos=0;
    while ((aPos < terms) && (bPos < b.terms)){ // 還有係數
        if (termArray[aPos].exp == b.termArray[bPos].exp){
            float t = termArray[aPos].coef + termArray[bPos].coef;
            if (t) c.NewTerm(t, termArray[aPos].exp);
            aPos++; bPos++;
        }
        else if (termArray[aPos].exp < b.termArray[bPos].exp){
            c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
            bPos++;
        }
        else{
            c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
            aPos++;
        }

        // add in remaining terms of *this
        for(; aPos<terms; aPos++)
            c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
        for(; bPos<terms; bPos++)
            c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
    }

    return c;
}

void Polynomial::NewTerm(float c, int exp){
    Term t;
    t.coef = c;
    t.exp = exp;

    // for(int i=0; i<)
}

int main () {

   return 0;
}