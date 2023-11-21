import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class p15552 {
    static StringBuffer sb;
    static BufferedWriter bw;
    static BufferedReader br;
    
    public static void main(String[] args) throws Exception{
        sb= new StringBuffer();
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        br= new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        for(int i=0;i<n;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int sum= Integer.parseInt(st.nextToken());
            sum+= Integer.parseInt(st.nextToken());
            sb.append(sum+"\n");
        }
        
        bw.flush();
        bw.write(sb.toString());
        bw.close();
    }
}
