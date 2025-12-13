#include <fstream>
#include <unordered_map>
#include <vector>
using namespace std;
ifstream fin("1337.in");
ofstream fout("1337.out");
int main(){
    int n;
    long long k, p;
    fin >> n >> k >> p;
    if(n <= 2500){
    static long long v[100005];
    static long long st[100005][20];
    static int lg[100005];
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    lg[1] = 0;
    for(int i = 2; i <= n; i++){
        lg[i] = lg[i/2] + 1;
    }
    for(int i = 1; i <= n; i++){
        st[i][0] = v[i];
    }
    for(int j = 1; j <= 19; j++){
        for(int i = 1; i + (1 << j) - 1 <= n; i++){
            st[i][j] = max(st[i][j-1], st[i + (1 << (j-1))][j-1]);
        }
    }
    long long maxVal = -1e18 - 1;
    int bestLen = n + 1;
    int bestI = -1, bestJ = -1;
    bool found = false;
    unordered_map<long long, vector<int>> positions;
    positions.reserve(n + 1);
    positions[0].push_back(0);
    long long sum = 0;
    for(int j = 1; j <= n; j++){
        sum += v[j];
        long long mod = ((sum % k) + k) % k;
        long long needRest = ((mod - p) % k + k) % k;
        auto it = positions.find(needRest);
        if(it != positions.end()){
            for(int pos : it->second){
                int i = pos + 1;
                int len = j - i + 1;
                int jlog = lg[len];
                long long maxInSubseq = max(st[i][jlog], st[j - (1 << jlog) + 1][jlog]);
                found = true;
                if(maxInSubseq > maxVal ||
                    (maxInSubseq == maxVal && len < bestLen) ||
                    (maxInSubseq == maxVal && len == bestLen && i < bestI)){
                    maxVal = maxInSubseq;
                    bestLen = len;
                    bestI = i;
                    bestJ = j;
                }
            }
        }
        positions[mod].push_back(j);
    }
    if(!found){
        fout << "Nu exista\n";
    }else{
        fout << maxVal << "\n";
        fout << bestI << " " << bestJ << "\n";
    }
    return 0;
    }
    static long long v[100005];
    static long long st[100005][20];
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        st[i][0] = v[i];
    }
    for(int j = 1; j <= 19; j++){
        int step = 1 << (j-1);
        for(int i = 1; i + (1 << j) - 1 <= n; i++){
            st[i][j] = max(st[i][j-1], st[i + step][j-1]);
        }
    }
    long long maxVal = -1e18 - 1;
    int bestLen = n + 1;
    int bestI = -1;
    unordered_map<long long, int> firstPos;
    firstPos[0] = 0;
    long long sum = 0;
    for(int j = 1; j <= n; j++){
        sum += v[j];
        long long mod = ((sum % k) + k) % k;
        long long needRest = ((mod - p) % k + k) % k;
        auto it = firstPos.find(needRest);
        if(it != firstPos.end()){
            int i = it->second + 1;
            int len = j - i + 1;
            int jlog = 0;
            int temp = len;
            while(temp > 1){
                temp >>= 1;
                jlog++;
            }
            long long maxInSubseq = max(st[i][jlog], st[j - (1 << jlog) + 1][jlog]);
            if(maxInSubseq > maxVal ||
                (maxInSubseq == maxVal && len < bestLen) ||
                (maxInSubseq == maxVal && len == bestLen && i < bestI)){
                maxVal = maxInSubseq;
                bestLen = len;
                bestI = i;
            }
        }
        if(firstPos.find(mod) == firstPos.end()){
            firstPos[mod] = j;
        }
    }
    if(maxVal == -1e18 - 1){
        fout << "Nu exista\n";
    }else{
        fout << maxVal << "\n";
        fout << bestI << " " << bestI + bestLen - 1 << "\n";
    }
    return 0;
}
