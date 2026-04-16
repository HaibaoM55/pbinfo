#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("multimi.in");
ofstream fout("multimi.out");

int n;
char x[10004];
int v[20][10004];
char lit[20];
int stiva[304][30004];
int dr = 0;
char ex[1004];
int r[30004];
// op[k] = operatorul INAINTEA elementului k de pe stiva ('+' sau '*' sau 0)
char op[304];

void intersecteaza(){
    int p1 = 1, p2 = 1, zz = 0;
    while(p1 <= stiva[dr-1][0] && p2 <= stiva[dr][0]){
        if(stiva[dr-1][p1] < stiva[dr][p2]) p1++;
        else if(stiva[dr-1][p1] > stiva[dr][p2]) p2++;
        else{ r[++zz] = stiva[dr-1][p1]; p1++; p2++; }
    }
    dr--;
    stiva[dr][0] = zz;
    for(int k = 1; k <= zz; k++) stiva[dr][k] = r[k];
}

void reuneste(){
    int p1 = 1, p2 = 1, zz = 0;
    while(p1 <= stiva[dr-1][0] && p2 <= stiva[dr][0]){
        if(stiva[dr-1][p1] < stiva[dr][p2]) r[++zz] = stiva[dr-1][p1++];
        else if(stiva[dr-1][p1] > stiva[dr][p2]) r[++zz] = stiva[dr][p2++];
        else{ r[++zz] = stiva[dr-1][p1]; p1++; p2++; }
    }
    while(p1 <= stiva[dr-1][0]) r[++zz] = stiva[dr-1][p1++];
    while(p2 <= stiva[dr][0])   r[++zz] = stiva[dr][p2++];
    dr--;
    stiva[dr][0] = zz;
    for(int k = 1; k <= zz; k++) stiva[dr][k] = r[k];
}

void solve(int i, int j){
    int dr_start = dr;
    for(int z = i; z <= j; z++){
        char operator_curent = 0;
        if(z > i) operator_curent = ex[z-1];
        if(ex[z] == '('){
            int nrp = 1, oz = z;
            while(nrp != 0){
                z++;
                if(ex[z] == ')'){
                    nrp--;
                }
                else if(ex[z] == '('){
                    nrp++;
                }
            }
            solve(oz+1, z-1);
            op[dr] = operator_curent;
        }else if(ex[z] == '+' || ex[z] == '*'){
            continue;
        }else if(1 <= ex[z] && ex[z] <= n){
            int x1 = ex[z];
            dr++;
            for(int k = 0; k <= v[x1][0]; k++){
                stiva[dr][k] = v[x1][k];
            }
            op[dr] = operator_curent;
        }
        if(op[dr] == '*' && dr > dr_start + 1){
            intersecteaza();
        }
    }
    while(dr > dr_start + 1){
        reuneste();
    }
}

int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x;
        lit[i] = x[0];
        int j = 2;
        int a = 0;
        while('0' <= x[j] && x[j] <= '9'){ a = a*10+x[j]-'0'; j++; }
        j++;
        int b = 0;
        while('0' <= x[j] && x[j] <= '9'){ b = b*10+x[j]-'0'; j++; }
        j++;
        int c = 0;
        while('0' <= x[j] && x[j] <= '9'){ c = c*10+x[j]-'0'; j++; }
        for(int z = a; z <= b; z += c){
            v[i][0]++;
            v[i][v[i][0]] = z;
        }
    }
    fin >> ex;
    int l = strlen(ex);
    for(int i = 0; i < l; i++){
        if('A' <= ex[i] && ex[i] <= 'Z'){
            for(int j = 1; j <= n; j++){
                if(lit[j] == ex[i]){ ex[i] = j; break; }
            }
        }
    }
    solve(0, l-1);
    fout << stiva[1][0] << '\n';
    for(int i = 1; i <= stiva[1][0]; i++) fout << stiva[1][i] << ' ';
    return 0;
}
