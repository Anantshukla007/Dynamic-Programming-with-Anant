/*okay here the second day begins */
/*Problem 1 

-> There are two arrays , 'B' and 'C' ; size of both the arrays is 'N' ;

-> At each index you are supposed to pick up an element either from array 'C' or array 'B'

->You have to maximize the final sum of all elements

->Condition : You cannot select 3 or more than 3 element consecutively from the same array.

*/

/*okay so the problem looks pretty straight forward you just
need selct elements from 2 array maximize the sum
and just dont select three consicutive elements 
so if i am at index 1 then then i can selcet only one of the 
two arrays so dp[1]=max(b[1],c[1])

now lets look for the dp[2] we have choices of (dp[1]+max(b[2],c[2])) \
prettty straight forward by far 
now lets look for dp[3]=wouldd be also be like this dp[2]+max(b[3],c[3]) nahh
here it  gets little difficult because you need to know what previous element did you select 
will it solve the problem now think even if we know in the last
step it will be of no use to use in current step decesion making
because we need three consicutive element and that can be made
sure if keep track of prev as well as prev-1 element 
so this introduces two new states in the process but thats all we need ok lets code it for better understanding */


#include<bits/stdc++.h>
using namespace std;
int maxi(int x,int y,int z,int g)
{
    return max(max(x,y),max(z,g));
}

int mx(int x,int y,int z)
{
    return max(x,max(y,z));
}
int main(){
    int n;
    cin>>n;
    int b[n+1]={0};
    int d[n+1]={0};
    int i=1;
    while(i<=n){
        cin>>b[i];
        cin>>d[i];
        i++;
    }
    int dp[n+1][5][5]={0};

    //dp[index][choice in i-1][choice in i index]
    dp[1][1][1]=b[1];
    dp[1][1][2]=b[1];
    dp[1][2][1]=d[1];
    dp[1][2][2]=d[1];

    i=2;
    while(i<=n){
        dp[i][1][1]=b[i]+b[i-1]+max(dp[i-2][2][2],dp[i-2][2][1]);
        dp[i][1][2]=b[i]+d[i-1]+mx(dp[i-2][1][1],dp[i-2][1][2],dp[i-2][2][1]);
        dp[i][2][1] = d[i] + b[i-1] + mx(dp[i-2][2][1],dp[i-2][2][2],dp[i-2][1][2]);
        dp[i][2][2] = d[i] + d[i-1] + max(dp[i-2][1][2],dp[i-2][1][1]);

        i++;
    }
    cout<<maxi(dp[n][1][1],dp[n][1][2],dp[n][2][2],dp[n][2][1])


    
}//this particular problem can be tricky to understand what you will need is good old pen and paper write it two or three times you will get it 


///////////////////////////////////////////////////////////////

/*problem 2

You are given two arrays a and b -> both are of size “N”. 

Start your journey at index 1 and end your journey at index “N”. 

In a move you can move from a[i]->a[i+1] or a[i]->b[i+1] 

OR 

b[i]->b[i+1] or b[i]->a[i+1]

Output the number of journeys whose sum is even and odd. 


if you are following along you might have seen a similar problem in 
yesterday also
*/

/*
so first thing that we directely see that at each particular we can
have multiple solution why???
well each index element will be odd and even and the sum on that
index to be even or will be generalized from the previous arree
even+even=even to current elemeny aagr even hai to us index pe jo
even sum milenge wo hame previous index ke evene sum se miljayega

lekin odd sum ke liye previous index ke odd sum bhi to chaiye honge

yaa now 
if current element tend to be odd then the above cases will be inversed


but the thing to look out for is that here we have two arrays so two different types of
sum ending at every index with current element selcetion from the which array we are 
selecting and also the previous state both array selcetio ie

if think at an index i the array a  a[i] is even then
we will have 
dp[i][a][even] = dp[i-1][a][even] + dp[i-1][b][even] 

If a[i] is odd:- 

dp[i][a][even] = dp[i-1][a][odd] + dp[i-1][b][odd]

and similarly for b[i] 



*/


#include <iostream>
#include <vector>

using namespace std;

