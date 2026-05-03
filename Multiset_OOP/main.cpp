//#include <bits/stdc++.h>
//using namespace std;
// aici va aparea definitia scrisa de voi a clasei Multiset
class Multiset{
    private:
        int size=0;
        int aib[1000004];
        int suma(int poz){
            int sma = 0;
            for(poz; poz >= 1; poz -= poz & (-poz)){
                sma += aib[poz];
            }
            return sma;
        }
        void update(int poz, int val){
            for(poz; poz <= size; poz += poz & (-poz)){
                aib[poz] += val;
            }
        }
    public:
        Multiset(int sz){
            size = sz;
        }
        int Find(int x) {
            int pos = 0;
            for(int step = (1 << 20); step >= 1; step >>= 1){
                if(pos + step <= size && aib[pos + step] < x){
                    pos += step;
                    x -= aib[pos];
                }
            }
            return pos+1;
        }
        void Erase(int x){
            update(Find(x), -1);
        }
        void Insert(int x){
            update(x, +1);
        }
};/*
int n, q, op, x;
int main()
{
    cin >> n;
    Multiset ms(n);
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        ms.Insert(x);
    }
    cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        cin >> op >> x;
        if (op == 1)
            ms.Insert(x);
        else if (op == 2)
            ms.Erase(x);
        else cout <<    ms.Find(x) << '\n';
    }
    return 0;
}*/
