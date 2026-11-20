// Given an array of non-negative integers, height representing the elevation of ground. Calculate the amount of water that can be trapped after rain.






#include <bits/stdc++.h>    
using namespace std;

class Solution {
public:
    int trap(vector<int> &height){
        int left = 0;
        int right = height.size() - 1;
        
        int leftMax = 0;
        int rightMax = 0;
        int waterTrapped = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax) leftMax = height[left];
                else waterTrapped += leftMax - height[left];
                left++;
            } else {
                if (height[right] >= rightMax) rightMax = height[right];
                else waterTrapped += rightMax - height[right];
                right--;
            }
        }

        return waterTrapped;
    }
};

int main() {
    Solution solution;
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int result = solution.trap(height);
    cout << "Amount of water trapped: " << result << endl;
}