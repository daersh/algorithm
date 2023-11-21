import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;


public class p12865 {
    static BufferedReader br;
    static BufferedWriter bw;
    static StringBuilder sb;
    public static void main(String[] args) throws Exception{
        br = new BufferedReader(new InputStreamReader(System.in)); // input c++ cin
        bw = new BufferedWriter(new OutputStreamWriter(System.out)); // ouput c++ cout
        sb = new StringBuilder();
        solve();        
        print();
    }

    public static void solve()throws Exception{
        int n,m;
        StringTokenizer st = new StringTokenizer(br.readLine());
        n=Integer.parseInt( st.nextToken());
        m=Integer.parseInt( st.nextToken());
        int [][]arr = new int[n][2];

        //무게, 가치 입력
        for(int i=0;i<n;i++){
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            arr[i][0]= Integer.parseInt( st2.nextToken());
            arr[i][1]= Integer.parseInt( st2.nextToken());
        }
        dp();
    }

    public static void dp() {

    }

    public static void print() throws Exception{
        bw.flush();
        bw.write(sb.toString());
        bw.close();
    }



}
