/*Based on my experience with dynamic programming (DP), I initially faced significant challenges. However, over time, I’ve gained a deeper understanding of the topic that I’d like to share with you.

To make dynamic programming more approachable, I’ve categorized it into specific types for better clarity. In this discussion, we’ll focus on one of these categories and work through examples to build a solid understanding.

We’ll start with simple patterns, as they are the easiest to comprehend and implement. Before we dive in, I assume you already have a good grasp of recursion and memoization, as our focus will primarily be on tabulation. Additionally, we’ll take a slightly different perspective on classic dynamic programming problems to enhance our understanding.*/

/*Problem 1
 We are given an array of integers(a[n]) . We are given multiple queries of the form : (1, i)
 which means we need to output the sum of all numbers from index- ‘1’ to index ‘i’ of the array.*/

// now what initially comes to mind is that run loop for each query and fid the answer for eacy query brute fore one O(N*Q) not good but
// always start with brute force
/* now lets look out for the dp solution
firstly what i do is create an dp array of size n
so dp[1] = sum of all numbers from 1 to 1
dp[2]=sum of all numbers from 1 to 2
lets say a[5]={4,5,3,2,1} so you can see clearely if have a dp array for this then dp[1] must be array[1]
now for dp[2]=a[1]+a[2] or we can say dp[2]=dp[1]+a[2]
now for dp[3]= a[1]+a[2]+a[3] but it can be written as dp[3]=dp[2]+a[3]
so now you might have started seeing the formula for this
it is dp[i]=dp[i-1]+a[i] for i>=2 for i=1 then dp[i]=a[i] you can call it kindaa base case

so lets code it
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 5;
    int a[5] = {6, 7, 5, 3, 2};
    int dp[n + 1] = {0};
    int i = 0;
    while (i <= n - 1)
    {
        if (i == = 0)
        {
            dp[i] = a[i];
        }
        else
        {
            dp[i] = a[i] + dp[i - 1];
        }
        i++;
    }
    int q = 4;
    int w[4] = {0, 3, 4, 2};
    i = 0;
    while (i <= q - 1)
    {
        int query;
        query = w[i];
        cout << dp[query];
        cout << endl;
        i++;
    }
    return 0;

} // now this was pretty basic but  we have a lot ahead so no worries it wast just to  make you familiar with the field

/*Problem 2
Given an array of integers(positive as well as negative) ,select some elements from this array(select a subset) such that:-
--Sum of those elements is maximum(Sum of the subset is maximum) .
--No two elements in the subset should be consecutive.

Example :- {2,4,6,7,8}

Answer:- {2+6+8=16}*/

/*ok the question is pretty basic you dont need a lot for this question if you have solved the previous question then you can solve this one
 pretyy easily

 now first thing that we want is that sum should be maximum and the selceted numbers should not be consicutive
 so lets create a dp array where dp[i] tell us the maximum sum till index i pretty easy i guess just like last one we can code this
 but the consicutive part is to look for so for that what we will do is dp[1]= array[1] because there is no issue of conscicutive selection
 but dp[2]=array[2] why ?? because we cant have consicutive selection and because of that we need to preintialize the dp[2] also
 but at dp[3] we have choice that is either it will be array[1]+ array[3 ] or it would be maximum sum before it ie dp[i-1] so
 we can generallize a formula dp[i]=max(dp[i-2]+a[i] ,dp[i-1]) now in this question all number are positive okk */

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n + 1] = {0};
    int dp[n + 1] = {0};
    int i = 1;
    while (i <= n)
    {
        cin >> a[i];
        i++;
    }
    int l = 0;
    dp[1] = max(a[1], l);            // i hope this is pretty understanding
    dp[2] = max(a[1], max(a[2], l)); // just pick the max so far

    i = 3;
    while (i <= n)
    {
        dp[i] = max(dp[i - 2] + a[i], dp[i - 1]);
        i++;
    }
    cout << dp[n];
    return 0;
}

