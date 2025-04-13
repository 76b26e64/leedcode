int climbStairs(int n) {
    if(n <= 0){
        return 0;
    }
    if(n==1){
        return 1;
    }else if(n == 2){
        return 2;
    }

    int prev_1 = 2;
    int prev_2 = 1;
    int ret;
    for(int i=3; i<=n; i++){
        ret = prev_1 + prev_2;
        prev_2 = prev_1;
        prev_1 = ret;
    }

    return ret;
}