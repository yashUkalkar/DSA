#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/car-fleet/

int carFleet(int target, vector<int>& position, vector<int>& speed) {
    stack<float> st;

    // Combine position and speed vectors
    vector<pair<int, int>> carData;
    for (int i = 0; i < position.size(); i++) {
        carData.push_back(pair<int, int>{position[i], speed[i]});
    }

    // Sort by position in descending order
    sort(carData.rbegin(), carData.rend());

    for (int i = carData.size() - 1; i >= 0; i--) {
        // Time to reach destination
        float time =
            (float)(target - carData[i].first) / (float)carData[i].second;

        while (!st.empty() && st.top() <= time) {
            st.pop();
        }

        st.push(time);
    }

    // Number of elements remaining in stack is the number of fleets
    return st.size();
}

int main() {
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};
    int target = 12;

    cout << carFleet(target, position, speed);

    return 0;
}