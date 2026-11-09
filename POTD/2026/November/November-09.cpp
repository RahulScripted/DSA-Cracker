// You have k servers numbered from 0 to k-1 that are being used to handle multiple requests simultaneously. Each server has infinite computational capacity but cannot handle more than one request at a time. The requests are assigned to servers according to a specific algorithm:

//     1 - The ith (0-indexed) request arrives.
//     2 - If all servers are busy, the request is dropped (not handled at all).
//     3 - If the (i % k)th server is available, assign the request to that server.
//     4 - Otherwise, assign the request to the next available server (wrapping around the list of servers and starting from 0 if necessary). For example, if the ith server is busy, try to assign the request to the (i+1)th server, then the (i+2)th server, and so on.
//     5 - You are given a strictly increasing array arrival of positive integers, where arrival[i] represents the arrival time of the ith request, and another array load, where load[i] represents the load of the ith request (the time it takes to complete). Your goal is to find the busiest server(s). 
    
// A server is considered busiest if it handled the most number of requests successfully among all the servers. Return a list containing the IDs (0-indexed) of the busiest server(s). You may return the IDs in any order.








#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> count(k, 0);
        set<int> available;
        for (int i = 0; i < k; ++i) available.insert(i);
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;
        for (int i = 0; i < arrival.size(); ++i) {
            long long curr_time = arrival[i];
            while (!busy.empty() && busy.top().first <= curr_time) {
                available.insert(busy.top().second);
                busy.pop();
            }
            
            if (available.empty()) continue;
            int preferred = i % k;
            auto it = available.lower_bound(preferred);
            if (it == available.end()) it = available.begin();
            
            int assigned_server = *it;
            count[assigned_server]++;
            busy.push({curr_time + load[i], assigned_server});
            available.erase(it);
        }
        
        int max_requests = *max_element(count.begin(), count.end());
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (count[i] == max_requests) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    int k = 3;
    vector<int> arrival = {1, 2, 3, 4, 5};
    vector<int> load = {5, 2, 3, 3, 3};
    
    vector<int> busiest_servers = solution.busiestServers(k, arrival, load);
    
    cout << "Busiest servers: ";
    for (int server : busiest_servers) cout << server << " ";
}