import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class Main {
    static BufferedReader br;
    static BufferedWriter bw;
    static StringBuffer sb;
    static StringTokenizer st;

    static int n,m;
    static boolean []visited= new boolean[101];
    // 한노드에 연결된 노드들을 저장하기 위함
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
       int n,m;
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        int [][]arr= new int[n][m];
        int [][]arr2= new int[n][m];
        boolean [][]visited = new boolean[n][m];
        Deque<data> q = new ArrayDeque<>();

        for (int i = 0; i < n; i++) {
            String x = br.readLine();
            for (int j = 0; j < m; j++) {
                arr[i][j]= Integer.parseInt(String.valueOf(x.charAt(j)));
            }
        }

        int[] x_new = {1,-1,0,0};
        int[] y_new = {0,0,1,-1};
        int cnt =0;
        q.push(new data(0,0));

        while(!q.isEmpty()){
            data dat = q.getFirst();
            int x= dat.x;
            int y= dat.y;
            int d= dat.d;
            q.removeFirst();
//            System.out.println("x: "+x+" y: "+y);

            if(visited[x][y]) continue;
            visited[x][y]=true;
            arr2[x][y]=d;

            for (int z = 0; z < 4; z++) {
                int x_next= x+x_new[z];
                int y_next= y+y_new[z];

                if(x_next>=0 && x_next<n && y_next>=0 && y_next<m&&
                        arr[x_next][y_next]==1 && !visited[x_next][y_next])
                {
//                    System.out.printf("q.add(%d,%d)\n",x_next,y_next);
                    q.addLast(new data(x_next,y_next,d+1));
                }
            }
        }


        System.out.println(arr2[n-1][m-1]+1);
        return null;
    }

    static class data{
        int x;
        int y;
        int d;
        data(int x,int y){
            this.x=x;
            this.y=y;
            d=0;
        }
        data(int x,int y,int d){
            this.x=x;
            this.y=y;
            this.d=d;
        }
    }
}
