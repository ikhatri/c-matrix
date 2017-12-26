#include "mtcmatrix.h"

using namespace std;

template <class T>
mtcmatrix<T>::mtcmatrix(vector<T> values, int n_rows, int n_cols){
    vals = values;
    rows = n_rows;
    cols = n_cols;
}

template <class T>
int mtcmatrix<T>::num_rows(){
    return rows;
}

template <class T>
int mtcmatrix<T>::num_cols(){
    return cols;
}

template <class T>
void mtcmatrix<T>::print(){
    for(auto const i : vals)
        cout << i << " ";
    cout << endl;
}

template <class T>
vector<T> mtcmatrix<T>::get_row(int i) const{
    vector<T> result;
    if(i>rows){
        cout << "Oops! You tried to get a row of the matrix that doesn't exist" << endl;
        return result;
    }
    int p = cols * (i-1);
    for(int x = p; x < p+cols; x++){
        result.push_back(this->vals[x]);
    }
    return result;
}

template <class T>
vector<T> mtcmatrix<T>::get_col(int i) const{
    vector<T> result;
    if(i>cols){
        cout << "Oops! You tried to get a column of the matrix that doesn't exist" << endl;
        return result;
    }
    for(int x = i-1; x<rows*cols; x+=cols)
        result.push_back(this->vals[x]);
    return result;
}

template <class T>
T mtcmatrix<T>::dot(vector<T> x, vector<T> y) const{
    T total = 0;
    if(x.size()!=y.size()){
        cout << "A fatal error occured: vectors must be of the same size to be dotted." << endl;
        return total;
    }
    for(int i=0; i<x.size(); i++)
        total += x[i] * y[i];
    return total;
}

template <class T>
mtcmatrix<T> mtcmatrix<T>::operator+(const mtcmatrix& right) const{
    vector<T> result;
    if(this->rows!=right.rows && this->cols!=right.cols){
        cout << "A fatal error occurred: matricies were not of the same size and could not be added." << endl;
        return mtcmatrix(result, 0, 0);
    }
    result = this->vals;
    for(int i=0; i<result.size(); i++)
        result[i]+=right.vals[i];
    return mtcmatrix(result, this->rows, this->cols);
}

template <class T>
mtcmatrix<T> mtcmatrix<T>::operator-(const mtcmatrix& right) const{
    vector<T> result;
    if(this->rows!=right.rows && this->cols!=right.cols){
        cout << "A fatal error occurred: matricies were not of the same size and could not be subtracted." << endl;
        return mtcmatrix(result, 0, 0);
    }
    result = this->vals;
    for(int i=0; i<result.size(); i++)
        result[i]-=right.vals[i];
    return mtcmatrix(result, this->rows, this->cols);
}

template <class T>
void mtcmatrix<T>::threadFunc(vector<T>* result, int i, vector<T> x, vector<T> y) const{
    result->at(i) = this->dot(x, y);
}

template <class T>
mtcmatrix<T> mtcmatrix<T>::operator*(const mtcmatrix& right) const{
    vector<T> result(this->rows*right.cols, 0);
    vector<thread> threads;
    if(this->cols!=right.rows){
        cout << "A fatal error occurred: matricies were not of compatible sizes for multiplication." << endl;
        cout << "Matrix 1: " << this->rows << " x " << this->cols << endl;
        cout << "Matrix 2: " << right.rows << " x " << right.cols << endl;
        return mtcmatrix(result, 0, 0);
    }
    int t=0;
    for(int r=1; r<=this->rows; r++){
        for(int c=1; c<=right.cols; c++){
            threads.emplace_back(thread(&mtcmatrix<T>::threadFunc, this, &result, t++, this->get_row(r), right.get_col(c)));
        }
    }
    for(auto& t : threads){
        t.join();
    }
    return mtcmatrix(result, this->rows, right.cols);
}
