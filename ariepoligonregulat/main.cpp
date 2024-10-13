#include <iostream>
#include <math.h>
using namespace std;
int n, l;
double cot(double x){
    return cos(x)/sin(x);
}
int main()
{
    cin >> n >> l;
    long double A = (long double)n*l*l/4;
    A = A*cot(M_PI/n);
    long long x = A*100;
    cout << x/100 << "." << x/10%10 <<x%10;
    return 0;
}
