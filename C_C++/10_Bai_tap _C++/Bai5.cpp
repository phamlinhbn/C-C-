#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Nguoi {
    private:
        string ten;
        int tuoi;
        string diaChi;
        int tinhTuoi() {
            time_t t = time(NULL);
            tm* timePtr = localtime(&t);
            int namHienTai = timePtr->tm_year + 1900;
            return namHienTai - tuoi;
        }
    public:
        Nguoi(string ten, int tuoi, string diaChi) {
            this->ten = ten;
            this->tuoi = tuoi;
            this->diaChi = diaChi;
        }
        void inThongTin() {
            cout << "Ho ten: " << ten << endl;
            cout << "Tuoi: " << tinhTuoi() << endl;
            cout << "Dia chi: " << diaChi << endl;
        }
};

int main() {
    Nguoi nguoi("Nguyen Van A", 1990, "Ha Noi");
    nguoi.inThongTin();
    return 0;
}
