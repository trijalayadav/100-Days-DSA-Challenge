// class Solution {
// public:
//     string removeKdigits(string num, int k) {
//         string st;
//         for (char ch : num) {
//             while (!st.empty() && k > 0 && st.back() > ch) {
//                 st.pop_back();
//                 k--;
//             }
//             st.push_back(ch);
//         }
//         while (k > 0 && !st.empty()) {
//             st.pop_back();
//             k--;
//         }
//         int i = 0;
//         while (i < st.size() && st[i] == '0')
//             i++;
//         string res = st.substr(i);

//         return res.empty() ? "0" : res;
//     }
// };

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        stack<char> st;
        for (int i = 0; i < num.size(); i++)
        {
            while (!st.empty() && k > 0 && (st.top() - '0') > (num[i] - '0'))
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while (k > 0)
        {
            st.pop();
            k--;
        }
        if (st.empty())
            return "0";

        string res = "";
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }
        while (res.size() != 0 && res.back() == '0')
        {
            res.pop_back();
        }

        if (res.size() == 0)
        {
            return "0";
        }

        reverse(res.begin(), res.end());

        return res;
    }
};