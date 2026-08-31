#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
char s[14], voc[14], cons[14];
string rasp[100004];
bool estevocala(char x){
    return (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u');
}
int main(){
    cin >> s;
    int l = strlen(s);
    sort(s, s+l);
    int v = 0, c = 0;
    for(int i = 0; i < l; i++){
        if(estevocala(s[i])){
            voc[v] = s[i];
            v++;
        }else{
            cons[c] = s[i];
            c++;
        }
    }
    if(c == v){
        int nr = 0;
        do{
            do{
                string r = "";
                for(int i = 0; i < l; i++){
                    if(i % 2 == 0){
                        r += cons[i/2];
                    }else{
                        r += voc[i/2];
                    }
                }
                nr++;
                rasp[nr] = r;
                r = "";
                for(int i = 0; i < l; i++){
                    if(i % 2 == 0){
                        r += voc[i/2];
                    }else{
                        r += cons[i/2];
                    }
                }
                nr++;
                rasp[nr] = r;
            }while(next_permutation(cons, cons+c));
        }while(next_permutation(voc, voc+v));
        sort(rasp+1, rasp+nr+1);
        for(int i = 1; i <= nr; i++){
            cout << rasp[i] << '\n';
        }
    }else{
        if(v == c+1){
            int nr = 0;
            do{
                do{
                    string r = "";
                    for(int i = 0; i < l; i++){
                        if(i % 2 == 0){
                            r += voc[i/2];
                        }else{
                            r += cons[i/2];
                        }
                    }
                    nr++;
                    rasp[nr] = r;
                }while(next_permutation(cons, cons+c));
            }while(next_permutation(voc, voc+v));
            sort(rasp+1, rasp+nr+1);
            for(int i = 1; i <= nr; i++){
                cout << rasp[i] << '\n';
            }
        }else if(c == v+1){
            int nr = 0;
            do{
                do{
                    string r = "";
                    for(int i = 0; i < l; i++){
                        if(i % 2 == 0){
                            r += cons[i/2];
                        }else{
                            r += voc[i/2];
                        }
                    }
                    nr++;
                    rasp[nr] = r;
                }while(next_permutation(cons, cons+c));
            }while(next_permutation(voc, voc+v));
            sort(rasp+1, rasp+nr+1);
            for(int i = 1; i <= nr; i++){
                cout << rasp[i] << '\n';
            }
        }else{
            cout << "IMPOSIBIL";
        }
    }
    return 0;
}
