#include <fstream>
#include <string.h>
#include <algorithm>
using namespace std;
ifstream fin("cufere.in");
ofstream fout("cufere.out");
int c, n;
struct obiectulCautat{
    int et = 0;
    int n = 0;
}v[105];
bool compara(obiectulCautat a, obiectulCautat b){
    if(a.n < b.n){
        return true;
    }
    return false;
}
int prime[30] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int main()
{
    fin >> c;
    fin >> n;
    for(int i = 1; i <= 3*n; i++){
        for(int j = 1; j <= 9; j++){
            char x[25];
            fin >> x;
            int l = strlen(x);
            int et;
            if(l > 1){
                et = (x[l-2]-'0')*10+x[l-1]-'0';
            }else{
                et = x[l-1]-'0';
            }
            int nr = 0;
            for(int i = 0; i <= l-3; i++){
                nr = nr*10+(x[i]-'0');
            }
            v[et].n = v[et].n+nr;
            v[et].et = et;
        }
    }
    if(c == 1){
        for(int i = 10; i <= 99; i++){
            if(v[i].n != 0){
                fout << v[i].et << " " << v[i].n << "\n";
            }
        }
    }else{
        int p = 0;
        for(int i = 1; i <= 100; i++){
            if(v[i].n != 0){
                bool ok = false;
                for(int j = 0; j <= 24; j++){
                    if(prime[j] == v[i].et){
                        ok = true;
                        break;
                    }
                }
                if(ok){
                    while(v[i].n > 16){
                        fout << 16 << v[i].et;
                        p++;
                        if(p % 9 ==0){
                            fout << "\n";
                        }else{
                            fout << " ";
                        }
                        v[i].n = v[i].n-16;
                    }
                }else{
                    while(v[i]. n > 64){
                        fout << 64 << v[i].et;
                        p++;
                        if(p % 9 ==0){
                            fout << "\n";
                        }else{
                            fout << " ";
                        }
                        v[i].n = v[i].n-64;
                    }
                }
                if(v[i].n > 0){
                    fout << v[i].n << v[i].et;
                    p++;
                    if(p % 9 == 0){
                        fout << "\n";
                    }else{
                        fout << " ";
                    }
                }
            }
        }
        while(p < 3*n*9){
            fout << 0;
            p++;
            if(p % 9 == 0){
                fout << "\n";
            }else{
                fout << " ";
            }
        }
    }
    return 0;
}
