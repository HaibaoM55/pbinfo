#include <fstream>
using namespace std;
ifstream fin("cifra4.in");
ofstream fout("cifra4.out");
int t;
long long c;
long long poz(long long n){
        long long x = 0;
        long long nr = n;
        long long p = 1;
        while(nr > 0){
            int k = nr%10;
            if(k >= c){
                k--;
            }
            x = x + k*p;
            nr = nr/10;
            p = p*10;
        }
        p = 1;
        long long s = 0;
        do{
            s = s+p*(x%10);
            p = p*9;
            x = x/10;
        }while(x > 0);
    if(c > 0){
        return s+1;
    }else{
        long long sol=0,p=1;
        nr=0;
        do{
            long long cif=n%10;
            sol += (cif-1)*p;
            p = p*9;
            nr++;
            n/=10;
        }while(n>0);
        p=9;
        for(int i=1;i<nr;i++){
            sol += p;
            p = p*9;
        }
        return sol+1;
    }
}
long long n;
int main()
{
    fin >> t;
    fin >> c;
    if(t == 1){
        fin >> n;
        if(c > 0){
            long long nr = n-1;
            long long  p = 1;
            long long  x = 0;
            while(nr > 0){
                int k = nr%9;
                if(k >= c){
                    k++;
                }
                x = x + k*p;
                nr = nr/9;
                p = p*10;
            }
            fout << x;
        }else{
            long long nr = n-1;
            long long p = 9;
            while(nr >= p){
                nr = nr-p;
                p = p*9;
            }
            p = 1;
            long long x = 0;
            while(nr > 0){
                int k = nr%9;
                k++;
                x = x + k*p;
                nr = nr/9;
                p = p*10;
            }
            fout << x;
        }
    }else{
        long long Y, Z;
        fin >> Y >> Z;
        if(Y > Z){
            long long aux = Y;
            Y = Z;
            Z = aux;
        }
        fout << (Z-Y+1)-(poz(Z)-poz(Y)+1);
    }
    return 0;
}