/*Problem 3
 It is an ATCoder coding platform problem

 There are
N stones, numbered
1,2,…,N. For each
i (
1≤i≤N), the height of Stone
i is
h
i
​
 .

There is a frog who is initially on Stone
1. He will repeat the following action some number of times to reach Stone
N:

If the frog is currently on Stone
i, jump to Stone
i+1 or Stone
i+2. Here, a cost of
∣h
i
​
 −h
j
​
 ∣ is incurred, where
j is the stone to land on.
Find the minimum possible total cost incurred before the frog reaches Stone
N.*/

/* so lets look at the problem there is a frog that wants to reach stone n each time either it can make a jump of i+1 or i+2 and the cost of the jump is differnce
of the heights of the two stones.
so the first thing we do is create the dp array of size n (well i tend to make it n+1 because i start the array indexing from 1 not 0 so you can adjust as per the use)
so if the frog is on the first stone then how many jumps he need to make the stone 1 -0 because he is already there so dp[1]=0
now if we want for stone 2 then he can only jump from 1 to 2 which is a jump of i+1 so the cost to reach stone 2 will be abs(a[1]-a[2])
now for stone three onward we will have two cases lets see for stone 3
we can reach stone 3 with one jump from 1 to 2 and then one jump from 2 to 3
or we can just directely make jump of i+2 from stone 1 to reach stone3
so we get a generallized formula that is
=>  dp[i]=min(dp[i-1]+abs(a[i]-a[i-1]),dp[i-2]+abs(a[i]-a[i-2]))
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n + 1] = {0};
    int dp[n + 1] = {0};
    while (i <= n)
    {
        cin >> b[i];
        i++;
    }
    dp[1] = 0;
    dp[2] = abs(a[1] - a[2]);
    i = 3;
    while (i <= n)
    {
        dp[i] = min(dp[i - 1] + abs(a[i] - a[i - 1]), dp[i - 2] + abs(a[i] - a[i - 2]));
        i++;
    }
    cout << dp[n];
    return 0;
}

/* this is a varition of the above problem (B-frog2) There are
N stones, numbered
1,2,…,N. For each
i (
1≤i≤N), the height of Stone
i is
h
i
​
 .

There is a frog who is initially on Stone
1. He will repeat the following action some number of times to reach Stone
N:

If the frog is currently on Stone
i, jump to one of the following: Stone
i+1,i+2,…,i+K. Here, a cost of
∣h
i
​
 −h
j
​
 ∣ is incurred, where
j is the stone to land on.
Find the minimum possible total cost incurred before the frog reaches Stone
N.*/
/*hmm so this is the variation of the above problem which can be pretty easily solved just like the
previous one the only differnce here is that we not only can make jumps of i+1 and i+2 but of varios types till i+k
so even for this the base case for stone 1 and stone 2 will remain same of the previous one but therew will be differecne when
it comes down this the varable jump part so since we can jump from i+1 to i+k so
so why not put a loop for this fucntionality
so it looks like j=1 to j=k we will try all the jumps from index i
fromula being=> dp[i]=dp[i-j]+abs(a[i]-a[j])
we will understand better once we see the code
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n + 1] = {0};
    int dp[n + 1] = {0};
    int k;
    cin >> k;
    int i = 1;
    while (i <= n)
    {
        cin >> a[i];
        i++;
    }
    dp[1] = 0;
    dp[2] = abs(a[1] - a[2]);
    i = 3;
    while (i <= n)
    {
        int answer = 1e18;
        int j = 1;
        while (j <= k && i - j >= 1)
        {
            int yy = dp[i - j] + abs(b[i] - b[j]);
            answer = min(answer, yy);
            j++;
        }
        dp[i] = answer;
        i++;
    }
    cout << dp[n];
    return 0;
}

/*
Problem 4
 You are given an array of size “N” ; you have to start your journey at index “1” and you need to end your journey at index “N”.

You can make jumps of size - 1 or 3 or 5

In the array positive as well as negative numbers can be available.

Please find the maximum sum of journey
*/
/*

now similarly to the frog jump one here also we have to go from 1 to n but here we have to add the sum and maximize it
now if you have solved the previous problems and understood them well then this one is going to be too easy for you
so as discussed lets first create a dp array
we can find the dp[1]=a[1] because thats the only way to reach there but what about
dp[2] it would be a[1]+a[2] because a jump of i+1 is only possible to reach there
dp[3] will be a[1]+a[2]+a[3] no other possible way to reach there
now here it gets intresting
the dp[4] we can reach there with a[1]+a[2]+a[3]+a[4] which is nothing but dp[3]+a[4] but we can also reach there with a i+3 jump from index 1 resulting in dp[1]+a[4]
now for dp[5]=>dp[4]+a[5] dp[2]+a[5]

and for index 6 onwards the forumla can be generallized as
max(
dp[i-1]+a[i]
dp[i-3]+a[i]
dp[i-5]+a[i])

lets code it
*/
#include <bits/stdc++.h>
using namesapce std;
int main()
{
    int n;
    cin >> n;
    int b[n + 1] = {0};
    int dp[n + 1] = {0};
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    dp[1] = b[1];
    dp[2] = b[1] + b[2];
    dp[3] = b[1] + b[2] + b[3];
    dp[4] = max(dp[1] + a[4], dp[3] + a[4]);
    dp[5] = max(dp[4] + b[5], dp[2] + b[5]);

    for (int i = 6; i <= n; i++)
    {
        dp[i] = max(dp[i - 1] + a[i], max(dp[i - 3] + a[i], dp[i - 5] + a[i]))
    }
    cout << dp[n] << endl;
    return 0;
}

