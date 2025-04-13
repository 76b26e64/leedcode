impl Solution {
    pub fn xor_queries(arr: Vec<i32>, queries: Vec<Vec<i32>>) -> Vec<i32> {

        let mut answer : Vec<i32> = vec![];
        let mut prefix_xor : Vec<i32> = vec![];

        prefix_xor.push(0);
        for i in 0..arr.len() {
            prefix_xor.push(prefix_xor[i] ^ arr[i]);
        }

        for n in 0..queries.len() {
            let mut i : usize = queries[n][0].try_into().unwrap();
            let mut j : usize = queries[n][1].try_into().unwrap();

            answer.push(prefix_xor[j+1] ^ prefix_xor[i]);
        }

        answer
    }
}
