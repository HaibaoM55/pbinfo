bool eprim(int k){
    if(k < 2) return false;
    for(int d = 2; d*d <= k; d++){
        if(k % d == 0) return false;
    }
    return true;
}
bool PP(int x){
    int p = 0;
    int nrc = 0;
    int og = x;
    do{
        p = p*10+x%10;
        nrc++;
        x = x/10;
    }while(x);
    x = og;
    if(nrc % 2 == 0 && p == x){
        nrc = nrc/2;
        while(nrc){
            p = p/10;
            x = x/10;
            nrc--;
        }
        return eprim(p);
    }
    return false;
}
