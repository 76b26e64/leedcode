
impl Solution {
    pub fn max_width_ramp(nums: Vec<i32>) -> i32 {
        let mut max_width : i32 = 0;
        let mut sorted_nums = nums.clone();
        sorted_nums.sort();

        max_width
    }
}

/*
impl Solution {
    pub fn max_width_ramp(nums: Vec<i32>) -> i32 {
        let mut max_width : i32 = 0;

        for i in (0..nums.len()-1) {
            for j in (i+1..nums.len()) {
                if nums[i] <= nums[j] {
                    let width : i32 = (j-i) as i32;
                    if max_width < width {
                        max_width = width;
                    }
                }
            }
        }

        max_width
    }
}
*/