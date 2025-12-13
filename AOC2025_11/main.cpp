/*PART 1:
#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("a.in");
ofstream fout("a.out");
#define LIMIT 593
char rasp[1004];
int f[20004][20];
int cti(char nume[]){
    return (nume[2]-'a'+1)*729+(nume[1]-'a'+1)*27+(nume[0]-'a'+1);
}
int path(int x){
    int r = 0;
    for(int i = 1; i <= f[x][0]; i++){
        if(f[x][i] == 15162){
            r++;
        }else{
            r += path(f[x][i]);
        }
    }
    return r;
}
int main(){
    for(int i = 1; i <= LIMIT; i++){
        fin.get(rasp, 1004);
        fin.get();
        int l = strlen(rasp);
        char pl[5];
        int z = 0;
        int numei;
        for(int j = 0; j <= l; j++){
            if(rasp[j] == ':'){
                z = 0;
                pl[3] = 0;
                numei = cti(pl);
                j++;
            }else if(rasp[j] == ' ' || rasp[j] == 0){
                pl[3]=0;
                z = 0;
                f[numei][0]++;
                f[numei][f[numei][0]] = cti(pl);
                continue;
            }else{
                pl[z] = rasp[j];
                z++;
            }
        }
    }
    fout << path(cti("you"));
    return 0;
}
*/
//PART 2:
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <tuple>
using namespace std;
unordered_map<string, vector<string>> graph;
map<tuple<string, bool, bool>, long long> dp;
long long countPaths(const string& current, const string& target,
    bool visitedDac, bool visitedFft) {
    if (current == "dac") visitedDac = true;
    if (current == "fft") visitedFft = true;
    if(current == target){
        return (visitedDac && visitedFft) ? 1 : 0;
    }
    auto key = make_tuple(current, visitedDac, visitedFft);
    if(dp.find(key) != dp.end()){
        return dp[key];
    }
    if(graph.find(current) == graph.end()){
        return 0;
    }
    long long totalPaths = 0;
    for(const string& neighbor : graph[current]){
        totalPaths += countPaths(neighbor, target, visitedDac, visitedFft);
    }
    dp[key] = totalPaths;
    return totalPaths;
}
int main() {
    ifstream input("a.in");
    string line;
    while (getline(input, line)) {
        if (line.empty()) continue;
        size_t colonPos = line.find(':');
        if (colonPos == string::npos) continue;
        string device = line.substr(0, colonPos);
        string outputs = line.substr(colonPos + 1);
        istringstream iss(outputs);
        string output;
        while (iss >> output) {
            graph[device].push_back(output);
        }
    }
    input.close();
    long long result = countPaths("svr", "out", false, false);
    cout << result << endl;
    return 0;
}
