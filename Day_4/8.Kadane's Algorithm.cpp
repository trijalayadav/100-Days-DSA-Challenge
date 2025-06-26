class Solution
{
public:
    void segregateElements(vector<int> &arr)
    {
        // Your code goes here
        int n = arr.size();
        vector<int> pos;
        vector<int> neg;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < 0)
            {
                neg.push_back(arr[i]);
            }
            else
            {
                pos.push_back(arr[i]);
            }
        }
        int i = 0;
        while (i < pos.size())
        {
            arr[i] = pos[i++];
        }
        int j = 0;
        while (j < neg.size())
        {
            arr[i++] = neg[j++];
        }

        // int i = 0;
        // for (int x : pos)
        //     arr[i++] = x;
        // for (int x : neg)
        //     arr[i++] = x;
    }
};