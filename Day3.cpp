/*okay lets start the day three ,our main focus today will be knapsack based problems*/
/*Problem 1
Given N items where each item has some weight and profit associated with it and also given a bag with capacity W, [i.e., the bag can hold at most W weight in it]. The task is to put the items into the bag such that the sum of profits associated with them is the maximum possible.


*/

/*hmm the kanpsack based problem is mainly focused on the 
fact how much can be placed without overflowing the bag
but how we will get to know how much to place and how we 
will use the previous state in these question

so first thing that you have to keep in mind is to try all the 
weights and then use the previous state in the next weights 


hindi mai samjahat hu 
aisa karte hai saare weight 1 se leke maximum weight limit jo di
gayi hai usse fill out karne ki koshish karte hai aur yahi
future mai use kar lenge

code se behtar samajh aayega*/

#include<bits/stdc++.h>
using namesapce std;
int main(){
    int n;
    int c;
    cin>>n;
    cin>>c;
    int i=1;
    while(i<=n ){
        cin>>w[i];
        cin>>p[i];
        i++;
    }
    vector<vector<int>>dp(n+1,vector<int>(c+1,0));
    for(int i=1;i<=n;i++){//iterate over items
        for(int j=1;j<=n;j++){//iterate over weights
            int not_take=dp[i-1][j]//current item nahi liya 
            int take=0;
            if(j>=w[i]){
                take=p[i]+dp[i-1][j-w[i]];//agar current weigth le liya to decrease to hoga ab dp se ye decreased weight le aao

            }
            dp[i][j]=max(not_take,take);
        }
    }
    cout<<dp[n][c];
    return 0;
 
}


/*Problem 2

 You are given an array of size N name cost[i] ; you are also given happy[i] ; max[i] ; min[i] ; m-> total budget 

Do shopping in such a way such that you get maximum happiness in the given money 

*/

/*Dekho ab previous problem mai weights mai travesrse karna tha
aur yaha pai bhi same hi karna hai items traverse karo fir budget 
aur yaha ye tumhe bas quantity pe ek extra loop marna padega
ab bhai happiness ke liye min se max tak sari quantity try karni padegi */

#include<bits/stdc++.h>
using namespace std;
int dp[105][105];
int main(){
    int n;
    cin>>n;
    vector<int>cost(n+1,0),happy(n+1,0),mn(n+1,0),mx(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>cost[i];
    }
    for(int i=1;i<=n;i++){
        cin>>happy[i];
    }
    for(int i=1;i<=n;i++){
        cin>mn[i];
    }

    for(int i=1;i<=n;i++){
        cin>>mx[i];
    }

    int m;
    cin>>m;//total budget

    vecotr<vector<int>>dp(n+1,vector<int>(m+1,-1e18));
    dp[0][0]=0;
    for(int i=1;i<=n;i++){//items ke upar iteration
        for(int j=1;j<=m;j++){//budget ke upar
            dp[ij][j]=d[i-1][j];//previous state utha li comparison ke liye
            for(int count=mn[i];count<=mx[i];i++){
                int total_cost=count*cost[i];
                if(j>=total_cost){
                    dp[i][j]=max(dp[i][j], dp[i - 1][j - total_cost] + count * happy[i]);
                }
            }
        }
    }
    cout<<max(0,dp[n][m]);
    return 0;

}

/*Problem 3

We are given “N” rows. Each row has “M” elements; we have to select 1 element from each row. 

Once we are done with it final sum of all elements should be as close as possible to K 

*/
/*ab dekho closest sum nikaln hai k ke liye ab har row se
ham ek hi element select kar sakte hai ab aisa karte hai har row 
se maximum uthao aur maximum sum bana lo aisa kyun ar bahi baki 
knapsack ki limit pata hoti hai ab yaha to nahi pata to
aise kar ke nikal lo bas fir wahi classic traversal karo aur same knapsack dp code*/

#inlcude<bits/stdc++.h>
using namesapce std;
int main(){
    int n,m,k;
    cin>>n,m,k;
    vector<vector<int>>matrix(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        maxsum += *max_element(matrix[i].begin(), matrix[i].end());
    }

    vector<vector<bool>>dp(n+1,vector<bool>(maxsum+1,false));
    dp[0][0]=true;
    for(int i=1;i<=n;i++){
        for(int sum=maxsum;sum>=0;sum--){
            for(int j=0;j<m;j++){
                int value=matrix[i-1][j];
                if(sum>=value && dp[i-1][sum-value]){
                    dp[i][sum]=true;
                }
            }
        }
    }

    int closestsum=INT_MAX;
    int mindiff=INT_MAX;
    for(int sum=0;sum<=maxsum;sum++){
        if(dp[n][sum]){
            int diff=abs(sum-k);
            if(diff<mindiff){
                mindiff=diff;
                closestsum=sum;
            }
        }
    }
    cout<<closestsum<<endl;
    return 0;
}