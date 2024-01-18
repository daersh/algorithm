
import java.io.*;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class p2606 {

    static BufferedReader br;
    static BufferedWriter bw;
    static StringBuffer sb;
	static StringTokenizer st;
    static int n,m;
    static boolean []visited= new boolean[101];
    // queue- 다음 노드 저장하기 위함
    static ArrayDeque<Integer> queue = new ArrayDeque<Integer>();
    static LinkedList<Integer>[] vec = new LinkedList[101];
    // stack - 한노드에 연결된 노드들을 저장하기 위함

    //static ArrayList<ArrayList<Integer>> vec = new ArrayList<>();

    public static void main(String[] args)throws Exception {
            //init
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        sb = new StringBuffer();

        insert();
        solve();
        print();
    }

    private static void solve() {

        int start= 1;
        queue.add(start);
        int cnt=0;

        while (! queue.isEmpty() ) {
            int node= queue.getFirst();
            queue.pop();
            if(visited[node]) continue;
            visited[node]=true;
            
            cnt++;
            for(int i=0; i<vec[node].size();i++){
                queue.add(vec[node].get(i));
            }
        }
        System.out.println(cnt-1);
    }

    static void insert() throws Exception{
				//입력받기
        st= new StringTokenizer(br.readLine());
				//입력받은 값을 변수에 넣어주기
        n=Integer.parseInt(st.nextToken());

        st= new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());

        for (int i = 0; i <= n; i++) {
            vec[i] = new LinkedList<Integer>();
        }
        // 노드 연결
		for(int i=0; i< m ;i++){
            st= new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            vec[x].add(y);
            vec[y].add(x);
        }
    }

	 static void print() throws Exception{
		bw.flush();
		bw.write(sb.toString());
        bw.close();
}
    
}