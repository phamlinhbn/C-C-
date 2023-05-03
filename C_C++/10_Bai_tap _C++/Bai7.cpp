#include <iostream>
#include <ctime>

using namespace std;

class Date {
private:
    uint8_t day, month;
    uint16_t year;
public:
    Date(uint8_t d, uint8_t m, uint16_t y);
    uint8_t Cal_Age();
    bool isHoliday();
};

Date::Date(uint8_t d, uint8_t m, uint16_t y) {
    day = d;
    month = m;
    year = y;
}

uint8_t Date::Cal_Age() {
    time_t now = time(NULL);
    tm *local_time = localtime(&now);
    uint16_t current_year = local_time->tm_year + 1900;
    uint8_t current_month = local_time->tm_mon + 1;
    uint8_t current_day = local_time->tm_mday;
    uint8_t age = current_year - year;
    if (current_month < month || (current_month == month && current_day < day)) {
        age--;
    }
    return age;
}

bool Date::isHoliday() {
    if ((month == 1 && day == 1) || // New Year's Day
        (month == 2 && day == 14) || // Valentine Day
        (month == 3 && day == 8) || // International Women's Day
        (month == 4 && day == 30) || // Liberation Day
        (month == 5 && day == 1) || // International Worker's Day
        (month == 6 && day == 1) || // International Children's Day
        (month == 9 && day == 2) || // National Dat
        (month == 10 && day == 20) || // Vietnamese Women's Day
        (month == 11 && day == 20) )// Teacher's Day
    {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    Date my_birthday(28, 4, 2000);
    uint8_t my_age = my_birthday.Cal_Age();
    cout << "I am " << static_cast<int>(my_age) << " years old." << endl;

    Date new_year(1, 1, 2023);
    if (new_year.isHoliday()) {
        cout << "New Year's Day is a holiday." << endl;
    }
    else {
        cout << "New Year's Day is not a holiday." << endl;
    }
    return 0;
}
