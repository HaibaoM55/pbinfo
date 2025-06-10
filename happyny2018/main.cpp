#include <iostream>
using namespace std;
int n, m, x;
int v[2025];
class OutParser

{

private:

    char *buff;

    int sp;


    void write_ch(char ch)

    {

        if (sp == 50000)

        {

            fwrite(buff, 1, 50000, stdout);

            sp = 0;

            buff[sp++] = ch;

        }

        else

        {

            buff[sp++] = ch;

        }

    }



public:
 OutParser() {
        buff = new char[50000]();
        sp = 0;}
    ~OutParser(){
        fwrite(buff, 1, sp, stdout);
        fclose(stdout);
    }
    OutParser& operator << (int vu32){
        if (vu32 <= 9){
            write_ch(vu32 + '0');
        }
        else{
            (*this) << (vu32 / 10);
            write_ch(vu32 % 10 + '0');
        }
        return *this;
    }
    OutParser& operator << (long long vu64){
        if (vu64 <= 9){
            write_ch(vu64 + '0');
        }
        else{
            (*this) << (vu64 / 10);
            write_ch(vu64 % 10 + '0');
        }
        return *this;
    }
    OutParser& operator << (char ch){
        write_ch(ch);
        return *this;
    }
    OutParser& operator << (const char *ch){
        while (*ch){
            write_ch(*ch);
            ++ch;
        }
        return *this;
    }
};
int main(){
    cin >> n >> m;
    OutParser out;
    for(int i = 1; i <= n; i++){
        cin >> x;
        int c = x/m;
        int r = x%m;
        for(int j = 1; j <= m-r; j++){
            out << c << " ";
        }
        for (int j = 1; j <= r; j++){
            out << c+1 << " ";
        }
        out << '\n';
    }
    return 0;
}
