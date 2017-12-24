#include "cmatrix.h"

using namespace std;

template <class T>
cmatrix<T>::cmatrix(vector<T> values, int n_rows, int n_cols){
    vals = values;
    rows = n_rows;
    cols = n_cols;
}

template <class T>
int cmatrix<T>::num_rows(){
    return rows;
}

template <class T>
int cmatrix<T>::num_cols(){
    return cols;
}

template <class T>
void cmatrix<T>::print(){
    for(auto const i : vals)
        cout << i << " ";
    cout << endl;
}

template <class T>
cmatrix<T> cmatrix<T>::operator+(const cmatrix& right) const{
    vector<T> result;
    if(this->rows!=right.rows && this->cols!=right.cols){
        cout << "A fatal error occurred: matricies were not of the same size and could not be added." << endl;
        return cmatrix(result, 0, 0);
    }
    result = this->vals;
    for(int i=0; i<result.size(); i++)
        result[i]+=right.vals[i];
    return cmatrix(result, this->rows, this->cols);
}

template <class T>
cmatrix<T> cmatrix<T>::operator-(const cmatrix& right) const{
    vector<T> result;
    if(this->rows!=right.rows && this->cols!=right.cols){
        cout << "A fatal error occurred: matricies were not of the same size and could not be added." << endl;
        return cmatrix(result, 0, 0);
    }
    result = this->vals;
    for(int i=0; i<result.size(); i++)
        result[i]-=right.vals[i];
    return cmatrix(result, this->rows, this->cols);
}
