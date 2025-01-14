#include <fstream>
using namespace std;
ifstream fin("tnia.in");
ofstream fout("tnia.out");
int n, m;
long long h[100004];
long long s[100004];
int q;
int main()
{
    fin >> n >> m;
    s[0] = 0;
    for(int i = 1; i <= n; i++){
        fin >> h[i];
        s[i] = s[i-1]+h[i];
    }
    fin >> q;
    for(int i = 1; i <= q; i++){
        int a, b, c, d;
        fin >> a >> b >> c >> d;
        //(b, a) -> (d, c);
        int p1 = a, p2 = c;
        //cautam primul h[i] >= b
        while(p1 <= p2){
            int mij = (p1+p2)/2;
            if(h[mij] >= b){
                p2 = mij-1;
            }else{
                p1 = mij+1;
            }
        }
        int p = p1;
        p1 = a;
        p2 = c;
        //cautam ultimul h[i] < d
        while(p1 <= p2){
            int mij = (p1+p2)/2;
            if(h[mij] < d){
                p1 = mij+1;
            }else{
                p2 = mij-1;
            }
        }
        long long suma = s[p2]-s[p-1];
        suma -= (long long)(b-1)*(p2-p+1);
        suma += (long long)(c-p2)*(d-b+1);
        fout << suma << '\n';
    }
    return 0;
}
