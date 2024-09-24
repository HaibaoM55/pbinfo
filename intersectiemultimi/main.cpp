#include <iostream>
#include <string.h>
using namespace std;
int n;
char x[100001];
struct numar{
    char nr[2001];
    char tip;
}v[51];
int nrn = 0;
int main()
{
    cin >> n;
    cin.get();
    cin.get(x, 100001);
    char *p;
    p = strtok(x," ");
    while(p != 0){
        nrn++;
        strcpy(v[nrn].nr, p);
        if(strchr(p, '.') == 0 && strchr(p, '-') == 0){
            v[nrn].tip = 'N';
        }
        if(strchr(p,'.') == 0 && strchr(p, '-') != 0){
            v[nrn].tip = 'Z';
        }
        if(strchr(p, '.') != 0 && strstr(p, "...") == 0){
            v[nrn].tip = 'Q';
        }
        if(strstr(p, "...") != 0){
            v[nrn].tip = 'I';
        }
        p = strtok(0, " ");
    }
    bool ok = false;
    for(int i = 1; i <= nrn; i++){
        if(v[i].tip == 'N'){
            ok = true;
            cout << v[i].nr << ' ';
        }
    }
    if(ok == false){
        cout <<"Multime vida";
    }
    cout << '\n';
    ok = false;
    for(int i = 1; i <= nrn; i++){
        if(v[i].tip == 'N' || v[i].tip == 'Z'){
            ok = true;
            cout << v[i].nr << ' ';
        }
    }
    if(ok == false){
        cout <<"Multime vida";
    }
    cout << '\n';
    ok = false;
    for(int i = 1; i <= nrn; i++){
        if(v[i].tip == 'N' || v[i].tip == 'Z' || v[i].tip == 'Q'){
            ok = true;
            cout << v[i].nr << ' ';
        }
    }
    if(ok == false){
        cout <<"Multime vida";
    }
    cout << '\n';
    ok = false;
    for(int i = 1; i <= nrn; i++){
        if(v[i].tip == 'I'){
            ok = true;
            cout << v[i].nr << ' ';
        }
    }
    if(ok == false){
        cout <<"Multime vida";
    }
    return 0;
}
