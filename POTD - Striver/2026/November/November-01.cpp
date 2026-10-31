// You are given several logs, where each log contains a unique ID and timestamp. Timestamp is a string that has the following format: Year:Month:Day:Hour:Minute:Second, for example, 2017:01:01:23:59:59. All domains are zero-padded decimal numbers. Implement the LogSystem class:

//     1 - LogSystem() Initializes the LogSystem object.
//     2 - void put(int id, string timestamp) Stores the given log(id, timestamp) in your storage system.
//     3 - int[] retrieve(string start, string end, string granularity) Returns the IDs of the logs whose timestamps are within the range from start to end inclusive. start and end all have the same format as timestamp, and granularity means how precise the range should be (i.e. to the exact Day,Minute, etc.). For example, start = "2017:01:01:23:59:59", end = "2017:01:02:23:59:59", and granularity = "Day" means that we need to find the logs within the inclusive range from Jan. 1st 2017 to Jan. 2nd 2017, and the Hour, Minute, and Second for each log entry can be ignored.









#include <bits/stdc++.h>
using namespace std;

class LogSystem {
public:
    LogSystem() {
        granularityToLength["Year"] = 4;
        granularityToLength["Month"] = 7;
        granularityToLength["Day"] = 10;
        granularityToLength["Hour"] = 13;
        granularityToLength["Minute"] = 16;
        granularityToLength["Second"] = 19;
    }
    
    void put(int id, string timestamp) {
        logEntries.push_back({id, timestamp});
    }
    
    vector<int> retrieve(string start, string end, string granularity) {
        vector<int> result;
        int substringLength = granularityToLength[granularity];
        string startPrefix = start.substr(0, substringLength);
        string endPrefix = end.substr(0, substringLength);

        for (const auto& [logId, logTimestamp] : logEntries) {
            string timestampPrefix = logTimestamp.substr(0, substringLength);
            if (startPrefix <= timestampPrefix && timestampPrefix <= endPrefix) result.emplace_back(logId);
        }

        return result;
    }

private:
    vector<pair<int, string>> logEntries;
    unordered_map<string, int> granularityToLength;
};

int main() {
    LogSystem logSystem;
    logSystem.put(1, "2017:01:01:23:59:59");
    logSystem.put(2, "2017:01:02:23:59:59");
    logSystem.put(3, "2016:12:31:23:59:59");

    vector<int> result1 = logSystem.retrieve("2017:01:01:00:00:00", "2017:01:02:23:59:59", "Day");
    for (int id : result1) cout << id << " ";
    cout << endl;

    vector<int> result2 = logSystem.retrieve("2016:12:31:00:00:00", "2017:01:01:23:59:59", "Hour");
    for (int id : result2) cout << id << " ";
    cout << endl;
}