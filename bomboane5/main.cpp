#include<fstream>
using namespace std;
ifstream fin("bomboane5.in");
ofstream fout("bomboane5.out");
int c, n, x, y, b;
int main() {
    fin >> c >> n >> x >> y;
    b = n / x;
    if (c == 1) {
        fout << b;
        return 0;
    }
    else if (c == 2) {
        int nrmax = 0;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                if (n / i > nrmax) {
                    nrmax = n / i;
                }
                if (i > nrmax) {
                    nrmax = i;
                }
            }
        }
        fout << nrmax;
    }else{
        //n-(b*i) >= 0
        long long minim=1e18;
        long long b=n;
        for(int i=min(x,y); i*i<=n; i++)
        {
            if(n%i<=minim){
                if(i >= x && n/i >= y && (i>=n/b || n%i<minim)) {
                    minim=n%i;
                    b=n/i;
                }
                if(i >= y && n/i>=x && (n/i>=n/b || n%i<minim)) {
                    minim=n%i;
                    b=i;
                }
            }
        }
        fout << minim << ' ' << n/b << ' ' << b;
    }
    return 0;
}
