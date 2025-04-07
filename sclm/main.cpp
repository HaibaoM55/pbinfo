#include <fstream>
using namespace std;
ifstream fin("sclm.in");
ofstream fout("sclm.out");
int n;
int A[1004], D[1004], P[1004],k,I[1004];
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> A[i];
    }
    k = 1;
    D[k] = A[1];
    P[1] = 1;
    for(int i = 2 ; i <= n ; i ++){
        if(A[i] >= D[k]){
            D[++k] = A[i];
            P[i] = k;
        }else{
            int st = 1 , dr = k , p = k + 1;
            while(st <= dr){
                int m = (st + dr) / 2;
                if(D[m] > A[i]){
                    p = m;
                    dr = m - 1;
                }
                else{
                    st = m + 1;
                }
            }
            D[p] = A[i];
            P[i] = p;
        }
    }
    int j = n;
    for(int i = k ; i >= 1 ; i --)
    {
        while(P[j] != i)
            j --;
        I[i] = j;
    }
    fout << k << '\n';
    for(int i = 1; i <= k; i++){
        fout << I[i] << ' ';
    }
    return 0;
}
