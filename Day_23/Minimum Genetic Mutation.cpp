class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> geneBank(bank.begin(), bank.end());
        if (!geneBank.count(endGene))
            return -1;

        queue<pair<string, int>> q;
        q.push({startGene, 0});

        vector<char> mutations = {'A', 'C', 'G', 'T'};
        unordered_set<string> visited;

        while (!q.empty()) {
            auto [current, steps] = q.front();
            q.pop();

            if (current == endGene)
                return steps;

            for (int i = 0; i < current.size(); ++i) {
                char originalChar = current[i];
                for (char c : mutations) {
                    if (c == originalChar)
                        continue;
                    current[i] = c;
                    if (geneBank.count(current) && !visited.count(current)) {
                        visited.insert(current);
                        q.push({current, steps + 1});
                    }
                }
                current[i] = originalChar; // revert back
            }
        }

        return -1;
    }
};
