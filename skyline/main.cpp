#include <fstream>
using namespace std;
ifstream fin("skyline.in");
ofstream fout("skyline.out");
int n;
struct pereche{
    int h, l;
}p[40005];
unsigned long long s[40005];
int stv[40005];
int st[40005];
int dr[40005];
int vf = 0;
unsigned long long amax=0;
int main()
{
    fin >> n;
    s[0] = 0;
    for(int i = 1; i <= n; i++){
        fin >> p[i].h >> p[i].l;
        s[i] = s[i-1]+p[i].l;
    }
    p[0].h = -1;
    stv[0] = 0;
    vf = 0;
    for(int i = 1; i <= n; i++){
        st[i] = i;
        while(p[stv[vf]].h >= p[i].h){
            st[i] = stv[vf];
            vf--;
        }
        vf++;
        stv[vf] = i;
    }
    vf = 0;
    stv[0] = n+1;
    p[n+1].h = -1;
    for(int i = n; i >= 1; i--){
        dr[i] = i;
        while(p[stv[vf]].h >= p[i].h){
            dr[i] = stv[vf];
            vf--;
        }
        vf++;
        stv[vf] = i;
    }
    for(int i = 1; i <= n; i++){
        unsigned long long a = (1LL*p[i].h)*(s[dr[i]]-s[st[i]-1]);
        if(a > amax){
            amax = a;
        }
    }
    fout << amax;
    return 0;
}
