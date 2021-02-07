//
// Created by Davide Del Bimbo.
//

#include <gtest/gtest.h>
#include "../Matrix.h"

TEST(MatrixTemplate, Costruttore) {
    //test matrix A(3x4) of float values
    Matrix<float> A(3, 4);

    ASSERT_EQ(3, A.getRow());
    ASSERT_EQ(4, A.getColumn());
    ASSERT_EQ(0, A.getValue(1, 0));
}

TEST(MatrixTemplate, SettareValore) {
    //set values test on a matrix A(3x3) of double values
    Matrix<double> A(3, 3);
    A.setValue(0, 0, 2.12);
    A.setValue(0, 1, 5.24);
    A.setValue(0, 2, 1.18);
    A.setValue(1, 0, 3.51);
    A.setValue(1, 1, 4.62);
    A.setValue(1, 2, 2.49);
    A.setValue(2, 0, 0.15);
    A.setValue(2, 1, 9.21);
    A.setValue(2, 2, 3.58);

    //test error out_of_range
    ASSERT_THROW(A.setValue(2, 4, 3.56), std::out_of_range);
}

TEST(MatrixTemplate, PrendereValore) {
    //get values test on a matrix A(2x3) of float values
    Matrix<float> A(2, 3);
    A.setValue(0, 0, 5.1);
    A.setValue(0, 1, 3.4);
    A.setValue(0, 2, 0.5);
    A.setValue(1, 0, 4.2);
    A.setValue(1, 1, 1.8);
    A.setValue(1, 2, 7.2);

    ASSERT_EQ(0.5, A.getValue(0, 2));

    //test error out_of_range
    ASSERT_THROW(A.getValue(4, 2), std::out_of_range);
}

TEST(MatrixTemplate, SelezioneRiga) {
    //selection row test on a matrix A(3x4) of int values
    Matrix<int> A(3, 4);
    A.setValue(0, 0, 2);
    A.setValue(0, 1, 1);
    A.setValue(0, 2, 5);
    A.setValue(0, 3, 3);
    A.setValue(1, 0, 0);
    A.setValue(1, 1, 4);
    A.setValue(1, 2, 2);
    A.setValue(1, 3, 6);
    A.setValue(2, 0, 1);
    A.setValue(2, 1, 0);
    A.setValue(2, 2, 9);
    A.setValue(2, 3, 2);

    Matrix<int> B(A.selectRow(0));

    ASSERT_EQ(2, B.getValue(0, 0));
    ASSERT_EQ(1, B.getValue(0, 1));
    ASSERT_EQ(5, B.getValue(0, 2));
    ASSERT_EQ(3, B.getValue(0, 3));

    //test error out_of_range
    ASSERT_THROW(A.selectRow(5), std::out_of_range);
}

TEST(MatrixTemplate, SelezioneColonna) {
    //selection column test on a matrix A(3x3) of int values
    Matrix<int> A(3, 3);
    A.setValue(0, 0, 0);
    A.setValue(0, 1, 4);
    A.setValue(0, 2, 1);
    A.setValue(1, 0, 3);
    A.setValue(1, 1, 2);
    A.setValue(1, 2, 2);
    A.setValue(2, 0, 5);
    A.setValue(2, 1, 1);
    A.setValue(2, 2, 6);

    Matrix<int> B(A.selectColumn(2));

    ASSERT_EQ(1, B.getValue(0, 0));
    ASSERT_EQ(2, B.getValue(1, 0));
    ASSERT_EQ(6, B.getValue(2, 0));

    //test error out_of_range
    ASSERT_THROW(A.selectRow(4), std::out_of_range);
}

TEST(MatrixTemplate, Trasposta) {
    //transpose test of a matrix A(4x2) of int values
    Matrix<int> A(4, 2);
    A.setValue(0, 0, 2);
    A.setValue(0, 1, 4);
    A.setValue(1, 0, 1);
    A.setValue(1, 1, 9);
    A.setValue(2, 0, 3);
    A.setValue(2, 1, 5);
    A.setValue(3, 0, 8);
    A.setValue(3, 1, 6);

    Matrix<int> B(A.transpose());

    ASSERT_EQ(2, B.getRow());
    ASSERT_EQ(4, B.getColumn());
    ASSERT_EQ(5, B.getValue(1, 2));
    ASSERT_EQ(1, B.getValue(0, 1));
    ASSERT_EQ(6, B.getValue(1, 3));
}

