/*#include <iostream>
using namespace std;
#define MOD 1000000007
#define int long long
long long n;
int kp(int i){
    if(i > n){
        return 0;
    }
    if(i == n){
        return 1;
    }
    return kp(i+1)+kp(i+2)+kp(i+3)+kp(i+4)+kp(i+5)+kp(i+6);
}
int p2(int i){
    if(i < 0){
        return 0;
    }
    if(i == 0){
        return 1;
    }
    if(i % 2 == 0){
        return (p2(i/2)*p2(i/2))%MOD;
    }else{
        return (p2(i-1)*2)%MOD;
    }
}
int fprev = 1;
signed main(){
    cin >> n;
    long long r = p2(n-1)%MOD;
    if(n >= 7){
        fprev = 1;
        fprev = p2(n-7)+p2(n-8)*(n-7);
        fprev = fprev%MOD;
        /*for(int i = 8; i <= n; i++){
            fprev = (fprev*2+p2(i-8)+MOD)%MOD;
        }
        r = (r-fprev+MOD)%MOD;
    }
    cout << r;
    return 0;
}*/
/*
1 2 4 8 16 32 63 125 248 492
1 2 3 4 5  6  7  8   9   10
             -1 -3  -8  -20

1 2 4 8 16 32 63 125 248 492 976 1936 3840 7617 15109 29970 59448 117920 233904 463968
1 2 3 4 5  6  7  8   9   10  11  12   13   14   15    16    17    18     19     20
             -1 -3  -8  -20  -48 -112 -256 *2  .................................
              2  6  16   40   96  224  512
                -1  -2  -4   -8  -16  -32
(-1)*2^(n-8)+(-2)*2^(n-9)+(-4)*2^(n-10)+...
 2^(n-7)+2^(n-8)*(n-7)

n = 13


fprev = fprev*2+p2(i-8)

*/
#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007
#define int long long
typedef vector<vector<int>> Mat;
Mat multiply(const Mat& A, const Mat& B) {
    int n = A.size();
    Mat C(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++)
        for(int k = 0; k < n; k++) if(A[i][k])
            for(int j = 0; j < n; j++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

Mat matpow(Mat M, int p) {
    int n = M.size();
    Mat result(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) result[i][i] = 1; // identitate
    while(p > 0) {
        if(p & 1) result = multiply(result, M);
        M = multiply(M, M);
        p >>= 1;
    }
    return result;
}
signed main(){
    int n;
    cin >> n;
    int base[] = {1, 2, 4, 8, 16, 32};
    if(n <= 6) {
        cout << base[n-1] << endl;
        return 0;
    }
    Mat M = {
        {1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0}
    };
    Mat R = matpow(M, n - 6);
    int v[] = {32, 16, 8, 4, 2, 1};
    int ans = 0;
    for(int j = 0; j < 6; j++){
        ans = (ans + R[0][j] * v[j]) % MOD;
    }
    cout << ans << endl;
    return 0;
}
