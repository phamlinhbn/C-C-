#include <iostream>
#define PI 3.14

using namespace std;

class HinhTron
{
    private:
        float BanKinh;
    public:
        HinhTron(float bankinh);
        float tinhchuvi();
        float tinhdientich();
};
HinhTron::HinhTron(float bankinh)
{
    BanKinh = bankinh;
}
float HinhTron::tinhchuvi()
{
    return 2*PI*BanKinh;
}
float HinhTron::tinhdientich()
{
    return PI*BanKinh*BanKinh;
}

int main()
{
    float bankinh;
    cout << "Nhap ban kinh hinh tron: ";
    cin >> bankinh;
    HinhTron ht(bankinh);
    cout << "Chu vi hinh tron la: " << ht.tinhchuvi() << endl;
    cout << "Dien tich hinh tron la: " << ht.tinhdientich() << endl;
    return 0;
}