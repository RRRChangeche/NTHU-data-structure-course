// Ref: https://stackoverflow.com/questions/16001803/pointer-to-pointer-dynamic-two-dimensional-array
#include <iostream>

class Matrix{
public:
    Matrix(int row, int col);
    ~Matrix();

    // member functions
    Matrix Trans(void);
    Matrix Add(Matrix b);
    Matrix Multiply(Matrix b);

    Matrix& operator=(const Matrix& rhs);
public:
    int **a, rows, cols;

};

// default constructor
Matrix::Matrix(const int row, const int col){
    rows = row; cols = col;
    a = new int* [row];
    for (int i=0; i< row; i++)
        a[i] = new int[col];

    // initial all element = 0
    for (int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            a[i][j] = 0;
        }
    }
}

Matrix::~Matrix(){

}

// implement member functions
// Time complexity O(rows*cols)
Matrix Matrix::Trans(){
    std::cout << "doing Transpose!" << std::endl;
    Matrix c(cols, rows);
    for (int i=0; i<rows; i++)       // O(rows)
        for(int j=0; j<cols; j++)    // O(cols)
            c.a[i][j] = a[j][i];
    return c;
}

// Time complexity O(rows*cols)
Matrix Matrix::Add(Matrix b){
    std::cout << "doing Add!" << std::endl;
    Matrix c(rows, cols);
    for (int i=0; i<rows; i++)       // O(rows)
        for(int j=0; j<cols; j++)    // O(cols)
            c.a[i][j] = a[i][j] + b.a[i][j];
    return c;
}

// Time complexity O(rows*cols*b.cols)
Matrix Matrix::Multiply(Matrix b){
    std::cout << "doing Multiply!" << std::endl;
    Matrix c(rows, b.cols);
    for (int i=0; i<rows; i++)       // O(rows)
    {
        for(int j=0; j<b.cols; j++)    // O(b.cols)
        {
            int sum = 0;
            for(int k=0; k<cols; k++){
                sum += a[i][k]*b.a[k][j];
            }
            c.a[i][j] = sum;
        }
    }
    return c;
}

// operator overloading 
Matrix& Matrix::operator=(const Matrix& rhs){
    if (this == &rhs) return *this;
    else{
        delete [] a;
        // initialize 2-D array
        a = new int* [rows];
        for (int i=0; i< rows; i++)
            a[i] = new int[cols];

        // copy values from rhs Matrix
        for (int i=0; i< rows; i++)
            for (int j=0; j<cols; j++)
                a[i][j] = rhs.a[i][j];

        return *this;
    }
}

std::ostream& operator <<(std::ostream& os, const Matrix& rhs){
    for (int i=0; i<rhs.rows; i++){
        for(int j=0; j<rhs.cols; j++){
            os << rhs.a[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}


int main () {
    // Transpose example
    Matrix m(3,3);
    for (int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            m.a[i][j] = j;
    std::cout << m;

    Matrix m_t(3,3);
    m_t = m.Trans();
    std::cout << m_t;

    // Add example
    Matrix m_add(3,3);
    m_add = m.Add(m_t);
    std::cout << m_add;
       
    // Multiply example
    Matrix m_mult(3,3);
    m_mult = m.Multiply(m_t);
    std::cout << m_mult;
   return 0;
}