#include<iostream>
#include<ctime>
using namespace std;
int linearSearch(int a[10], int s);
int RlinearSearch(int a[10], int s,int i);
int main(){
    int a[10];
    int n;
    cout <<" Enter the Number of Elements:";
    cin >>n;
    for(int i=0;i<n;i++)
    {
        a[i]=i;
    }
    int s;
    cout <<"Enter the Element to be searched:";
    cin >>s;
    clock_t start = clock();
    int result = linearSearch(a,s);
    clock_t end = clock();
    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken: " << duration << " seconds" << endl;
    start = clock();
    result = RlinearSearch(a,s,0);
    end = clock();
    duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken: " << duration << " seconds" << endl;
    
    start = clock();
    result = binarySearch(a,0,10,s);
    end = clock();
    duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken: " << duration << " seconds" << endl;
    
    start = clock();
    result = RbinarySearch(a,0,10,s);
    end = clock();
    duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken: " << duration << " seconds" << endl;
}

int linearSearch(int a[10], int s)
{
    for(int i=0;i<10;i++)
    {
        if(a[i]==s)
        {
            return i;
        }
    }
    return -1;
}

int RlinearSearch(int a[10], int s,int i)
{
    if(i>10)
    {
        return -1;
    }
    if(a[i]==s)
    {
        return i;
    }
    else
    {
        return RlinearSearch(a,s,i+1);
    }
}

int binarySearch(int a[10], int l, int h, int s)
{
    while(h>=l)
    {
        int m= (l + h)/2;
        if(a[m]==s)
        {
            return m;
        }
        if(a[m]>s)
        {
            h=m-1;
        }
        if(a[m]<s)
        {
            l=m+1;
        }
    }
    return -1;
} 

int RbinarySearch(int a[10], int l, int h, int s)
{
    if(h>=l)
    {
        int mid = (l+h)/2;
        if(a[mid]==s)
        {
            return mid;
        }
        else if(a[mid] > s)
        {
            return RbinarySearch(a,l,mid-1,s);
        }
        return RbinarySearch(a,mid+1,h,s);
    }
    return -1;
}
