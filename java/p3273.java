import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class p3273 {
static BufferedWriter bw;
    static BufferedReader br;
    static StringBuffer   sb;

    public static void main(String[] args)throws Exception {
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuffer();

        int N = Integer.parseInt(br.readLine());
        int []arr= new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0;i<N;i++){
            arr[i]= Integer.parseInt(st.nextToken());
        }
        int cmp = Integer.parseInt(br.readLine());

        Arrays.sort(arr);
        int cnt= 0;
        for(int i = 0;i<N;i++){
            int x = cmp-arr[i];
            if(x>0){
                int val = lowerbound(i,x,arr);   
                if(arr[i]+arr[val]==cmp&&i<val){
                    //System.out.println(i + " " + val);
                    cnt++;
                }
            }
        }
        System.out.println(cnt);
    }    

    private static int lowerbound(int start , int x, int[]arr){
       
        int end= arr.length-1;
        int mid = 0;

        while (start+1<end){
            mid= (start+end)/2;
            if(arr[mid]<x){
                start=mid;
            }else {
                end=mid;
            }
        }
        
        if(mid+1<arr.length && arr[mid+1]==x){
            return mid+1;
        }
        return mid;
    }
}
