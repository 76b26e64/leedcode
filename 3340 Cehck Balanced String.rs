impl Solution {
    pub fn is_balanced(num: String) -> bool {

        let s_len = num.len();
        let mut even_sum = 0;
        let mut index = 0;
        while index < s_len {
            even_sum += num.chars().nth(index).unwrap() as i32 - 0x30;
            index += 2;
        }
        
        let mut odd_sum = 0;
        index = 1;
        while index < s_len {
            odd_sum += num.chars().nth(index).unwrap() as i32 - 0x30;
            index += 2;
        }

        return even_sum == odd_sum;

    }
}