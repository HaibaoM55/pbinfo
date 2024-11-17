#include <fstream>
using namespace std;
ifstream fin("medians.in");
ofstream fout("medians.out");
int n, k;
long long v[100004];
long long nr = 0;
long long stv[100004];
long long a[200005];
int main()
{
    fin >> n >> k;
    stv[0] = 100000;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        if(v[i] > k){
            stv[i]=-1;
        }else{
            stv[i]=1;
        }
        stv[i] = stv[i-1]+stv[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = stv[i]; j < 200002; j += j & -j){
            a[j] += 1;
        }
    }
    long long s = 0;
    for(int i = 1; i <= n; i++){
        long long sm = 0;
        for(int j = stv[i]-1; j > 0; j -= j & -j){
            sm += a[j];
        }
        s = s+sm;
        if(stv[i] < 100000){
            s++;
        }
        for(int j = stv[i]; j < 200002; j += j & -j){
            a[j] -= 1;
        }
    }
    stv[0] = 100000;
    k--;
    for(int i = 1; i <= n; i++){
        if(v[i] > k){
            stv[i]=-1;
        }else{
            stv[i]=1;
        }
        stv[i] = stv[i-1]+stv[i];
    }
    for(int i = 1; i <= 200002; i++){
        a[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = stv[i]; j < 200002; j += j & -j){
            a[j] += 1;
        }
    }
    long long s1 = 0;
    for(int i = 1; i <= n; i++){
        for(int j = stv[i]-1; j > 0; j -= j & -j){
            s1 += a[j];
        }
        if(stv[i] < 100000){
            s1++;
        }
        for(int j = stv[i]; j < 200002; j += j & -j){
            a[j] -= 1;
        }
    }
    fout << abs(s-s1);
    return 0;
}
