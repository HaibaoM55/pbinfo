#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("risc.in");
ofstream fout("risc.out");
int c,n;
int v[100004], a[100004];
int vmax=0, vmaxi;
int m, m1, m2;
int main()
{
    fin >> c;
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        if(v[i] > vmax){
            vmax = v[i];
            vmaxi = i;
        }
    }
    if(c == 1){
        for(int i = 1;i <= vmaxi-1; i++){
            if(v[i] >= v[i+1]){
                fout <<-1;
                return 0;
            }
        }
        for(int i = vmaxi; i <= n-1; i++){
            if(v[i] <= v[i+1]){
                fout <<-1;
                return 0;
            }
        }
        if(v[vmaxi-1] < v[n]){
            fout <<vmaxi;
        }else{
            fout <<-1;
        }
    }else{
        for(int i = 1; i <= n; i++){
            a[i] = v[i];
        }
        sort(a+1, a+n+1);
        int j = 1;
        for(int i = 1; i <= n; i++){
            if(v[i] == a[j]){
                j++;
                m++;
            }
            if(i == vmaxi){
                m2 = m;
            }
        }
        j = n;
        for(int i = vmaxi; i <= n; i++){
            if(v[i] == a[j]){
                m1++;
                j--;
            }
        }
        m = max(m, m1+m2);
        fout << n-m;
    }
    return 0;
}
