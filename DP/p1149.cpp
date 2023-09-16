#include <bits/stdc++.h>
using namespace std;



int arr[1010][3];



int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
   int N;
   cin >>N;
   for(int i=0;i<N;i++){
      cin >> arr[i][0];
      cin >> arr[i][1];
      cin >> arr[i][2];
   }
   
   for(int i=1;i<N;i++){
      
      if(arr[i-1][1] < arr[i-1][2]){
         arr[i][0]+=arr[i-1][1];
      }else{
         arr[i][0]+=arr[i-1][2];
      }

      if(arr[i-1][0] < arr[i-1][2]){
         arr[i][1]+=arr[i-1][0];
      }else{
         arr[i][1]+=arr[i-1][2];
      }
      
      if(arr[i-1][1] < arr[i-1][0]){
         arr[i][2]+=arr[i-1][1];
      }else{
         arr[i][2]+=arr[i-1][0];
      }
      

   }

   // cout<< "R= " << arr[N-1][0] << '\n';
   // cout<< "G= " << arr[N-1][1] << '\n';
   // cout<< "B= " << arr[N-1][2] << '\n';
   
   int R=  arr[N-1][0];
   int G= arr[N-1][1];
   int B= arr[N-1][2];
   if(R <= G && R<=B){
      cout << R;
   }else if(G <= R && G<=B){
      cout << G;
   }else if(B <= G && B<=R){
      cout << B;
   }
    
}