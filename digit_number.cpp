ount the number of k's between 0 and n. k can be 0 - 9.

Example
if n=12, in [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12], we have FIVE 1's (1, 10, 11, 12)

当某一位的数字小于2时，那么该位出现2的次数为：更高位数字x当前位数
当百位c为2时，比如说12213。那么，我们还是有200~299, 1200~1299, 2200~2299, … , 11200~11299这1200个数，他们的百位为2。但同时，还有一部分12200~12213， 共14个(低位数字+1)。所以，当百位数字为2时， 百位出现2的次数既受高位影响也受低位影响，结论如下：

当某一位的数字等于2时，那么该位出现2的次数为：更高位数字x当前位数+低位数字+1
当百位c大于2时，比如说12313，那么固定低3位为200~299，高位依次可以从0到12， 这一次就把12200~12299也包含了，同时也没低位什么事情。因此出现2的次数是： (更高位数字+1)x当前位数。结论如下：

当某一位的数字大于2时，那么该位出现2的次数为：(更高位数字+1)x当前位数

class Solution {
    /*
     * param k : As description.
     * param n : As description.
     * return: An integer denote the count of digit k in 1..n
     */
    public int digitCounts(int k, int n) {
        int count = 0;
        int base = 1;
        while (n / base >= 1) {
            int curBit = n % (base*10) / base;
            int higher = n / (base*10);
            int lower = n % base;
            if (curBit < k) {
                count += higher * base;
            }
            else if (curBit == k) {
                count += higher * base + lower + 1;
            }
            else {
                count += (higher + 1) * base;
            }
            base *= 10;
        }
        return count;
    }
}
