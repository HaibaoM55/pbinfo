
// constructor stabileste valoare partii reale si acelei imaginare
Complex::Complex(int pr, int pi){
    r = pr;
    i = pi;
}
void Complex::set(int pr, int pi){
    r = pr;
    i = pi;
}
Complex::Complex(){
    i = 0;
    r = 0;
}
double Complex::modul(){
    return (double) sqrt(r*r+i*i);
}
//returneaza partea reala
int Complex::real(){
    return r;
}
//returneaza partea imaginara
int Complex::imag(){
    return i;
}
//supraincarcare operator pentru afisarea numarului complex
ostream& operator<<(ostream& stream, const Complex& nr) {
    if(nr.i == 0 && nr.r == 0){
        stream << 0;
    }else{
        if(nr.r == 0){
            stream << nr.i << "i";
        }else if(nr.i == 0){
            stream << nr.r;
        }else if(nr.i < 0){
            stream << nr.r << nr.i << "i";
        }else{
            stream << nr.r << "+"<<nr.i <<"i";
        }
    }
    return stream;
}
// supraincarcare operator adunare
Complex Complex::operator +(Complex nr) {
    Complex aux(real()+nr.real(), imag()+nr.imag());
    return aux;
}
// supraincarcare operator scadere
Complex Complex::operator -(Complex nr) {
    Complex aux(real()-nr.real(), imag()-nr.imag());
    return aux;
}
// supraincarcare operator inmultire
Complex Complex::operator *(Complex nr) {
    Complex aux(real()*nr.real()-imag()*nr.imag(), real()*nr.imag()+imag()*nr.real());
    return aux;
}
