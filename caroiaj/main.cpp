//ajutat de claude
#include <fstream>
#include <string>
using namespace std;
ifstream fin("caroiaj.in");
ofstream fout("caroiaj.out");
short p[500005];
char grid[505][505];
int main(){
    int n;
    fin >> n;
    for(int i = 1; i <= n; i++){
        string row;
        fin >> row;
        for(int j = 1; j <= n; j++)
            grid[i][j] = row[j-1];
    }

    string s;
    s.reserve(n * n);

    int pm = 0;
    while(pm < (n + 1) / 2){
        int top    = 1 + pm;
        int bottom = n - pm;
        int left   = 1 + pm;
        int right  = n - pm;
        if(top > bottom || left > right) break;

        for(int i = left; i <= right; i++)   s.push_back(grid[top][i]);
        for(int i = top+1; i <= bottom; i++) s.push_back(grid[i][right]);
        if(top != bottom)
            for(int i = right-1; i >= left; i--)     s.push_back(grid[bottom][i]);
        if(left != right)
            for(int i = bottom-1; i >= top+1; i--)   s.push_back(grid[i][left]);
        pm++;
    }
    int m = 2 * (int)s.size() + 1;
    auto T = [&](int i) -> char {
        return (i % 2 == 0) ? '#' : s[(i-1)/2];
    };

    int p1 = 0, p2 = 0;
    int vmax = 0, vmaxi = 0;

    for(int i = 0; i < m; i++){
        p[i] = 0;
        if(i < p2){
            int mirror = 2 * p1 - i;
            p[i] = (short)min(p2 - i, (int)p[mirror]);
        }
        while(i - p[i] - 1 >= 0 && i + p[i] + 1 < m &&
              T(i - p[i] - 1) == T(i + p[i] + 1)){
            p[i]++;
        }
        if(i + p[i] > p2){
            p1 = i;
            p2 = i + p[i];
        }
        if(p[i] >= vmax){
            vmax = p[i];
            vmaxi = i;
        }
    }

    int start = (vmaxi - vmax) / 2;
    fout << s.substr(start, vmax);
    return 0;
}
