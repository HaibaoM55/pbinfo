#include <fstream>
using namespace std;
ifstream  cin("partitiimultime2.in");
ofstream cout("partitiimultime2.out");
int n, p;
int x[16],z[16];
char y[16][30];
void bk(int k, int vm, int p){
    if(k == n+1){
        for(int i = 1; i <= p; i++){
            y[i][z[i]]='*';
            y[i][z[i]+1]=0;
            cout<<y[i];
        }
        cout << '\n';
    }else{
        for(int i = 1; i <= vm; i++){
            x[k] = i;
            if(k>9){
                y[i][z[i]++]=k/10+'0';
            }
            y[i][z[i]++]=k%10+'0';
            bk(k+1, vm, p);
            z[i]--;
            if(k>9){
                z[i]--;
            }
        }
        x[k]=vm+1;
        if(k>9){
            y[vm+1][z[vm+1]++]=k/10+'0';
        }
        y[vm+1][z[vm+1]++]=k%10+'0';
        bk(k+1, vm+1, p+1);
        z[vm+1]--;
        if(k>9){
            z[vm+1]--;
        }
    }
}
int main()
{
    cin >> n;
    x[1] = 1;
    y[1][0]='1';
    z[1]=1;
    bk(2, 1, 1);
    return 0;
}
