#include <fstream>
using namespace std;
ifstream fin("cautafibo.in");
ofstream fout("cautafibo.out");
int nr = 0;
long long fib[104];
long long x;
int main(){
    fib[1] = 1;
    fib[2] = 1;
    for(int i = 3; fib[i-1]+fib[i-2] <= 10000000000; i++){
        fib[i] = fib[i-1]+fib[i-2];
    }
    while(fin >> x){
        int p1 = 2, p2 = 49;
        while(p1 <= p2){
            int mij = (p1+p2)/2;
            if(fib[mij] == x){
                nr++;
                break;
            }else if(fib[mij] < x){
                p1 = mij+1;
            }else{
                p2 = mij-1;
            }
        }
    }
    fout << nr;
    return 0;
}
