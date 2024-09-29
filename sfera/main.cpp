#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int r;
    double a,pi;
    long double v;
    cin >> r;
    pi = atan(1)*4.0;
    a = 4.0*pi*r*r;
	v = 4.0*pi*r*r*r/3;
	long long x = 100*a;
    cout <<x/100<<"."<<x/10%10<<x%10<<' ';
    long long y = 100*v;
    cout << y/100<<"."<<y/10%10<<y%10;
}
