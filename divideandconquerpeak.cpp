#include <bits/stdc++.h> 
#include <time.h>
#define MAX 1000  
using namespace std; 

clock_t begin, end;  
double time_;
int** matrix_allocate(int n,int m) 
{
  int i, j;
  int** mat = (int** ) malloc(n * sizeof(int* ));
  for (i = 0; i < n; ++i) 
  {
          mat[i] = (int* ) malloc(m * sizeof(int));
  }
  return mat;
}

int Max(int **mat,int r,int mid,int& max)
{

int ind=0;
	for (int i = 0; i < r; i++) 
	{ 
        if (max < mat[i][mid]) 
		{ 
            max = mat[i][mid]; 
            ind = i; 
        } 
    }
    return ind;
}
int Peak(int **mat, int r, int c, int mid) 
{ 
    int max = 0; 
    int ind = Max(mat, r, mid, max); 

	
	//cout<<"ind"<<max; 
	 if (mid == 0 || mid == c - 1) 
        return max; 
    
    if (max >= mat[ind][mid - 1] && max >= mat[ind][mid + 1]) 
        return max; 
  
    // If max is less than its left 
    if (max < mat[ind][mid - 1])
	{
		if(mid - ceil((double)mid / 2) >=0)
		return Peak(mat, r, c, mid - ceil((double)mid / 2)); 
		else
		return Peak(mat, r, c, 0);
	}
    
   // if (max < mat[ind][mid+1]) 			//If max is less than its right
  	 if(mid + ceil((double)mid / 2) <= c-1)
		return Peak(mat, r, c, mid + ceil((double)mid / 2)); 
	else
		return Peak(mat, r, c, c-1);
} 
  

int main() 
{
		int r,c;
		printf("Enter rows and columns:");
		cin>>r>>c;
		int** mat = matrix_allocate(r,c);
		printf("\nEnter matrix elements:");
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				cin>>mat[i][j];
			}
		}
		int mid=c/2;
		begin = clock();
   		cout << "\n\nFirst Peak element is : "<<Peak(mat, r, c,mid); 
		end = clock();
		time_= ((double)(end-begin)) / CLOCKS_PER_SEC;
		cout<<"\nTime taken :"<<time_;
	
    return 0; 
}

/* input= 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
 
input=
1 2 3 4 5 6 7
2 3 4 5 6 7 8
3 4 5 6 7 8 9
4 5 6 7 8 9 10
6 7 8 9 10 11 12
7 8 9 10 11 12 13
8 9 10 11 12 13 14
*/
