#include <fstream>
using namespace std;
ifstream fin("cub.in");
ofstream fout("cub.out");
long long n;
long long frecv[5][5][5][5];
int main()
{
    fin >> n;
    long long nr = 0;
    frecv[0][0][0][0] = 1;
    long long p1 = 0;
    long long p2 = 0;
    long long p3 = 0;
    long long p4 = 0;
    for(int i = 1; i <= n; i++){
        long long x;
        fin >> x;
        while(x % 2 == 0){
            x = x/2;
            p1++;
        }
        while(x % 3 ==0){
            x = x/3;
            p2++;
        }
        while(x % 5 ==0){
            x = x/5;
            p3++;
        }
        while(x % 7 ==0){
            x = x/7;
            p4++;
        }
        p1 %= 3;
        p2 %= 3;
        p3 %= 3;
        p4 %= 3;
        nr += frecv[p1][p2][p3][p4];
        frecv[p1][p2][p3][p4]++;
    }
    fout << nr;
    return 0;
}
