#include <iostream>
#include <string.h>
#include <climits>
using namespace std;
char x[260];
long long vmax = INT_MIN;
long long nrx=0, nry=0, nrz=0;
bool folx=false, foly=false, folz=false;
int nr = 0;
bool splus = true;
void faraspatiu(char *str)
{
    int cnt = 0;
    for (int i = 0; str[i]; i++)
        if (str[i] != ' ')
            str[cnt++] = str[i];
    str[cnt] = 0;
}
int main()
{
    cin.getline(x, 260);
    faraspatiu(x);
    int l = strlen(x);
    for(int i = 0; i < l; i++){
        if(x[i] == '-'){
            splus = false;
        }else if(x[i] == '+'){
            splus = true;
        }else if(x[i] != ' '){
            bool exista = false;
            int nr = 0;
            while('0' <= x[i] && x[i] <= '9'){
                nr = nr*10+(x[i]-'0');
                exista = true;
                i++;
            }
            if(!exista){
                nr = 1;
            }
            if(x[i] == 'x'){
                folx = true;
                if(splus){
                    nrx += nr;
                }else{
                    nrx -= nr;
                }
            }else if(x[i] == 'y'){
                foly = true;
                if(splus){
                    nry += nr;
                }else{
                    nry -= nr;
                }
            }else if(x[i] == 'z'){
                folz = true;
                if(splus){
                    nrz += nr;
                }else{
                    nrz -= nr;
                }
            }
        }
    }
    if(folx == false){
        nrx = INT_MIN;
    }
    if(foly == false){
        nry = INT_MIN;
    }
    if(folz == false){
        nrz = INT_MIN;
    }
    if(nrx > nry && nrx > nrz){
        cout << nrx << 'x';
    }
    if(nry > nrx && nry > nrz){
        cout << nry << 'y';
    }
    if(nrz > nrx && nrz > nry){
        cout << nrz << 'z';
    }
    return 0;
}
