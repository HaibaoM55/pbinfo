#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("changecase.in");
ofstream fout("changecase.out");
char tip[50];
char x[256], y[256];
int z =0 ;
int main(){
    fin.getline(tip, 50);
    fin.getline(x, 256);
    int l = strlen(x);
    if(strcmp(tip, "lowercase") == 0){
        for(int i = 0; i < l; i++){
            if('A' <= x[i] && x[i] <= 'Z'){
                x[i] = x[i]-'A'+'a';
            }
        }
        fout << x;
    }else if(strcmp(tip, "UPPERCASE") == 0){
        for(int i = 0; i < l; i++){
            if('a' <= x[i] && x[i] <= 'z'){
                x[i] = x[i]-'a'+'A';
            }
        }
        fout << x;
    }else if(strcmp(tip, "TitleCase") == 0){
        z = 0;
        for(int i = 0; i <= l; i++){
            if(('a' <= x[i] && x[i] <= 'z') || ('A' <= x[i] && x[i] <= 'Z')){
                y[z] = x[i];
                z++;
            }else{
                if(z > 0){
                    if('a' <= y[0] && y[0] <= 'z'){
                        y[0] = y[0]-'a'+'A';
                    }
                    for(int j = 1; j < z; j++){
                        if('A' <= y[j] && y[j] <= 'Z'){
                            y[j] = y[j]-'A'+'a';
                        }
                    }
                    y[z] = 0;
                    fout << y;
                }
                fout << x[i];
                z = 0;
            }
        }
    }else if(strcmp(tip, "iNVERTcASE") == 0){
        z = 0;
        for(int i = 0; i <= l; i++){
            if(('a' <= x[i] && x[i] <= 'z') || ('A' <= x[i] && x[i] <= 'Z')){
                y[z] = x[i];
                z++;
            }else{
                if(z > 0){
                    if('A' <= y[0] && y[0] <= 'Z'){
                        y[0] = y[0]-'A'+'a';
                    }
                    for(int j = 1; j < z; j++){
                        if('a' <= y[j] && y[j] <= 'z'){
                            y[j] = y[j]-'a'+'A';
                        }
                    }
                    y[z] = 0;
                    fout << y;
                    z = 0;
                }
                fout << x[i];
            }
        }
    }else{
        int i = 0;
        for(i; i < l; i++){
            if('a' <= x[i] && x[i] <= 'z'){
                x[i] = x[i]-'a'+'A';
            }
            if(('a' <= x[i] && x[i] <= 'z') || ('A' <= x[i] && x[i] <= 'Z')){
                i++;
                break;
            }
        }
        for(i; i < l; i++){
            if('A' <= x[i] && x[i] <= 'Z'){
                x[i] = x[i]-'A'+'a';
            }
        }
        fout << x;
    }
    return 0;
}
