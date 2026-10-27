// Given two strings s and t, return true if t is an anagram of s, and false otherwise. An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.






#include <bits/stdc++.h>
using namespace std;

class Solution{	
	public:
		bool anagramStrings(string &s,string &t){
            // Using constant space array
            if (s.length() != t.length()) return false;

            vector<int> count(26, 0);
            for (int i = 0; i < s.length(); i++) {
                count[s[i] - 'a']++;
                count[t[i] - 'a']--;
            }

            for (int val : count) {
                if (val != 0) return false;
            }
            return true;

            // Using Hashmap
            // if (s.length() != t.length()) return false;

            // unordered_map<char, int> countS;
            // unordered_map<char, int> countT;
            // for (int i = 0; i < s.length(); i++) {
            //     countS[s[i]]++;
            //     countT[t[i]]++;
            // }
            // return countS == countT;

            // Brute-force Approach
			// if (s.length() != t.length()) return false;

            // sort(s.begin(), s.end());
            // sort(t.begin(), t.end());
            // return s == t;
		}
};

int main(){
    string s = "anagram";
    string t = "nagaram";
    Solution sol;
    if(sol.anagramStrings(s, t)) cout << s << " is an anagram of " << t << " True" << endl;
    else cout << s << " is not an anagram of " << t << "  False" << endl;
}