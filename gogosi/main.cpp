#include <fstream>
using namespace std;
ifstream fin("gogosi.in");
ofstream fout("gogosi.out");
int n;
int v[100005];
int nr = 0;
int main()
{
    fin >> n;
    fin >> v[1];
    nr = 1;
    for(int i = 1; i <= n; i++){
        int x;
        fin >> x;
        int p1 = 1;
        int p2 = nr;
        while(p1 <= p2){
            int mij = (p1+p2)/2;
            if(x < v[mij]){
                p1 = mij+1;
            }else{
                p2 = mij-1;
            }
        }
        v[p1] = x;
        if(p1 == nr+1){
            nr++;
        }
    }
    fout << nr;
    return 0;
}
