#include <iostream>
#include <string.h>
using namespace std;
char x[1004], y[1004];
char cuvX[1004][25], cuvY[1004][25];
int nrCuvX = 0, nrCuvY = 0;
void extrageCuvinte(char text[], char cuv[1000][25], int &nr) {
    int len = strlen(text), poz = 0;
    char temp[25];
    int tempLen = 0;
    for(int i = 0; i <= len; i++){
        if('a' <= text[i] && text[i] <= 'z'){
            temp[tempLen++] = text[i];
        }else{
            if(tempLen > 0){
                temp[tempLen] = 0;
                strcpy(cuv[nr++], temp);
                tempLen = 0;
            }
        }
    }
}
bool estePrefix(char* prefix, char* cuvant) {
    int lenP = strlen(prefix), lenC = strlen(cuvant);
    if (lenP > lenC) return false;
    for(int i = 0; i < lenP; i++){
        if(prefix[i] != cuvant[i]){
            return false;
        }
    }
    return true;
}
int main() {
    cin.get(x, 1004);
    cin.get();
    cin.get(y, 1004);
    extrageCuvinte(x, cuvX, nrCuvX);
    extrageCuvinte(y, cuvY, nrCuvY);
    int nr = 0;
    for(int i = 0; i < nrCuvX; i++){
        for(int j = 0; j < nrCuvY; j++){
            if(estePrefix(cuvX[i], cuvY[j])){
                nr++;
                break;
            }
        }
    }
    cout << nr;
    return 0;
}
