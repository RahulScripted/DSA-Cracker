// You are given two 0-indexed integer arrays servers and tasks of lengths n​​​​​​ and m​​​​​​ respectively. servers[i] is the weight of the i​​​​​​th​​​​ server, and tasks[j] is the time needed to process the j​​​​​​th​​​​ task in seconds. Tasks are assigned to the servers using a task queue. Initially, all servers are free, and the queue is empty. At second j, the jth task is inserted into the queue (starting with the 0th task being inserted at second 0). As long as there are free servers and the queue is not empty, the task in the front of the queue will be assigned to a free server with the smallest weight, and in case of a tie, it is assigned to a free server with the smallest index. If there are no free servers and the queue is not empty, we wait until a server becomes free and immediately assign the next task. If multiple servers become free at the same time, then multiple tasks from the queue will be assigned in order of insertion following the weight and index priorities above. A server that is assigned task j at second t will be free again at second t + tasks[j]. Build an array ans​​​​ of length m, where ans[j] is the index of the server the j​​​​​​th task will be assigned to. Return the array ans​​​​.






#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct Server {
        long long at;
        int weight, index;
        auto operator<=>(const Server&) const = default;
    };
    using MinHeap = priority_queue<Server, vector<Server>, greater<>>;

public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        vector<Server> all;
        for (int i = 0; i < ssize(servers); ++i) all.push_back({0, servers[i], i});
        MinHeap free(greater<>{}, std::move(all));

        MinHeap busy;
        vector<int> ans;
        for (int s = 0; s < ssize(tasks); ++s) {
            while (!busy.empty() && busy.top().at <= s) {  // done by second s
                auto [at, weight, index] = busy.top();
                busy.pop();
                free.push({0, weight, index});
            }
            MinHeap& from = free.empty() ? busy : free;  // none free: the first to finish takes it
            auto [at, weight, index] = from.top();
            from.pop();
            busy.push({max<long long>(at, s) + tasks[s], weight, index});
            ans.push_back(index);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> servers = {3, 3, 2};
    vector<int> tasks = {1, 2, 3, 2, 1, 2};
    vector<int> ans = sol.assignTasks(servers, tasks);
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}