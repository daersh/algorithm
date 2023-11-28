package programmers.java;
import java.util.*;
import java.lang.*;

class Solution {
    public int solution(int[] nums) {
        int answer = -1;

        Arrays.sort(nums);
        
        int max = nums[nums.length-1]+nums[nums.length-2]+nums[nums.length-3];
        
        //제곱근
        int n = (int)Math.sqrt(max);
        
        int []arr= new int[max+1];
        
        for(int i=0;i<arr.length;i++){
            arr[i]=i;
        }
        
        for(int i=2; i<=n;i++){
            if(arr[i]!=0){
                for(int j=i;j<=max;j+=i){
                    arr[j]=0;
                }
            }
        }
        
        int cnt=0;
        
        for(int i=0;i<nums.length-1;i++){
            for(int j=i+1;j<nums.length;j++){
                
                if(arr[ nums[i]+nums[j] ]!=0){
                    cnt++;
                }
            }
        }
    
        return cnt;
    }
}
public class p1 {
    
}

