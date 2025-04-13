public class Solution {
    private static final int NUM_DIGITS = 10;

    public void countingSort(int[] arr, int placeVal) {
        // Sorts an array of integers where minimum value is 0 and maximum value is NUM_DIGITS
        int[] counts = new int[NUM_DIGITS];

        for (int elem : arr) {
            int current = elem / placeVal;
            counts[current % NUM_DIGITS] += 1
        }

        // we now overwrite our original counts with the starting index
        // of each digit in our group of digits
        int startingIndex = 0;
        for (int i = 0; i < counts.length; i++) {
            int count = counts[i];
            counts[i] = startingIndex;
            startingIndex += count;
        }

        int[] sortedArray = new int[arr.length];
        for (int elem : arr) {
            int current = elem / placeVal;
            sortedArray[counts[current % NUM_DIGITS]] = elem;
            // since we have placed an item in index counts[current % NUM_DIGITS],
            // we need to increment counts[current % NUM_DIGITS] index by 1 so the
            // next duplicate digit is placed in appropriate index
            counts[current % NUM_DIGITS] += 1;
        }

        // common practice to copy over sorted list into original arr
        // it's fine to just return the sortedArray at this point as well
        for (int i = 0; i < arr.length; i++) {
            arr[i] = sortedArray[i];
        }
    }

    public void radixSort(int[] arr) {
        int maxElem = Integer.MIN_VALUE;
        for (int elem : arr) {
            if (elem > maxElem) {
                maxElem = elem;
            }
        }

        int placeVal = 1;
        while (maxElem / placeVal > 0) {
            countingSort(arr, placeVal);
            placeVal *= 10;
        }
    }
}