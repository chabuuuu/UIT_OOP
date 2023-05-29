#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
struct HocSinh {
    std::string hoTen;
    std::string ngaySinh;
    float diemToan[2]; // 0: GK Toán, 1: CK Toán
    float diemVan[2]; // 0: GK Văn, 1: CK Văn
    float diemAnh[2]; // 0: GK Tiếng Anh, 1: CK Tiếng Anh
};

bool isValidDate(const std::string& date) {
    // Kiểm tra ngày sinh hợp lệ theo định dạng dd/mm/yyyy
    // Code kiểm tra ngày sinh hợp lệ ở đây
    return true; // Tạm thời luôn trả về true
}

bool isValidScore(float score) {
    // Kiểm tra điểm hợp lệ (trong khoảng từ 0 đến 10)
    return (score >= 0 && score <= 10);
}

float calculateAverageScore(const HocSinh& hocSinh) {
    // Tính điểm trung bình của học sinh dựa trên công thức cho trước
    float tbToan = (hocSinh.diemToan[0] + hocSinh.diemToan[1]) / 2;
    float tbVan = (hocSinh.diemVan[0] + hocSinh.diemVan[1]) / 2;
    float tbAnh = (hocSinh.diemAnh[0] + hocSinh.diemAnh[1]) / 2;
    return (tbToan + tbVan + tbAnh) / 3;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::cin.ignore(); // Loại bỏ kí tự '\n' sau khi nhập k

    std::vector<HocSinh> danhSachHocSinh;

    // Nhập thông tin từng học sinh
    for (int i = 0; i < n; i++) {
        HocSinh hocSinh;

        std::getline(std::cin, hocSinh.hoTen);
        std::getline(std::cin, hocSinh.ngaySinh);

        // Kiểm tra và nhập điểm Toán
        do {
            std::cin >> hocSinh.diemToan[0] >> hocSinh.diemToan[1];
        } while (!(isValidScore(hocSinh.diemToan[0]) && isValidScore(hocSinh.diemToan[1])));
        std::cin.ignore(); // Loại bỏ kí tự '\n' sau khi nhập điểm Toán

        // Kiểm tra và nhập điểm Văn
        do {
            std::cin >> hocSinh.diemVan[0] >> hocSinh.diemVan[1];
        } while (!(isValidScore(hocSinh.diemVan[0]) && isValidScore(hocSinh.diemVan[1])));
        std::cin.ignore(); // Loại bỏ kí tự '\n' sau khi nhập điểm Văn

        // Kiểm tra và nhập điểm Tiếng Anh
            // Kiểm tra và nhập điểm Tiếng Anh
        do {
            std::cin >> hocSinh.diemAnh[0] >> hocSinh.diemAnh[1];
        } while (!(isValidScore(hocSinh.diemAnh[0]) && isValidScore(hocSinh.diemAnh[1])));
        std::cin.ignore(); // Loại bỏ kí tự '\n' sau khi nhập điểm Tiếng Anh

        danhSachHocSinh.push_back(hocSinh);
    }

    std::vector<HocSinh> hocSinhGioi;

    // Lọc và tính toán học sinh đủ điều kiện thi học sinh giỏi
    for (const auto& hocSinh : danhSachHocSinh) {
        if (isValidDate(hocSinh.ngaySinh)) {
            float tb = calculateAverageScore(hocSinh);
            if (tb >= 8 && hocSinh.diemToan[0] >= 7 && hocSinh.diemVan[0] >= 7 && hocSinh.diemAnh[0] >= 7 &&
                hocSinh.diemToan[1] >= 5 && hocSinh.diemVan[1] >= 5 && hocSinh.diemAnh[1] >= 5) {
                hocSinhGioi.push_back(hocSinh);
            }
        }
    }

    // Sắp xếp danh sách học sinh giỏi theo điểm trung bình giảm dần
    sort(hocSinhGioi.begin(), hocSinhGioi.end(), [](const HocSinh& a, const HocSinh& b) {
        return calculateAverageScore(a) > calculateAverageScore(b);
    });

    // Xuất thông tin k học sinh đủ điều kiện thi học sinh giỏi
    for (int i = 0; i < std::min(k, static_cast<int>(hocSinhGioi.size())); i++) {
        const auto& hocSinh = hocSinhGioi[i];
        float tb = calculateAverageScore(hocSinh);
        std::cout << "Ho ten: " << hocSinh.hoTen << " - Diem trung binh: " << std::fixed << std::setprecision(2) << tb << std::endl;
    }

    return 0;
}