TEST(MatrixTemplate, OperatoreAssegnazione) {
    //assignment test of a matrix A(4x2) of int values
    Matrix<int> A(4, 2);
    A.setValue(0, 0, 2);
    A.setValue(0, 1, 3);
    A.setValue(1, 0, 0);
    A.setValue(1, 1, 4);
    A.setValue(2, 0, 2);
    A.setValue(2, 1, 5);
    A.setValue(3, 0, 9);
    A.setValue(3, 1, 6);

    Matrix<int> B(4, 2);
    B = A;

    ASSERT_EQ(3, B.getValue(0, 1));
    ASSERT_EQ(9, B.getValue(3, 0));
    ASSERT_EQ(0, B.getValue(1, 0));

    //test condition of  assignment matrices
    Matrix<int> C(2,2);
    ASSERT_THROW(C = A, std::domain_error);
}

TEST(MatrixTemplate, OperatoreMoltiplicazione) {
    //product test between matrices A(2x3) and B(3,3) of int values
    Matrix<int> A(2, 3);
    A.setValue(0, 0, 2);
    A.setValue(0, 1, 1);
    A.setValue(0, 2, 7);
    A.setValue(1, 0, 3);
    A.setValue(1, 1, 4);
    A.setValue(1, 2, 0);

    Matrix<int> B(3,3);
    B.setValue(0,0,4);
    B.setValue(0,1,1);
    B.setValue(0,2,5);
    B.setValue(1,0,0);
    B.setValue(1,1,3);
    B.setValue(1,2,1);
    B.setValue(2,0,2);
    B.setValue(2,1,6);
    B.setValue(2,2,3);

    Matrix<int> C = A * B;

    ASSERT_EQ(2, C.getRow());
    ASSERT_EQ(3, C.getColumn());
    ASSERT_EQ(C.getValue(0, 0), 22);
    ASSERT_EQ(C.getValue(0, 1), 47);
    ASSERT_EQ(C.getValue(0, 2), 32);
    ASSERT_EQ(C.getValue(1, 0), 12);
    ASSERT_EQ(C.getValue(1, 1), 15);
    ASSERT_EQ(C.getValue(1, 2), 19);

    //test condition of product between matrices
    Matrix<int> D(2, 3);
    ASSERT_THROW(A * D, std::logic_error);

    //test scalar product between matrix and scalar value
    Matrix<int> E = A * 3;
    ASSERT_EQ(E.getValue(0, 0), 6);
    ASSERT_EQ(E.getValue(0, 1), 3);
    ASSERT_EQ(E.getValue(0, 2), 21);
    ASSERT_EQ(E.getValue(1, 0), 9);
    ASSERT_EQ(E.getValue(1, 1), 12);
    ASSERT_EQ(E.getValue(1, 2), 0);
}

TEST(MatrixTemplate, OperatoreSomma) {
    //sum test between matrices A(3x3) and B(3,3) of int values
    Matrix<int> A(3,3);
    A.setValue(0 ,0, 4);
    A.setValue(0, 1, 5);
    A.setValue(0, 2, 3);
    A.setValue(1, 0, 1);
    A.setValue(1, 1, 6);
    A.setValue(1, 2, 0);
    A.setValue(2, 0, 1);
    A.setValue(2, 1, 6);
    A.setValue(2, 2, 3);

    Matrix<int> B(3, 3);
    B.setValue(0 ,0, 1);
    B.setValue(0, 1, 4);
    B.setValue(0, 2, 0);
    B.setValue(1, 0, 3);
    B.setValue(1, 1, 6);
    B.setValue(1, 2, 1);
    B.setValue(2, 0, 0);
    B.setValue(2, 1, 3);
    B.setValue(2, 2, 4);

    Matrix<int> C = A + B;

    ASSERT_EQ(3, C.getValue(0, 2));
    ASSERT_EQ(5, C.getValue(0, 0));
    ASSERT_EQ(1, C.getValue(1, 2));
    ASSERT_EQ(9, C.getValue(0, 1));
    ASSERT_EQ(1, C.getValue(2, 0));

    //test condition of sum between matrices
    Matrix<int> D(2,3);
    ASSERT_THROW(A + D, std::logic_error);
}
