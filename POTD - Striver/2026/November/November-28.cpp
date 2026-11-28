// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1 return the area of the largest rectangle in the histogram.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        stack<int> st;
        int maxArea = 0;
        heights.push_back(0);

        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int height = heights[st.top()];
                st.pop();
                int width;
                if (st.empty()) width = i;
                else width = i - st.top() - 1;
                int area = height * width;
                maxArea = max(maxArea, area);
            }

            st.push(i);
        }

        return maxArea;
    }
};

int main() {
    Solution solution;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int result = solution.largestRectangleArea(heights);
    cout << "The area of the largest rectangle in the histogram is: " << result << endl;
}