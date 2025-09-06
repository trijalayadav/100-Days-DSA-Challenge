class Solution
{
public:
    vector<string> result;

    void backtrack(string &s, int start, int part, string current)
    {
        if (part == 4 && start == s.size())
        {
            current.pop_back();
            result.push_back(current);
            return;
        }

        if (part == 4 || start == s.size())
            return;

        for (int len = 1; len <= 3 && start + len <= s.size(); len++)
        {
            string segment = s.substr(start, len);
            if ((segment.size() > 1 && segment[0] == '0') || stoi(segment) > 255)
                continue;

            backtrack(s, start + len, part + 1, current + segment + ".");
        }
    }

    vector<string> restoreIpAddresses(string s)
    {
        result.clear();
        backtrack(s, 0, 0, "");
        return result;
    }
};
