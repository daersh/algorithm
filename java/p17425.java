import java.io.*;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;


public class p17425 {
    static BufferedReader br;
    static StringTokenizer st;
    static StringBuffer sb;
    static BufferedWriter bw;

    static long []arr= new long[1000001];
    static int n;
    
    static void init()throws Exception{
        st= new StringTokenizer(br.readLine());
        n=Integer.parseInt(st.nextToken());

        for(int i=1; i<=1000000;i++){
            for(int j=1;j<=1000000;j++){
                if(i*j<=1000000){
                    arr[i*j]+=i;
                }else{
                    break;
                }
            }
        }
        
        for(int i=1;i<=1000000;i++){
            arr[i]+=arr[i-1];
        }
    }

    public static void solve() throws Exception{
        init();
        for(int i=0; i< n; i++ ){
            st= new StringTokenizer(br.readLine());
            int s= Integer.parseInt(st.nextToken());
            sb.append(arr[s]);
            sb.append('\n');
        }   
    }

    public static void main(String[] args) throws Exception{
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        sb = new StringBuffer();
        solve();
        bw.flush();
        bw.write(sb.toString());
        bw.close();
    }

}
