#include <fstream>
using namespace std;
ifstream fin("civilizatie.in");
ofstream fout("civilizatie.out");
long long p;
long long x, y;
long long t;
long long n;
long long m[2001][2001], m1[2002], m2[2002];
long long b[2002], vmin[2002], m3[2002][2002];
struct oras{
    int i, j;
}v[2004];
int main(){
    fin >> p;
    fin >> x >> y;
    fin >> t;
    if(p == 1){
        long long s= 1+2LL*t*(t-1);
        fout << s;
    }else{
        fin >> n;
        long long a = x*y;
        for(int i = 1; i<= n; i++){
            fin >> v[i].i >> v[i].j;
        }
        for(int i = 1; i <= n; i++){
            int xi = v[i].i, yi = v[i].j;
            m1[i] = min(xi, yi), m1[i] = min(m1[i], min(x-xi+1, y-yi+1));
            for(int j = 1; j <= n; j++){
                if(i != j){
                    m3[i][j] = abs(xi-v[j].i)+abs(yi-v[j].j)+1;
                    m[i][j] = m3[i][j]/2;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            m3[i][i] = x+y;
            m[i][i] = m3[i][i];
        }
        for(int i = 1; i <= n; i++){
            m2[i] = x+y;
            for (int j = 1; j <= n; j++){
                if(i == j){
                    continue;
                }
                if(m2[i] > m[i][j]){
                    m2[i] = m[i][j];
                    b[i] = j;
                }
            }
        }
        m2[0] = x+y;
        for(int i = 1; i <= n; i++){
            int im1 = 0, jm1 = 0, im = 0, mmin = x+y;
            for(int j = 1; j <= n; j++){
                if(vmin[j]){
                    continue;
                }
                if(mmin > m2[j]){
                    mmin = m2[j];
                    im1 = j;
                    jm1 = b[j];
                    im = 0;
                }
                if(mmin> m1[j]){
                    mmin = m1[j], im = j;
                }
            }
            if(im != 0){
                im1 = im;
                vmin[im] = m1[im];
            }else{
                vmin[im1] = m[im1][jm1];
            }
            m2[im1] = x+y;
            for(int j = 1; j <= n; j++){
                if (!vmin[im1] || !vmin[j]){
                    if (m[j][im1] != vmin[im1]){
                        m[im1][j] = m3[j][im1]-vmin[im1];
                        m[j][im1] = m[im1][j];
                        if (m[j][im1] < m2[im1] && j != im1 && (!vmin[im1] || !vmin[j])){
                            m2[im1] = m[j][im1], b[im1] = j;
                        }
                        if(b[j]==im1 && j != im1){
                            m2[j]=x+y;
                            for(int ik=1;ik<=n;ik++){
                                if(m[j][ik]<m2[j] && j!=ik){
                                    m2[j]=m[j][ik];
                                    b[j]=ik;
                                }
                            }
                        }
                    }
                }
            }
        }
        long long ar = 0;
        long long tmp = 0;
        for(int i = 1; i <= n; i++){
            tmp = max(tmp, vmin[i]);
            ar += 1+2LL*vmin[i]*(vmin[i]-1);
        }
        ar = x*y-ar;
        fout << ar << '\n';
        fout << tmp;
    }
    return 0;
}
