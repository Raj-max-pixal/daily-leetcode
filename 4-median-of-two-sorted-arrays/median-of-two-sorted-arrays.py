class Solution:
    def findMedianSortedArrays(self, nums1: list[int], nums2: list[int]) -> float:
        # Step 1: Ensure nums1 is always the smaller array
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
            
        x, y = len(nums1), len(nums2)
        low, high = 0, x
        
        while low <= high:
            # Step 3: Calculate partitions
            partitionX = (low + high) // 2
            partitionY = (x + y + 1) // 2 - partitionX
            
            # Step 4: Extract edge values, using infinity for out-of-bounds
            maxLeftX = float('-inf') if partitionX == 0 else nums1[partitionX - 1]
            minRightX = float('inf') if partitionX == x else nums1[partitionX]
            
            maxLeftY = float('-inf') if partitionY == 0 else nums2[partitionY - 1]
            minRightY = float('inf') if partitionY == y else nums2[partitionY]
            
            # Step 5 & 6: Verify and adjust
            if maxLeftX <= minRightY and maxLeftY <= minRightX:
                # We have partitioned correctly
                if (x + y) % 2 == 0:
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0
                else:
                    return float(max(maxLeftX, maxLeftY))
            elif maxLeftX > minRightY:
                # Partition is too far right, move left
                high = partitionX - 1
            else:
                # Partition is too far left, move right
                low = partitionX + 1
                
        raise ValueError("Input arrays are invalid.")