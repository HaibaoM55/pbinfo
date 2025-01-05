#include <fstream>
using namespace std;
ifstream fin("nrecou.in");
ofstream fout("nrecou.out");
int n;
long long x[500004];
int main()
{
    fin >> n;
    x[1] = 9;
    for(int i = 2; i <= n/2; i++){
        x[i] = x[i-1]*10;
        x[i] = x[i] % 1000000017;
    }
    long long nr = 0;
    for(int i = 1; i <= n/2; i++){
        if(n % i == 0){
            for(int j = 1; j <= i/2; j++){
                if(i % j == 0){
                    x[i] = x[i]-x[j];
                    if(x[i] < 0){
                        x[i] = x[i]+ 1000000017;
                    }else if(x[i] > 1000000017){
                        x[i] = x[i]-1000000017;
                    }
                }
            }
            nr = nr+x[i];
            nr = nr % 1000000017;
        }
    }
    fout << nr;
    return 0;
}
