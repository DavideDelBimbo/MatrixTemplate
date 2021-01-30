//
// Created by Davide Del Bimbo.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H
#include <stdexcept>

template<typename T>
class Matrix{
private:
    int rows, columns;
    T *buffer;

public:
    Matrix(int r, int c);
    ~Matrix();
    Matrix(const Matrix &m);
    void print() const;
    void setValue(int x, int y, T value);
    T getValue(int x, int y) const;

    Matrix<T> transpose() const;
    Matrix<T> operator*(const Matrix& m) const;

    Matrix<T> selectRow(int x);
    Matrix<T> selectColumn(int y);
};

template<typename T>
Matrix<T>::Matrix(int r, int c) {
    rows = r;
    columns = c;

    //create a matrix of dimension rows*columns
    buffer = new T[rows * columns];

    //initializes a matrix of dimension rows*columns
    for(int i=0; i < rows*columns; i++) {
        buffer[i] = 0;
    }
}

template<typename T>
Matrix<T>::~Matrix() {
    delete[] buffer;
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T> &m) {
    rows = m.rows;
    columns = m.columns;

    buffer = new T[rows * columns];

    //inizialize second matrix for operations
    for (int i = 0; i < rows * columns; i++)
        buffer[i] = m.buffer[i];
}

template<typename T>
void Matrix<T>::print() const {
    //print the matrix
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            std::cout << buffer[i*columns + j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

template<typename T>
void Matrix<T>::setValue(int x, int y, T value) {
    //set the value in position (x,y)
    if(x >= 0 && x < rows && y >= 0 && y < columns){
        buffer[x*columns + y] = value;
    } else { //return error if (x,y) exceeded range (rows,columns)
        throw std::out_of_range("range exceeded.");
    }
}

template<typename T>
T Matrix<T>::getValue(int x, int y) const {
    //return the value in position (x,y)
    if(x >= 0 && x < rows && y >= 0 && y < columns){
        return buffer[x*columns + y];
    } else { //return error if (x,y) exceeded range (rows,columns)
        throw std::out_of_range("range exceeded.");
    }
}

template<typename T>
Matrix<T> Matrix<T>::transpose() const{
    //creates a transposed matrix
    Matrix<T> transposedMatrix(columns, rows);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            //invert rows and columns
            transposedMatrix.buffer[i + j*rows] = buffer[i*columns + j];
        }
    }
    return transposedMatrix;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &m) const{
    //checks the condition for the product between matrices
    if(columns == m.rows){
        //creates a product matrix
        Matrix<T> productMatrix(rows, m.columns);
        for(int i = 0; i < rows; i++) {
            for (int j = 0; j < m.columns; j++) {
                //initializes the product matrix to 0
                productMatrix.buffer[i*m.columns + j] = 0;
                for(int k = 0; k < columns; k++){
                    //product operation between matrices
                    productMatrix.buffer[i * m.columns + j] += buffer[i * columns + k] * m.buffer[k * m.columns + j];
                }
            }
        }
        return productMatrix;
    } else { //returns error if the condition of the product between matrices is not respected
        throw std::logic_error("In the product, the columns of the first matrix must be equal to the rows of the second matrix.");
    }
}

template<typename T>
Matrix<T> Matrix<T>::selectRow(int x) {
    //creates a matrix with one row
    Matrix rowMatrix(1, columns);
    if(x >= 0 and x < rows){
        for(int j = 0; j < columns; j++){
            rowMatrix.buffer[j] = buffer[x*columns + j];
        }
        //return the row x
        return rowMatrix;
    } else { //return error if x exceeded range rows
        throw std::out_of_range("range exceeded.");
    }
}

template<typename T>
Matrix<T> Matrix<T>::selectColumn(int y) {
    //creates a matrix with one column
    Matrix columnMatrix(rows, 1);
    if(y >= 0 and y < columns){
        for(int i = 0; i < rows; i++){
            columnMatrix.buffer[i] = buffer[i*columns + y];
        }
        //return the column y
        return columnMatrix;
    } else { //return error if y exceeded range columns
        throw std::out_of_range("range exceeded.");
    }
}

#endif //MATRIX_MATRIX_H
