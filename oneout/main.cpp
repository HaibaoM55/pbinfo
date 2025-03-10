#include <fstream>
using namespace std;
ifstream fin("oneout.in");
ofstream fout("oneout.out");
bool ciur[1000004];
int s[1000004];
int c, n, x;
int main()
{
    for(int i = 2; i <= 1000000/i; i++){
        int x = i*i;
        for(int j = x; j <= 1000000; j += x){
            ciur[j] = true;
        }
    }
    fin >> c;
    fin >> n;
    if(c == 1){
        int nrc = 0;
        for(int i = 1; i <= n; i++){
            fin >> x;
            if(ciur[x] == false){
                nrc++;
            }
        }
        fout << nrc;
    }else{
        int secv=0;
        for(int i = 1; i <= n; i++){
            fin >> x;
            if(ciur[x] == false){
                secv++;
            }else{
                for(int j = i-1; j >= i-secv; j--){
                    s[j] = secv;
                }
                secv = 0;
            }
        }
        for(int j = n; j >= n-(secv-1); j--){
            s[j] = secv;
        }
        int nrmax = 0, nrm = 0;
        for(int i = 2; i <= n-1; i++){
            if(s[i-1] != 0 && s[i] == 0 && s[i+1] != 0){
                int nr = s[i-1]+s[i+1];
                if(nr > nrmax){
                    nrmax =nr;
                    nrm = 1;
                }else if(nr == nrmax){
                    nrm++;
                }
            }
        }
        fout << nrmax << ' ' << nrm <<'\n';
        for(int i = 2; i <= n-1; i++){
            if(s[i-1] != 0 && s[i+1] != 0 && s[i] == 0 && s[i-1]+s[i+1] == nrmax){
                fout << i-s[i-1] << ' ' << i+s[i+1] << '\n';
            }
        }
    }
    return 0;
}
