void nule(std::vector<int> &v)
{
    int i, j, aux, size = v.size();
    bool swaped;
    std::vector<int> b;
    int z = 0;
    for(i = 0; i < size; i++){
        if(v[i] == 0){
        	z++;
        }else{
			b.push_back(v[i]);
        }
    }
    for(i = 1; i <= z; i++){
    	b.push_back(0);
    }
    v = b;
}
