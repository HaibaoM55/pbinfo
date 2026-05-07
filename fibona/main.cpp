#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

typedef vector<vector<long long>> Matrix;

Matrix mat_mul(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

Matrix mat_pow(Matrix M, long long e) {
    int n = M.size();
    Matrix result(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) result[i][i] = 1;
    while (e > 0) {
        if (e % 2 == 1)
            result = mat_mul(result, M);
        M = mat_mul(M, M);
        e /= 2;
    }
    return result;
}

long long fib(long long m) {
    if (m == 0) return 0;
    if (m == 1) return 1;
    Matrix F = {{1, 1}, {1, 0}};
    Matrix R = mat_pow(F, m - 1);
    return R[0][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k, p;
    cin >> n >> k >> p;

    // Matricea de tranzitie pentru suma
    // Stare: [F(i*k+p+k), F(i*k+p), suma_curenta, 1]
    // Folosim identitatea: F(a+b) = F(a+1)*F(b) + F(a)*F(b-1)

    long long fk1 = fib(k + 1);
    long long fk  = fib(k);
    long long fk_1 = fib(k - 1); // F(k-1)

    // Matricea de tranzitie 3x3:
    // [F(i+1)]   [fk1  fk  0] [F(i)  ]
    // [F(i)  ] = [fk  fk_1 0] [F(i-1)]
    // [S(i)  ]   [fk1  fk  1] [S(i-1)]
    // unde F(i) = F(i*k + p)

    Matrix T = {
    {fk1, fk,   0},
    {1,   0,    0},
    {fk1, fk,   1}
};

    long long fp   = fib(p);
    long long fp_1 = (p >= 1) ? fib(p - 1) : 1;

    Matrix R = mat_pow(T, n);

    // Starea initiala: [F(k+p), F(p), F(p)]
    long long fkp = fib(k + p);

    long long ans = (R[2][0] * fkp % MOD
                   + R[2][1] * fp  % MOD
                   + R[2][2] * fp  % MOD) % MOD;

    cout << ans << endl;
    return 0;
}
