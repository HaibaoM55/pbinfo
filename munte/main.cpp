#include <fstream>
#include <map>
#include <vector>
using namespace std;
ifstream fin("munte.in");
ofstream fout("munte.out");
int n, c;
int v[200004];
map<vector<int>, bool> f;
int s = 0;
bool verif(vector<int> a){
    int i1=n;
    for(int i = 0; i < n-1; i++){
        if(a[i] > a[i+1]){
            i1 = i;
            break;
        }
    }
    bool ok = true;
    for(int i = i1; i < n-1; i++){
        if(a[i] < a[i+1]){
            ok = false;
            break;
        }
    }
    if(ok){
        return true;
    }else{
        bool ok = false;
        for(int p = 0; p < n; p++){
            swap(a[p], a[n-p-1]);
            if(!f[a]){
                f[a] = true;
                if(verif(a)){
                    ok = true;
                    break;
                }
            }
            swap(a[p], a[n-p-1]);
        }
        if(ok){
            return true;
        }
        for(int p = 0; p < n && !ok; p++){
            for(int q = 0; q < n; q++){
                swap(a[p], a[q]);
                swap(a[n-p-1], a[n-q-1]);
                if(!f[a]){
                    f[a] = true;
                    if(verif(a)){
                        ok = true;
                        break;
                    }
                }
                swap(a[p], a[q]);
                swap(a[n-p-1], a[n-q-1]);
            }
        }
        if(ok){
            return true;
        }
    }
    return false;
}
int verif2(vector<int> a){
    int i1=n;
    for(int i = 0; i < n-1; i++){
        if(a[i] > a[i+1]){
            i1 = i;
            break;
        }
    }
    bool ok = true;
    for(int i = i1; i < n-1; i++){
        if(a[i] < a[i+1]){
            ok = false;
            break;
        }
    }
    int nr = 0;
    if(ok){
        nr++;
//        for(int i = 0; i < n; i++){
//            fout << a[i] << ' ';
//        }
//        fout << '\n';
    }else{
        for(int p = 0; p < n; p++){
            swap(a[p], a[n-p-1]);
            if(!f[a]){
                f[a] = true;
                nr += verif2(a);
            }
            swap(a[p], a[n-p-1]);
        }
        for(int p = 0; p < n && !ok; p++){
            for(int q = 0; q < n; q++){
                swap(a[p], a[q]);
                swap(a[n-p-1], a[n-q-1]);
                if(!f[a]){
                    f[a] = true;
                    nr += verif2(a);
                }
                swap(a[p], a[q]);
                swap(a[n-p-1], a[n-q-1]);
            }
        }
    }
    return nr;
}
vector<int> b;
int main(){
    fin >> c >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        b.push_back(v[i]);
    }
    f[b] = true;
    if(c == 1){
        if(verif(b)){
            fout << "DA";
        }else{
            fout << "NU";
        }
    }else{
        fout << verif2(b);
    }
    return 0;
}
