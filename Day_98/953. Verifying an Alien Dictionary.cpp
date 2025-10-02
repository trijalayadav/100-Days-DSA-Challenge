class Solution
{
public:
    bool compare(string &w1, string &w2, vector<int> &pos)
    {
        int n = min(w1.size(), w2.size());
        for (int i = 0; i < n; i++)
        {
            if (w1[i] != w2[i])
            {
                return pos[w1[i] - 'a'] < pos[w2[i] - 'a'];
            }
        }
        return w1.size() <= w2.size();
    }
    bool isAlienSorted(vector<string> &words, string order)
    {
        vector<int> pos(26, 0);
        for (int i = 0; i < order.size(); i++)
        {
            pos[order[i] - 'a'] = i;
        }
        for (int i = 0; i < words.size() - 1; i++)
        {
            if (!compare(words[i], words[i + 1], pos))
                return false;
        }
        return true;
    }
};