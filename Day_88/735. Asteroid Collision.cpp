class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> st;
        for (int num : asteroids)
        {
            bool destroyed = false;
            while (!st.empty() && st.top() > 0 && num < 0)
            {
                if (abs(st.top()) < abs(num))
                {
                    st.pop();
                    continue;
                }
                else if (abs(st.top()) == abs(num))
                {
                    st.pop();
                    destroyed = true;
                    break;
                }
                else
                {
                    destroyed = true;
                    break;
                }
            }
            if (!destroyed)
            {
                st.push(num);
            }
        }
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--)
        {
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};