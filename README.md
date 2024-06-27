# Compresie

 - Method: Greedy
 - Complexity:
   - Time: O(n + m)
      - Explanation: The while loop stops when either vector has been fully traversed. So it could be either n or m.
   - Space: O(1)
      - Explanation: We do not use any vectors except the ones we used to read the data.
 - We start with 2 sums, one for each number sequence and each represent the first number of that sequence.
 - We iterate through the rest of the numbers.
    - If the sums are equal, we increment the counter(k) and move to the next numbers in sequence.
    - Else we add the next number to the smaller sum.
 - If the counter hasn't incremented or either sequence hasn't been fully traversed, a solution has not been found.
 - Used Dynamic Programming.
