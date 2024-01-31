
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br;
    static BufferedWriter bw;
    static StringBuffer sb;
    static StringTokenizer st;

    static int n,m;
    static boolean []visited= new boolean[101];
    // 한노드에 연결된 노드들을 저장하기 위함
    static LinkedList<Integer>[] vec = new LinkedList[101];
    // 다음 노드 저장하기 위함
    static ArrayDeque<Integer> queue = new ArrayDeque<Integer>();

    public static void main(String[] args)throws Exception {
        //init
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        sb = new StringBuffer();
        Integer x= solution();
    }
    static Integer solution() throws Exception{
        int T, n,m,k;
        st = new StringTokenizer(br.readLine());
        T= Integer.parseInt(st.nextToken());
        for(int t=0; t<T;t++){

            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());

            int [][]arr= new int[n][m];
            boolean [][]visited = new boolean[n][m];
            ArrayDeque<data> q = new ArrayDeque<>();

            for (int i = 0; i < k; i++) {
                st= new StringTokenizer(br.readLine());
                int x= Integer.parseInt(st.nextToken());
                int y= Integer.parseInt(st.nextToken());
                arr[x][y] = 1;
            }
            int[] x_new = {1,-1,0,0};
            int[] y_new = {0,0,1,-1};

            int cnt =0;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {

                    if(arr[i][j]==1 && !visited[i][j]){
                        cnt++;
                        q.push(new data(i,j));

                        while(!q.isEmpty()){
                            int x= q.peek().x;
                            int y= q.peek().y;
                            q.pop();
                            if(visited[x][y]) continue;
                            visited[x][y]=true;
                            for (int z = 0; z < 4; z++) {
                                int x_next= x+x_new[z];
                                int y_next= y+y_new[z];
                                if(x_next>=0 && x_next<n && y_next>=0 && y_next<m&&
                                        arr[x_next][y_next]==1 && !visited[x_next][y_next]){
                                    q.push(new data(x_next,y_next));
                                }
                            }
                        }

                    }

                }
            }
            System.out.println(cnt);
        }

        return null;
    }

    static class data{
        int x;
        int y;
        data(int x,int y){
            this.x=x;
            this.y=y;
        }
    }
}
