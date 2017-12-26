#include "cmatrix.h"
#include "cmatrix.cpp" // This shouldn't be necessary, need to figure out why I can't compile without it
#include "mtcmatrix.h"
#include "mtcmatrix.cpp" // This shouldn't be necessary either
#include <chrono>

using namespace std;
using Clock = std::chrono::steady_clock;
using std::chrono::time_point;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
//using namespace std::literals::chrono_literals;
using std::this_thread::sleep_for;

int main(){
    time_point<Clock> start = Clock::now();
    
    vector<int> t1;
    for(int i=1; i<10001; i++)
        t1.push_back(i);
    cmatrix<int> m1(t1, 100, 100);
    cmatrix<int> m2(t1, 100, 100);
    cmatrix<int> m3 = m1 * m2;
    //m3.print();
    
    time_point<Clock> end = Clock::now();
    milliseconds diff = duration_cast<milliseconds>(end - start);
    std::cout << diff.count() << "ms" << std::endl;
    return 0;
}