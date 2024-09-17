#include <fstream>
using namespace std;
ifstream fin("countbits.in");
ofstream fout("countbits.out");
int f, f1, f2;
short countbits(int x) {
    short k = 0;
    while (x) {
        if ((x & 1))
            k++;
        x = (x >> 1);
    }
    return k;
}
int n, A, B, C, D, E;
int main()
{
    fin >> n >> A >> B >> C >> D >> E;
    f2 = A; //f[3-2] = A
    f1 = B; //f[3-1] = B
    int nr = __builtin_popcount(A)+__builtin_popcount(B);
    for(int i = 3; i <= n; i++){
        f = 1 + ((1ll*f2*C) +(1ll*f1*D))%E;
        f2 = f1;
        f1 = f;
        nr += __builtin_popcount(f);
    }
    fout << nr;
    return 0;
}
