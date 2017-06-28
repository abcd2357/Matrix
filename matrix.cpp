#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#define MAX_SIZE 100  //矩阵的最大规模

int main()
{   double a[MAX_SIZE][MAX_SIZE],p[MAX_SIZE][MAX_SIZE],c[MAX_SIZE][MAX_SIZE],q[MAX_SIZE][MAX_SIZE],d[MAX_SIZE][MAX_SIZE];
    int i,j,x,y,n,k,U;
    double s=1.0,T,R;
    
    cout << "\n输入方阵q的行数：(友情提示：请自动四舍五入答案)";
    cin >> n;
    
    cout << "\n输入A:\n";
    for (i=0; i< n; ++i)
        for (j=0; j < n; ++j)  {
	          cout << "q[" << i+1 << "][" << j+1 << "] = ";
	          cin >> q[i][j];
	          a[i][j]=q[i][j];
                               }
    cout << "\n输出q:";
    for (i=0; i < n; ++i) {
              cout << endl;
        for (j=0; j< n; ++j)  cout << q[i][j] << '\t';
                          }

    //Det----------------------------------------------------------
    T=q[0][1];
    for(i=0;i<n;++i){q[i][1]=q[i][1]-(T*q[i][0]*1.0/q[0][0]);};

    for(j=2;j<n;++j){
        for(k=0;k<j;++k){
             R=(q[k][j]*1.0/(q[k][k]*1.0));
             for(i=0;i<n;++i){q[i][j]=q[i][j]-(R*q[i][k]);};
                        }
                    }
    
    for(i=0;i<n;++i){s*=q[i][i];};
    
    cout<<endl;
    cout<<"\ndet="<<s<<endl;

    //伴随矩阵------------------------------------------------------
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
           U=i+j+2;
           x=i,y=j;
           double S=1.0;
             
            {int i,j;

             for(i=0;i<n;++i){
              for(j=0;j<n;++j){
                  if(i>x&&j>y){d[i-1][j-1]=a[i][j];}
                    else if(i>x&&j<y){d[i-1][j]=a[i][j];}
                       else if(i<x&&j>y){d[i][j-1]=a[i][j];}
                          else if(i<x&&j<y){d[i][j]=a[i][j];}
                            else;}                                
                             }
            }

            {int i,j;

            T=d[0][1];
             for(i=0;i<n-1;++i){if(d[0][0]==0){d[0][0]=0.00001;};
             d[i][1]=d[i][1]-(T*d[i][0]*1.0/d[0][0]);};

             for(j=2;j<n-1;++j){
                for(k=0;k<j;++k){if(d[k][k]==0){d[k][k]=0.00001;};
                    R=(d[k][j]*1.0/(d[k][k]*1.0));
                     for(i=0;i<n-1;++i){d[i][j]=d[i][j]-(R*d[i][k]);};
                                }
                               }
            }
            

            {int i;
            for(i=0;i<n-1;++i){S*=d[i][i];};
            }
             
            c[i][j]=pow((-1),U)*S;

          }
       }


    for(j=1;j<n;++j){
        for(i=0;i<j;++i){
                p[i][j]=c[i][j];
                c[i][j]=c[j][i];
                c[j][i]=p[i][j];
                        }
                    }

    cout << "\n输出伴随矩阵:";
    for (i=0; i < n; ++i) {
              cout << endl;
        for (j=0; j< n; ++j)  cout << setprecision(2) << fixed << c[i][j] << '\t';
    }

     cout <<endl<< "\n输出逆矩阵="<<"1/"<<s<<"*";
        for (i=0; i < n; ++i) {
              cout << endl;
        for (j=0; j< n; ++j)  cout << setprecision(2) << fixed << c[i][j] << '\t';
    }
    return 0;
}

