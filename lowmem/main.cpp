#include <fstream>
using namespace std;
ifstream fin("lowmem.in");
ifstream fein("lowmem.in");
ofstream fout("lowmem.out");
int n, k, t;
int s = 0;
int x;
int main()
{
    fin >> n;
    fin >> k;
    for(int i = 1; i <= n; i++){
        fin >> t;
    }
    int l = 0;
    fein >> x;
    fein >> k;
    for(int i = 1; i <= n; i++){
        fein >> x;
        if(x > t){
            l = 0;
        }else{
            l++;
            if(l >= k){
                s++;
            }
        }
    }
    fout << s;
    return 0;
}
