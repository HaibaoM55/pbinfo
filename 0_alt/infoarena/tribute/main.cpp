#include <bits/stdc++.h>
using namespace std;
ifstream fin("tribute.in");
ofstream fout("tribute.out");
int n,dx,dy;
inline int dist(vector<int> &v,int n,int val)
{
    sort(v.begin(),v.end());
    int st=0,dr=n-1,s=0;
    while(v[dr]-v[st]>val)
    {
        s+=v[dr]-v[st]-val;
        dr--;
        st++;
    }
    return s;
}
int main()
{
    fin>>n>>dx>>dy;
    vector<int> x(n), y(n);
    for(int i=0;i < n;i++)
    {
        fin>>x[i]>>y[i];
    }
    fout<<dist(x,n,dx)+dist(y,n,dy);
}
