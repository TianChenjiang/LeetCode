package Array;

/**
 * Given a sorted array and a target value, return the index if the target is found.
 * If not, return the index where it would be if it were inserted in order.
 *
 * You may assume no duplicates in the array.
 *
 * Example 1:
 *
 * Input: [1,3,5,6], 5
 * Output: 2
 * Example 2:
 *
 * Input: [1,3,5,6], 2
 * Output: 1
 * Example 3:
 *
 * Input: [1,3,5,6], 7
 * Output: 4
 * Example 4:
 *
 * Input: [1,3,5,6], 0
 * Output: 0
 */
public class SearchInsert {
    public int searchInsert(int[] nums, int target) {
        if(nums.length == 1) return target <= nums[0]? 0:1;
        if(target > nums[nums.length-1]) return nums.length;
        for (int i = 0; i < nums.length; i++) {
            if (target == nums[i]) return i;
            if (target < nums[i]) return i;
        }
        return 0;
    }
    public static void main(String[] args) {
        int[] array = {1,3,5,6};
        System.out.println(new SearchInsert().searchInsert(array,2));
    }
}
