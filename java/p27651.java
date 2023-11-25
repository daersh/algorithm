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
        for(int i=1; i< n-1;i++){
            head = arr[i];
            int loc = lowerbound(arr, i+1, head, n);
            if(loc ==-1){
                break;
            }
            
            int l= loc;
            int r= n;
            
            while (l+1<r) {
                int mid = (l+r)/2;
                if(arr[n]-arr[mid]>head){
                    l=mid;
                }else{
                    r=mid;
                }
            }
            int loc2;
            if(arr[n]-arr[r]>head){
                loc2=r;
            }else{
                loc2=l;
            }
            //System.out.printf("l: %d r: %d loc2: %d\n",l,r,loc2);
            //System.out.printf("loc: %d\n",loc);
            cnt+= loc2-loc+1;
        }
        System.out.println(cnt);
    }
    //벌레 가슴 크기 최대치 구하기
    static int lowerbound(long[]arr, int end,long head, int n){
        int l= end;
        int r= n;
        long l_val = 0;
        long r_val = 0;

        while(l+1<r){
            int mid = (l+r)/2;
            
            l_val= arr[mid]-head;
            r_val = arr[n]-arr[mid];
            
            if(l_val<=r_val || r_val<=head){
                l=mid;
            }else{
                r=mid;
            }

        }

        if(arr[n]-arr[l]>head && arr[l]-head>arr[n]-arr[l]){
            return l;
        }else if(arr[n]-arr[r]>head && arr[r]-head>arr[n]-arr[r]){
            return r;
        }else{
            return -1;
        }
    }
}
