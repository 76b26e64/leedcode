#include <stdlib.h>
#include <string.h>

/* Portable bit count (fallback if __builtin_popcount not available) */
static int bitcount(int x) {
#ifdef __GNUC__
    return __builtin_popcount(x);
#else
    int c = 0;
    while (x) { x &= x - 1; ++c; }
    return c;
#endif
}

int maxStudents(char** seats, int seatsSize, int* seatsColSize) {
    if (seatsSize == 0) return 0;
    int rows = seatsSize;
    int cols = seatsColSize[0]; /* LeetCode instances have consistent column counts */

    int limit = 1 << cols;

    /* Precompute, per row:
       - good mask: seats available ('.')
       - list of valid masks (no adjacent seats horizontally and subset of good)
       - popcount for each valid mask
    */
    int **validMasks = (int**)malloc(rows * sizeof(int*)); // Patterns students seating
    int **vmPop = (int**)malloc(rows * sizeof(int*)); // Numbers of students in each pattern
    int *vmSize = (int*)calloc(rows, sizeof(int)); //  Pattern number of each rows

    for (int r = 0; r < rows; ++r) {
        int broken_seats = 0;
        for (int c = 0; c < cols; ++c) {
            if (seats[r][c] == '#') broken_seats |= (1 << c);
        }

        /* Upper bound on valid masks is limit; allocate conservatively, shrink later if desired */
        validMasks[r] = (int*)malloc(limit * sizeof(int));
        vmPop[r]      = (int*)malloc(limit * sizeof(int));
        vmSize[r] = 0;

        for (int m = 0; m < limit; ++m) {
            if ((m & broken_seats) != 0) continue; /* uses a broken seat */
            if ((m & (m << 1)) != 0) continue;     /* adjacent students in same row */
            validMasks[r][vmSize[r]] = m;
            vmPop[r][vmSize[r]] = bitcount(m);
            vmSize[r]++;
        }
    }

    /* DP: dp[r][mask] = max students up to row r-1 (0-based rows) with row r-1 using 'mask'
       We'll roll two rows to save memory.
    */
    int *prev = (int*)malloc(limit * sizeof(int));
    int *curr = (int*)malloc(limit * sizeof(int));
    for (int m = 0; m < limit; ++m) prev[m] = -1;
    prev[0] = 0;

    for (int r = 0; r < rows; ++r) {
        for (int m = 0; m < limit; ++m) {
            curr[m] = -1;
        }
       
        for (int i = 0; i < vmSize[r]; ++i) {
            int m = validMasks[r][i];
            int add = vmPop[r][i];
            
            /* check with previous rows mask(pm) */
            for (int pm = 0; pm < limit; ++pm) {
                if (prev[pm] < 0) continue;  /* Cannot realize */
                /* No cheating with upper-left / upper-right:
                   current m cannot conflict with pm shifted left or right
                */
                if ((m & (pm << 1)) != 0) continue;
                if ((m & (pm >> 1)) != 0) continue;
                
                
                if (prev[pm] + add > curr[m]) curr[m] = prev[pm] + add;
            }
        }
        /* also allow placing nobody on this row if that’s optimal */
        if (prev[0] > curr[0]) curr[0] = prev[0];

        /* swap */
        int *tmp = prev; prev = curr; curr = tmp;
    }

    int ans = 0;
    for (int m = 0; m < limit; ++m) if (prev[m] > ans) ans = prev[m];

    /* cleanup */
    free(curr);
    free(prev);
    for (int r = 0; r < rows; ++r) {
        free(validMasks[r]);
        free(vmPop[r]);
    }
    free(vmSize);
    free(vmPop);
    free(validMasks);

    return ans;
}
