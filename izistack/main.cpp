#include <fstream>
using namespace std;
ifstream fin("izi.in");
ofstream fout("izi.out");
int n;
int s[1000004];
int mars[1000004];
int dr = 0;
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        int c;
        fin >> c;
        if(c == 0){
            int x;
            fin >> x;
            dr++;
            s[dr] = x;
            fout << x << '\n';
        }else if(c == 1){
            int x, y, m;
            fin >> x >> y >> m;
            mars[x-1] -= m;
            mars[y] += m;
            fout << mars[dr]+s[dr] << '\n';
        }else{
            dr--;
            mars[dr] += mars[dr+1];
            mars[dr+1] = 0;
            fout << mars[dr]+s[dr] << '\n';
        }
    }
    return 0;
}
