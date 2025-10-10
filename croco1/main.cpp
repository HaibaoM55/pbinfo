#include <fstream>
using namespace std;
int n,m,a[102][102],nc=0,ne=0;
ifstream  fin("croco1.in");
ofstream fout("croco1.out");
void fill(int lin, int col, int &n2, int &n3, int u){
    if(lin>=1 && lin<=n && col>=1 && col<=m && a[lin][col]==0){
        a[lin][col]=5-u;
        if(5-u==2)n2++;
        else n3++;
        fill(lin-1,col,n2,n3,5-u);
        fill(lin+1,col,n2,n3,5-u);
        fill(lin,col-1,n2,n3,5-u);
        fill(lin,col+1,n2,n3,5-u);
    }
}

int main(){
    fin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            fin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==0){
                int n2=0,n3=0;
                fill(i,j,n2,n3,3);
                if(n2<n3)swap(n2,n3);
                nc+=n2;
                ne+=n3;
            }
        }
    }
    fout<<nc<<" "<<ne;
    return 0;
}
