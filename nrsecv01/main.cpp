long long NrSecv01(const char s[]){
    map<int,int> m;
    long long sp = 0;
    long long nrs = 0;
    m[0] = 1;
    for(int i = 0 ; s[i] ; ++i){
        sp += (s[i] - '0');
        nrs += m[sp - 1];
        m[sp]++;
    }
    return nrs;
}
