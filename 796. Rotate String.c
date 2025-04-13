bool rotateString(char* s, char* goal) {

    size_t len = strlen(s);
    for (int i = 0; i < len; i++){
        if (strncmp(s+i, goal, len-i) == 0 && strncmp(s, goal+len-i, i) == 0){
            return true;
        }
    }

    return false;
    
}