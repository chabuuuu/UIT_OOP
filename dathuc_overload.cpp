#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class Polynomial {
private:
    std::vector<int> coefficients;

public:
    Polynomial() {}

    Polynomial(const std::vector<int>& coeffs) : coefficients(coeffs) {}

    int Degree() const {
        return coefficients.size() - 1;
    }

    Polynomial operator+(const Polynomial& other) const {
        int maxDegree = std::max(Degree(), other.Degree());
        std::vector<int> resultCoeffs(maxDegree + 1, 0);

        for (int i = 0; i <= maxDegree; i++) {
            if (i <= Degree())
                resultCoeffs[i] += coefficients[i];
            if (i <= other.Degree())
                resultCoeffs[i] += other.coefficients[i];
        }

        return Polynomial(resultCoeffs);
    }

    Polynomial operator-(const Polynomial& other) const {
        int maxDegree = std::max(Degree(), other.Degree());
        std::vector<int> resultCoeffs(maxDegree + 1, 0);

        for (int i = 0; i <= maxDegree; i++) {
            if (i <= Degree())
                resultCoeffs[i] += coefficients[i];
            if (i <= other.Degree())
                resultCoeffs[i] -= other.coefficients[i];
        }

        return Polynomial(resultCoeffs);
    }

    Polynomial operator*(const Polynomial& other) const {
        int resultDegree = Degree() + other.Degree();
        std::vector<int> resultCoeffs(resultDegree + 1, 0);

        for (int i = 0; i <= Degree(); i++) {
            for (int j = 0; j <= other.Degree(); j++) {
                resultCoeffs[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        return Polynomial(resultCoeffs);
    }

    std::string ToString() const {
        std::stringstream ss;

        for (int i = 0; i <= Degree(); i++) {
            if (coefficients[i] != 0) {
                if (i != 0 && coefficients[i] >= 0)
                    ss << "+";

                ss << coefficients[i];

                // if (i != 0)
                    ss << "x^" << i;
            }
        }

        return ss.str();
    }
};

int main() {
    // Bước 1: Nhập đa thức thứ nhất
    int n1;
    std::cin >> n1;
    std::vector<int> coeffs1(n1 + 1);
    for (int i = 0; i <= n1; i++) {
        std::cin >> coeffs1[i];
    }
    Polynomial polynomial1(coeffs1);

    // Bước 2: Nhập đa thức thứ hai
    int n2;
    std::cin >> n2;
    std::vector<int> coeffs2(n2 + 1);
    for (int i = 0; i <= n2; i++) {
        std::cin >> coeffs2[i];
    }
    Polynomial polynomial2(coeffs2);

    // Bước 3: Nhập phép toán
    std::string op;
    std::cin >> op;

    // Bước 4: Thực hiện phép toán và xuất kết quả
    Polynomial result;
    if (op == "+") {
        result = polynomial1 + polynomial2;
    } else if (op == "-") {
        result = polynomial1 - polynomial2;
} else if (op == "*") {
result = polynomial1 * polynomial2;
}
std::string resultString = result.ToString();
std::cout << resultString << std::endl;

// Bước 5: Kết thúc chương trình
return 0;
}
       
