/*#include <bits/stdc++.h>

using namespace std;

// codul scris de tine

class big_int
{
private:

public:
    int sign; // -1 daca numarul este negativ, +1 daca este pozitiv
    int no;
    string digits; // cifrele numarului, stocate in ordine inversa
    big_int()
    {
        no = 1;
        digits[0] = '0';
    }
    big_int(string s)
    {
        no = s.size();
        if(s[0] == '-'){
            sign = -1;
            no--;
            digits = s+1;
        }else{
            sign = 1;
            digits = s;
        }
    }
    big_int(int n)
    {
        if(n < 0){
            sign = -1;
            n = -n;
        }else{
            sign = 1;
        }
        no = 0;
        do{
            digits[no] = n%10+'0';
            no++;
            n = n/10;
        }while(n);
        // initializare prin intermediul unui numar intre -2^31 si 2^31 - 1
    }
    operator string() const
    {
        return digits;
    }
    friend bool operator == (const big_int& a, const big_int& b)
    {
        if(a.no == b.no){
            for(int i = 0; i < a.no[0]; i++){
                if(a.digits[i] != b.digits[i]){
                    return false;
                }
            }
            return true;
        }
        return false;
    }
    friend bool operator < (const big_int& a, const big_int& b)
    {
        if(a.no == b.no){
            for(int i = 0; i < a.no; i++){
                if(a.digits[i]-'0' != b.digits[i]-'0'){
                    return a.digits[i]-'0' < b.digits[i]-'0';
                }
            }
        }else{
            return a.no < b.no;
        }
    }
    big_int abs() const
    {
        big_int temp;
        temp.sign = 1;
        temp.digits = digits;
        temp.no = no;
        return temp;
        // valoarea absoluta
    }
    big_int operator - () const
    {
        big_int temp;
        temp.sign = -sign;
        temp.digits = digits;
        temp.no = no;
        return temp;
    }
    big_int operator + (const big_int& b) const
    {
        big_int temp;
        temp.sign = sign;
        temp.no = no;
        temp.digits = digits;
        int cmax = max(no, b.no)
        int t = 0;
        for(int i = 0; i < cmax; i++){
            t += temp.digits[i]+b.digits[i];
            temp.digits[i] = t%10;
            t = t/10;
        }
        if(t){
            temp.no++;
            temp[temp.no] = t;
        }
        return temp;
        // suma a 2 numere
    }
    big_int operator - (const big_int& b) const
    {
        big_int temp;
        temp.sign = sign;
        temp.no = no;
        temp.digits = digits;
        for(int i = 0; i <= temp.no; i++){
            if(temp.digits[i] >= b.digits[i]){
                temp.digits[i] -= b.digits[i]-'0';
            }else{
                int j = i+1;
                while(temp.digits[j] == 0){
                    temp.digits[j++]=9;
                }
                temp.digits[j]--;
                temp.digits[i] = 10+temp.digits[i]-b.digits[i];
            }
        }
        for(; temp.digits[0] > 1 && !temp.no; temp.no--);
        return temp;
        // diferenta a 2 numere
    }
    big_int operator * (const big_int& b) const
    {
        // produsul a 2 numere
        big_int temp;
        temp.sign = sign;
        temp.no = no;
        temp.digits = digits;
        int t = 0;
        temp.no = no+b.no-1;
        for(int i = 0; i < no+b.no; i++){
            temp.digits[i] = 0;
        }
        for(int i = 0; i <= no; i++){
            for(int j = 0; j <= b.no; j++){
                temp.digits[i+j]+=digits[i]*b.digits[j];
            }
        }
        for(int i = 0; i < temp.no; i++){
            t += temp.digits[i];
            temp.digits[i] = t%10;
            t = t/10;
        }
        if(t){
            temp.no++;
            temp.digits[temp.no] = t;
        }
        return temp;
    }
    big_int operator / (const big_int& b) const
    {
        // catul impartirii a 2 numere
    }
    big_int operator % (const big_int& b) const
    {
        // restul impartirii a 2 numere pozitive
    }
    friend istream& operator >> (istream& in, big_int& n)
    {
        // citire prin intermediul stream-urilor
    }
    friend ostream& operator << (ostream& out, const big_int& n)
    {
        // scriere prin intermediul stream-urilor
    }
};*/
class big_int {
public:
    int sign; // -1 negativ, +1 pozitiv
    int no;
    string digits; // cifre în ordine INVERSĂ (units first)

    big_int() {
        sign = 1;
        no = 1;
        digits = "0";
    }

    big_int(string s) {
        if (s[0] == '-') {
            sign = -1;
            digits = s.substr(1);
        } else {
            sign = 1;
            digits = s;
        }
        // inversăm ca să fie units first
        reverse(digits.begin(), digits.end());
        no = digits.size();
    }

    big_int(int n) {
        if (n < 0) { sign = -1; n = -n; }
        else sign = 1;
        no = 0;
        digits = "";
        do {
            digits += (char)(n % 10 + '0'); // units first automat
            no++;
            n /= 10;
        } while (n);
    }

    operator string() const {
        string s = digits;
        reverse(s.begin(), s.end());
        if (sign == -1) s = "-" + s;
        return s;
    }

    friend bool operator==(const big_int& a, const big_int& b) {
        return a.sign == b.sign && a.no == b.no && a.digits == b.digits;
    }