/*Problem 5

this is an atcoder question c-vacation
Problem Statement
Taro's summer vacation starts tomorrow, and he has decided to make plans for it now.

The vacation consists of
N days. For each
i (
1≤i≤N), Taro will choose one of the following activities and do it on the
i-th day:

A: Swim in the sea. Gain
a
i
​
  points of happiness.
B: Catch bugs in the mountains. Gain
b
i
​
  points of happiness.
C: Do homework at home. Gain
c
i
​
  points of happiness.
As Taro gets bored easily, he cannot do the same activities for two or more consecutive days.

Find the maximum possible total points of happiness that Taro gains.*/

/*so the question is asking us is to get maximum total points that can be achieved that we dont do the same work any two consicutive
days so we can form different combinations but how to get best out of it ,now if like earlier quetion we go for the only one
dp array then there will be a problem that is there are three different choices on every day and before that day we need to make
sure that we pick different work from present day which can not be achived through a single dp array
we have two choices one is to make a 2d dp array with day and the type of work choice or we can just make three different arrays
since it is just the begining i will prefer to use three different array for the job
do lets create three dp arrays dpa ,dpb and dpc telling us the best answe of that day if we chosse that particular type of work

on first day we have only one choice in all the three arrays

dpa[1]=a[1]
dpb[1]=b[1]
dpc[1]=c[1]


now this here now we will derive the formula from day 2 onwards
so lets say on day 2 i decided to do job type of a then
there are two possible answe for dpa[2]=max(a[2]+dpb[1],dpc[1]+a[2]) because job cant be consicutive now similary if we pick job type
b on day 2 and job type c on the second day

lets code it

*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n + 1];
    int b[n + 1];
    int c[n + 1];
    int dpa[n + 1], dpb[n + 1], dpc[n + 1];

    int i = 1;
    while (i <= n)
    {
        cin >> a[i] >> b[i] >> c[i];
        i++;
    }
    dpa[1] = a[1];
    dpb[1] = b[1];
    dpc[1] = c[1];

    i = 2;
    while (i <= n)
    {
        dpa[i] = max(dpb[i - 1] + a[i], dpc[i] + a[i]);
        dpb[i] = max(dpa[i - 1] + b[i], dpc[i] + b[i]);
        dpc[i] = max(dpb[i - 1] + c[i], dpa[i] + c[i]);
    }

    cout << max(dpa[n], max(dpb[n], dpc[n]));
    return 0;
}

/*Problem 6
Find the number of journeys where you start from index 1 and end at index ‘n’ and the sum of every journey should be odd..

Allowed to make jumps of size 1 or 2
*/

