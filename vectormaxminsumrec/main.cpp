#include <iostream>
using namespace std;
void P(int x[], int n, int &mini, int &maxi, int &sum, int pt = 1){
    if(pt == 1){
        mini = x[n-1];
     	maxi = x[n-1];
     	sum  = 0;
    }
    mini = min(mini, x[n-1]);
    maxi = max(maxi, x[n-1]);
    sum += x[n-1];
    n--;
    if(n == 0){
     	return;
    }
    P(x, n, mini, maxi, sum, 0);
}/*
int x[104] = {12, 7, 6, 3, 8, 5};
int main(){
    int mini, maxi, sum;
    P(x, 6, mini, maxi, sum);
    cout << mini << ' ' << maxi << ' ' << sum;
    return 0;
}
*/
