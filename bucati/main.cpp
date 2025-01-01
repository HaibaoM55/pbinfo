#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("bucati.in");
ofstream fout("bucati.out");
int c;
char x[12];
int v[12];
bool esteprim(int x){
    if(x < 2){
        return false;
    }
    for(int j = 2; j*j <= x; j++){
        if(x % j == 0){
            return false;
        }
    }
    return true;
}
int main()
{
    fin >> c;
    fin >> x;
    int l = strlen(x);
    for(int i = 0; i < l; i++){
        v[i+1] = x[i]-'0';
    }
    if(c == 1){
        int s = 0;
        int smax = 0;
        for(int i = 1; i <= l; i++){
            s = 0;
            if(i > 2){
                for(int j = i; j <= l; j++){
                    s = s*10+v[j];
                }
                for(int j = 1; j <= i-3; j++){
                    s = s*10+v[j];
                }
                s = s+v[i-2]+v[i-1];
            }else if(i == 1){
                for(int j = 1; j <= l-2; j++){
                    s = s*10+v[j];
                }
                s = s+v[l-1]+v[l];
            }else if(i == 2){
                for(int j = 2; j <= l-1; j++){
                    s = s*10+v[j];
                }
                s = s + v[l]+ v[1];
            }
            smax = max(smax, s);
        }
        fout << smax;
    }else{
        int s = 0;
        int smin = 1000000000;
        for(int i = 1; i <= l; i++){
            s = s + v[i];
        }
        //incercam mai intai cu 2 cifre
        for(int i = 1; i <= l-1; i++){
            int s1 = s;
            s1 = s1-v[i]-v[i+1];
            s1 = s1+v[i]*10+v[i+1];
            if(s1 < smin){
                if(esteprim(s1)){
                    smin = s1;
                }
            }
        }
        int s1 = s;
        s1 = s1-v[l]-v[1];
        s1 = s1+v[l]*10+v[1];
        if(s1 < smin){
            if(esteprim(s1)){
                smin = s1;
            }
        }
        //incercam apoi cu 3 cifre
        for(int i = 1; i <= l-2; i++){
            int s1 = s;
            s1 = s1-v[i]-v[i+1]-v[i+2];
            s1 = s1+v[i]*100+v[i+1]*10+v[i+2];
            if(s1 < smin){
                if(esteprim(s1)){
                    smin = s1;
                }
            }
        }
        s1 = s;
        s1 = s-v[l-1]-v[l]-v[1];
        s1 = s1+v[l-1]*100+v[l]*10+v[1];
        if(s1 < smin){
            if(esteprim(s1)){
                smin = s1;
            }
        }
        s1 = s;
        s1 = s-v[l]-v[1]-v[2];
        s1 = s1+v[l]*100+v[1]*10+v[2];
        if(s1 < smin){
            if(esteprim(s1)){
                smin = s1;
            }
        }
        fout << smin;
    }
    return 0;
}