    // comparatie valoare absoluta
    static bool absLess(const big_int& a, const big_int& b) {
        if (a.no != b.no) return a.no < b.no;
        for (int i = a.no - 1; i >= 0; i--) {
            if (a.digits[i] != b.digits[i])
                return a.digits[i] < b.digits[i];
        }
        return false;
    }

    friend bool operator<(const big_int& a, const big_int& b) {
        if (a.sign != b.sign) return a.sign < b.sign;
        if (a.sign == 1) return absLess(a, b);
        return absLess(b, a); // ambele negative, inversat
    }

    big_int abs() const {
        big_int temp = *this;
        temp.sign = 1;
        return temp;
    }

    big_int operator-() const {
        big_int temp = *this;
        temp.sign = -sign;
        return temp;
    }

    // adunare valori absolute (fara semn)
    static big_int addAbs(const big_int& a, const big_int& b) {
        big_int temp;
        temp.digits = "";
        int t = 0;
        int cmax = max(a.no, b.no);
        for (int i = 0; i < cmax || t; i++) {
            int da = (i < a.no) ? (a.digits[i] - '0') : 0;
            int db = (i < b.no) ? (b.digits[i] - '0') : 0;
            t += da + db;
            temp.digits += (char)(t % 10 + '0');
            t /= 10;
        }
        temp.no = temp.digits.size();
        return temp;
    }

    // scadere valori absolute, PRESUPUNE a >= b ca valoare absoluta
    static big_int subAbs(const big_int& a, const big_int& b) {
        big_int temp;
        temp.digits = a.digits;
        int borrow = 0;
        for (int i = 0; i < a.no; i++) {
            int da = temp.digits[i] - '0' - borrow;
            int db = (i < b.no) ? (b.digits[i] - '0') : 0;
            if (da < db) { da += 10; borrow = 1; }
            else borrow = 0;
            temp.digits[i] = (char)(da - db + '0');
        }
        // elimina zerouri de la final (most significant)
        while (temp.digits.size() > 1 && temp.digits.back() == '0')
            temp.digits.pop_back();
        temp.no = temp.digits.size();
        return temp;
    }

    big_int operator+(const big_int& b) const {
        big_int temp;
        if (sign == b.sign) {
            temp = addAbs(*this, b);
            temp.sign = sign;
        } else {
            if (!absLess(*this, b)) {
                temp = subAbs(*this, b);
                temp.sign = sign;
            } else {
                temp = subAbs(b, *this);
                temp.sign = b.sign;
            }
        }
        // -0 fix
        if (temp.no == 1 && temp.digits[0] == '0') temp.sign = 1;
        return temp;
    }

    big_int operator-(const big_int& b) const {
        return *this + (-b);
    }

    big_int operator*(const big_int& b) const {
        big_int temp;
        temp.no = no + b.no;
        temp.digits.assign(temp.no, '0');
        temp.sign = sign * b.sign;

        for (int i = 0; i < no; i++) {
            int t = 0;
            for (int j = 0; j < b.no; j++) {
                int cur = (temp.digits[i+j] - '0')
                        + (digits[i] - '0') * (b.digits[j] - '0') + t;
                temp.digits[i+j] = (char)(cur % 10 + '0');
                t = cur / 10;
            }
            if (t) temp.digits[i + b.no] += t;
        }

        while (temp.digits.size() > 1 && temp.digits.back() == '0')
            temp.digits.pop_back();
        temp.no = temp.digits.size();
        if (temp.no == 1 && temp.digits[0] == '0') temp.sign = 1;
        return temp;
    }

    big_int operator/(const big_int& b) const {
        // impartire prin scaderi repetate pe cifre (long division)
        big_int result, current;
        result.digits.assign(no, '0');
        result.sign = sign * b.sign;
        big_int absB = b.abs();

        for (int i = no - 1; i >= 0; i--) {
            // current = current * 10 + digits[i]
            current.digits.insert(current.digits.begin(), digits[i]);
            current.no = current.digits.size();
            while (current.digits.size() > 1 && current.digits.back() == '0')
                current.digits.pop_back();
            current.no = current.digits.size();

            // gasim cifra: cat de multe ori intra absB in current
            int q = 0;
            while (!absLess(current, absB)) {
                current = subAbs(current, absB);
                q++;
            }
            result.digits[i] = (char)(q + '0');
        }

        while (result.digits.size() > 1 && result.digits.back() == '0')
            result.digits.pop_back();
        result.no = result.digits.size();
        if (result.no == 1 && result.digits[0] == '0') result.sign = 1;
        return result;
    }

    big_int operator%(const big_int& b) const {
        big_int q = *this / b;
        return *this - q * b;
    }

    friend istream& operator>>(istream& in, big_int& n) {
        string s; in >> s;
        n = big_int(s);
        return in;
    }

    friend ostream& operator<<(ostream& out, const big_int& n) {
        out << (string)n;
        return out;
    }
};/*
int main()
{
    big_int a = 96, b("420");
    cin >> a >> b;
    cout << a + b << "\n";
    cout << -a + b << "\n";
    cout << a - b << "\n";
    cout << a * b << "\n";
    cout << a / b << "\n";
    cout << a.abs() % b.abs() << "\n";
    if(a < b)
        cout << "a < b\n";
    else if(a == b)
        cout << "a = b\n";
    else cout << "a > b\n";

    return 0;
}*/
