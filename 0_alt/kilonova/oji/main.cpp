#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("oji.in");
ofstream fout("oji.out");
int n;
struct concurent{
    int r1, r2, i;
}v[500004];
bool compara1(concurent a, concurent b)
{
    if (a.r1<b.r1){
        return true;
    }else if(a.r1 == b.r1){
        return a.r2>b.r2;
    }
    return false;
}
bool compara2(concurent a, concurent b)
{
    if (a.r1>b.r1){
        return true;
    }
    else if(a.r1 == b.r1){
        return a.r2<b.r2;
    }
    return false;
}
int a[500004], b[500004];
int f[654];
int fa[654], fb[654];
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i].r1 >> v[i].r2;
        v[i].i = i;
        if(v[i].r1 == 0){
            fa[v[i].r2]++;
        }
        if(v[i].r2 == 0){
            fb[v[i].r1]++;
        }
    }
    sort(v+1, v+1+n, compara1);
    for(int i =1; i <= n; i++){
        int z = 0;
        for(int j = 0; j < v[i].r2; j++){
            z += f[j];
        }
        if(v[i].r2 == 650){
            z += fb[v[i].r1];
        }
        if(v[i].r1 == 650){
            z += fa[v[i].r2];
        }
        b[v[i].i] = n-z;
        f[v[i].r2]++;
    }
    for(int i = 0; i <= 650; i++){
        f[i] = 0;
    }
    sort(v+1, v+n+1, compara2);
    for(int i = 1; i <= n; i++){
        int z = 1;
        for(int j = v[i].r2+1; j <= 650; j++){
            z += f[j];
        }
        a[v[i].i] = z;
        f[v[i].r2]++;
    }
    for(int i = 1; i <= n; i++){
        fout << a[i] << ' '<< b[i] << '\n';
    }
    return 0;
}
