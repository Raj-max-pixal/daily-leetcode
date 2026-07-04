#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Hash map to store: {number: index}
        std::unordered_map<int, int> num_map;
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            // Check if complement already exists in the map
            if (num_map.find(complement) != num_map.end()) {
                return {num_map[complement], i};
            }
            
            // Otherwise, add the current number and its index to the map
            num_map[nums[i]] = i;
        }
        
        // Return empty vector if no solution is found (per constraints, this won't happen)
        return {};
    }
};