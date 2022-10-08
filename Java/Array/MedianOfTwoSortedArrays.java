public double FindMedianSortedArrays(int[] A, int[] B) 
{
    // TODO: Check for corner cases

    int aLen = A.Length;
    int bLen = B.Length;
    int leftHalfLen = GetLeftHalfLength(aLen + bLen);

    // aMinCount and aMaxCount are the min and max number
    // of values A can contribute to the left half of A ∪ B,
    // respectively.
    (int aMinCount, int aMaxCount) = GetMinMaxCounts(aLen, bLen);

    while (aMinCount <= aMaxCount)
    {
        // aCount is the number of values A will contribute to left half of A ∪ B
        int aCount = (aMinCount + aMaxCount) / 2;
        
        // bCount is the number of values B will contribute to left half of A ∪ B.
        // B will contribute as many values as necessary to fill however many remaining
        // slots in the left half.
        int bCount = leftHalfLen - aCount;

        int x = A[aCount - 1];      // Last value contributed by A to left half of A ∪ B
        int y = B[bCount - 1];      // Last value contributed by B to left half of A ∪ B
        int xP = A[aCount];         // x' (value right after x)
        int yP = B[bCount];         // y' (value right after y)

        if (x > yP)
        {
            // Decrease A's contribution size; x lies in the right half of A ∪ B.
            aMaxCount = aCount - 1;
        }
        else if (y > xP)
        {
            // Decrease B's contribution size, i.e. increase A's contribution size; 
            // y lies in the right half of A ∪ B.
            aMinCount = aCount + 1;
        }
        else
        {
            //
            // Neither x nor y lie beyond the left half of A ∪ B. This implies we 
            // found the right aCount. We don't know how x and y compare to each 
            // other yet though.
            //

            //
            // If x > y then x is the median because x <= yP (see line 21) ⟹ y < x ≤ yP
            //
            if (x > y)
            {
                return x;
            }

            //
            // If y > x then y is the median because y <= xP (see line 26) ⟹ x < y ≤ xP
            //
            if (y > x) 
            {
                return y;
            }

            // x and y are equal. We can return either.
            return x;
        }
    }

    // TODO: Report invalid input
    return -1;
}