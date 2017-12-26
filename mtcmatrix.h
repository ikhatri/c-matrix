#ifndef MTCMATRIX_H
#define MTCMATRIX_H
#include <string>
#include <vector>
#include <iostream>
#include <thread>
#include <functional>

using namespace std;
template <class T>

class mtcmatrix {
    public:
        mtcmatrix(vector<T> values, int n_rows, int n_cols);
        int num_rows();
        int num_cols();
        void print();

        vector<T> get_row(int i) const;
        vector<T> get_col(int i) const;
        T dot(vector<T> x, vector<T> y) const;
        void threadFunc(vector<T>* result, int i, vector<T> x, vector<T> y) const;

        mtcmatrix operator+(const mtcmatrix& first) const;
        mtcmatrix operator-(const mtcmatrix& first) const;
        mtcmatrix operator*(const mtcmatrix& first) const;
    
    protected:
        vector<T> vals;
        int rows;
        int cols;
};

#endif
