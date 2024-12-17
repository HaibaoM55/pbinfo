#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("aproape.in");
ofstream fout("aproape.out");
int c, n;
char x[101];
int l;
int cate_sunt_aproape(int j){
    int n1 = 0;
    for(int i = j+1; i <= l-1; i++){
        if(x[i] == '9'){
            n1++;
        }else if(x[i] == '0'){
            n1++;
        }else if(x[i] == '1' && i == 0 && l > 1){
            n1++;
        }
        else{
            n1 = n1 + 2;
        }
    }
    return n1;
}
int main()
{
    fin >>c;
    fin >> x;
    l = strlen(x);
    if(c == 1){
        fout << l;
    }
    n = 0;
    if(c == 2){
        for(int i = 0; i <= l-1; i++){
            if(x[i] == '9'){
                n++;
            }else if(x[i] == '0'){
                n++;
            }else if(x[i] == '1' && i == 0 && l > 1){
                n++;
            }
            else{
                n = n + 2;
            }
        }
        fout << n;
    }
    if(c == 3){
        n = 1;
        for(int i = 0; i <= l-1; i++){
            if(x[i] == '9'){
                x[i] = '8';
                n = n + cate_sunt_aproape(i);
                n++;
            }else if(x[i] == '0'){
                x[i] = '1';
                n++;
                n = n + cate_sunt_aproape(i);
            }else if(x[i] == '1' && i == 0 && l > 1){
                x[i] = '2';
                n++;
                n = n + cate_sunt_aproape(i);
            }
            else{
                if(x[i] == '8' || x[i] == '1' || (x[i] == '2' && i == 0 && l > 1)){
                    n++;
                }else{
                    n = n+2;
                }
                x[i] = ((x[i]-'0')+1)+'0';
                n = n + cate_sunt_aproape(i);
                x[i] = ((x[i]-'0')-1)+'0';
                x[i] = ((x[i]-'0')-1)+'0';
                n = n + cate_sunt_aproape(i);
            }
        }
        fout << n;
    }
    return 0;
}
