#include <fstream>
#include <vector>
using namespace std;
ifstream fin("detdrum3.in");
ofstream fout("detdrum3.out");
int n;
int t[104], s[104];
vector<int> v[104];
struct varf{
    int smax, copil = -1, terminal = -1;
}vf[104];
int rad;
void smax(int k){
    int vmax = 0;
    int l = v[k].size();
    if(l == 0){
        vf[k].smax = s[k];
        vf[k].terminal = k;
    }else{
        int vmax = 0, term = 0, copil = 0;
        for(int i = 0; i < l; i++){
            smax(v[k][i]);
            if(vf[v[k][i]].smax > vmax){
                vmax = vf[v[k][i]].smax;
                copil = v[k][i];
                term = vf[v[k][i]].terminal;
            }else if(vf[v[k][i]].smax == vmax){
                if(vf[v[k][i]].terminal < term){
                    term = vf[v[k][i]].terminal;
                    copil = v[k][i];
                }
            }
        }
        vf[k].smax = s[k]+vmax;
        vf[k].copil = copil;
        vf[k].terminal = term;
    }
}
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> t[i];
        v[t[i]].push_back(i);
        if(t[i] == 0){
            rad = i;
        }
    }
    for(int i = 1; i <= n; i++){
        fin >> s[i];
    }
    smax(rad);
    fout << vf[rad].smax << '\n';
    while(vf[rad].copil != -1){
        fout << rad << ' ';
        rad = vf[rad].copil;
    }
    fout << rad;
    return 0;
}
