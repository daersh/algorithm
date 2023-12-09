import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;



public class p6087 {

    static StringBuffer sb;
    static BufferedReader br;
    static BufferedWriter bw;
    static StringTokenizer st;
    static class pair implements Comparable<pair>{
        int first;
        int second;
        int cnt;
        int move=0;
        public pair(int first,int second, int cnt, int move){
            this.first = first;
            this.second = second;
            this.cnt= cnt;
            this.move= move;
        }
        
        public int getPrioirity(){
            return cnt;
        }
        public int compareTo(pair other){
            return this.cnt - other.cnt;
        }
    }
    
    static int bfs(char[][]arr,int[]start, int[]end, int[][] visited, int w, int h){
        int answer= (int)1e9;
        int[][]visited_cnt= new int[h][w];
        PriorityQueue<pair> list = new PriorityQueue<>();

        list.add(new pair(start[0],start[1],0,0));
        while(!list.isEmpty()){
            
            int x= list.peek().first;
            int y= list.peek().second;
            int cnt = list.peek().cnt;
            int m= list.poll().move;
            
            if(visited[x][y]==-1){
                visited[x][y]=cnt;
                visited_cnt[x][y]++;
            }else if(visited[x][y]>=cnt){
                visited[x][y]=cnt;
                visited_cnt[x][y]++;
            }else{
                continue;
            }
            if(x==end[0]&&y==end[1]){
                return  visited[end[0]][end[1]];
            }
            int[] x_new ={1,-1,0,0};
            int[] y_new ={0,0,-1,1};
            //우 좌 하 상
            int[] move  ={1,2,3,4};

            for(int i=0;i<4;i++){
                int x_next= x+x_new[i];
                int y_next= y+y_new[i];

                if(x_next>=0&&x_next<h && y_next>=0 && y_next<w){
                    if(arr[x_next][y_next]=='*'){
                        continue;
                    }
                    
                    if(visited[x_next][y_next]==-1){
                        if(m ==0 || m==move[i]){
                            list.add(new pair(x_next, y_next, cnt, move[i]));
                            visited_cnt[x_next][y_next]=move[i];
                        }else {
                            list.add(new pair(x_next, y_next, cnt+1, move[i]));
                            visited_cnt[x_next][y_next]=move[i];
                        }
                    }else {
                        int next_val=cnt;
                        if(m!=0 && m!=move[i]){
                            next_val++;
                        }
                        if(visited[x_next][y_next]>=next_val){
                                visited_cnt[x_next][y_next]++;
                            if(visited_cnt[x_next][y_next]>50){
                                continue;
                            }
                            list.add(new pair(x_next, y_next, next_val,move[i]));
                            
                        }
                    }

                }
              
            }
            
        }
        answer = visited[end[0]][end[1]];
        return answer;
    }

    static void solve()throws Exception{
        int w, h;
        st= new StringTokenizer(br.readLine());
        w= Integer.parseInt(st.nextToken());
        h= Integer.parseInt(st.nextToken());
        char [][]arr= new char[h][w];
        int [][]visited= new int[h][w];

        //cnt: 거울 개수
        int cnt  =0;
        int []start=new int[2];
        start[0]=-1;
        int []end=new int[2];
        //input
        for(int i=0;i<h;i++){
            st= new StringTokenizer(br.readLine());
            String str = st.nextToken();

            for(int j=0;j<w;j++){
                arr[i][j]=str.charAt(j);
                visited[i][j]= -1;
                if(arr[i][j]=='C')
                {
                    if(start[0]==-1){
                        start[0]=i;
                        start[1]=j;
                    }else{
                        end[0]=i;
                        end[1]=j;
                    }
                }
            }
        }

        cnt = bfs(arr,start,end,visited, w, h);
        System.out.println(cnt);
    }
    
    public static void main(String[] args) throws Exception{
        sb= new StringBuffer();
        br= new BufferedReader(new InputStreamReader(System.in));
        bw= new BufferedWriter(new OutputStreamWriter(System.out));
        solve();
    }
    
}
