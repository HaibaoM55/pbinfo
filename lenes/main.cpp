#include <fstream>
#include <algorithm>
using namespace std;
#define int long long
ifstream fin("lenes.in");
ofstream fout("lenes.out");
int p;
int n, m, k1, k2;
int a[504][504];
int b[504][504];
int f1[504], f2[504];
int fmin(int n1,int v1[1002],int n2,int v2[1002],int n12,int v12[1002],int k1,int k2){

    if(k1<n1)n1=k1;
    if(k2<n2)n2=k2;
    int vmax=max(v1[n1],max(v2[n2],v12[n12]));
    v1[n1+1]=1+vmax;
    v2[n2+1]=1+vmax;
    v12[n12+1]=1+vmax;
    int i1=1,i2=1,i12=1,s=0;
    for(int i=1;i<=k1+k2;i++){
        int vmin=min(v1[i1],min(v2[i2],v12[i12]));
        s=s+vmin;
        if(v1[i1]==vmin)i1++;
        else if(v2[i2]==vmin)i2++;
        else i12++;
    }
    return s;
}
signed main(){
    fin >> p;
    fin >> n >> m >> k1 >> k2;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> a[i][j];
            b[j][i] = a[i][j];
            b[j][0] += a[i][j];
        }
    }
    for(int j = 1; j <= m; j++){
        sort(b[j]+1, b[j]+n+1);
    }
    if(p == 1){
        int smin = 2e9;
        int s = b[1][0];
        for(int k = 1; k <= k1; k++){
            s += b[2][k];
        }
        if(s < smin){
            smin = s;
        }
        s = b[m][0];
        for(int k = 1; k <= k1; k++){
            s += b[m-1][k];
        }
        if(s < smin){
            smin = s;
        }
        for(int j = 2; j <= m-1; j++){
            s = b[j][0];
            int p1 = 1, p2 = 1;
            for(int k = 1; k <= k1; k++){
                if(b[j-1][p1] < b[j+1][p2]){
                    s += b[j-1][p1];
                    p1++;
                }else{
                    s += b[j+1][p2];
                    p2++;
                }
            }
            if(s < smin){
                smin = s;
            }
        }
        fout << smin;
    }
    else{
        int smin = 2e9;
        for(int i = 0; i <= n; i++){
            b[m+1][i]=2e9;
            b[0][i]=2e9;
        }
        for(int j1 = 1; j1 <= m; j1++){
            int p1 = 1, p2 = 1;
            for(int k = 1; k <= k1; k++){
                if(b[j1-1][p1] < b[j1+1][p2]){
                    f1[j1] += b[j1-1][p1];
                    p1++;
                }else{
                    f1[j1] += b[j1+1][p2];
                    p2++;
                }
            }
        }
        for(int j2 = 1; j2 <= m; j2++){
            int p1 = 1, p2 = 1;
            for(int k = 1; k <= k2; k++){
                if(b[j2-1][p1] < b[j2+1][p2]){
                    f2[j2] += b[j2-1][p1];
                    p1++;
                }else{
                    f2[j2] += b[j2+1][p2];
                    p2++;
                }
            }
        }
        for(int j1 = 1; j1 <= m; j1++){
            for(int j2 = 1; j2 <= m; j2++){
                int s = b[j1][0]+b[j2][0];
                if(j1 == j2){
                    continue;
                }else if(j2 == j1+1){
                    for(int k = 1; k <= k1; k++){
                        s += b[j1-1][k];
                    }
                    for(int k = 1; k <= k2; k++){
                        s += b[j2+1][k];
                    }
                }else if(j1 == j2+1){
                    for(int k = 1; k <= k1; k++){
                        s += b[j1+1][k];
                    }
                    for(int k = 1; k <= k2; k++){
                        s += b[j2-1][k];
                    }
                }else if(j1 == j2+2){
                    int v1[1004], v2[1004], v12[1004];
                    for(int i = 1; i <= n; i++){
                        v1[i] = b[j1+1][i];
                        v12[i] = b[j2+1][i];
                        v2[i] = b[j2-1][i];
                    }
                    s += fmin(n, v1, n, v2, n, v12, k1, k2);
                }else if(j2 == j1+2){
                    int v1[1004], v2[1004], v12[1004];
                    for(int i = 1; i <= n; i++){
                        v1[i] = b[j1-1][i];
                        v12[i] = b[j1+1][i];
                        v2[i] = b[j2+1][i];
                    }
                    s += fmin(n, v1, n,v2, n, v12, k1, k2);
                }else{
                    s += f1[j1];
                    s += f2[j2];
                }
                if(s < smin){
                    smin = s;
                }
            }
        }
        fout << smin;
    }
    return 0;
}
