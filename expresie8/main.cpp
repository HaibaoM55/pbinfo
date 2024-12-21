#include <fstream>
using namespace std;
ifstream fin("expresie8.in");
ofstream fout("expresie8.out");
int n;
int v[1004];
int pmax = 0, pmaxi;
int pmax2 = 0, pmaxi2;
int pmax3 = 0, pmaxi3;
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    for(int i = 1; i <= n-1; i++){
        if(v[i]*v[i+1] > pmax){
            pmax = v[i]*v[i+1];
            pmaxi = i;
        }
    }
    for(int i = 1; i <= n-1; i++){
        if(v[i]*v[i+1] > pmax2 && i != pmaxi && i != pmaxi+1){
            pmax2 = v[i]*v[i+1];
            pmaxi2 = i;
        }
    }
    for(int i = 1; i <= n-2; i++){
        if(v[i]*v[i+1]*v[i+2] > pmax3){
            pmax3 = v[i]*v[i+1]*v[i+2];
            pmaxi3 = i;
        }
    }
    long long s;
    if(pmax3 > pmax+pmax2){
        s = pmax3;
        for(int i = 1; i <= n; i++){
            if(pmaxi3 <= i && i <= pmaxi3+2){
                continue;
            }

            s = s + v[i];
        }
    }else{
        s = pmax+pmax2;
        for(int i = 1; i <= n; i++){
            if(pmaxi <= i && i <= pmaxi+1){
                continue;
            }
            if(pmaxi2 <= i && i <= pmaxi2+1){
                continue;
            }
            s = s + v[i];
        }
    }
    fout << s;
    return 0;
}
