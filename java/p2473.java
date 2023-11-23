import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class p2473 {
    static BufferedReader br;
    static BufferedWriter bw;
    static StringBuffer   sb;

    public static void main(String[] args)throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        sb = new StringBuffer();

        int n = Integer.parseInt(br.readLine());
        long []arr = new long[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0;i<n;i++){
            arr[i]= Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);
        long result = 1000000000;
        long result_l=0,result_r=0, result_m=0 ;

        if(arr[n-1]<0){
            result_l=arr[n-3];
            result_m=arr[n-2];
            result_r=arr[n-1];
        }else if(arr[0]>=0){
            result_l=arr[0];
            result_m=arr[1];
            result_r=arr[2];
        }
        else{

        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<=n-2;j++){
                
                long sum= arr[i]+arr[j];
                if(arr[i]>0){
                    sum +=arr[j+1];
                    if(sum<result){
                    result=sum;
                    result_l=arr[i];
                    result_m=arr[j];
                    result_r=arr[j+1];
                    }
                    break;
                }

                int x = lowerbound(arr, j+1, n-1, sum);
                sum+=arr[x];
                // System.out.printf("x: %d i: %d j: %d ",arr[x],arr[i],arr[j]);
                if(sum<0){
                    sum*=-1;
                }
               //System.out.printf("sum: %d\n",sum);
                if(sum<result){
                    result= sum;
                    result_l=arr[i];
                    result_m=arr[j];
                    result_r=arr[x];
                }
            }
        }
    }

        sb.append(result_l);
        sb.append(" ");
        sb.append(result_m);
        sb.append((" "));
        sb.append(result_r);
        bw.flush();
        bw.write(sb.toString());
        bw.close();
    }

    private static int lowerbound(long [] arr, int start, int end, long sum){
        if(sum<0){
            sum *= -1;
        }

        int mid=0;
        int l = start;
        int r = end;

        while(l + 1<r){
            mid = (l+r)/2;
            if(arr[mid]<sum){
                l =mid;
            }else {
                r = mid;
            }
        }
        long cmp1= sum- arr[l];
        long cmp2= sum- arr[r];
        if(cmp1 <0) cmp1*=-1;
        if(cmp2 <0) cmp2*=-1;
        int ret=0;
        if(cmp2<cmp1)ret = r;
        else ret= l;
        

        return ret;
    }

}
