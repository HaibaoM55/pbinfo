/*PART1
#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("input");
ofstream fout("output");
char x[50];
int nr = 0;
struct range{
    long long st, dr;
}v[204];
long long n;
int main(){
    for(int i = 1; i <= 200; i++){
        fin.get(x, 50);
        fin.get();
        if(x[0] == 0){
            break;
        }
        int l = strlen(x);
        nr++;
        v[nr].st = 0;
        int j = 0;
        while(x[j] != '-'){
            v[nr].st = v[nr].st*10+(x[j]-'0');
            j++;
        }
        j++;
        v[nr].dr = 0;
        while(j < l){
            v[nr].dr = v[nr].dr*10+(x[j]-'0');
            j++;
        }
        if(v[nr].st > v[nr].dr){
            swap(v[nr].st, v[nr].dr);
        }
    }
    int ans = 0;
    for(int zz = 1; zz <= 1000; zz++){
        fin >> n;
        bool ok = false;
        for(int i = 1; i <= nr; i++){
            if(v[i].st <= n && n <= v[i].dr){
                ok = true;
                break;
            }
        }
        if(ok){
            ans++;
        }
    }
    fout << ans;
    return 0;
}
*/
//PART 2:
#include <fstream>
#include <string.h>
#include <algorithm>
using namespace std;
ifstream fin("input");
ofstream fout("output");
char x[50];
int nr = 0;
struct range{
    long long st, dr;
}v[204];

bool compara(range a, range b){
    return a.st < b.st;
}

int main(){
    for(int i = 1; i <= 200; i++){
        fin.get(x, 50);
        fin.get();
        if(x[0] == 0){
            break;
        }
        int l = strlen(x);
        nr++;
        v[nr].st = 0;
        int j = 0;
        while(x[j] != '-'){
            v[nr].st = v[nr].st*10+(x[j]-'0');
            j++;
        }
        j++;
        v[nr].dr = 0;
        while(j < l){
            v[nr].dr = v[nr].dr*10+(x[j]-'0');
            j++;
        }
        if(v[nr].st > v[nr].dr){
            swap(v[nr].st, v[nr].dr);
        }
    }
    sort(v+1, v+nr+1, compara);
    long long ans = 0;
    long long st = v[1].st;
    long long dr = v[1].dr;
    for(int i = 2; i <= nr; i++){
        if(v[i].st <= dr + 1){
            dr = max(dr, v[i].dr);
        }else{
            ans += dr - st + 1;
            st = v[i].st;
            dr = v[i].dr;
        }
    }
    ans += dr - st + 1;
    fout << ans;
    return 0;
}
