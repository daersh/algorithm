import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class p2295 {
    static BufferedReader br;
    static BufferedWriter bw;
    static StringBuffer sb;


    public static void main(String[] args)throws Exception{
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        sb = new StringBuffer();

        int n = Integer.parseInt(br.readLine());
        long []arr=new long[n];
        for(int i=0;i<n;i++){
            arr[i]= Integer.parseInt(br.readLine());
        }
        Arrays.sort(arr);

        int start=0;
        
        int end= n-1;
        long temp = arr[start]+arr[end];
        long max= 0;
        while(start<n){

            long x= arr[end]-arr[start];
            int loc=lowerbound(arr, x);

        }

    }

    public static int lowerbound(long []arr, long val){

        int l = 0;
        int r = arr.length;

        while (l+1<r) {
            int mid = (l+r)/2;
            if(arr[mid]<val){
                l=mid;
            }else{
                r=mid;
            }
        }

        if(arr[l]==val) return l;
        else if(arr[r]==val) return r;
        else return -1;
    }

}
