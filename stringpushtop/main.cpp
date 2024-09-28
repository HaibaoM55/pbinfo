#include <iostream>
#include <string.h>
using namespace std;
char c[200004];
char v[100000];
int q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> c+100000;
    int k = 100000+strlen(c+100000);
    k--;
    int st  = 100000;
    bool rasturnat = false;
    cin >> q;
    for(int i = 1; i <= q; i++){
        short nr;
        char x;
        cin >> nr;
        /*
        (1, c) – se adaugă caracterul c la începutul string-ului
        (2, c) – se adaugă caracterul c la finalul string-ului
        (3) – se șterge primul caracter al string-ului
        (4) – se șterge ultimul caracter al string-ului
        (5) – string-ul se va transforma în răsturnatul său
        */
        if(nr == 1){
            cin >> x;
            if(!rasturnat){
                st--;
                c[st] = x;
            }else{
                k++;
                c[k] = x;
            }
        }else if(nr == 2){
            cin >> x;
            if(!rasturnat){
                k++;
                c[k] = x;
            }else{
                st--;
                c[st] = x;
            }
        }else if(nr == 3){
            if(!rasturnat){
                st++;
            }else{
                k--;
            }
        }else if(nr == 4){
            if(!rasturnat){
                k--;
            }else{
                st++;
            }
        }else{
            rasturnat = !rasturnat;
        }
    }
    if(rasturnat){
        for(int i = k; i >= st; i--){
            cout << c[i];
        }
    }else{
        for(int i = st; i <= k; i++){
            cout << c[i];
        }
    }
    return 0;
}
