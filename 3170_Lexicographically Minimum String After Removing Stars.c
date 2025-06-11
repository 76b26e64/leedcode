/*
3170. Lexicographically Minimum String After Removing Stars
Solved
Medium
Topics
conpanies icon
Companies
You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.

While there is a '*', do the following operation:

Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can delete any of them.
Return the lexicographically smallest resulting string after removing all '*' characters.

 

Example 1:

Input: s = "aaba*"

Output: "aab"

Explanation:

We should delete one of the 'a' characters with '*'. If we choose s[3], s becomes the lexicographically smallest.

Example 2:

Input: s = "abc"

Output: "abc"

Explanation:

There is no '*' in the string.

 

Constraints:

1 <= s.length <= 105
s consists only of lowercase English letters and '*'.
The input is generated such that it is possible to delete all '*' characters.
*/


typedef struct stack_s {
    int capacity;
    int size;
    int *data;
}stack_t;

stack_t *create_stack(int capacity){
    if(capacity <= 0){
        return NULL;
    }

    stack_t *stack = calloc(1, sizeof(stack_t));
    stack->capacity = capacity;
    stack->size = 0;
    stack->data = calloc(capacity, sizeof(int));
    if(!(stack->data)){
        free(stack);
        return NULL;
    }

    return stack;
}

void free_stack(stack_t *stack){
    free(stack->data);
    free(stack);
}

void push_stack(stack_t *stack, int index){
    if(stack->capacity <= stack->size){
        return;
    }
    stack->data[stack->size] = index;
    (stack->size)++;
    return;
}

int pop_stack(stack_t *stack){
    if(stack->size == 0){
        return -1;
    }

    int index = stack->data[stack->size - 1];
    (stack->size)--;
    return index;
}

bool is_enpty_stack(stack_t *stack){
    return (stack->size == 0);
}

#define CHAR_PATTERN (26)

int smallest_index(stack_t *char_indeies[CHAR_PATTERN]){
    for(int i = 0; i < CHAR_PATTERN; i++){
        if (!is_enpty_stack(char_indeies[i])){
            return pop_stack(char_indeies[i]);
        }
    }
    return -1;
}

char* clearStars(char* s) {
    if(!s){
        return s;
    }
    
    int s_len = strlen(s);
    stack_t *char_indeies[CHAR_PATTERN];
    for(int i = 0; i < CHAR_PATTERN; i++){
        char_indeies[i] = create_stack(s_len);
        if(!char_indeies[i]){
            for(int j = 0; j < i; j++){
                free_stack(char_indeies[j]);
                return NULL; 
            }
        }
    }

    int most_right_index = -1;
    for(int i = 0; i < s_len; i++){
        char c = s[i];
        if(c == '*'){
            most_right_index = smallest_index(char_indeies);
            if(most_right_index != -1){
                s[most_right_index] = '*';
            }
        }else{
            push_stack(char_indeies[c - 'a'], i);
        }
    }

    int to_index = 0; 
    int from_index = 0; 

    while(to_index < s_len){
        if(from_index >= s_len){
            s[to_index] = '\0';
            break;
        }

        if(s[from_index] == '*'){
            from_index++;
        }else{
            s[to_index++] = s[from_index++];
        }
    }

    for(int i = 0; i < CHAR_PATTERN; i++){
        free_stack(char_indeies[i]);
    }
    return s;
}