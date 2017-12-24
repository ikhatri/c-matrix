#include "cmatrix.h"
#include "cmatrix.cpp"

using namespace std;

int main(){
    vector<int> t1;
    for(int i=1; i<4; i++)
        t1.push_back(i);
    cmatrix<int> m1(t1, 1, 3);
    cmatrix<int> m2(t1, 1, 3);
    cmatrix<int> m3 = m1 + m2;
    m3.print();
    return 0;
}