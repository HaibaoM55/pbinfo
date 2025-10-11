///O(n^3)
#include <fstream>
using namespace std;
ifstream  fin("hambar.in");
ofstream fout("hambar.out");
int n, m, x, y;
char a[1005][1005];
int main(){
    fin >> n >> m;
    for(int i = 1; i <= m; i++){
        fin >> x >> y;
        a[x][y] = 1;
    }
    ///cautam dreptunghiul de arie maxima care contine doar valori egale cu 0
    int amax=0;
    for(int i1=1;i1<=n;i1++){
        int s[1005]={0},h=0;
        for(int i2=i1;i2<=n;i2++){
            h++;
            int arie=0;
            for(int j=1;j<=n;j++){
                s[j]+=a[i2][j];///s[j]=suma din secventa a[i1..i2][j] din coloana j
                if(s[j]==0){
                    arie+=h;
                    if(arie>amax){
                        amax=arie;
                    }
                }
                else{
                    arie=0;
                }
            }
        }
    }
    fout<<amax;
    return 0;
}
