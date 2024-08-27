#include <fstream>
using namespace std;
ifstream fin("aparitiicifra.in");
ofstream fout("aparitiicifra.out");
long long n, n2;
long long o = 0, s = 0, p = 1;
int nr = 0, c;
int main()
{
    fin >> n >> c;
    n2 = n;
    while(n2!=0)
    {
        nr++;
        if(n2%10==c){
            s++;
        }
        o = o*10+n2%10;
        n2 = n2/10;
        p *= 10;
    }
    nr--;
    p = p/10;
    while(nr >= 0){
        if(o%10 > c){
            s += (o%10)*nr*p/10+p;
        }
        else if(o%10 <= c){
            s += (o%10)*nr*p/10;
        }
        if(o%10==c){
            s += n%p;
        }
        p = p/10;
        o = o/10;
        nr--;
    }
    fout<<s;
}
