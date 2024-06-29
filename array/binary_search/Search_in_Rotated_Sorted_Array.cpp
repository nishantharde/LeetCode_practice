#include <iostream>
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int L = 0, R = nums.size() - 1;
        int mid = (L + R) / 2;

        while (L <= R) {
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] >= nums[L]) {
                if (nums[L] <= target && target <= nums[mid]) {
                    R = mid - 1;
                } else {
                    L = mid + 1;
                }
            } else {
                if (nums[mid] <= target && target <= nums[R]) {
                    L = mid + 1;
                } else {
                    R = mid - 1;
                }
            }
            mid = (L + R) / 2;
        }
        return -1;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2}; // Example rotated sorted array
    int target = 0; // Element to search for

    int result = solution.search(nums, target);
    if (result != -1) {
        std::cout << "Element found at index: " << result << "\n";
    } else {
        std::cout << "Element not found in the array.\n";
    }

    return 0;
}
