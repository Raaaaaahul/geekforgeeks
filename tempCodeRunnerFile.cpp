#include <iostream>
#include <cmath>
using namespace std;
int gcd(int a, int b) {
    while (b) {
        a = a % b;
        std::swap(a, b);
    }
    return a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int minimumHappyNumber(int num1, int num2, int x, int y) {
    int lcm_xy = lcm(x, y);
    int n = std::ceil(std::max(num1, num2) / (double)lcm_xy) * lcm_xy; // Round up to the nearest multiple of lcm

    while (true) {
        if (n - num1 >= lcm_xy && n - num2 >= lcm_xy) {
            return n;
        }
        n += lcm_xy; // Increment by lcm
    }
}

int main() {
    // Example usage for the given input:
    int Num1 = 1;
    int Num2 = 3;
    int X = 2;
    int Y = 7;

    int result = minimumHappyNumber(Num1, Num2, X, Y);
    std::cout << "The minimum number N is: " << result << std::endl;

    return 0;
}