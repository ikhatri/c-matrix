#include "cmatrix.h"
#include "cmatrix.cpp" // This shouldn't be necessary, need to figure out why I can't compile without it

using namespace std;

int main(){
    vector<int> t1;
    for(int i=1; i<7; i++)
        t1.push_back(i);
    cmatrix<int> m1(t1, 2, 3);
    cmatrix<int> m2(t1, 3, 2);
    cmatrix<int> m3 = m1 * m2;
    m3.print();
    return 0;
}