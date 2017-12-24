#ifndef CMATRIX_H
#define CMATRIX_H
#include <string>
#include <vector>
#include <iostream>

using namespace std;
template <class T>

class cmatrix {
    public:
        cmatrix(vector<T> values, int n_rows, int n_cols);
        int num_rows();
        int num_cols();
        void print();

        cmatrix operator+(const cmatrix& first) const;
        cmatrix operator-(const cmatrix& first) const;
    
    protected:
        vector<T> vals;
        int rows;
        int cols;
};

#endif
