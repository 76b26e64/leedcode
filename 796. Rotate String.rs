impl Solution {
    pub fn rotate_string(s: String, goal: String) -> bool {
        let s_len = s.len();

        for i in 0..s_len {
            let tmp = format!("{}{}", &s[i..], &s[..i]);
            if tmp == goal {
                return true;
            }
        }
        return false;
    }
}