#include <fstream>
#include <math.h>
using namespace std;
ifstream fin("2017.in");
ofstream fout("2017.out");
int q;
long long c, k;
unsigned long long count_digit(unsigned long long n, int c) {
    unsigned long long count = 0;
    unsigned long long factor = 1;
    while (factor <= n) {
        unsigned long long lower_numbers = n - (n / factor) * factor;
        unsigned long long current_digit = (n / factor) % 10;
        unsigned long long higher_numbers = n / (factor * 10);
        if (current_digit < c) {
            count += higher_numbers * factor;
        } else if (current_digit == c) {
            count += higher_numbers * factor + lower_numbers + 1;
        } else {
            count += (higher_numbers + 1) * factor;
        }
        factor *= 10;
    }
    return count;
}
int main()
{
    fin >> q;
    for(int i = 1; i <= q; i++){
        fin >> c >> k;
        unsigned long long p1 = 1;
        unsigned long long p2 = 1000000000000;
        while(p1 < p2){
            unsigned long long mij = (p1+p2)/2;
            unsigned long long x = count_digit(mij, c);
            if(x < k){
                p1 = mij+1;
            }else{
                p2 = mij-1;
            }
        }
        if(count_digit(p1, c) < k){
            fout << p1+1 << '\n';
        }else{
            fout << p1 << '\n';
        }
    }
    return 0;
}
