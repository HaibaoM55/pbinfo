#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("pro3.in");
ofstream fout("pro3.out");
struct progresie{
    long long a,r,n;
}v[5];
long long gcd(long long x, long long y)
{
    if (y == 0) return x;
    return gcd(y, x%y);
}
long long nr = 0;
long long cmmmc(long long x, long long y){
    long long g = gcd(x, y);
    return (x*y)/g;
}
long long in(progresie a,progresie b)
{
    long long lim=min(a.a+(a.n-1)*a.r,b.a+(b.n-1)*b.r);
    for(long long i=0; i<1000000; i++)
    {
        long long o=a.a+a.r*i;
        if(o<=lim && (o-b.a)%b.r == 0 &&(b.a<=o))
        {
            long long mc = cmmmc(a.r,b.r);
            return (lim-o)/mc+1;
        }
    }
    return 0;
}
int main()
{
    for(int z = 1; z <= 3; z++){
        fin >> v[z].a >> v[z].r >> v[z].n;
        nr += v[z].n;
    }
    nr -= in(v[1], v[2]);
    nr -= in(v[1], v[3]);
    nr -= in(v[2], v[3]);
    progresie v123;
    progresie a = v[1];
    progresie b = v[2];
    bool ok = true;
    long long lim=min(a.a+(a.n-1)*a.r,b.a+(b.n-1)*b.r);
    for(long long i=0; i<1000000; i++)
    {
        long long o=a.a+a.r*i;
        if(o<=lim && (o-b.a)%b.r == 0 &&(b.a<=o))
        {
            long long mc = cmmmc(a.r,b.r);
            v123.n = (lim-o)/mc+1;
            v123.a = o;
            v123.r = mc;
            ok = false;
            break;
        }
    }
    if(ok){
        v123.a = 0;
        v123.n = 0;
        v123.r = 0;
    }
    nr += in(v123, v[3]);
    fout << nr << "\n";
    return 0;
}
