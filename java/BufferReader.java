import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.StringReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BufferReader {

    static BufferedReader br;
    static BufferedWriter bw;
    static StringBuffer sb;

    //1: 빈칸
    //2: 바이러스
    static void solve() throws Exception{
        StringTokenizer st= new StringTokenizer(br.readLine());
        int n=Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int [][]arr= new int[n+1][m+1];
        // ArrayList<Integer>[] virus = new ArrayList(2);
        for(int i=0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<m;j++){
                arr[i][j]=Integer.parseInt(st.nextToken());
                if(arr[i][j]==2){
                    virus.add();
                }
            }
        }

    }

    static void bfs(int[][] arr){

        
    }

    public static void main(String[] args)throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        sb = new StringBuffer();

        solve();
        
    }
}
