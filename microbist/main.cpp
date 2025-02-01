#include <fstream>
using namespace std;
ifstream fin("microbist.in");
ofstream fout("microbist.out");
int c, n;
int v[100004];
int main()
{
    fin >> c >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    if(c == 1){
        int a=0, b=0;
        for(int i = 1; i <= n; i++){
            if(v[i] == 1){
                a++;
            }else{
                b++;
            }
        }
        fout << a << ' ' << b;
    }else if(c == 2){
        int a = 0, b = 0, c = 1;
        for(int i = 1; i <= n; i++){
            if(v[i] == 1){
                a++;
            }else{
                b++;
            }
            if(a == b){
                c++;
            }
        }
        fout << c;
    }else{
        int a = 0, b= 0, cmax = 0;
        int c = 1;
        for(int i = 1; i <= n; i++){
            if(v[i] == 1){
                a++;
            }else{
                b++;
            }
            if(v[i] == v[i-1]){
                c++;
            }else{
                c = 1;
            }
            if(b == a+1 && v[i] == 2){
                cmax = max(c, cmax);
            }else if(a == b+1 && v[i] == 1){
                cmax = max(c, cmax);
            }
        }
        fout << cmax;
    }
    return 0;
}
