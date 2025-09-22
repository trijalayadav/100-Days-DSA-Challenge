class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        // brute
        // long long n = 0;
        // for (int d : num) {
        //     n = n * 10 + d; // overflows for a large number
        // }
        // n += k;
        // string s = to_string(n);
        // vector<int> ans;
        // for (char c : s)
        //     ans.push_back(c - '0');
        // return ans;

        // better
        // vector<int> res;
        // int i = num.size() - 1, carry = 0;

        // while (i >= 0 || k > 0) {
        //     int digit = (i >= 0 ? num[i] : 0);
        //     int sum = digit + carry + k % 10;

        //     res.push_back(sum % 10);
        //     carry = sum / 10;

        //     k = k / 10;
        //     i--;
        // }
        // if (carry)
        //     res.push_back(carry);
        // reverse(res.begin(), res.end());
        // return res;

        // optimal
        int i = num.size() - 1;
        while (i >= 0 || k > 0)
        {
            if (i >= 0)
            {
                k += num[i];
                num[i] = k % 10;
                i--;
            }
            else
            {
                num.insert(num.begin(), k % 10);
            }
            k /= 10;
        }
        return num;
    }
};