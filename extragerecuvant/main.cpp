int extrageCuvant(char* dest, const char* sursa, const char* sep, int nrcuv){
    int nr = 0;
    int i = 0;
    int j = 0;
    while(sursa[i] != 0){
        int estesep = 0;
        int k = 0;
        while(sep[k] != 0){
            if(sursa[i] == sep[k]){
                estesep = 1;
                break;
            }
            k++;
        }
        if(!estesep){
            dest[j] = sursa[i];
            j++;
        }else if(j > 0){
            dest[j] = 0;
            j = 0;
            nr++;
            if(nr > nrcuv){
                return 1;
            }
        }
        i++;
    }
    if(j > 0 && nr == nrcuv){
        dest[j] = 0;
        return 1;
    }
    return 0;
}
