#include <fstream>
using namespace std;
ifstream fin("leftmax.in");
ofstream fout("leftmax.out");
#define MOD 1000000007
int n;
struct nr{
    int x;
    int st, dr;
}v[100004];
int stiva[100004];
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i].x;
    }
    int nr = 0;
    v[1].st = 1;
    int dr = 1;
    stiva[1] = 1;
    for(int i = 2; i <= n; i++){
        bool ok = false;
        while(dr >= 1 && v[stiva[dr]].x < v[i].x){
            ok = true;
            v[i].st = v[stiva[dr]].st;
            dr--;
        }
        dr++;
        stiva[dr] = i;
        if(!ok){
            v[i].st = i;
        }
    }
    dr = 1;
    stiva[1] = n;
    v[n].dr = n;
    for(int i = n-1; i >= 1; i--){
        bool ok = false;
        while(dr >= 1 && v[stiva[dr]].x < v[i].x){
            ok = true;
            v[i].dr = v[stiva[dr]].dr;
            dr--;
        }
        dr++;
        stiva[dr] = i;
        if(!ok){
            v[i].dr = i;
        }
    }
    /*for(int i = 1; i <= n; i++){
        fout << v[i].x << ' ' << v[i].st << ' ' << v[i].dr << '\n';
    }*/
    for(int i = 1; i <= n; i++){
        //st = 0 => nr += v[i].dr
        //st = 1 => nr += v[i].dr-1
        //v[i].dr-i+1-i-v[i].st =v[i].dr-v[i].st-2*i+1
        //                                          +2
        //v[i].dr-i+1
        int j = i-v[i].st;
        int p1 = max(1, v[i].dr-i+1-j)-1;
        int p2 = v[i].dr-i+1;
        nr += ((1LL*p2*(p2+1))/2)-((1LL*p1*(p1+1))/2);
        nr = nr % MOD;
    }
    fout << nr;
    return 0;
}
