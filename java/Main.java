import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;


public class Main{
    static BufferedReader br;
    static BufferedWriter bw;
    static StringBuilder sb;
    public static void solve() throws Exception {
        int n = Integer.parseInt(br.readLine());

        while(n != 0) {
            int a = n % 10;
        }

        StringTokenizer st = new StringTokenizer(br.readLine(), "-=*");
        while(st.hasMoreTokens()) {
            sb.append(st.nextToken() + "\n");
        }
    }
    public static void print()throws Exception{
        bw.flush();
        bw.write(sb.toString());
        bw.close();
    }

    public static void main(String[] args) throws Exception{
        //입력
        br = new BufferedReader(new InputStreamReader(System.in)); // input c++ cin
        bw = new BufferedWriter(new OutputStreamWriter(System.out)); // ouput c++ cout
        sb = new StringBuilder();
        solve();


        print();
        
    }
}