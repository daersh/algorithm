import java.io.*;
import java.util.*;

import javax.print.DocFlavor.STRING;

public class Main{
    static BufferedReader br;
    static BufferedWriter bw;
    static StringBuilder sb;

    static public class Node{

        List<Node> Node_next;
        List<String> childs;
        boolean isEnd;
        PriorityQueue<String> pque = new PriorityQueue<>();

        Node(){
            Node_next = new ArrayList<>();
            childs = new ArrayList<>();

            isEnd = false;
        }
    }
    
    public static class TRIE{
        Node root;

        TRIE(){root = new Node();}

        void insert(List<String> a){
            Node loc = root;
                //문자열 a를 받는동안
       loop :   for(int i=0;i<a.size();i++){

                if(loc.childs.size()==0){
                    loc.childs.add(a.get(i));
                    loc.Node_next.add(new Node());
                    loc.pque.add(a.get(i));
                    loc= loc.Node_next.get(0);

                }else{
                    for(int j=0;j<loc.childs.size();j++){
                        if(a.get(i).equals(loc.childs.get(j))){    
                            loc= loc.Node_next.get(j);
                            continue loop;
                        }
                    }
                    loc.childs.add(a.get(i));
                    loc.Node_next.add(new Node());
                    loc.pque.add(a.get(i));
                    loc = loc.Node_next.get(loc.childs.size()-1);
                }
            }
            loc.isEnd=true;
        }
        
        void print(Node trie, int cnt){
            Node loc = trie;
            for(int i=0;i<loc.childs.size();i++ ){
                String x= loc.pque.poll();
                
                for(int j=0;j<cnt;j++){
                    sb.append(" ");
                }
                sb.append(x + "\n");

                for(int j=0;j<loc.childs.size();j++){
                    if(x.equals(loc.childs.get(j))){
                        //if(loc.Node_next.get(j).isEnd!= true)
                            print(loc.Node_next.get(j), cnt+1);
                    }
                }

            }
        }
        
    }

    public static void solve() throws Exception {
        int n = Integer.parseInt(br.readLine());
        TRIE test = new TRIE();
        for(int i=0; i<n;i++){
        StringTokenizer st = new StringTokenizer(br.readLine(), "\\" );
        List<String> strs = new ArrayList<>();
        while(st.hasMoreTokens()) {
            strs.add(st.nextToken());
        }
        test.insert(strs);
        }
        test.print(test.root, 0);
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