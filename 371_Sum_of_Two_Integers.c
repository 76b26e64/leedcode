/*
Given two integers a and b, return the sum of the two integers without using the operators + and -.

 

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = 2, b = 3
Output: 5
 

Constraints:

-1000 <= a, b <= 1000
*/

int getSum(int a, int b) {

    unsigned int ans = 0;
    int carry = 0;
    int digit = 1;
    while(a != 0 || b != 0){
        if(carry){
            ans = ((unsigned int)!((a & 1) ^ (b & 1)) << (digit-1)) | ans;
            carry = ((a & 1) | (b & 1));
        }else{
            ans = ((unsigned int)((a & 1) ^ (b & 1)) << (digit-1)) | ans;
            carry = ((a & 1) & (b & 1));
        }
        a = (int)((unsigned int)a >> 1);
        b = (int)((unsigned int)b >> 1);
        digit++;
        //printf("digit=%d a=%d b=%d\n", digit,a,b);
    }

    if(carry && digit <= 32){
        ans = (1 << (digit-1)) | ans;
    }

    return (int)ans;
    
}