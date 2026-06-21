class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> result(nums.size());
        for(int i = 0; i < nums.size(); i++){
            int offset = 0;
            if(nums[i] > 0){
                offset = i + nums[i];
                while(offset >= nums.size()){
                    offset -= nums.size();
                }
                result[i] = nums[offset];
            }else if(nums[i] < 0){
                offset = i + nums[i];
                while(offset < 0){
                    offset += nums.size();
                }
                result[i] = nums[offset];
            }else{
                result[i] = nums[i];
            }
        } 
        return result;
    }
};

