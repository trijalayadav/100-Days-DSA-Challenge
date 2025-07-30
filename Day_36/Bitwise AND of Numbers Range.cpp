class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        // int ans=1,count=0;
        // while(left!=right){
        //     left=left>>1;
        //     right=right>>1;
        //     count++;
        // }
        // ans=left;
        // while(count!=0){
        //     ans=ans<<1;
        //     count--;
        // }
        // return ans;

        int ans = right;
        while (ans > left)
        {
            ans = ans & (ans - 1);
        }
        return ans;
    }
};