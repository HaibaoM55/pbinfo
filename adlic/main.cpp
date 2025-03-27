#include <fstream>
using namespace std;
ifstream fin("adlic.in");
ofstream fout("adlic.out");
int c;
int n, j = 1;
int v[1000004], cl[1000004];
bool ok = false;
int main()
{
    fin >> c;
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        if(ok == false && i > 1 && v[i] < v[i-1]){
            j = i;
            ok = true;
        }
    }
    if(c == 1){
        fout << v[j];
    }else{
        int nrc = 1;
        cl[1] = v[1];
        for(int i = 2; i <= n; i++){
            int p1 = 1, p2 = nrc;
            int j = -1;
            while(p1 <= p2){
                int mij = (p1+p2)/2;
                if(cl[mij] <= v[i]){
                    j = mij;
                    p2 = mij-1;
                }else{
                    p1 = mij+1;
                }
            }
            if(j == -1){
                nrc++;
                cl[nrc] = v[i];
            }else{
                cl[j] = v[i];
            }
        }
        fout << nrc;
    }
    return 0;
}
