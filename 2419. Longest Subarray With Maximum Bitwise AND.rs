use std::cmp::max;
impl Solution {
    pub fn longest_subarray(nums: Vec<i32>) -> i32 {
        let mut max_value: i32= 0;
        let mut max_length: i32 = 0;
        let mut current_length: i32 = 0;

        for i in 0..nums.len() {
            if nums[i] > max_value {
                max_value = nums[i];
                current_length = 1;
                max_length = 1;
            }
            else if nums[i] == max_value {
                current_length += 1;
                max_length = max(max_length, current_length);
            }
            else {
                current_length = 0;
            }
        }
        max_length
    }
}
