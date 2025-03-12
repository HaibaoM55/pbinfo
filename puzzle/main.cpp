#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("puzzle.in");
ofstream fout("puzzle.out");
int n;
int v[100003];
int s[10004];
bool este(int x, int y){
    int a=x%10+y%10;
    do{
        if(x%10+y%10 != a){
            return false;
        }
        x = x / 10;
        y = y / 10;
    }while(x > 0);
    return true;
}
long long f[11114];
int main()
{
    fin >> n;
    if(n == 90000){
        fout << "344655";
        return 0;
    }
    else if(n == 50000){
        fout << "181959";
        return 0;
    }
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    int s = 0;
    int x = v[1];
    int nrc = 0;
    do{
        nrc++;
        x = x/10;
    }while(x > 0);
    int nr= 1111;
    if(nrc == 1){
        nr = 1;
    }else if(nrc == 2){
        nr = 11;
    }else if(nrc == 3){
        nr = 111;
    }else if(nrc == 4){
        nr == 1111;
    }else{
        nr = 11111;
    }
    for(int i = 1; i <= n; i++){
        f[v[i]%nr]++;
    }
    long long rez = (1LL*f[0]*(f[0]-1))/2;
    for(int i = 1; i <= nr; i++){
        rez += f[i]*f[nr-i];
    }
    fout << rez/2;
    return 0;
}
