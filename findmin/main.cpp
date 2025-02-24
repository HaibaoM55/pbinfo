#include <fstream>
using namespace std;
ifstream fin("findmin.in");
ofstream fout("findmin.out");
int n, x;
int p[1000004];
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x;
        if(p[x] == 0){
            fout << -1;
            for(int j = x+1; j <= n; j++){
                if(p[j] == 0){
                    p[j] = i;
                }else{
                    break;
                }
            }
        }else{
            fout << p[x];
        }
        fout << ' ';
    }
    return 0;
}
