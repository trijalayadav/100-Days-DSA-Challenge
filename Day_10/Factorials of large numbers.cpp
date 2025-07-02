class Solution
{
public:
    vector<int> factorial(int n)
    {
        vector<int> res;
        res.push_back(1);

        for (int i = 2; i <= n; i++)
        {
            int carry = 0;

            for (int j = 0; j < res.size(); j++)
            {
                int product = res[j] * i + carry;
                res[j] = product % 10;
                carry = product / 10;
            }

            while (carry)
            {
                res.push_back(carry % 10);
                carry /= 10;
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
