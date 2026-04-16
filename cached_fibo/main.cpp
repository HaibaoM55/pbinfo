#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <ostream>
#include <string>

class BigNumber {
 public:
    BigNumber(int64_t n);
    BigNumber(const std::string &s);
    BigNumber() : BigNumber(0) { };

    BigNumber operator+(const BigNumber&);
    operator bool();
    friend std::ostream& operator<<(std::ostream& os, const BigNumber& num);
    std::vector<int> get_digits() const {
        return digits;
    }

 private:
    std::vector<int> digits;
};
// You cannot use the following words/syntax: return, exit, goto, while, for, do, fork, //, /*, /**, #define

std::unordered_map<int, BigNumber> cached_fibo;

BigNumber::BigNumber(int64_t n) {
    if (n == 0) {
        digits.push_back(0);
    } else {
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
    }
}
BigNumber::operator bool() {
    return (digits.size() == 0);
}
BigNumber BigNumber::operator+(const BigNumber& other) {
    BigNumber result;
    result.digits.clear();
    int carry = 0;
    int i = 0, j = 0;

    while (i < digits.size() || j < other.digits.size()) {
        int sum = carry;
        if (i < digits.size()) {
            sum += digits[i];
            i++;
        }
        if (j < other.digits.size()) {
            sum += other.digits[j];
            j++;
        }

        result.digits.push_back(sum % 10);
        carry = sum / 10;
    }
    if(carry){
        result.digits.push_back(carry);
    }
    return result;
}
std::ostream& operator<<(std::ostream& os, const BigNumber& num) {
    std::string s;
    auto digits = num.get_digits();

    if (!digits.size()) {
        return os << "0";
    }

    std::for_each(digits.rbegin(), digits.rend(), [&s](auto digit) {
        s += std::to_string(digit);
    });

    return os << s;
}
BigNumber fibo(const int n) {
    if (n < 2) {
        return n;
    }

    if (cached_fibo[n]) {
        return cached_fibo[n];
    }

    BigNumber res = fibo(n - 1) + fibo(n - 2);
    cached_fibo[n] = res;
    return res;
}
int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x;
        std::cin >> x;
        std::cout << fibo(x) << '\n';
    }
}
