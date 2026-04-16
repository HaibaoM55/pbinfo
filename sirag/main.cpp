#include <fstream>
using namespace std;
#define MOD 1000000007
ifstream fin("sirag.in");
ofstream fout("sirag.out");
int n;
char s[1000004], s1[1000004];
int ciur[1000004];
int f[32];
bool toateegale=true, toatedistincte=true;
void clearfrecv(){
    for(int i = 0; i < 26; i++){
        f[i] = 0;
    }
}
int main(){
    fin >> n;
    for(int i = 0; i < n; i++){
        fin >> s[i];
        if(i > 0){
            if(s[i] == s[i-1]){
                toatedistincte = false;
            }else{
                toateegale = false;
            }
        }
    }
    if(toatedistincte){
        for(int i = 2; i <= n; i++){
            for(int j = i; j <= n; j+= i){
                ciur[j]++;
            }
        }
        int z = 1;
        long long nr = 0;
        for(int i = n; i >= 1; i--){
            nr += ciur[i]*z;
            nr = nr % MOD;
            z++;
        }
        fout << nr;
    }else if(toateegale){
        int z = n-1;
        long long nr = 0;
        long long p = 1;
        for(int i = 2; i <= n; i++){
            p = p*2;
            p = p%MOD;
            nr += (z*((p-1+MOD)%MOD))%MOD;
            nr = nr %MOD;
            z--;
            //C(i,1)+...C(i,i)=2^(i-1)-1;
        }
        fout << nr;
    }else{
        long long nr = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                s1[j-i] = s[j];
                s1[j-i+1] = 0;
                if(j == i){
                    continue;
                }
                fout << nr << '\n';
                fout << s1 << ' ';
                int l = j-i+1;
                for(int nrdist = 1; nrdist <= 26; nrdist++){
                    long long nrt = 1;
                    int st = -1, dr = 0;
                    bool macarodata = false;
                    int nrd = 0;
                    for(int i = 0; i < l; i++){
                        f[s1[i]-'a']++;
                        if(f[s1[i]-'a'] == 1){
                            nrd++;
                        }
                        if(nrd == nrdist && st == -1){
                            st = i;
                        }
                        if(nrd == nrdist+1){
                            dr = i-1;
                            macarodata = true;
                            nrt = nrt*(dr-st+1);
                            nrt = nrt % MOD;
                            st = -1;
                            clearfrecv();
                            nrd=0;
                            i--;
                        }
                    }
                    if(nrd != nrdist){
                        nrt = 0;
                    }
                    clearfrecv();
                    nr += nrt;
                    nr = nr % MOD;
                }
            }
        }
        fout << nr;
    }
    return 0;
}
