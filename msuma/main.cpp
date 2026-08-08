#include <fstream>
using namespace std;
ifstream fin("msuma.in");
ofstream fout("msuma.out");
int n, m, p, q,x;
int a[104][104];
long long suma = 0;
int main(){
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j =1; j <= m; j++){
            fin >> x;
	        a[i][j] += x;
        }
    }
    fin >> p >> q;
    for(int i = 1; i <= p; i++){
        for(int j =1; j <= q; j++){
            fin >> x;
	        a[i][j] += x;
        }
    }
    n = max(n, p);
    m = max(m, q);
    fout <<  n<< ' ' << m << '\n';
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
			fout << a[i][j] << ' ';
        }
        fout << '\n';
    }
    return 0;
}
