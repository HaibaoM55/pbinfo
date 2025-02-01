#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("matematica.in");
ofstream fout("matematica.out");
long long x[1003];
int main()
{
    int c;
    fin >> c;
    long long a, b;
    int li = 0;
    char l;
    fin >> a;
    if(a < 0){
        li++;
        x[li] = -a;
    }
    bool doarplus = true;
    long long s = a;
    long long vmin = 9223372036854775806LL;
    while(fin >> l){
        fin >> b;
        if(l == '+'){
            s = s + b;
            if(vmin > b){
                vmin = b;
            }
        }else{
            doarplus = false;
            if(b < 0){
                s = s-b;
            }else{
                s = s - b;
                li++;
                x[li] = b;
            }
        }
    }
    if(c == 1){
        fout << s;
    }else{
        long long vmax = 0;
        for(int i = 1; i <= li; i++){
            if(vmax < x[i]){
                vmax = x[i];
            }
            if(vmin > x[i]){
                vmin = x[i];
            }
        }
        if(doarplus){
            s = s-(vmin*2);
        }else{
            s = s+(vmax*2);
        }
        fout << s;
    }
    return 0;
}
