#include <fstream>
using namespace std;
ifstream fin("sir.in");
ofstream fout("sir.out");
int n;
int v[100004];
long long s[100004];
int main()
{
    fin >> n;
    s[0] = 0;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        s[i] = s[i-1]+v[i];
    }
    for(int i = 2; i <= n; i++){
        int p1 = 1, p2 = i-1;
        while(p1 <= p2){
            int mij = (p1+p2)/2;
            if(s[mij] < v[i]){
                p1 = mij+1;
            }else{
                p2 = mij-1;
            }
        }
        if(v[i] == s[p1]){
            fout << p1 << '\n';
        }else{
            fout << "-1\n";
        }
    }
    return 0;
}
