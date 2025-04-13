int lengthOfLongestSubstring(char* s) {

    if (s == NULL){
        return 0;
    }

    int s_len = 0;
    char c = s[s_len];
    for(s_len = 0; c != 0; s_len++){
        c = s[s_len];
    }
    if(s_len == 0){
        return 0;
    }


    int max_len = 0;
    int current_len = 0;
    int counter[128];
    memset(counter, 0, sizeof(counter));
    for(int i = 0; i < s_len; i++){
        if(s_len-i <= max_len){
            break;
        }
        for(int j = i; j < s_len; j++){
            c = s[j];
            if(counter[c] != 0){
                if (max_len < current_len) {
                    max_len = current_len;
                }
                current_len = 0;
                memset(counter, 0, sizeof(counter));
            }
            counter[c]++;
            current_len++;
        }
        if (max_len < current_len) {
            max_len = current_len;
        }
    }

    return max_len;
}
