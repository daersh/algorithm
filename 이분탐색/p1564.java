package 이분탐색;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class p1564 {
    static StringBuffer sb;
    static BufferedReader br;
    static BufferedWriter bw;
    static int n,m;
    static StringTokenizer st;
    static int []arr=new int[10010];

    public static void main(String[] args) throws Exception{
        sb= new StringBuffer();
        br= new BufferedReader(new InputStreamReader(System.in));
        bw= new BufferedWriter(new OutputStreamWriter(System.out));
        solve();    
    }
    
    public static void solve() throws IOException{
        st= new StringTokenizer(br.readLine());
        n=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());
        
        for(int i=0;i<n;i++){
            st=new StringTokenizer(br.readLine());
            arr[i]=Integer.parseInt(st.nextToken());
        }
        
    }

}

// 457 539 743 802
// 