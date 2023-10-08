#include <iostream>
#include  <vector>

using namespace std;


vector<pair<int,int> > vec[10];

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,m;

    cin >> n >> m;
    int arr[n][m];
    
    int max=1;
    int x,y;
    for(int i=0;i<n;i++){
        string a;
        cin >> a;
        for(int j=0;j<m;j++){     
            x = a[j]-48;
            vec[x].push_back(make_pair(i,j));
        }
    }
    for(int i=0;i<10;i++){
        //cout << i<<"번 시작\n";
        vector<pair<int,int> > vec2;
        vector<int> vec3;
        for(int j=0;j<vec[i].size();j++){
            
            int k=j+1;
            while(vec[i][j].first==vec[i][k].first){
                //printf("[%d,%d] == [%d,%d] \n", vec[i][j].first,vec[i][j].second,vec[i][k].first,vec[i][k].second );
                vec2.push_back(make_pair(vec[i][j].second,vec[i][k].second));
                vec3.push_back(vec[i][j].first);
                k++;
            }
        }
        //cout << "최대 크기 계산 시작 \n";
        for(int j=0;j<vec2.size();j++){

            for(int k=j+1;k<vec2.size();k++){
                if(vec2[j].first ==vec2[k].first && vec2[j].second ==vec2[k].second ){
                    int height= vec3[k]-vec3[j];
                    if(height==vec2[j].second-vec2[j].first &&  max<height+1){
                        
                        max=height+1;
                    }
                }
            }
        }      

        //cout << i << ": "<< max*max<< '\n';
    }
    cout << max*max;
}