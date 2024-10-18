#include <fstream>
#include <math.h>
using namespace std;
ifstream fin("sumo.in");
ofstream fout("sumo.out");
int n;
int p, q;
long long sumOfDigits(int n) {
    long long totalSum = 0;
    long long factor = 1;
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
        long long x, y;
        long long c = 0;
        int ncif = 1;
        long long c1 = 9;
        long long s1 = 1;
        while (p > c + ncif * c1) {
            c += ncif * c1;
            ncif++;
            c1 *= 10;
            s1 *= 10;
        }
        long long i1 = (p-c-1)/ncif;
        long long j1 = (p-c-1)%ncif;
        c = 0;
        ncif = 1;
        long long c2 = 9;
        long long s2 = 1;
        while (q > c + ncif * c2) {
            c += ncif * c2;
            ncif++;
            c2 *= 10;
            s2 *= 10;
        }
        long long i2 = (q - c - 1)/ncif;
        long long j2 = (q - c - 1)%ncif;
        s = sumOfDigits(s2+i2-1)-sumOfDigits(s1+i1);
        long long n1 = s1+i1;
        int cif[12];
        int z = 0;
        do{
            cif[z] = n1%10;
            z++;
            n1 = n1/10;
        }while(n1 > 0);
        int nrc = z-1;
        int cfr[12];
        for(int j = 0; j <= z-1; j++){
            cfr[nrc] = cif[j];
            nrc--;
        }
        for(int j = j1; j <= z-1; j++){
            s += cfr[j];
        }
        int cif1[12], cfr1[12];
        z = 0;
        n1 = s2+i2;
        do{
            cif1[z] = n1%10;
            z++;
            n1 = n1/10;
        }while(n1 > 0);
        nrc = z-1;
        for(int j = 0; j <= z-1; j++){
            cfr1[nrc] = cif1[j];
            nrc--;
        }
        for(int j = 0; j <= j2; j++){
            s += cfr1[j];
        }
        fout << s << '\n';
    }
    return 0;
}
