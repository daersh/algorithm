import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class p25314 {
    static StringBuffer sb;
    static BufferedReader br;
    static BufferedWriter bw;

    public static void main(String[] args)throws Exception {
        sb= new StringBuffer();
        br= new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int x =Integer.parseInt(br.readLine());
        x /= 4;
        for(int i=0; i<x;i++){
            sb.append("long");
            sb.append(" ");
        }
        sb.append("int");
        
        bw.flush();
        bw.write(sb.toString());
        bw.close();
    }
}