/*ok number of journey where we start from index 1  and then we reach the index n then the sum should be odd
now the initial thought that came to my mind was just make an dp array and keep the track of only odd sum that has been achieved
till index i but for some obivous reasons it didnt work why the main reason was  i was keeping track of only odd sum
but what i should have done was to keep the track of both odd and even sum because odd+odd =even and odd+even=odd and even +even=even

now there are two states to deal with at every index i want the even as well as odd sum for that either i just like previous question
i can make two arrays but now we will one up our self and use a 2d array that will have dp[index][evesum/oddsum]

so for index 1 what will happen if the element present there turns out to be even
the dp[1][even]=1 and dp[1][odd]=0

but what if it is odd then
dp[1][even]=0 and dp[1][odd]=1;hmm well good till here now frrom index 2 onwards we will be needing a formula for the

that will be if element is even
then dp[i][even]=dp[i-1][even]+dp[i-2][even] because even +even=even
dp[i][odd]=dp[i-1][odd]+dp[i-2][odd] because even + odd=odd

now if it is odd then
dp[i][even]=dp[i-1][odd]+dp[i-2][odd]  because odd + odd =even
dp[i][odd]=dp[i-1][even]+dp[i-2][even] because odd +even =odd

okk now lets code it


*/

#include <bits/stdc++.h>

using namespace std;
int dp[100005][3];
int main()
{
    int n;
    cin >> n;
    int a[n + 1] = {0};
    int i = 1;
    while (i <= n)
    {
        cin >> a[i];
        i++;
    }

    // dp[i][1]--> number of journeys till index 'i' whose sumis odd.
    // dp[i][2]--> number of journeys till index 'i' whose sumis even.

    if (a[1] % 2 == 0)
    {
        dp[1][2] = 1;
    }

    else
    {
        dp[1][1] = 1;
    }

    i = 2;
    while (i <= n)
    {
        if (a[i] % 2 == 0)
        {
            dp[i][2] = dp[i - 1][2] + dp[i - 2][2];
            dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
        }

        else
        {
            dp[i][2] = dp[i - 1][1] + dp[i - 2][1];
            dp[i][1] = dp[i - 1][2] + dp[i - 2][2];
        }
        i++;
    }

    cout << dp[n][1] << " " << dp[n][2];

    return 0;
}

/*Problem 7
Given an integer “N” ; find the minimum cost to reduce it to 1
The operations you can do are as follows.->

i) Reduce the number by 1 in “y” dollars;

ii) Reduce the number by /7 in “x” dollars.(if number is divisible by 7)

iii) Reduce the number by /3 in “z” dollars;(if number is divisible by 3)

iv) Reduce the number by /5 in “b” dollars;(if number is divisible by 5)
*/

