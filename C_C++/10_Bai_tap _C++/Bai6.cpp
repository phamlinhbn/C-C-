#include <iostream>
#include <stdint.h>

 
using namespace std;

class phanso
{
    private:
        int tuso;
        int mauso;
    public:
        phanso() : tuso(0), mauso(1) {}
        phanso(int tuso, int mauso);
        void nhapphanso();
        void hienthi();
        phanso cong(phanso ps);
        phanso tru(phanso ps);
        phanso nhan(phanso ps);
        phanso chia(phanso ps);
};

phanso::phanso(int tuso, int mauso)
{
    this->tuso = tuso;
    this->mauso = mauso;
}
void phanso::nhapphanso()
{
    cout << "Nhap tu so: ";
    cin >> tuso;
    cout << "Nhap mau so: ";
    cin >> mauso;
}
void phanso::hienthi()
{
    cout << tuso << "/" << mauso;
}

phanso phanso::cong(phanso ps)
{
    phanso tong;
    tong.tuso = tuso*ps.mauso + mauso*ps.tuso;
    tong.mauso = mauso*ps.mauso;
    return tong;
}

phanso phanso::tru(phanso ps)
{
    phanso hieu;
    hieu.tuso = tuso*ps.mauso - mauso*ps.tuso;
    hieu.mauso = mauso*ps.mauso;
    return hieu;
}

phanso phanso::nhan(phanso ps)
{
    phanso tich;
    tich.tuso = tuso*ps.tuso;
    tich.mauso = mauso*ps.mauso;
    return tich;
}

phanso phanso::chia(phanso ps)
{
    phanso thuong;
    thuong.tuso = tuso*ps.mauso;
    thuong.mauso = mauso*ps.tuso;
    return thuong;
}

int main()
{
    phanso a,b,c;
    a.nhapphanso();
    cout << "Phan so a: ";
    a.hienthi();
    cout << endl;
    b.nhapphanso();
    cout << "Phan so b: ";
    b.hienthi();
    cout << endl;
    c = a.cong(b);
    cout << "Tong 2 phan so a va b: ";
    c.hienthi();
    cout << endl;
    c = a.tru(b);
    cout << "Hieu 2 phan so a va b: ";
    c.hienthi();
    cout << endl;
    c = a.nhan(b);
    cout << "Tich 2 phan so a va b: ";
    c.hienthi();
    cout << endl;
    c = a.chia(b);
    cout << "Thuong 2 phan so a va b: ";
    c.hienthi();
    cout << endl;
}
