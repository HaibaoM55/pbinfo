#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("opsir.in");
ofstream fout("opsir.out");
int c;
int k;
int n, m;
char s[200004], t[200004];
int fs[27], ft[27];
int si[200004],ti[200004];
int main(){
    fin >> c;
    fin >> k;
    while(k){
        fin >> n >> m;
        for(int i = 0; i < 26; i++){
            fs[i] = 0;
            ft[i] = 0;
        }
        bool esortat = true;
        for(int i = 1; i <= n; i++){
            fin >> s[i];
            si[i] = s[i]-'a';
            if(i > 1 && s[i]-'a' < s[i-1]-'a'){
                esortat = false;
            }
            fs[s[i]-'a']++;
        }
        for(int i = 1; i <= m; i++){
            fin >> t[i];
            ti[i] = t[i]-'a';
            ft[t[i]-'a']++;
        }
        if(c == 1){
            int nr = 0;
            for(int i = 0; i < 26; i++){
                if(fs[i] != 0 || ft[i] != 0){
                    nr++;
                }
            }
            fout << nr << '\n';
            for(int i = 0; i < 26; i++){
                if(fs[i] > ft[i]){
                    fout << (char) (i+'a') << ' ' << 'S';
                    fout << '\n';
                }else if(ft[i] > fs[i]){
                    fout << (char) (i+'a') << ' ' << 'T';
                    fout << '\n';
                }else if(ft[i] == fs[i] && ft[i] != 0){
                    fout << (char) (i+'a') << ' ' << 'T';
                    fout << '\n';
                }
            }
        }else{
            if(esortat){
                bool ok = true;
                for(int i = 0; i < 26; i++){
                    if(fs[i] > ft[i]){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    fout << "DA\n";
                }else{
                    fout << "NU\n";
                }
            }else{
                /*
                int z = 1;
                for(int i = 1; i <= m; i++){
                    if(t[i] == s[z]){
                        z++;
                    }
                    if(z == n+1){
                        break;
                    }
                }
                if(z == n+1){
                    fout << "DA\n";
                }else{
                    fout << "NU\n";
                }
                */
                int z = 1;
                int pmax = 0;
                for(int i = 1; i <= m; i++){
                    if(ti[i] == si[z]){
                        z++;
                    }else{
                        int j = i;
                        while(ti[j] > si[z]){
                            j++;
                        }
                        if(j == m+1){
                            break;
                        }
                        if(ti[j] == si[z] && pmax < i){
                            sort(ti+i, ti+j+1);
                            pmax = j;
                        }else{
                            while(ti[j]-'a' != si[z]-'a'){
                                j++;
                            }
                            i = j;
                        }
                        z++;
                    }
                    if(z == n+1){
                        break;
                    }
                }
                if(z == n+1){
                    fout << "DA\n";
                }else{
                    fout << "NU\n";
                }
            }
        }
        k--;
    }
    return 0;
}
