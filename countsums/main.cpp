#include <iostream>
#include <unordered_map>
using namespace std;
long long CountSumS(vector<int> &a, int s){
    int sz = a.size();
    unordered_map<int, int> f;
    long long nr = 0;
    for(int i = 0; i < sz; i++){
        nr += f[s-a[i]];
        f[a[i]]++;
    }
    return nr;
}
/*
int main()
{
    return 0;
}
*/
