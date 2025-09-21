#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
string p, s;
int n, k, x;
vector<int> ordinef(const string& p) {
    vector<int> p1(26);
    for (int i = 0; i < 26; i++) {
        p1[p[i] - 'a'] = i;
    }
    return p1;
}
bool compara(const string& s1, const string& s2, const vector<int>& p1) {
    int len = s1.length();
    for (int i = 0; i < len; i++) {
        if (p1[s1[i] - 'a'] < p1[s2[i] - 'a']) return true;
        if (p1[s1[i] - 'a'] > p1[s2[i] - 'a']) return false;
    }
    return false;
}
int main() {
    cin >> p;
    cin >> n >> k >> x;
    cin >> s;
    vector<int> p1 = ordinef(p);
    vector<string> subsequences;
    for (int i = 0; i <= n - k; i++) {
        subsequences.push_back(s.substr(i, k));
    }
    sort(subsequences.begin(), subsequences.end(), [&p1](const string& s1, const string& s2) {
        return compara(s1, s2, p1);
    });
    cout << subsequences[x-1];
    return 0;
}
