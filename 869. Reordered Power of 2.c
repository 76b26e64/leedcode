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

#include <stdbool.h>
#include <stdint.h>
#include <string.h>   // memset
#include <stdio.h>    // optional for debugging prints

#define MAX_DIGITS     10
#define MAX_PER_DIGIT  4
#define LIMIT          1000000000U

typedef struct {
    int count[10];
} num_count_t;

typedef struct {
    int used;                        // how many entries filled
    num_count_t counts[MAX_PER_DIGIT];
} power_bucket_t;

static int calc_digit(uint32_t n) {
    if (n == 0) return 1;
    int d = 0;
    while (n > 0) { d++; n /= 10; }
    return d;
}

static void count_digits(uint32_t n, num_count_t *c) {
    while (n > 0) {
        c->count[n % 10]++;
        n /= 10;
    }
}

static bool same_counts(const num_count_t *a, const num_count_t *b) {
    for (int i = 0; i < 10; i++) {
        if (a->count[i] != b->count[i]) return false;
    }
    return true;
}

// Precompute counts for powers of two up to LIMIT, grouped by digit length
static void init_powers(power_bucket_t buckets[MAX_DIGITS]) {
    memset(buckets, 0, sizeof(power_bucket_t) * MAX_DIGITS);

    uint32_t val = 1;  // 2^0
    while (val <= LIMIT) {
        int d = calc_digit(val);                 // 1..10
        power_bucket_t *pb = &buckets[d - 1];    // index 0..9

        // Safety: ensure we don't exceed MAX_PER_DIGIT (should not for LIMIT=1e9)
        if (pb->used < MAX_PER_DIGIT) {
            num_count_t *dst = &pb->counts[pb->used];
            memset(dst, 0, sizeof(*dst));
            count_digits(val, dst);
            pb->used++;
        }

        // Next power of two; guard against overflow (though loop bound stops us)
        if (val > (UINT32_MAX >> 1)) break;
        val <<= 1;
    }
}

bool reorderedPowerOf2(int n) {
    if (n <= 0) return false;

    power_bucket_t buckets[MAX_DIGITS];
    init_powers(buckets);

    num_count_t target;
    memset(&target, 0, sizeof(target));
    count_digits((uint32_t)n, &target);

    int d = calc_digit((uint32_t)n);
    if (d < 1 || d > MAX_DIGITS) return false;

    power_bucket_t *pb = &buckets[d - 1];
    for (int i = 0; i < pb->used; i++) {
        if (same_counts(&target, &pb->counts[i])) {
            return true;
        }
    }
    return false;
}
