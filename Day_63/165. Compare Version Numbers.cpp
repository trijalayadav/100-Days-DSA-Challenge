class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        // brute force approach
        //  Split the strings by '.'
        // vector<int> v1, v2;
        // stringstream ss1(version1), ss2(version2);
        // string token;

        // while (getline(ss1, token, '.')) {
        //     v1.push_back(stoi(token)); // converts string to interger
        // }
        // while (getline(ss2, token, '.')) {
        //     v2.push_back(stoi(token));
        // }

        // int n = max(v1.size(), v2.size());
        // for (int i = 0; i < n; i++) {
        //     int num1 = (i < v1.size()) ? v1[i] : 0;
        //     int num2 = (i < v2.size()) ? v2[i] : 0;
        //     if (num1 < num2)
        //         return -1;
        //     if (num1 > num2)
        //         return 1;
        // }
        // return 0;

        // better- manually parse strings
        // vector<int> v1, v2;

        // // Parse version1 manually
        // int num = 0;
        // for (int i = 0; i <= version1.size(); i++) {
        //     if (i == version1.size() || version1[i] == '.') {
        //         v1.push_back(num);
        //         num = 0;
        //     } else {
        //         num = num * 10 + (version1[i] - '0');
        //     }
        // }

        // // Parse version2 manually
        // num = 0;
        // for (int i = 0; i <= version2.size(); i++) {
        //     if (i == version2.size() || version2[i] == '.') {
        //         v2.push_back(num);
        //         num = 0;
        //     } else {
        //         num = num * 10 + (version2[i] - '0');
        //     }
        // }

        // int n = max(v1.size(), v2.size());
        // for (int i = 0; i < n; i++) {
        //     int num1 = (i < v1.size()) ? v1[i] : 0;
        //     int num2 = (i < v2.size()) ? v2[i] : 0;
        //     if (num1 < num2)
        //         return -1;
        //     if (num1 > num2)
        //         return 1;
        // }
        // return 0;

        // optimal approach
        int i = 0, j = 0;
        int n = version1.size(), m = version2.size();

        while (i < n || j < m)
        {
            long num1 = 0, num2 = 0;

            // Parse number from version1
            while (i < n && version1[i] != '.')
            {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }
            // Parse number from version2
            while (j < m && version2[j] != '.')
            {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }

            if (num1 < num2)
                return -1;
            if (num1 > num2)
                return 1;

            // skip the '.'
            i++;
            j++;
        }
        return 0;
    }
};
