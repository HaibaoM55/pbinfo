#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("determinantb.in");
ofstream fout("determinantb.out");
int n, v[1004];
const int MAX = 1200005;
int rasp[MAX], len = 1;
int r = 1;
void ProdusMic(int x)
{
    long long t = 0;

    for (int i = 0; i < len; i++) {
        t += 1LL * rasp[i] * x;
        rasp[i] = t % 10;
        t /= 10;
    }

    while (t) {
        rasp[len++] = t % 10;
        t /= 10;
    }
}

int main()
{
    fin >> n;
    for (int i = 0; i < n; i++)
        fin >> v[i];

    rasp[0] = 1;
    bool negativ = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int d = v[i] - v[j];

            if (d == 0) {
                fout << 0;
                return 0;
            }
            if (d < 0) {
                negativ = !negativ;
                d = -d;
            }
            r = r*d;
            if(r >= 10000000){
                ProdusMic(r);
                r = 1;
            }
        }
    }
    ProdusMic(r);
    if(negativ)
        fout << '-';
    for (int i = len - 1; i >= 0; i--)
        fout << rasp[i];

    return 0;
}
