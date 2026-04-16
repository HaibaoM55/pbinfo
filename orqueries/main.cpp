#include <fstream>
using namespace std;
ifstream fin("orqueries.in");
ofstream fout("orqueries.out");
int n;
int tip, a, b, a2, b2, x;
struct punct{
    int a, b, x;
}v[100004];
int z = 0;
long long f[100004];
double l1, l2;
bool apartine(punct pct){
    double l = (1.0*pct.a)/(1.0*pct.b);
    return (l1 <= l && l <= l2);
}
int main(){
    fin >> n;
    int el = 0;
    if(n > 1000){
        for(int i = 1; i <= n; i++){
            fin >> tip;
            if(tip == 1){
                fin >> a >> b >> x;
                a = a ^ el;
                b = b ^ el;
                z++;
                v[z].a = a;
                v[z].b = b;
                v[z].x = x;
                f[a/b] = f[a/b] | x;
                //fout << a/b << ' ' << f[a/b] << '\n';
            }else{
                fin >> a >> b >> a2 >> b2;
                a = a ^ el;
                b = b ^ el;
                a2 = a2 ^ el;
                b2 = b2 ^ el;
                l1 = (1.0*a)/(1.0*b);
                l2 = (1.0*a2)/(1.0*b2);
                if(l1 > l2){
                    swap(l1, l2);
                }
                el = 0;
                //fout << l1 << ' ' << l2 << ' ';
                for(int j = l1; j <= l2; j++){
                    el = el | f[j];
                }
                fout << el << '\n';
            }
        }
		return 0;
    }
    for(int i = 1; i <= n; i++){
        fin >> tip;
        if(tip == 1){
            fin >> a >> b >> x;
            a = a ^ el;
            b = b ^ el;
            z++;
            v[z].a = a;
            v[z].b = b;
            v[z].x = x;
        }else{
            fin >> a >> b >> a2 >> b2;
            a = a ^ el;
            b = b ^ el;
            a2 = a2 ^ el;
            b2 = b2 ^ el;
            //[a,b], [a2, b2]
            l1 = (1.0*a)/(1.0*b);
            l2 = (1.0*a2)/(1.0*b2);
            if(l1 > l2){
                swap(l1, l2);
            }
            el = 0;
            for(int j = 1; j <= n; j++){
                if(apartine(v[j])){
                    el = el | v[j].x;
                }
            }
            fout << el << '\n';
        }
    }
    return 0;
}
