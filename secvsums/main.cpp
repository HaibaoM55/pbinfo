int SecvSumS(vector<int> &a, int s) {
    map<long long, int> f;
    long long sma = 0;
    int n = a.size();
    int vmin = n + 1;
    for(int i = 0; i < n; i++){
        sma += a[i];
        if(sma == s){
            vmin = min(vmin, i + 1);
        }
        if(f.find(sma - s) != f.end()){
            vmin = min(vmin, i - f[sma - s]);
        }
        if(f.find(sma) == f.end()){
            f[sma] = i;
        }
    }
    if(vmin == n + 1){
        return -1;
    }
    return vmin;
}
