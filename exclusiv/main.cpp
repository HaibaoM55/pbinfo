#include <fstream>
using namespace std;
ifstream fin("exclusiv.in");
ofstream fout("exclusiv.out");
int n, m;
int v[2005];
int s[100005];
int t[100005];
bool b[100005];
int main()
{
    fin >> m >> n;
    for(int i = 1; i <= m; i++){
        fin >> s[i];
    }
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    for(int i = 1; i <= m; i++){
        b[i] = true;
    }
    for(int i = 1; i <= n; i++){
        int pmax = 0, p = 0;
        for(int j = 1; j <= m; j++){
            if(v[i] == s[j]){
                b[j] = false;
            }
            if(b[j]){
                p++;
            }else{
                p =0;
            }
            pmax = max(pmax, p);
        }
        fout << pmax << "\n";
    }
    return 0;
}
