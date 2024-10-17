#include <fstream>
#include <math.h>
using namespace std;
ifstream fin("sumo.in");
ofstream fout("sumo.out");
int n;
int p, q;
int sumOfDigits(int n) {
    int totalSum = 0;
    int factor = 1;
    while (factor <= n) {
        int lowerNumbers = n - (n / factor) * factor;
        int currentDigit = (n / factor) % 10;
        int higherNumbers = n / (factor * 10);
        totalSum += higherNumbers * factor * 45;
        if (currentDigit > 0) {
            totalSum += currentDigit * (currentDigit - 1) / 2 * factor;
            totalSum += currentDigit * (lowerNumbers + 1);
        }
        factor *= 10;
    }

    return totalSum;
}
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> p >> q;
        long long s = 0;
        int x, y;
        long long z = 1;
        long long st=1, dr=9;
        int pi, qi;
        int stp, stq;
        for(int j = 1; j <= 9; j++){
            dr = 9*j*z+st-1;
            if(st <= p && p <= dr){
                pi = j;
                stp = st;
            }
            if(st <= q && q <= dr){
                qi = j;
                stq = st;
                break;
            }
            st = dr+1;
            z = z*10;
        }
    }
    return 0;
}
