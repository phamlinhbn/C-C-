#include <iostream>
#include <string>
using namespace std;

class DongVat
{
private:
    float tuoi;
    float canNang;
public:
    string ten;
    DongVat(float t, float c, string ten);
    float tinhChiSoBMI();
    bool lonHon(DongVat other);
};

DongVat::DongVat(float t, float c, string ten)
{
    tuoi = t;
    canNang = c;
    this->ten = ten;
}

float DongVat::tinhChiSoBMI()
{
    float chiSoBMI = canNang / (tuoi * tuoi);
    return chiSoBMI;
}

bool DongVat::lonHon(DongVat other)
{
    if (canNang > other.canNang) {
        return true;
    } else {
        return false;
    }
}

int main()
{
    DongVat cho(2, 5, "Cho");
    DongVat meo(3, 4, "Meo");
    
    float bmiCho = cho.tinhChiSoBMI();
    float bmiMeo = meo.tinhChiSoBMI();
    
    cout << "BMI cua " << meo.ten << " la " << bmiMeo << endl;
    cout << "BMI cua " << cho.ten << " la " << bmiCho << endl;
    
    if (cho.lonHon(meo)) {
        cout << cho.ten << " nang hon " << meo.ten << endl;
    } else {
        cout << meo.ten << " nhe hon " << cho.ten << endl;
    }
    
    return 0;
}

