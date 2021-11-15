class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target <= nums[0])
            return 0;
        else if (target > nums[nums.size() - 1])
            return (nums.size());
  
        int left = 0;
        int right = nums.size() - 1;
        int middle;
        
        while (left <= right)
        {
            middle = left + (right - left) / 2;
            
            if (target == nums[middle])
                return middle;

            else if (target > nums[middle])
            {
                left = middle + 1;
                middle = left;
            }
          
            else if (target < nums[middle])
                right = middle - 1;
        }   
        return middle;
    }
};
