#include <iostream>
using namespace std;

//* Link - https://leetcode.com/problems/climbing-stairs/

//* SOLUTION
int climbStairs(int n) {
    // Using Bottom-Up DP
    int pos1 = 1, pos2 = 1;

    for (int i = 0; i < n - 1; i++) {
        int temp = pos1;
        pos1 += pos2;
        pos2 = temp;
    }

    return pos1;
}

int main() {
    int n = 5;
    cout << "Number of steps = " << n << "\n";
    cout << "Soln = " << climbStairs(n) << "\n";
    return 0;
}