class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        // if ((word[0] - 'a') >= 0 && (word[0] - 'a') < 26) {
        //     for (int i = 1; i < word.length(); i++) {
        //         char ch = word[i];
        //         if ((ch - 'a') >= 0 && (ch - 'a') < 26) {
        //             continue;
        //         } else {
        //             return false;
        //         }
        //     }
        // } else {
        //     if ((word[1] - 'a') >= 0 && (word[1] - 'a') < 26) {
        //         for (int i = 2; i < word.length(); i++) {
        //             char ch = word[i];
        //             if ((ch - 'a') >= 0 && (ch - 'a') < 26) {
        //                 continue;
        //             } else {
        //                 return false;
        //             }
        //         }
        //     } else {
        //         for (int i = 2; i < word.length(); i++) {
        //             char ch = word[i];
        //             if ((ch - 'A') >= 0 && (ch - 'A') < 26) {
        //                 continue;
        //             } else {
        //                 return false;
        //             }
        //         }
        //     }
        // }
        // return true;

        int upper = 0, lower = 0;
        for (char ch : word)
        {
            if (isupper(ch))
            {
                upper++;
            }
            else
            {
                lower++;
            }
        }
        if (lower == word.length())
            return true;
        if (upper == word.length())
            return true;
        if (isupper(word[0]) && lower == (word.length() - 1))
            return true;

        return false;
    }
};