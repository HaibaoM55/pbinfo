#include <fstream>
using namespace std;
ifstream fin("pdif.in");
ofstream fout("pdif.out");
int n, c;
int v[100004];
int main()
{
    fin >> n >> c;
    for(int i = 1; i <= n; i++){
        int x;
        fin >> x;
        while(x >= 10){
            int s = 0;
            do{
                s = s+x%10;
                x = x/10;
            }while(x > 0);
            x = s;
        }
        v[i] = x%2;
    }
    int nr = 1;
    int nrmax = 1, nrap=0;
    int i1 = 0;
    for(int i = 1; i <= n-1; i++){
        if(v[i] != v[i+1]){
            nr++;
            if(nr > nrmax){
                i1 = i;
                nrmax = nr;
                nrap = 1;
            }else if(nr == nrmax){
                nrap++;
            }
        }else{
            nr = 1;
        }
    }
    if(c == 1){
        fout << nrmax << ' ' << nrap;
    }else{
        fout << i1-nrmax+2 << ' ' << i1+1;
    }
    return 0;
}
