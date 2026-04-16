#include <fstream>
#include <map>
using namespace std;
ifstream fin("arcade.in");
ofstream fout("arcade.out");
int cer, t;
int n;
int v[100004], v2[100004];
char ics[1000004];
struct poz{
    int i, j, pasi=0;
}coada[1000004];
map<pair<int, int>, bool> f;
int main(){
    fin >> cer >> t;
    while(t){
        fin >> n;
        for(int i = 1; i <= n; i++){
            fin >> v[i];
            v2[v[i]] = i;
        }
        if(cer == 1){
            int l=1, c=1;
            fin.get();
            fin.get(ics, 1000004);
            fin.get();
            int i = 0;
            int bfrl = 0, bfrc = 0;
            bool castigat = false;
            while(ics[i] != 0){
                char x = ics[i];
                if(x == 'L'){
                    if(l == n && c < v[l]){
                        castigat = true;
                        break;
                    }
                    c = v[l]+1;
                }else if(x == 'R'){
                    if(l == n && c > v[l]){
                        castigat = true;
                        break;
                    }
                    c = v[l]-1;
                }else if(x == 'U'){
                    if(c == n && l < v2[c]){
                        castigat = true;
                        break;
                    }
                    l = v2[c]+1;
                }else if(x == 'D'){
                    if(c == n && l > v2[c]){
                        castigat = true;
                        break;
                    }
                    l = v2[c]-1;
                }
                if(l == 0){
                    l = n;
                }
                if(l == n+1){
                    l = 1;
                }
                if(c == 0){
                    c = n;
                }
                if(c == n+1){
                    c = 1;
                }
                //fout << l << ' ' << c << '\n';
                i++;
            }
            if(castigat || (l == n && c == n)){
                fout << "Won";
            }else{
                fout << "Lost";
            }
            fout << '\n';
        }else{
            int st = 1, dr = 1;
            coada[1].i = 1;
            coada[1].j = 1;
            coada[1].pasi = 0;
            int rasp = -1;
            while(st <= dr){
                int l1 = coada[st].i;
                int c1 = coada[st].j;
                int l, c;
                int pasi = coada[st].pasi+1;
                //fout << l1 << ' ' << c1 << ' ' << pasi << '\n';
                if(l1 == n && c1 == n){
                    rasp = pasi;
                    break;
                }
                //CAZUL 'L'
                l = l1, c = c1;
                if(l == n && c < v[l]){
                    rasp = pasi;
                    break;
                }
                c = v[l]+1;
                if(l == 0){l = n;}
                if(l == n+1){l = 1;}
                if(c == 0){c = n;}
                if(c == n+1){c = 1;}
                if(!f[{l,c}]){
                    dr++;
                    coada[dr].i = l;
                    coada[dr].j = c;
                    coada[dr].pasi = pasi;
                    f[{l,c}] = true;
                }
                //CAZUL 'R'
                l = l1, c = c1;
                if(l == n && c > v[l]){
                    rasp = pasi;
                    break;
                }
                c = v[l]-1;
                if(l == 0){l = n;}
                if(l == n+1){l = 1;}
                if(c == 0){c = n;}
                if(c == n+1){c = 1;}
                if(!f[{l,c}]){
                    dr++;
                    coada[dr].i = l;
                    coada[dr].j = c;
                    coada[dr].pasi = pasi;
                    f[{l,c}] = true;
                }
                //CAZUL 'U'
                l = l1, c = c1;
                if(c == n && l < v2[c]){
                    rasp = pasi;
                    break;
                }
                l = v2[c]+1;
                if(l == 0){l = n;}
                if(l == n+1){l = 1;}
                if(c == 0){c = n;}
                if(c == n+1){c = 1;}
                if(!f[{l,c}]){
                    dr++;
                    coada[dr].i = l;
                    coada[dr].j = c;
                    coada[dr].pasi = pasi;
                    f[{l,c}] = true;
                }
                //CAZUL 'D'
                l = l1, c = c1;
                if(c == n && l > v2[c]){
                    rasp = pasi;
                    break;
                }
                l = v2[c]-1;
                if(l == 0){l = n;}
                if(l == n+1){l = 1;}
                if(c == 0){c = n;}
                if(c == n+1){c = 1;}
                if(!f[{l,c}]){
                    dr++;
                    coada[dr].i = l;
                    coada[dr].j = c;
                    coada[dr].pasi = pasi;
                    f[{l,c}] = true;
                }
                st++;
            }
            f.clear();
            fout << rasp << '\n';
        }
        t--;
    }
    return 0;
}
