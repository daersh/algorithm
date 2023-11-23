import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class p27651 {
    static BufferedReader br;
    static BufferedWriter bw;
    static StringBuffer sb;

    public static void main(String[] args)throws Exception{
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        sb = new StringBuffer();


        int n = Integer.parseInt(br.readLine());
        long []arr= new long[n+1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=1;i<=n;i++){
            arr[i]= Integer.parseInt(st.nextToken());
            arr[i]+=arr[i-1];
        }

        int start= 1;
        int end= 2;
        int cnt=0;
        long head = arr[start];
        long chest = arr[end]-arr[start];
        long stomach = arr[n]-arr[end];
        while(start<n){
            if(chest>stomach && stomach > head){
                cnt+=n-end;
                start++;
                end=start+1;
                head = arr[start];
                chest = arr[end]-arr[start];
                stomach = arr[n]-arr[end];
            }else if(chest<=stomach){
                end++;
                chest = arr[end]-arr[start];
                stomach = arr[n]-arr[end];
                if(end==n){
                    break;
                }
            }else{
                start++;
                end=start+1;
            }
        }

        System.out.println(cnt);   
    }

    void lowerbound(int[]arr, int end){

    }
}
