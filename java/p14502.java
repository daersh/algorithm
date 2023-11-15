import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*; 
import javax.print.DocFlavor.STRING;


public class p14502 {
    static BufferedReader br;
    static BufferedWriter bw;
    static StringBuilder sb;


    public static void main(String[] args) throws Exception{
        br = new BufferedReader(new InputStreamReader(System.in)); // input c++ cin
        bw = new BufferedWriter(new OutputStreamWriter(System.out)); // ouput c++ cout
        sb = new StringBuilder();
        solve();
    }

    public static void solve() throws Exception{
        StringTokenizer st = new StringTokenizer(br.readLine());

    }

    public static void print() throws Exception{
        bw.flush();
        bw.write(sb.toString());
        bw.close();
    }
}
