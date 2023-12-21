import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class p1929 {
    static StringBuffer sb;
    static BufferedReader br;
    static BufferedWriter bw;
    static StringTokenizer st;

    public static void main(String[] args)throws Exception {
        sb= new StringBuffer();
        br= new BufferedReader(new InputStreamReader(System.in));
        bw= new BufferedWriter(new OutputStreamWriter(System.out));

        int n , m;
        st = new StringTokenizer(br.readLine());
        n= Integer.parseInt(st.nextToken());
        m= Integer.parseInt(st.nextToken());
        int []arr= new int[m+1];
        arr[1]=1;
        for(int i=2;i<m;i++){
            for(int j=2;j*i<=m;j++)
                arr[i*j]=1;
        }

        for(int i=n;i<=m;i++){
            if(arr[i]==0){
                System.out.println(i);
            }
        }
    }
}
