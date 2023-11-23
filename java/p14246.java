/*
 * 투포인터 기본 문제
 */

import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

class p14246{
    static StringBuffer sb;
    static BufferedReader br;
    static BufferedWriter bw;

    public static void main(String[] args)throws Exception {
        sb = new StringBuffer();
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());

        for(int i=0;i<n;i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        long cmp = Integer.parseInt(br.readLine());
        long cnt = 0;
        int start= 0;
        int end = 0;
        long temp = arr[0];

        while(start< n || end <n){
            if(temp<=cmp){
                end++;
                if(end==n){
                    break;
                }
                temp+=arr[end];
            }else {
                cnt += n-end;
                temp-= arr[start];
                start++;
                if(start ==n)break;
            }
        }
        System.out.println(cnt);
    }
}