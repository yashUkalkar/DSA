#include <iostream>
using namespace std;

//* Link -

//* SOLUTION
uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;

    for (int i = 0; i < 32; i++) {
        result <<= 1;
        result |= n & 1;
        n >>= 1;
    }

    return result;
}

int main() {
    uint32_t n = 43261596;
    cout << "Input = " << n << "\n";

    cout << "Reversed = " << reverseBits(n) << "\n";

    return 0;
}