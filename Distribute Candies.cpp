
// Shaky has N (1<=N<=50000) candy boxes each of them contains a non-zero number of candies (between 1 and 1000000000). Shaky want to distibute these candies among his K (1<=K<=1000000000) IIIT-Delhi students. He want to distibute them in a way such that:
// 1. All students get equal number of candies.
// 2. All the candies which a student get must be from a single box only.
// As he want to make all of them happy so he want to give as many candies as possible. Help Shaky in finding out what is the maximum number of candies which a student can get.
// Input
// First line contains 1<=T<=20 the number of test cases. Then T test cases follow. First line of each test case contains N and K. Next line contains N integers, ith of which is the number of candies in ith box.
// Output
// For each test case print the required answer in a seperate line.
// Sample Input:
// 2
// 3 2 
// 3 1 4
// 4 1
// 3 2 3 9
// Sample Output:
// 3
// 9

#include<bits/stdc++.h>
using namespace std;

void check(long long arr[],long long left,long long right,long long n,long long k,long long temp)
{
    long long mid=left+(right-left)/2, count=0;
    // cout<< left<<" "<<mid<<" "<< right<<" | ";
    if(left<=right)
    {
        for(long long i=0;i<n;i++)
        {
            if(arr[i]/mid>=0)
            {
                count+=(arr[i]/mid);
            }
        }
        if(count>=k)
        {
            temp=mid;
            check(arr, mid+1, right, n, k, temp);
        }
        else
        {
            check(arr, left, mid-1, n, k,temp);
        }
    }
    if(left>right){
        cout<<temp<<endl;
        }

}

int main()
{
    long long t,n,k;
    cin>>t;

    while(t--)
    {
        cin>>n>>k;
        long long arr[n],left,right;
        for(long long i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        sort(arr,arr+n);
        left=0;
        right=arr[n-1];
        if(k==1)
        {
            cout<<right<<endl;
        }
        else
            check(arr, left, right, n, k, 0);
    }
}
