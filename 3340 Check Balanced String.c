bool isBalanced(char* num) {
    int s_len = strlen(num);
    int even_sum = 0;

    int index = 0;
    while (index < s_len) {
        even_sum += num[index] - '0';
        index += 2;
    }

    int odd_sum = 0;
    index = 1;
    while (index < s_len) {
        odd_sum += num[index] - '0';
        index += 2;
    }

    return even_sum == odd_sum;
}