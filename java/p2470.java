import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class p2470 {
        static BufferedReader br;
    static BufferedWriter bw;
    static StringBuffer   sb;

    public static void main(String[] args)throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        sb = new StringBuffer();
        int N= Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        long []arr= new long[N];
        for(int i=0;i<N;i++){
            arr[i]=Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);

        long min = 2000000010;
        int loc1 = 0;
        int loc2 = 0;
        int loc =0;
        while(loc<N){
            if(arr[loc]<0){

                int x= lowerbound(arr[loc],loc, N-1, arr,loc);
                if(x==loc){
                    loc++;
                    continue;
                }
                long cmp = arr[x]+arr[loc];
                
                if(cmp<0){
                    cmp *= -1;
                }

                //System.out.printf("loc: %d, x: %d, cmp: %d\n",arr[loc],arr[x],cmp);
                if(cmp<min) {
                    min = cmp;
                    loc1= loc;
                    loc2= x;
                    if(min==0){
                        break;
                    }
                }
                loc++;
            }
            else {
                if(loc+1 < N){
                    long cmp = arr[loc]+arr[loc+1];
                    if(cmp<min) {
                        min = cmp;
                        loc1= loc;
                        loc2= loc+1;
                    }
                }
                break;
            }
            
        }
        System.out.println(arr[loc1] + " "+arr[loc2]);

    }


    static int lowerbound(long val,int start, int end, long[]arr,int loc){
        int mid=0;

        while (start+1<end) {
            mid=(start+end)/2;
            if(arr[mid]< -val) start=mid;
            else end=mid;
        }
        
        //System.out.println("MID:" + mid);

            long cmp1 = arr[start]+val;
            if(cmp1<0) cmp1*= -1;
            long cmp2 = arr[end]+val;
            if(cmp2<0) cmp2 *=-1;
            
            //System.out.printf("cmp1: %d, cmp2:%d",cmp1,cmp2);
            if(cmp2<cmp1){
                if(loc!=end)
                    return end;
            }
            
        if(start==loc){
            return end;
        }
        return start;
    }
}

