/*
11. Container With Most Water
Solved
Medium
Topics
conpanies icon
Companies
Hint
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

 

Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1
 

Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104

*/


int maxArea(int* height, int heightSize) {
    if (!height || heightSize <= 0) {
        return 0;
    }

    int left_index = 0;
    int right_index = heightSize - 1;
    int max_volume = 0;

    while(left_index < right_index){
        int width = right_index - left_index;
        int volume = fmin(height[left_index], height[right_index]) * width;
        max_volume = fmax(volume, max_volume);
        
        if(height[left_index] < height[right_index]){
            left_index++;
        }else{
            right_index--;
        }
    }

    return max_volume;
}