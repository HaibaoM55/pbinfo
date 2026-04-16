#include <fstream>
#include <string.h>
using namespace std;
#define int long long
#define MOD 1999999973
ifstream fin("anagrame.in");
ofstream fout("anagrame.out");
int c, n, q;
char x[200004];
int f1[27], f2[27], f[27];
int fmin[27];
long long fact[200004], inv_fact[200004];
int st[27][10004], dr[27][10004];
int invers(int b){
    long long rasp=1;
    int rr = MOD-2;
    while(rr){
        if(rr % 2 == 1){
            rasp=(1LL*rasp*b)%MOD;
        }
        b=(1LL*b*b)%MOD;
        rr = rr/2;
    }
    return rasp;
}
void generare(int x1, int y1){
    for(int i = y1; i >= x1; i--){
        if(f2[x[i]-'a'] == 0){
            f2[x[i]-'a'] = i;
        }
    }
    for(int i = x1; i <= y1; i++){
        if(f1[x[i]-'a'] == 0){
            f1[x[i]-'a'] = i;
        }
    }
    if(c == 1){
        bool ok = true;
        for(int i = 0; i < 26; i++){
            if(f2[i]-f1[i] < fmin[i]){
                ok = false;
                break;
            }else if(f2[i]-f1[i] > fmin[i]){
                ok = true;
                break;
            }
        }
        for(int i = 0; i < 26; i++){
            if(ok){
                fmin[i] = f2[i]-f1[i];
            }
        }
    }else{
        int s = 0;
        for(int i = 0; i < 26; i++){
            f[i] = f2[i]-f1[i];
            s = s + f[i];
        }
        long long rasp = fact[s];
        for(int i = 0; i < 26; i++){
           rasp = rasp * inv_fact[f[i]];
           rasp = rasp % MOD;
        }
        fout << rasp << '\n';
    }
    for(int i = 0; i < 26; i++){
        f1[i] = 0;
        f2[i] = 0;
        f[i] = 0;
    }
}
char chr[1004];
bool lafel = true;
bool doarab = true;
int fa=0, fb =0;
void genfara(int x1, int y1){
    for(int i = 0; i < 26; i++){
        f2[i] = st[i][y1];
        f1[i] = dr[i][x1];
        if(f2[i]-f1[i] < 0){
            f2[i] = 67;
            f1[i] = 67;
        }
    }
    bool ok = true;
    for(int i = 0; i < 26; i++){
        if(f2[i]-f1[i] < fmin[i]){
            ok = false;
            break;
        }else if(f2[i]-f1[i] > fmin[i]){
            ok = true;
            break;
        }
    }
    for(int i = 0; i < 26; i++){
        if(ok){
            fmin[i] = f2[i]-f1[i];
        }
        f1[i] = 0;
        f2[i] = 0;
    }
}
signed main(){
    fin >> c >> n >> q;
    for(int i = 1; i <= n; i++){
        fin >> x[i];
        if(i > 1 && x[i] != x[i-1]){
            lafel = false;
        }
        if(x[i] == 'a'){
            fa++;
        }else if(x[i] == 'b'){
            fb++;
        }else{
            doarab = false;
        }
    }
    if(n <= 10000){
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < 26; j++){
                st[j][i] = st[j][i-1];
            }
            st[x[i]-'a'][i] = i;
        }
        for(int i = 0; i < 26; i++){
            dr[i][n+1] = n+1;
        }
        for(int i = n; i >= 1; i--){
            for(int j = 0; j < 26; j++){
                dr[j][i] = dr[j][i+1];
            }
            dr[x[i]-'a'][i] = i;
        }
    }
    if(c == 2){
        fact[0] = 1;
        for(int i = 1; i <= n; i++){
            fact[i] = fact[i-1]*i;
            fact[i] = fact[i]%MOD;
        }
        inv_fact[0] = 1;
        for(int i = 1; i <= n; i++){
            inv_fact[i] = invers(fact[i]);
            inv_fact[i] = inv_fact[i]%MOD;
        }
    }
    fin.get();
    int vmin = 2e9;
    bool faraactualizari = true;
    for(int i = 1; i <= q; i++){
        fin.get(chr, 1004);
        fin.get();
        int l = strlen(chr);
        int x1 = 0, y1 = 0;
        char val = '0';
        int j = 0;
        while('0' <= chr[j] && chr[j] <= '9'){
            x1 = x1*10+chr[j]-'0';
            j++;
        }
        if(x1 == 0){
            val = chr[j];
            j++;
        }
        j++;
        while('0' <= chr[j] && chr[j] <= '9'){
            y1 = y1*10+chr[j]-'0';
            j++;
        }
        if(c == 1 && n > 500 && lafel){
            vmin = min(vmin, y1-x1+1);
            continue;
        }
        if(c == 2 && n > 500 && lafel){
            fout << "1\n";
            continue;
        }
        if(val == '0'){
            if(c == 1 && n <= 10000 && faraactualizari){
                genfara(x1, y1);
                continue;
            }
            generare(x1, y1);
        }else{
            faraactualizari = false;
            if(x[y1] == 'a'){
                fa--;
            }else{
                fb--;
            }
            if(val == 'a'){
                fa++;
            }else{
                fb++;
            }
            x[y1] = val;
        }
    }
    if(c == 1){
        if(n > 500 && lafel){
            for(int i = 1; i <= vmin-1; i++){
                fout << x[1];
            }
        }else{
            for(int i = 0; i < 26; i++){
                while(fmin[i]){
                    fout << (char)(i+'a');
                    fmin[i]--;
                }
            }
        }
    }
    return 0;
}
