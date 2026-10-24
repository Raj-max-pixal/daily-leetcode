class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        # Define 32-bit integer limits
        INT_MIN, INT_MAX = -2147483648, 2147483647
        
        # Handle the special overflow edge case
        if dividend == INT_MIN and divisor == -1:
            return INT_MAX
        
        # Determine the sign of the result
        negative = (dividend < 0) ^ (divisor < 0)
        
        # Work with positive absolute values
        dvd, dvs = abs(dividend), abs(divisor)
        quotient = 0
        
        # Bitwise long division
        while dvd >= dvs:
            temp_divisor, multiple = dvs, 1
            while dvd >= (temp_divisor << 1):
                temp_divisor <<= 1
                multiple <<= 1
            
            dvd -= temp_divisor
            quotient += multiple
            
        # Apply the correct sign
        if negative:
            quotient = -quotient
            
        # Clamp to 32-bit signed integer range (just in case)
        return max(INT_MIN, min(quotient, INT_MAX))