/*
okk we need to reduce and integer n to 1 and there are certain operetaion that can be performed over these hmm why so
if we have some n then if reuce it by 1 then it will cost y dollars but since we are using dp this n-1 would have already been computed
in our dp so dp[n]=dp[n-1]+y  now similarly if n%7=0 then we can divide the n to reduce it to 1 but what about the previous cost
that can be simply obtained by dp[n/7]+x and similaray for 3 and five so now lets code this one*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int dp[n + 1] = {0};
    int y, x, z, b;
    cin >> y >> x >> z >> b;
    dp[1] = 0; // no cost to reduce 1 to 1

    // now the main part
    int i = 2;
    while (i <= n)
    {
        int v1 = dp[i - 1] + y;
        int v2 = 1e18;
        int v2 = 1e18;
        int v3 = 1e18;
        if (i % 7 == 0)
        {
            v3 = dp[i / 7] + x;
        }
        if (i % 3 == 0)
        {
            v2 = dp[i / 3] + z;
        }
        if (i % 5 == 0)
        {
            v1 = dp[i / 5] + b;
        }
        dp[i]=min(v1,min(v2,min(v3,v4)));
        i++;
    }
    cout<<dp[n];
    return 0;
}


/*Problem 8
You are given a positive integer 'N’. Your task is to find and return the minimum number of steps that 'N' has to take to get reduced to 1. 
You can perform any one of the following 3 steps:
If the number is even you can divide it by 2. 
If the number is odd you can do +1 or -1 
*/


/*now here what want to highlight is that these type of question are more focused on observation then tecanhique 
beacuse the first look the problem is straight up easy 
see if then number is even divide by 2 and the previous state can be calculated from dp 
even when we subtarct one the the previous state can be found from the dp but what when we add 1 i mean to 
say dp[i/2] we precalculated
dp[i-1] precalculted but how to find dp[i+1] the problem gets stuck 
but if you make an observatrion that since when the number is odd then only we need dp[i+1] now odd next will be even so since it would be
even we can get the state through dp[(i+1)/2] see observation nothing tough but for this observation you have to sit 45 min with pen and paper 

and one  more thing when ever you are doing i+1 operation it will be two steps on to move i+1 and other (i+1)/2 okk

*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n=5;
    int dp[n+1]={0};
    dp[1]=0;
    int i=2;
    while(i<=n){
        if(i%2==0){
            dp[i]=dp[i/2]+1;
        }
        else{
            dp[i]=min(dp[i-1]+1 ,dp[(i+1)/2]+2);
        }
        i++;
    }
    cout<<dp[n];
    return 0;
}

/*Problem 9
An array of costs was given. 
You always start at index 1. 
You can either take two jumps forward or one jump backward. If you land on a particular index, you have to add the cost to your total. 
Find the minimum cost needed to cross the array or reach the end of the array.
You can visit any index for only 1 time. 

b = [ 2 5 8 ] 
*/

/*i will need some time to work on this will update it soon */




/*Problem 10
 You are given 2 arrays ; travel from start to end; maximum maximum dollars  
 whenever you try to jump from Array “A” to Array “B” you make no money  
*/

/*

dp[i] = best answer to the question if the size of array was “i” 
-> we really need information at ith index whether we have take element from array A or B   

-> dp[i][a] = best answer to the question if size of both array were “i” and the element picked at the ith index if for sure from array “a”

-> dp[i][b] = best answer to the question if size of both array were i and element picked at ith index is from B

dp[i][a] = max(a[i] + dp[i-1][a] Or a[i] + dp[i-2][b]) 

dp[i][b] = max(b[i] + dp[i-1][b] or b[i] + dp[i-2][a]) 
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll ; 
ll dp[100005][2];
int main() {
    
    ll n ; 
    cin>>n ; 
    ll a[n+1]={0};
    ll b[n+1]={0};
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=1;i<=n;i++){
        cin>>b[i];
    }
    
    dp[1][0] = a[1]; //dp[1][a]=dp[1][0]
    dp[1][1] = b[1]; //dp[1][b]=dp[1][1]
    
    for(ll i=2;i<=n;i++){
        dp[i][0] = max(dp[i-1][0] + a[i],dp[i-2][1] + a[i]);
        //cout<<dp[i][0]<<'\n';
        dp[i][1] = max(dp[i-1][1] + b[i],dp[i-2][0] + b[i]);
    }
    
    cout<<dp[n][0]<<" "<<dp[n][1];
    
    return 0 ; 
}