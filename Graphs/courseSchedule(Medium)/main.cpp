#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/course-schedule/

//* SOLUTION
bool dfs(int course, unordered_map<int, unordered_set<int>>& adjacencyMap,
         unordered_set<int>& visited) {
    if (visited.find(course) != visited.end()) return false;

    if (adjacencyMap[course].empty()) return true;

    visited.insert(course);
    for (auto prereq : adjacencyMap[course]) {
        if (!dfs(prereq, adjacencyMap, visited)) return false;
    }
    visited.erase(course);
    adjacencyMap[course].clear();

    return true;
}
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, unordered_set<int>> adjacencyMap;
    for (auto prereq : prerequisites) adjacencyMap[prereq[0]].insert(prereq[1]);

    unordered_set<int> visited;

    for (int course = 0; course < numCourses; course++) {
        if (!dfs(course, adjacencyMap, visited)) return false;
    }

    return true;
}

bool canFinishCycleDetectSolution(int numCourses,
                                  vector<vector<int>>& prerequisites) {
    // Create adjacency list/map
    unordered_map<int, vector<int>> adjacencyMap;
    for (auto prereq : prerequisites)
        adjacencyMap[prereq[0]].push_back(prereq[1]);

    unordered_set<int> visited;

    stack<int> st;
    st.push(0);

    while (!st.empty()) {
        int course = st.top();
        st.pop();

        if (visited.find(course) != visited.end()) return false;

        for (auto prereq : adjacencyMap[course]) st.push(prereq);

        visited.insert(course);
    }

    return true;
}

int main() {
    int numCourses = 20;
    cout << "Number of courses = " << numCourses << "\n";

    vector<vector<int>> prerequisites = {{0, 10},  {3, 18}, {5, 5},  {6, 11},
                                         {11, 14}, {13, 1}, {15, 1}, {17, 4}};
    cout << "Prerequisites = [";
    for (int i = 0; i < prerequisites.size(); i++) {
        cout << "[";
        for (int j = 0; j < prerequisites[i].size(); j++) {
            cout << prerequisites[i][j];
            if (j != prerequisites[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if (i != prerequisites.size() - 1) cout << ", ";
    }
    cout << "]\n";

    cout << (canFinishCycleDetectSolution(numCourses, prerequisites) ? "True"
                                                                     : "False");

    return 0;
}