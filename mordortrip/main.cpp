#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("mordortrip.in");
ofstream fout("mordortrip.out");
int n, nr = 0;
int a[1000004], v[1000004];
int k = 0;
bool invers(int a, int b){
    if(a > b){
        return true;
    }
    return false;
}
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> a[i];
        v[i] = a[i];
    }
    sort(v+1, v+n+1, invers);
    for(int i = 1; i <= n; i++){
        int p1 = 1, p2 = n;
        int cr = 0;
        while(p1 <= p2){
            int mij = (p1+p2)/2;
            if(v[mij] >= a[i]){
                p1 = mij+1;
                cr = mij;
            }else{
                p2 = mij-1;
            }
        }
        if(i - cr > k){
            k = i-cr;
        }
    }
    fout << k;
    return 0;
}
