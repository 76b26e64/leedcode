void reverse_str(char *s){

    int s_len = strlen(s);

    for(int i=0; i<s_len; i++){
        char tmp = s[i];
        s[i] = s[s_len-1-i];
        s[s_len-1-i] = tmp;
    }
}

bool is_palindrome(char *s){
    int s_len = strlen(s);

    int left=0;
    int right=s_len-1;

    while(left < right){
        if(s[left] != s[right]){
            return false;
        }
        left++;
        right--;
    }
    return false;
}

int longestPalindrome(char* s, char* t) {

    int s_len = strlen(s);
    int t_len = strlen(t);

    char s_r[s_len+1];
    char t_r[t_len+1];

    memcpy(s_r, s, s_len);
    memcpy(t_r, t, t_len);

    reverse_str(s_r);
    reverse_str(t_r);

    int longest = 0;
    for(int i=0; i<s_len; i++){
        for(int j=0; j<t_len; j++){
            if(s[i] == t_r[j]){
                int l=1;
                for(int k=1; i+k<s_len && j+k<t_len; k++){
                    if(s[i+k] != t_r[j+k]){
                        break;
                    }
                    l++;
                }
                if(longest < l){
                    longest = l;
                }
            }
        }
    }


    return longest;
}