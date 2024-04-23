#include<iostream>
#include<climits>
using namespace std;

class OBST{
    int n = 4;
    double w[4 + 1][4 + 1];
    double c[4 + 1][4 + 1];
    int r[4 + 1][4 + 1];

    public:
    OBST(){
       for(int i = 0; i < n + 1; i++){
        r[i][i] = 0;
       } 
    }

    void getdata()
    {

    }

    void weightCalculate(double pfreq[], double qfreq[])
    {
        for(int i = 0; i < n + 1; i++)
        {
            for(int j = i; j < n + 1; j++)
            {
                if(i == j)
                {
                    w[i][j] = qfreq[j];
                }
                else
                {
                    w[i][j] = w[i][j - 1] + pfreq[j] + qfreq[j];
                }
            }
        }
    }

    void costCalculate()
    {
        for(int l = n; l >= 0; l--)
        {
            for(int i = 0, j = n - l; i <= l , j < n + 1; i++, j++)
            {
                if(i == j)
                {
                    c[i][j] = 0;
                }
                else
                {
                    int costMin = INT_MAX;
                    for(int k = i + 1; k < j + 1; k++)
                    {
                        int cost = c[i][k - 1] + c[k][j];
                        
                        if(cost < costMin)
                        {
                            costMin = cost;
                            r[i][j] = k;
                        }                        
                    }
                    c[i][j] = double(costMin) + w[i][j];
                }                
            }
        }
    }

    void displayTree(int key[],int a,int b)
    {   int k = r[a][b];
        if(k == 0)
        {
            return;
        }
        cout << key[r[a][b]] << " ";
        displayTree(key,a,k - 1);
        displayTree(key,k,b);
    }

    void OBST_Cost()
    {
        cout << "Optimal Tree Cost is = " << c[0][n] << endl;
    }
};

int main()
{
    OBST obj;
    int n = 4;
    int key[n + 1] = {0,10,20,30,40};
    double pfreq[n + 1] = {0,3,3,1,1};
    double qfreq[n + 1] = {2,3,1,1,1};

    obj.weightCalculate(pfreq, qfreq);
    obj.costCalculate();
    obj.OBST_Cost();
    obj.displayTree(key,0,4);
    return 0;
}

