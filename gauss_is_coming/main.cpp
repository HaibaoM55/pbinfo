#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

vector<double *> A;
double *b;
size_t n;

/**
 * O functie care realizeaza alocarea dinamica pentru o matrice patratica
 * de ordin n.
*/
static vector<double *> __alloc_matrix(int n)                     // DO NOT MODIFY
{                                                                 // DO NOT MODIFY
    vector<double *> res = vector<double *>(n);                   // DO NOT MODIFY
    for_each(res.begin(), res.end(), [n](double* &line) {         // DO NOT MODIFY
        line = new double[n];                                     // DO NOT MODIFY
    });                                                           // DO NOT MODIFY
                                                                  // DO NOT MODIFY
    return res;                                                   // DO NOT MODIFY
}                                                                 // DO NOT MODIFY

/**
 * O functie care realizeaza alocarea dinamica de memorie pentru un vector
 * de lungime n.
*/
static double *__alloc_vector(int n)  // DO NOT MODIFY
{                                     // DO NOT MODIFY
    return new double[n];             // DO NOT MODIFY
}                                     // DO NOT MODIFY

/**
 * O functie care realizeaza pivotarea, asa cum este descrisa in enunt.
*/
void perform_pivoting(size_t p)
{
    double max_value = A[p][p];
    size_t max_index = p;

    for (size_t i = p + 1; i < n; ++i) {
        double curr_value = A[i][p];

        if (max_value < curr_value) {
            max_value = curr_value;
            max_index = i;
        }
    }

    swap(A[max_index], A[p]);
    swap(b[max_index], b[p]);
}

/**
 * O functie care realizeaza eliminarea gaussiana.
*/
void perform_gaussian_elimination()
{
    for (size_t p = 0; p < n - 1; ++p) {
        perform_pivoting(p);

        for (size_t i = p + 1; i < n; ++i) {            // DO NOT MODIFY
            double mu = A[i][p] / A[p][p];              // DO NOT MODIFY
                                                        // DO NOT MODIFY
            for (size_t k = p; k < n; ++k)              // DO NOT MODIFY
                A[i][k] -= mu * A[p][k];                // DO NOT MODIFY
                                                        // DO NOT MODIFY
            b[i] -= mu * b[p];                          // DO NOT MODIFY
        }
    }
}

/**
 * O functie care rezolva un sistem superior triunghiular
*/
double *solve_sst_system()
{
    double *x = __alloc_vector(n);

    for (size_t i = n - 1; i >= 0; i--) {
        double sum = 0;

        for (size_t j = i + 1; j < n; ++j)              // DO NOT MODIFY
            sum += A[i][j] * x[j];                      // DO NOT MODIFY
                                                        // DO NOT MODIFY
        x[i] = (b[i] - sum) / A[i][i];                  // DO NOT MODIFY
    }

    return x;
}

int main(void)
{
    size_t n;
    cin >> n;
    A = __alloc_matrix(n);
    b = __alloc_matrix(n);
    // aloca memorie pentru A si b
    for (size_t i = 0; i < n; ++i) {                    // DO NOT MODIFY
        for (size_t j = 0; j < n; ++j)                  // DO NOT MODIFY
            cin >> A[i][j];                             // DO NOT MODIFY
                                                        // DO NOT MODIFY
        cin >> b[i];                                    // DO NOT MODIFY
    }                                                   // DO NOT MODIFY

    perform_gaussian_elimination();                     // DO NOT MODIFY
    double *x = solve_sst_system();                     // DO NOT MODIFY

    // printeaza rezultatul obtinut
    for (size_t i = 0; i < n; ++i)
        cout << setprecision(10) << x[i] << "\n";
    return 0;
}
