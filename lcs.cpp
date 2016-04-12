#include<fstream>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<iomanip>
using namespace std;
int i,j,m,n,a,c[100][100];
char x[100],y[100],b[100][100];

 int max(int a, int b)
{
    return (a > b)? a : b;
}

int lcs( char *X, char *Y, int m, int n )
{
   if (m == 0 || n == 0)
     return 0;
   if (X[m-1] == Y[n-1])
     return 1 + lcs(X, Y, m-1, n-1);
   else
     return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}
 


void print_lcs(int i,int j)
{
                if(i==0 || j==0)
                    return ;
                if(b[i][j]=='c')
                {
                     print_lcs(i-1,j-1);
                     printf(" %c",x[i-1]);
                }
                else if(b[i][j]=='u')
                      print_lcs(i-1,j);
                else
                      print_lcs(i,j-1);
}
void lcs_length()
{
            m=n;
	          for(i=0;i<=m;i++)
            	c[i][0]=0;
                for(i=0;i<=n;i++)
                c[0][i]=0;
                for(i=1;i<=m;i++)
                    for(j=1;j<=n;j++)
                        {
                           if(x[i-1]==y[j-1])
                           {
                                c[i][j]=c[i-1][j-1]+1;
                                b[i][j]='c';
                           }
                           else if(c[i-1][j]>=c[i][j-1])
                           {
                                c[i][j]=c[i-1][j];
                                b[i][j]='u';
                           }
                           else
                           {
                                c[i][j]=c[i][j-1];
                                b[i][j]='l';
                           }
                        }
                 print_lcs(m,n);
                
 }
int main()
{ 	
	double str,end,str1,end1;
	int k;
	ifstream  f("input1.txt");
	ofstream f1("output1.txt");
	unsigned int sval;
	time_t t;
	sval=(unsigned)time(&t);
	srand(sval);
	for(k=0;k<3;k++)
	{
	
	f>>n;
		for(i=0;i<n;i++)	
				{
					m=rand()%10+65;
					 x[i]=(char)m;
				
				}
					cout<<x<<endl;
			for(i=0;i<n;i++)	
				{
					m=rand()%10+65;
					 y[i]=(char)m;
					
				}
			cout<<y<<endl;
		
				str1=clock();
				lcs_length();
				end1=clock();
				m=n;				
				cout<<endl;
				if(k==0)
				{
				
					f1<<"X-sequence"<<setw(25)<<"Y-sequence"<<setw(25)<<"LCS Length"<<"\t"<<setw(25)<<"Time for Dynamic"<<setw(25)
					<<"Time for Brute"<<endl;
					f1<<"*************************************************************************************************************"<<endl;
			    }
					
			
					f1<<x<<right<<setw(25)<<y<<right<<setw(25);
					str=clock();
					f1<<lcs( x, y, m, n )<<right<<setw(30);
					end=clock();
					f1<<(end1-str1)/CLOCKS_PER_SEC<<right<<setw(15)<<(end-str)/CLOCKS_PER_SEC<<endl;
					
		}
					f1<<"************************************************************************************************************"<<endl;
		return 0;
            
}
