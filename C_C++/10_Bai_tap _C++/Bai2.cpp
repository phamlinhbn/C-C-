#include <iostream>
#include <cmath>
using namespace std;

class HinhChuNhat
{
    private:
        float chieuDai;
        float chieuRong;
    public:
        HinhChuNhat(float dai, float rong);
        float tinhChuVi();
        float tinhDienTich();
        float tinhDuongCheo();
        bool kiemTraHinhVuong();
};

HinhChuNhat::HinhChuNhat(float dai, float rong)
{
    chieuDai = dai;
    chieuRong = rong;
}

float HinhChuNhat::tinhChuVi()
{
    return 2 * (chieuDai + chieuRong);
}

float HinhChuNhat::tinhDienTich()
{
    return chieuDai * chieuRong;
}

float HinhChuNhat::tinhDuongCheo()
{
    return sqrt(pow(chieuDai, 2) + pow(chieuRong, 2));
}

bool HinhChuNhat::kiemTraHinhVuong()
{
    if (chieuDai == chieuRong) {
        return true;
    }
    return false;
}

int main()
{
    float dai, rong;
    cout << "Nhap chieu dai: ";
    cin >> dai;
    cout << "Nhap chieu rong: ";
    cin >> rong;

    HinhChuNhat hcn(dai, rong);

    cout << "Chu vi cua hinh chu nhat la: " << hcn.tinhChuVi() << endl;
    cout << "Dien tich cua hinh chu nhat la: " << hcn.tinhDienTich() << endl;
    cout << "Duong cheo cua hinh chu nhat la: " << hcn.tinhDuongCheo() << endl;

    if (hcn.kiemTraHinhVuong()) {
        cout << "Day la hinh vuong." << endl;
    } else {
        cout << "Day khong phai la hinh vuong." << endl;
    }

    return 0;
}
