#include <fstream>
using namespace std;
ifstream fin("secvente.in");
ofstream fout("secvente.out");
int n, t;
bool a[1000004];
int s[1000004], v[1000004];
int nr = 0, vmax=0;
int main()
{
    fin >> n >> t;
    for(int i = 1; i <= n; i++){
        char x;
        fin >> x;
        if(x == '1'){
            a[i] = true;
            nr++;
            s[i]++;
        }else{
            a[i] = false;
        }
        s[i] = s[i-1]+s[i];
        if(i>=t){
            if(s[i]-s[i-t] > v[i-1]){
                v[i] = s[i]-s[i-t];
            }else{
                v[i] = v[i-1];
            }
        }
    }
    if(nr < t*2){
        fout << "-1";
    }else{
        int vmax = 0;
        for(int i = t; i <= n-t; i++){
            int x = v[i]+s[i+t]-s[i];
            if(x > vmax){
                vmax = x;
            }
        }
        nr = 2*t-vmax;
        fout << nr;
    }
    return 0;
}
