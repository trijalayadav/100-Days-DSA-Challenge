// brute force
//  class Solution {
//  public:
//      int countFreq(string& s, char ch) {
//          int count = 0;
//          for (char c : s) {
//              if (c == ch) {
//                  count++;
//              }
//          }
//          return count;
//      }
//      string frequencySort(string s) {
//          int n = s.length();
//          vector<pair<int, char>> vp;
//          for (int i = 0; i < n; i++) {
//              vp.push_back({countFreq(s, s[i]), s[i]});
//          }
//          sort(vp.begin(), vp.end(),
//               [](auto& a, auto& b) { return a.first > b.first; });

//         string ans = "";
//         for (int i = 0; i < vp.size(); i++) {
//             ans += vp[i].second;
//         }
//         return ans;
//     }
// };

// better
// class Solution {
// public:
//     string frequencySort(string s) {
//         int n = s.length();
//         vector<int> freq(128, 0);
//         for (char ch : s) {
//             freq[ch]++;
//         }

//         vector<pair<int, char>> vp;
//         for (int i = 0; i < 128; i++) {
//             if (freq[i] > 0) {
//                 vp.push_back({freq[i], (char)i});
//             }
//         }
//         sort(vp.begin(), vp.end(),
//              [](auto& a, auto& b) { return a.first > b.first; });

//         string ans = "";
//         for (auto& p : vp) {
//             ans.append(p.first, p.second);
//         }
//         return ans;
//     }
// };

// optimal
class Solution
{
public:
    string frequencySort(string s)
    {
        int n = s.length();
        vector<int> freq(128, 0);
        for (char ch : s)
        {
            freq[ch]++;
        }

        vector<vector<char>> bucket(n + 1);
        for (int i = 0; i < 128; i++)
        {
            if (freq[i] > 0)
            {
                bucket[freq[i]].push_back((char)i);
            }
        }
        string ans = "";
        for (int f = n; f >= 1; f--)
        {
            for (char ch : bucket[f])
            {
                ans.append(f, ch);
            }
        }
        return ans;
    }
};