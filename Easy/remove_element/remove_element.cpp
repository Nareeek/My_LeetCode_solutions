class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int k = len;
        int end = len - 1;
        
        for (int i = 0; i < len; ++i)
            if (nums[i] == val)
            {
                nums[i] = -1;
                k--;
            }
        
        for (int current = 0; current < len; ++current)
            if (nums[current] == -1)
            {
                while (nums[end] == -1)
                {
                    if (current == end)
                        return k;
                    end--;
                }
                
                nums[current] = nums[end];
                nums[end] = -1;
            }
        return k;
    }
};
