#include <bits/stdc++.h>
using namespace std;


int max(int a, int b) { 
    if (a > b) 
      return a;
    return b;
}

void print_array(vector<int>& result){
    for (int item : result)
        cout << item << "\t";
    cout << endl;
}


vector<int> knapSack(int capacity, vector<int> wt, vector<int> val, int n)
{
    vector<vector<int> > K(n + 1, vector<int>(capacity + 1));
    vector<int> items;

    //main part
    for (int i = 0; i <= n; i++) 
        for (int w = 0; w <= capacity; w++)  {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (w >= wt[i - 1])
                K[i][w] = max(  (val[i-1]+ K[i-1][w-wt[i-1]]) , K[i-1][w]  );   //this is given formula
            else
                K[i][w] = K[i - 1][w];
        }

    //K[n][capacity] has max profit now
    
    cout<<"-----------------------------\nMax profit =  "<<K[n][capacity]<<endl;

    int w = capacity;
    for (int i = n; i > 0 && w > 0; i--)
        if (K[i][w] != K[i - 1][w]) {
            items.push_back(i); 
            w -= wt[i - 1];
        }
    return items;
}


int main(){
    vector<int> profit = { 6, 10, 12, 7, 5 };
    vector<int> weight = { 3, 4, 5, 2, 1 };
    int capacity = 10;
    int n = sizeof(profit) / sizeof(profit[0]);

    cout<<"Profit =  ";
    print_array(profit);
    cout<<"Weight =  ";
    print_array(weight);
    cout<<"Capacity = "<<capacity<<endl;
    
    vector<int>result= knapSack(capacity, weight, profit, n); 
    
    cout<<"Items =  ";
    print_array(result);
    return 0;
}