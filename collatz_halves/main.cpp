#include <iostream>

#define NMAX 200

using namespace std;

int collatz_next(int x) {
    if (x % 2 == 0) {
        return x / 2;
    } else {
        return 3 * x + 1;
    }
}

int main() {
    int val;
    int n;
    int operations[NMAX];
    int count = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> val;
        int initial_val = val;
        if(val == 1 || val == 2 || val == 4 || val == 8){
            cout << val << ' ';
            continue;
        }
        while (val != 5 && val != 32) {
            operations[count++] = val % 2;
            val = collatz_next(val);
        }

        // Schimba jumatatea in care se afla
        if (val == 5) {
            val = 32;
        }else if (val == 32) {
            val = 5;
        }

        int twin = val;

        // Aplica operatiile invers
        while (count) {
            if (operations[count - 1] == 0) {
                twin *= 2;
            } else {
                if (twin % 3 != 1) {
                    break;
                }
                twin = (twin - 1) / 3;
            }

            count--;
        }

        if (count != 0) {
            cout << initial_val << ' ';
            continue;
        }

        cout << twin << ' ';
    }

    return 0;
}
