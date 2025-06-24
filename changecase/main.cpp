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
        for(int i = 0; i < l; i++){
            if(i == 0){
                if('a' <= x[i] && x[i] <= 'z'){
                    x[i] = x[i]-'a'+'A';
                }
            }else{
                if(strchr(".,; ", x[i-1])){
                    if('a' <= x[i] && x[i] <= 'z'){
                        x[i] = x[i]-'a'+'A';
                    }
                }else{
                    if('A' <= x[i] && x[i] <= 'Z'){
                        x[i] = x[i]-'A'+'a';
                    }
                }
            }
        }
        fout << x;
    }else if(strcmp(tip, "iNVERTcASE") == 0){
        for(int i = 0 ; i < l; i ++){
            if(i == 0){
                if('A' <= x[i] && x[i] <= 'Z'){
                    x[i] = x[i]-'A'+'a';
                }
            }else{
                if(strchr(".,; ", x[i-1])){
                    if('A' <= x[i] && x[i] <= 'Z'){
                        x[i] = x[i]-'A'+'a';
                    }
                }else{
                    if('a' <= x[i] && x[i] <= 'z'){
                        x[i] = x[i]-'a'+'A';
                    }
                }
            }
        }
        fout << x;
    }else{
        bool inprop = true;
        for(int i = 0; i < l; i++){
            if(x[i] == '.'){
                inprop = true;
            }else if('a' <= x[i] && x[i] <= 'z'){
                if(inprop){
                    x[i] = x[i]-'a'+'A';
                }
                inprop = false;
            }else if('A' <= x[i] && x[i] <= 'Z'){
                if(!inprop){
                    x[i] = x[i]-'A'+'a';
                }
                inprop = false;
            }
        }
        fout << x;
    }
    return 0;
}
