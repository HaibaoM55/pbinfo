#include <fstream>
#include <map>
#include <iterator>
using namespace std;
ifstream fin("ambuscada.in");
ofstream fout("ambuscada.out");
#define maX 1000000000
int n, m, v;
map<int, int>a;
int main()
{
    fin >> n >> m >> v;
    a.insert(make_pair(0, v));
    a.insert(make_pair(n, 0));
    for (int p = 0; p < m; p++){
        int i, j, k;
        fin >> i >> j >> k;
        i--;
        j--;
        map<int, int>::iterator iterator1 = a.find(i);
        if (iterator1 == a.end()){
            a.insert(make_pair(i, -k));
        }
        else{
            iterator1->second -= k;
        }
        iterator1 = a.find(j + 1);
        if (iterator1 == a.end()){
            a.insert(make_pair(j + 1, k));
        }
        else{
            iterator1->second += k;
        }
    }
    int nr = 0, v1, j;
    map<int, int>::iterator iterator1 = a.begin();
    j = iterator1->first;
    v1 = iterator1->second;
    for(++iterator1; iterator1 != a.end(); ++iterator1)
    {
        if (v1 > 0){
            nr += iterator1->first - j;
        }
        j = iterator1->first;
        v1 += iterator1->second;
    }
    fout << nr;
    return 0;
}
