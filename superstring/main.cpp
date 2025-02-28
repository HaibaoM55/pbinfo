#include <fstream>
using namespace std;
ifstream fin("superstring.in");
ofstream fout("superstring.out");
unsigned long long t;
unsigned long long k;
unsigned long long cn(long long x, int d) {
    unsigned long long n,t1,r,p;
    n=0;
    t1=1;
    r=0;
    p=0;
    for(int i = 1; i <= d-1; i++) {
        n = n * 10 + 9;
        t1 = t1 * 10;
        r += (n * t1/ 2 - p) * i;
        p = n * t1 / 2;
    }
    r += (x*(x+1)/2 - p) * d;
    return r;
}
int main()
{
    fin >> t;
    for(int i = 1; i <= t; i++){
        fin >> k;
        if(k == 1){
            fout << "1\n";
            continue;
        }
        unsigned long long p1=1, p2 = 1 << 29;
        unsigned long long cor=1;
        while(p1 <= p2){
            unsigned long long mij=(p1+p2)/2;
            unsigned long long x= mij;
            unsigned long long d = 0;
            do{
                d++;
                x = x/10;
            }while(x > 0);
            x = mij;
            unsigned long long r = cn(x, d);
            if(r < k){
                cor = mij;
                p1 = mij+1;
            }else{
                p2 = mij-1;
            }
        }
        unsigned long long cnt = cor;
        unsigned long long d = 0;
        do{
            d++;
            cnt = cnt/10;
        }while(cnt > 0);
        unsigned long long r = cn(cor, d);
        k -= r;
        cor++;
        unsigned long long cl = cor;
        d = 0;
        do{
            cl = cl/10;
            d++;
        }while(cl > 0);
        k = k % d;
        if(k == 0){
            k = d;
        }
        unsigned long long o = d-k;
        while(o >= 1){
            cor = cor/10;
            o--;
        }
        fout << cor%10 << '\n';
    }
    return 0;
}
