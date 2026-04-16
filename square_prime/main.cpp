#include <iostream>

using namespace std;

bool is_prime(int x) {
    if (x == 1) {
        return false;
    }
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0) {
            return false;
        }
    }

    return true;
}

bool is_special_sum(int x) {
    for (int a = 1; a < x; a++) {
        int p = x - a * a;
        if(p < 0){
            return false;
        }
        if (is_prime(p)) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, x;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;

        if (is_special_sum(x)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}
