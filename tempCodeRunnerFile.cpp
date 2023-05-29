#include <iostream>

class Clock {
private:
    int hour;
    int minute;
    int second;

public:
    Clock(int hour, int minute, int second) {
        this->hour = hour % 24;
        this->minute = minute % 60;
        this->second = second % 60;
    }

    void operator++() {
        second++;
        if (second >= 60) {
            second = 0;
            minute++;
            if (minute >= 60) {
                minute = 0;
                hour++;
                hour %= 24;
            }
        }
    }

    void operator--() {
        second--;
        if (second < 0) {
            second = 59;
            minute--;
            if (minute < 0) {
                minute = 59;
                hour--;
                if (hour < 0) {
                    hour = 23;
                }
            }
        }
    }

    Clock operator+(int seconds) {
        Clock result = *this;
        result.second += seconds;
        while (result.second >= 60) {
            result.second -= 60;
            result.minute++;
            if (result.minute >= 60) {
                result.minute = 0;
                result.hour++;
                result.hour %= 24;
            }
        }
        return result;
    }

    Clock operator-(int seconds) {
        Clock result = *this;
        result.second -= seconds;
        while (result.second < 0) {
            result.second += 60;
            result.minute--;
            if (result.minute < 0) {
                result.minute = 59;
                result.hour--;
                if (result.hour < 0) {
                    result.hour = 23;
                }
            }
        }
        return result;
    }

    void Print() {
        std::cout << hour << " " << minute << " " << second << " " << std::endl;
    }
};

int main() {
    // Bước 1: Nhập giờ, phút, giây ban đầu
    int hour, minute, second;
    std::cin >> hour >> minute >> second;
    Clock clock(hour, minute, second);

    // Bước 2: Nhập số lượng chỉ thị
    int n;
    std::cin >> n;

    // Bước 3: Thực hiện chỉ thị
    for (int i = 0; i < n; i++) {
        std::string op;
        std::cin >> op;
        if (op == "++") {
            ++clock;
        } else if (op == "--") {
            --clock;
        } else if (op == "+") {
            int seconds;
            std::cin >> seconds;
            clock = clock + seconds;
        } else if (op == "-") {
            int seconds;
            std::cin >> seconds;
            clock = clock - seconds;
        }
    }

    // Bước 4: Xuất kết quả
    clock.Print();

    // Bước 5: Kết thúc chương trình
    return 0;
}
