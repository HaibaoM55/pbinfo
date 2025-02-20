#include <fstream>
using namespace std;
ifstream fin("drag.in");
ofstream fout("drag.out");
int c, n;
int b[1004];
int ba[1004];
int nrb =0;
char x;
int main()
{
    fin >> c >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            fin >> x;
            if(x == '1'){
                b[i]++;
                nrb++;
            }
        }
    }
    if(c == 1){
        fout << nrb/n;
    }else{
        int cost = 0;
        for(int i = n; i > n-(nrb/n); i--){
            int p = n-b[i];
            for(int j=n-(nrb/n); j >= 1; j--){
                if(b[j] < p){
                    cost=cost+(i-j)*b[j];
                    p -= b[j];
                    b[j]=0;
                }
                else{
                    cost=cost+(i-j)*p;
                    b[j] -= p;
                    p = 0;
                    break;
                }
            }
        }
        fout << nrb/n << ' ' << cost;
    }
    return 0;
}