void countJourneys(vector<int>& a, vector<int>& b) {
    int n = a.size();
    

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(2, 0)));
    
    //dp[index][a][even]=dp[i][0][0]
    //dp[index][a][odd]=dp[i][0][1]
    //similarly for b


    if(b[1]%2==0){
      dp[1][1][0] = 1 ; 
      dp[1][1][1] = 0 ; 
    }
    else{
      dp[1][1][0] = 0 ; 
      dp[1][1][1] = 1 ; 
    }
    if(a[1]%2==0){
      dp[1][0][0] = 1 ; 
      dp[1][0][1] = 0 ; 
    }
    else{
      dp[1][0][0] = 0 ; 
      dp[1][0][1] = 1 ; 
    }

    for (int i = 2; i <= n; ++i) {

        if (a[i] % 2 == 0) {
            dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][1][0])  ;
        } else {
            dp[i][0][0] = (dp[i - 1][0][1] + dp[i - 1][1][1])  ;
        }
        
        // Update dp[i][a][odd]
        if(a[i] % 2 == 0) {
            dp[i][0][1] = (dp[i - 1][0][1] + dp[i - 1][1][1])  ;
        } else {
            dp[i][0][1] = (dp[i - 1][0][0] + dp[i - 1][1][0])  ;
        }
        
        // Update dp[i][b][even]
        if (b[i] % 2 == 0) {
            dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][1][0])  ;
        } else {
            dp[i][1][0] = (dp[i - 1][0][1] + dp[i - 1][1][1])  ;
        }
        
        // Update dp[i][b][odd]
        if (b[i] % 2 == 0) {
            dp[i][1][1] = (dp[i - 1][0][1] + dp[i - 1][1][1])  ;
        } else {
            dp[i][1][1] = (dp[i - 1][0][0] + dp[i - 1][1][0])  ;
        }
    }
    
    // Total even and odd journeys
    int evenJourneys = (dp[n][0][0] + dp[n][1][0])  ;
    int oddJourneys = (dp[n][0][1] + dp[n][1][1])  ;
    
    cout << "Even journey count is " << evenJourneys << endl;
    cout << "Odd journey count is " << oddJourneys << endl;
}

int main() {
    vector<int> a = {1, 2, 1};
    vector<int> b = {3, 1, 1};
    
    countJourneys(a, b);
    
    return 0;
}//to be precise i hate these kind of question same thing just need to write it extra times 

/*Problem 3

Find the number of ways to make sum “y” with the numbers “1”,”2”,”4”,”6”. 

Condition :- 4 can be used at most 2 times.

*/

/*Okk this is a pretty intresting one 
initilly the problem is pretty easy just need to make the sum y
by selecting  number 1,2,4,6 
so lets first solve it for the case where we dont have to worry 
about this 4 can be used only 2 times condition then
it will be pretty easy 
base cases dp[1]=1 only one way
dp[2]= 2 or 1+1 there are two ways and  so on the cases can be derived
dp[3] = dp[2] + dp[1] 


dp[4] = dp[0] + dp[2] + dp[3]

dp[5] = dp[1]+dp[4]+dp[3]
lets code this first then we will wrok for the condition part*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int dp[n+1]={0};
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
        if(i>=4){
            dp[i]+=dp[i-4];
        }
        if(i>=6){
            dp[i]+=dp[i-6];
        }
    }
    cout<<dp[n];
    return 0;
}

/*now lets deal with the condition part of the problem so what
we want is that we use the number four at most two times
so technically we can achieve sum with 4 being used 0 times
4 being used 1 time and 4 being used 2 times

okk so we add a new state to our dp 
dp[sum][how many times we have used four]

Final answer = dp[n][0] + dp[n][1] + dp[n][2]

there we will be three conditions or cases say 

dp[i][0]=dp[i-1][0]+dp[i-2][0]+dp[i-6][0] basic 4 was never used 

dp[i][1]=dp[i-1][1]+dp[i-2][1]+dp[i-4][0]+dp[i-6][1] why  dp[i-4][0] ???
since we are using only one four so we can't have another state of 4 sum 
so te ensure that we use this case with zero four

similarly we will have

dp[i][2] =dp[i-1][2]+dp[i-2][2]+dp[i-4][1]+dp[i-6][2]

*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << 3 << endl; // dp[0][0] + dp[0][1] + dp[0][2] = 1 + 1 + 1
        return 0;
    }
    vector<vector<long long>> dp(n+1, vector<long long>(3, 0));
    
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        if (i-1 >= 0) dp[i][0] += dp[i-1][0];
        if (i-2 >= 0) dp[i][0] += dp[i-2][0];
        if (i-6 >= 0) dp[i][0] += dp[i-6][0];
        
        if (i-1 >= 0) dp[i][1] += dp[i-1][1];
        if (i-2 >= 0) dp[i][1] += dp[i-2][1];
        if (i-4 >= 0) dp[i][1] += dp[i-4][0];
        if (i-6 >= 0) dp[i][1] += dp[i-6][1];
        
        if (i-1 >= 0) dp[i][2] += dp[i-1][2];
        if (i-2 >= 0) dp[i][2] += dp[i-2][2];
        if (i-4 >= 0) dp[i][2] += dp[i-4][1];
        if (i-6 >= 0) dp[i][2] += dp[i-6][2];
    }
    long long result = dp[n][0] + dp[n][1] + dp[n][2];
    cout << result << endl;

    return 0;
}
//okk so this was all for the simple pattern dp question !!!


/*now we can move to second pattern in dp problems that being
the subarray dp where as the name suggests the main focus is on the 
subarray these problems unlike the simple pattern are little more
tricky and tend to use a different approach okkay lets see the problem itself*/

