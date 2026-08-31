// A critical point in a linked list is defined as either a local maxima or a local minima. A node is a local maxima if the current node has a value strictly greater than the previous node and the next node. A node is a local minima if the current node has a value strictly smaller than the previous node and the next node. Note that a node can only be a local maxima/minima if there exists both a previous node and a next node. Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].







#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minDistance = INT_MAX, firstMaxIndex = -1, prevMaxIndex = -1, index = 1;
        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr->next != nullptr) {
            if ((curr->val > prev->val && curr->val > curr->next->val )|| (curr->val < prev->val && curr->val < curr->next->val)) {
                if (firstMaxIndex == -1) firstMaxIndex = index;
                if (prevMaxIndex != -1) minDistance = min(minDistance, index - prevMaxIndex);
                prevMaxIndex = index;
            }
            prev = curr;
            curr = curr->next;
            ++index;
        }

        if (minDistance == INT_MAX) return {-1, -1};
        return {minDistance, prevMaxIndex - firstMaxIndex};
    }
};

int main() {
    ListNode* head = new ListNode(5);
    head->next = new ListNode(3);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next->next = new ListNode(6);

    Solution solution;
    vector<int> result = solution.nodesBetweenCriticalPoints(head);

    cout << "Minimum Distance: " << result[0] << endl;
    cout << "Maximum Distance: " << result[1] << endl;
}