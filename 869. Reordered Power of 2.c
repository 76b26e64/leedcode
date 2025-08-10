/*
869. Reordered Power of 2
Solved
Medium
Topics
conpanies icon
Companies
You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this so that the resulting number is a power of two.
 

Example 1:

Input: n = 1
Output: true
Example 2:

Input: n = 10
Output: false
 

Constraints:
1 <= n <= 109
*/

typedef struct num_count_s {
    int count[10];
}num_count_t;

typedef struct power_s {
    int number;
    num_count_t counts[4];
}power_t;

int calc_digit(int n){
    int digit = 0;
    for(;n > 0; n /= 10){
        digit++;
    }
    return digit;
}

void count(int n, num_count_t *c){
    for(;n > 0; n /= 10){
        (c->count[n%10])++;
    }
}

void init_powers(power_t powerof2[10]){
    int val = 1;
    for(int i = 0; i < 32; i++){
        if(val > pow(10, 9)){
            break;
        }
        //printf("%d : %d\n", i, val);
        int digit = calc_digit(val);
        //printf("i = %d : val = %d : digit = %d\n",i, val, digit);
        power_t *p = &powerof2[digit-1];
        //printf("i = %d : p->number = %d\n",i, p->number);
        count(val, &(p->counts[p->number]));
        (p->number)++;
        
        val = val << 1;
    }
} 

bool cmp(num_count_t *a, num_count_t *b){
    for(int i = 0; i < 10; i++){
        if(a->count[i] != b->count[i]){
            return false;
        }
    }
    return true;
} 

bool reorderedPowerOf2(int n) {
    if(n <= 0){
        return false;
    }

    power_t powerof2[10];
    bzero(powerof2, sizeof(powerof2));
    init_powers(powerof2);

    num_count_t nums;
    bzero(&nums, sizeof(nums));
    count(n, &nums);

    int digit = calc_digit(n);
    for(int i = 0; i < powerof2[digit-1].number; i++){
        if(cmp(&nums, &powerof2[digit-1].counts[i])){
            return true;
        }
    }

    return false;
}