/*Problem 4
leetcode 647 Palindromic substring
Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

*/
/*okay lets look for the brute force then we will move our
way to the dp part so the intial idea is just use loops
to chech every possible substring possible in the array but 
that for sure is pretty bad so lets look at the dp part

so since its a subarray you will require a start and end index for sure
what will be our define palidrome each charecter in the string ie
if we have abc then a b c will all be a palindromic substring in 
themselves so if you were a dp then dp[i][i] would be 1 for sure
okk this was good now what more can be checked easily see if 
two adjacent charecters are same it is pretty easy to initalize
the dp for them right you just need to check s[i]==s[i+1] or not
and make dp[i][i+1]=1 bases on the condition

ok so this dp will help to know if that particular substring is palindrome or
not what about the count of palindromic substring between i and j
so for that what i tend to do is make on more dp it will do nothing
special just keep the track of number of substring in the range i and j 
whcih are palindromic

okk so let's code it and see what it looks like

*/
#include<bits/stdc++.h>
using namespace std;

int dp[5000][5000];
int dp1[5000][5000];

int main(){

    string s;
    cin>>s;
    int n=s.size();
    int i,j,k;
    
    i=0;
    int g=0;
    while(i<n){
        dp[i][i]=1;//it is palindrome true
        dp1[i][i]=1;//how manny palindromic substrings 1
        i++;
    }
    //now adjacent charecter case
    
    i=0;
    while(i<n-1){
        if(s[i]==s[i+1]){
            dp[i][i+1]=1;//if both the adjacent charecters are same

        }
        dp1[i][i+1]=dp1[i][i+1]+dp1[i][i+1]+dp1[i+1][i+1]//so if two adjacent charecters are same then there will be three palindromice substrings right

    }
    //ok now here is the real deal

    int length=3;//why length well we have already checked palindrome for length 1 and so for the length 2 right so we start from lenght 3 and will try till n
    //ans see how many  substring starting at i with lenght l are palindromic 
    while(length<=n){
        i=0;
        while(i<n-length+1){//well we can not go out side right
            int j=i+length-1;
            if(s[i]==s[j] && dp[i+1][j-1]==1){//if both the charecter at i and j are same check for the answer between i+1 and j-1 index we will be having it in dp
                dp[i][j]=1;
            }
            dp1[i][j]= dp1[i][j-1] + dp1[i+1][j] - dp1[i+1][j-1] + dp[i][j] ;
            i++;
          


        }
        length++;
    }
    int q ; 
    cin>>q ; 
    for(int i=0;i<q;i++){
    	int l,r ; 
    	cin>>l>>r ; 
    	cout<<dp1[l][r];
    	cout<<'\n';
    }
    return 0;
}

/*
Problem 5
Longest Palindromic Substring

i hope the name is enough and you can make a google search for this

*/
/*ok by far the question was how many but now the question changes
to what length and what is the longest possible and
i will show you how just the previous solution can be molded right into
the solution for this one

so just like previous solution dp[i][i] will be there to chcek wheteher the 
the substring is palindromic or not but here you will not dp1 because
there is no cost involvement right we just need length 
you will better understand with the code itself
*/

#include<bits/stdc++.h>
using namespace std;
int dp[50000][50000];
int main(){
    string s;
    cin>>s;
    int n=s.size();
    int longest=0;
    int i=0;
    while(i<n){
        dp[i][i]=1;
        longest=1;

    }
    i=0;
    while(i<n-1){
        if(s[i]==s[i+1]){
            dp[i][i+1]=1;
            longest=2;
        }
        i++;

    }
    int length=3;
    while(length<=n){
        int i=0;
        while(i<n-length+1){
            int j=i+length-1;
            if(s[i]==s[j] && dp[i+1][j-1]==1){
                dp[i][j]=1;
                longest=length
            }
            i++;
        }
        length++;
        
    }
    cout<<longest;
}//pretty easy right 

/*Problem 6
Leetcode 312 Burst Balloons
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

 

Example 1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
*/

