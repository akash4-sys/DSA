#include "../../headers.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        if(nums.size() == 1) return (nums[0] == target)? 0 : -1;
        
        int st = 0;
        int end = nums.size()-1;
        while(st <= end){
            int mid = (end + st)/2;

            if(nums[mid] == target) return mid;
            if(st == end) break;
            if(st == mid) { 
                st++; 
                continue; 
            }

            if(nums[st] <= nums[mid]){
                if(nums[st] <= target && target <= nums[mid]) end = mid;
                else st = mid;
            }
            else{
                if(target < nums[st] && nums[mid] < target) st = mid;
                else end = mid;
            }
        }
        return -1;
    }
};