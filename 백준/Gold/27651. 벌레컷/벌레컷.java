import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
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
        long cnt=0;
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
            if(l>r){
                int temp = l;
                l=r;
                r=temp;
            }
            int loc2;
            if(arr[n]-arr[r]>head){
                loc2=r;
            }else{
                loc2=l;
            }
            // System.out.println("loc1: "+ loc );
            // System.out.println("loc2: " + loc2);
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
            
            if(l_val<=r_val ){
                l=mid;
            }else{
                r=mid;
            }
        }

        if(l>r){
            int temp = l;
            l= r;
            r= temp;
        }
        // System.out.println("l: "+ l + " r: "+ r);
        // System.out.println("head: "+head+" arr[n]-arr[l]: "+ (arr[n]-arr[l]) + "  arr[n]-arr[r]: "+ (arr[n]-arr[r]) );
        if(arr[n]-arr[l]>head && arr[l]-head>arr[n]-arr[l]){
            return l;
        }else if(arr[n]-arr[r]>head && arr[r]-head>arr[n]-arr[r]){
            return r;
        }else{
            return -1;
        }
    }
}
