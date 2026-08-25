void interclasare(){
	ifstream fin1("file1.txt");
    ifstream fin2("file2.txt");
    ofstream fout("file.out");
    int n, m;
    int a, b;
    fin1 >> n;
    fin2 >> m;
    int p1 = 1, p2 = 1;
    fin1 >> a;
    fin2 >> b;
    while(p1 <= n && p2 <= m){
        if(a < b){
            fout << a << ' ';
            p1++;
            fin1 >> a;
        }else{
            fout << b << ' ';
            p2++;
            fin2 >> b;
        }
    }
    while(p1 <= n){
        fout << a << ' ';
        p1++;
        fin1 >> a;
    }
    while(p2 <= m){
        fout << b << ' ';
        p2++;
        fin2 >> b;
    }
}
