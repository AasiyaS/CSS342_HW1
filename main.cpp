#include <iostream>
#include <string>
using namespace std;

// 1: Check if a number is a power of two (loop method)
    bool isPowerOfTwo_loop(int n) {
        if (n < 1)  {
            return false;
        }
        while (n > 1) {
            if (n % 2 != 0) {
                return false;
            }
            n = n / 2;
        }
        return true;
    }

// 1: Check if a number is a power of two (non-loop method)
    bool isPowerOfTwo_nonLoop(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }

// 1: Power of two test function
    void testPowerOfTwo() {
        int testCases[] = {1, 2, 4, 8, 16, 3, 5, 18, 0, -2};
        bool expected[] = {true, true, true, true, true, false, false, false, false, false};
        for (int i = 0; i < 10; i++) {
            if (isPowerOfTwo_loop(testCases[i]) != expected[i] || isPowerOfTwo_nonLoop(testCases[i]) != expected[i]) {
                cout << "FAIL" << endl;
                return;
            }
        }
        cout << "PASS" << endl;
    }

// 2: Check if a number is a prime number
    bool isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

// 2: Prime number test function
    void testIsPrime() {
        int testCases[] = {1, 2, 3, 4, 5, 9, 11, 13, 16, 17};
        bool expected[] = {false, true, true, false, true, false, true, true, false, true};
        for (int i = 0; i < 10; i++) {
            if (isPrime(testCases[i]) != expected[i]) {
                cout << "FAIL" << endl;
                return;
            }
        }
        cout << "PASS" << endl;
    }

// 3: Reduce a fraction number to its lowest term
class Fraction {
    public:
        int numerator;
        int denominator;

        Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {

        }

        string to_string() {
            return std::to_string(numerator) + "/" + std::to_string(denominator);
        }

        bool operator==(Fraction &other) {
            return this->numerator == other.numerator &&
                   this->denominator == other.denominator;
        }
    };

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    Fraction reduce(Fraction input) {
        int g = gcd(input.numerator, input.denominator);
        input.numerator /= g;
        input.denominator /= g;
        return input;
    }

// 3: Reducing a function test function
    void testReduceFraction() {
        Fraction inputs[4] = {Fraction(1, 2),
                              Fraction(2, 4),
                              Fraction(4, 2),
                              Fraction(6, 8)};
        Fraction outputs[4] = {Fraction(1, 2),
                              Fraction(1, 2),
                              Fraction(2, 1),
                              Fraction(3, 4)};

        for (int i = 0; i < 4; ++i) {
            Fraction input = inputs[i];
            Fraction expected = outputs[i];
            Fraction actual = reduce(input);

            if (expected == actual) {
                continue;
            } else {
                cout << "FAIL" << endl;
                return;
            }
        }
        cout << "PASS" << endl;
    }

int main() {
        testPowerOfTwo();   // Test 1
        testIsPrime();  // Test 2
        testReduceFraction(); // Test 3
        return 0;
}