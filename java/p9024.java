import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class p9024 {
    static BufferedReader br;
    static BufferedWriter bw;
    static StringBuffer sb;

    public static void main(String[] args)throws Exception{
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        sb = new StringBuffer();

        int T = Integer.parseInt(br.readLine());

        for(int t= 0;t<T;t++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n =Integer.parseInt(st.nextToken());
            int m =Integer.parseInt(st.nextToken());
            int[]arr= new int[n];
            int cnt= 0;
            st = new StringTokenizer(br.readLine());
            for(int i=0;i<n;i++){
                arr[i]=Integer.parseInt(st.nextToken());
            }
            Arrays.sort(arr);
            int loc =0;
            while(loc<n){
                int num = m - arr[loc];
                int num2 = lowerbound( num,arr, loc);
                
                arr[loc]= m-arr[loc]-arr[num2];
                if(arr[loc]<0){
                    arr[loc]*=-1;
                }
                loc++;
            }

            Arrays.sort(arr);
            int cmp = arr[0];
            
            for(int i=0;i<n;i++){
                //System.out.println(arr[i]);            
                if(cmp == arr[i]){
                    cnt++;
                }else {
                    break;
                }
            }
            
            System.out.println(cnt);
        }
    }


    static int lowerbound(int val, int[] list,int loc){
        int result=0;
        int l= loc;
        int r = list.length-1;
        int m = 0;

        while (l+1<r) {
            m = (l+r)/2;
            if(list[m]< val){
                l = m;
            }else{
                r = m;
            }
        }
        int cmp1 = val- list[l] ;
        int cmp2 = val - list[r];
        if(cmp1<0){
            cmp1 *=-1;
        }
        if(cmp2 <0 ){
            cmp2 *= -1;
        }
        if(cmp1<cmp2){
            if(loc==l){
                return r;
            }
            return l;
        }else{
            if(loc==r){
                return l;
            }
            return r;
        }
    }


}