/*now this one here is little tricky but we can do it
first thing first here also we need to pick ballons in a range
and burst them and get the cost pretty easy

but the main problem is we can select differnt ballons and we also need
to keep track of various range that we have already burst.
so for that we use a variable k so what k does is
we start moving k from start of the range i and move it till the
end of the range j so so we will have our selves doffernt ranges to burst 
ballons form 
so what we are trying to do is say we are considering with k is that
we have already burst the ballons in range i to k-1 
and ballons k+1 to j and
we will get add new cost cost[i-1]*cost[k ]*cost[j+1] */


class Solution {
public:
    int maxCoins(vector<int>& b) {


        int n = b.size();
        vector <int> g ; 
        g.push_back(1);
        int i = 0 ; 
        while(i<n){
            g.push_back(b[i]);
            i++;
        }
        g.push_back(1);

        vector<vector<int>> dp(n+5, vector <int> (n+5,0));

        i = 1;
        while(i<=n){
            dp[i][i] = g[i-1]*g[i]*g[i+1];
            i++;
        }

        int length = 2 ; //finding for all subarrays of length givn 
        while(length<=n){

            i = 1 ; 
            int j = i + length - 1 ; 
            //i--->start point of subarray 
            //j--->end point of subarray 

            while(j<=n){

                //dp[i][j] is best answer for subarray starting from index i and ending at j
                int ii = INT_MIN ; 
                int k = i ; //k-->last element u decide to destroy  
                while(k<=j){
                    int possibility = g[i-1]*g[k]*g[j+1]  ;


                    if(i<=k-1){
                        possibility+=(dp[i][k-1]);
                    } 

                    if(k+1<=j){
                        possibility+=(dp[k+1][j]);
                    }

                    ii = max(ii,possibility);
                    k++;
                }

                dp[i][j] = ii ; 

                i++;j++;
            }
            length++;
        }
        return dp[1][n]; 

    }
};

/*problem 7

leetcode 3277 Maximum XOR Score Subarray Queries

You are given an array nums of n integers, and a 2D integer array queries of size q, where queries[i] = [li, ri].

For each query, you must find the maximum XOR score of any 
subarray
 of nums[li..ri].

The XOR score of an array a is found by repeatedly applying the following operations on a so that only one element remains, that is the score:

Simultaneously replace a[i] with a[i] XOR a[i + 1] for all indices i except the last one.
Remove the last element of a.
Return an array answer of size q where answer[i] is the answer to query i.

 

Example 1:

Input: nums = [2,8,4,32,16,1], queries = [[0,2],[1,4],[0,5]]

Output: [12,60,60]

Explanation:

In the first query, nums[0..2] has 6 subarrays [2], [8], [4], [2, 8], [8, 4], and [2, 8, 4] each with a respective XOR score of 2, 8, 4, 10, 12, and 6. The answer for the query is 12, the largest of all XOR scores.

In the second query, the subarray of nums[1..4] with the largest XOR score is nums[1..4] with a score of 60.

In the third query, the subarray of nums[0..5] with the largest XOR score is nums[1..4] with a score of 60.
*/

/*okay this is the last one for today and last for the subarray part
now the thing is that it is totally similar to the problem first of the subarray
part and the you just need to stor the maximum xor between the range i and j and return it out in soluiton
*/
class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        // observation1 : if size of subarray is odd then XOR score will be first^last
        // observation2 : if size of subarray is even then XOR score will be XOR of all elements in that subarray
        int n = nums.size();
        int ans[n][n];
        // ans[i][j] = XOR score of subarray from i to j
        for(int i=0; i<n; i++){
            ans[i][i] = nums[i];
        }
        int length = 2;
        while(length <= n){
            for(int i=0; i<=n-length; i++){
                int j = i+length-1;
                ans[i][j] = (ans[i][j-1]^ans[i+1][j]);
            }
            length++;
        }
        // Now use subarray dp to calculate all the queries answers in advance
        int dp[n][n];
        for(int i=0; i<n; i++)
        dp[i][i] = nums[i];

        for(int i=0; i<n-1; i++)
        dp[i][i+1] = max(ans[i][i+1],max(dp[i][i],dp[i+1][i+1]));

        length = 3;
        while(length <= n){
            for(int i=0; i<=n-length; i++){
                int j = i+length-1;
                dp[i][j] = max(ans[i][j],max(dp[i][j-1],dp[i+1][j]));
            }
            length++;
        }
        // Now directly give answer of all queries from dp array 
        vector<int> q;
        for(int k=0; k<queries.size(); k++){
            int i = queries[k][0];
            int j = queries[k][1];

            q.push_back(dp[i][j]);
        } 
        return q;
    }
};