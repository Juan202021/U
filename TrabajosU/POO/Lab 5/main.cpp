#include <iostream>

using namespace std;

class Hora{
    int horas, minutos, segundos;
public:
    Hora(){
        horas = 0;
        minutos = 0;
        segundos = 0;
    }
    Hora(int h, int m, int s){
        validar(h,m, s);
        horas = h;
        minutos = m;
        segundos = s;
    }

    int getHoras(){
        return horas;
    }
    void setHoras(int horas) {
        this -> horas = horas;
    }

    int getMinutos(){
        return minutos;
    }
    void setMinutos(int minutos) {
        this -> minutos = minutos;
    }

    int getSegundos(){
        return segundos;
    }
    void setSegundos(int segundos) {
        this -> segundos = segundos;
    }

    friend ostream& operator<<(ostream &out, Hora &h){
        out << h.horas << ":";
        out << h.minutos << ":";
        out << h.segundos << endl;
        return out;
    }

    friend istream& operator>>(istream &in, Hora &h){
        cout << "Digite la hora: " << endl;
        in >> h.horas;
        cout << "Digite los minutos: " << endl;
        in >> h.minutos;
        cout << "Digite los segundos: " << endl;
        in >> h.segundos;
        return in;
    }

    Hora operator++(){
        segundos++;
        if (segundos > 59){
            segundos -= 60;
            ++minutos;
        }
        if (minutos > 59){
            minutos -= 60;
            ++horas;
        }
        if (horas > 23){
            horas = 0;
            minutos = 0;
            segundos = 0;
        }
        return Hora(horas,minutos,segundos);
    }
    void operator+=(const int n){
        segundos += n;
        validar(horas,minutos,segundos);
    }
    void operator-=(const int n){
        segundos -= n;
        validar(horas,minutos,segundos);
    }

private:
    void validar(int &h, int &m, int &s){
        h = (h<0) ? -h : h;
        m = (m<0) ? -m : m;
        s = (s<0) ? -s : s;
        if (s > 59){
            m += s/60;
            s %= 60;
        }
        if (m > 59){
            h += m/60;
            m %= 60;
        }
        if (h > 23){
            h = 0;
        }
    }
};

int totalSegundos(Hora &hh){
    int h, m, s;
    h = hh.getHoras()*(60*60);
    m = hh.getMinutos()*60;
    s = hh.getSegundos();
    return h+m+s;
}

int main() {
    int n=0;
    Hora h1(-23,59,-23);
    Hora h2(-5,345,-145);

    while (n<100){
        cout << h1;
        ++h1;
        n++;
    }
    cout << h1 << "Pasaron " << totalSegundos(h1) << " minutos desde la media noche" << endl;
    system("pause");

    return 0;
}
