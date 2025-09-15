// brute force
//  class Solution {
//  public:
//      vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
//          unordered_set<string> dict(words.begin(), words.end());
//          vector<string> ans;

//         for (string& word : words) {
//             if (isConcatenated(word, dict)) {
//                 ans.push_back(word);
//             }
//         }
//         return ans;
//     }

//     bool isConcatenated(string word, unordered_set<string>& dict) {
//         int n = word.size();
//         for (int i = 1; i < n; i++) {
//             string left = word.substr(0, i);
//             string right = word.substr(i);
//             if (dict.count(left) &&
//                 (dict.count(right) || isConcatenated(right, dict))) {
//                 return true;
//             }
//         }
//         return false;
//     }
// };

// better
//  class Solution {
//  public:
//      unordered_set<string> dict;
//      unordered_map<string, bool> memo;

//     bool canForm(string word) {
//         if (memo.count(word)) return memo[word];

//         int n = word.size();
//         for (int i = 1; i < n; i++) {
//             string left = word.substr(0, i);
//             string right = word.substr(i);
//             if (dict.count(left) && (dict.count(right) || canForm(right))) {
//                 return memo[word] = true;
//             }
//         }
//         return memo[word] = false;
//     }

//     vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
//         dict = unordered_set<string>(words.begin(), words.end());
//         vector<string> ans;
//         for (string &word : words) {
//             if (word.empty()) continue;
//             if (canForm(word)) ans.push_back(word);
//         }
//         return ans;
//     }
// };

// optimal
// class Trie {
// public:
//     bool end;
//     Trie* child[26];
//     Trie() {
//         end = false;
//         memset(child, 0, sizeof(child));
//     }
// };

// class Solution {
// public:
//     Trie* root;
//     Solution() { root = new Trie(); }

//     void insert(const string &s) {
//         Trie* node = root;
//         for (char c : s) {
//             int idx = c - 'a';
//             if (!node->child[idx]) node->child[idx] = new Trie();
//             node = node->child[idx];
//         }
//         node->end = true;
//     }

//     bool dfs(const string &w, int idx, vector<int>& memo) {
//         if (idx == w.size()) return true;
//         if (memo[idx] != -1) return memo[idx];

//         Trie* node = root;
//         for (int i = idx; i < w.size(); i++) {
//             int c = w[i] - 'a';
//             if (!node->child[c]) break;
//             node = node->child[c];
//             if (node->end) {
//                 if (dfs(w, i + 1, memo)) {
//                     memo[idx] = 1;
//                     return true;
//                 }
//             }
//         }
//         memo[idx] = 0;
//         return false;
//     }

//     vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
//         // sort by length so shorter words are available first
//         sort(words.begin(), words.end(), [](const string &a, const string &b) {
//             return a.size() < b.size();
//         });

//         vector<string> result;
//         for (auto &w : words) {
//             if (w.empty()) continue;
//             vector<int> memo(w.size(), -1);
//             if (dfs(w, 0, memo)) {
//                 result.push_back(w);
//             } else {
//                 insert(w); // insert only after check
//             }
//         }
//         return result;
//     }
// };

// optimal -dp

class Solution
{
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        unordered_set<string> dict(words.begin(), words.end());
        vector<string> result;

        for (auto &w : words)
        {
            if (w.empty())
                continue;
            dict.erase(w); // avoid using itself

            if (canForm(w, dict))
                result.push_back(w);

            dict.insert(w); // put it back
        }
        return result;
    }

    bool canForm(const string &word, unordered_set<string> &dict)
    {
        int n = word.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true; // empty prefix is valid

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (!dp[j])
                    continue;
                if (dict.count(word.substr(j, i - j)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
