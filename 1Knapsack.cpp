#include<iostream>
using namespace std;
int main()
{
    int weight[10], profit[10];
    int n;
    cout << "Enter Number of items:";    
    cin >> n;
    for (int i = 0; i <n; i++)
    {
        cout <<"Enter the Weight of the item"<<i<<":";
        cin >> weight[i];
        cout << "Profit of the item"<<i<<":";
        cin >> profit[i];
    }
    
    for(int i = 0; i < n; i++)
    {
        int max=i;
        for(int j = i; j < n; j++)
        {
            if(profit[i]/weight[i] < profit[j]/weight[j])
            {
                max = j;
            }
        }
        swap(profit[i], profit[max]);
        swap(weight[i], weight[max]);
    }
     cout << "The Array is ";
    for (int i = 0; i <n; i++)
    {
       cout<<profit[i]<<"   "<<weight[i]<<endl;   
    }

}