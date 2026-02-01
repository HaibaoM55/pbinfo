#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("parimpar.in");
ofstream fout("parimpar.out");
int n, q;
long long r[200005];
int z = 0;
void kp(int a[], int b[], int caz){
    int a_copy[200005], b_copy[200005];
    int len_a = a[0];
    int len_b = b[0];
    for(int i = 0; i <= len_a; i++) a_copy[i] = a[i];
    for(int i = 0; i <= len_b; i++) b_copy[i] = b[i];
    if(caz == 2){
        int l = a_copy[0];
        a_copy[0] = 0;
        for(int i = 1; i <= l; i++){
            if(i % 2 == 1){
                b_copy[0]++;
                b_copy[b_copy[0]] = a_copy[i];
            }else{
                a_copy[0]++;
                a_copy[a_copy[0]] = a_copy[i];
            }
        }
    }else{
        int l = a_copy[0];
        a_copy[0] = 0;
        for(int i = 1; i <= l; i++){
            if(i % 2 == 0){
                b_copy[0]++;
                b_copy[b_copy[0]] = a_copy[i];
            }else{
                a_copy[0]++;
                a_copy[a_copy[0]] = a_copy[i];
            }
        }
    }
    if(a_copy[0] == 0){
        long long smax = 0, s = 0;
        for(int i = 1; i <= b_copy[0]; i++){
            s += b_copy[i];
            if(s > smax){
                smax = s;
            }
            if(s < 0){
                s = 0;
            }
        }
        z++;
        r[z] = smax;
    }else{
        if(a_copy[0] == 1){
            kp(a_copy, b_copy, 2);
        }else{
            kp(a_copy, b_copy, 1);
            kp(a_copy, b_copy, 2);
        }
    }
}
static int v[200005], v1[200005];
static int v2[200005], v3[200005];
int main(){
    fin >> n >> q;
    v[0] = n;
    v2[0] = n;
    v1[0] = 0;
    v3[0] = 0;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        v2[i] = v[i];
    }
    kp(v, v1, 1);
    kp(v2, v3, 2);
    for(int i=  1; i <= z; i++){
        fout << r[i] << ' ';
    }
    sort(r + 1, r + z + 1);
    for(int i = 1; i <= q; i++){
        long long L, R;
        fin >> L >> R;
        int left = z + 1;
        int p1 = 1, p2 = z;
        while(p1 <= p2){
            int mid = (p1 + p2) / 2;
            if(r[mid] >= L){
                left = mid;
                p2 = mid - 1;
            }else{
                p1 = mid + 1;
            }
        }
        int right = z + 1;
        p1 = 1;
        p2 = z;
        while(p1 <= p2){
            int mid = (p1 + p2) / 2;
            if(r[mid] > R){
                right = mid;
                p2 = mid - 1;
            }else{
                p1 = mid + 1;
            }
        }
        fout << right-left << '\n';
    }
    return 0;
}
