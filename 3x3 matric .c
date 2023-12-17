#include<stdio.h>
#include<stdlib.h>
 
int main(){
 
  int a[3][3], i, j;

  long determinant;
  
///////////////////////***////////////////////////////// Enter matrix
  
  printf("Enter the 9 elements of matrix: ");
  for(i = 0 ;i < 3;i++)
      for(j = 0;j < 3;j++)
           scanf("%d", &a[i][j]);
           
///////////////////////***////////////////////////////// Print matrix
 
  printf("\nThe matrix is\n");
  for(i = 0;i < 3; i++){
      printf("\n");
      for(j = 0;j < 3; j++)
           printf("%d\t", a[i][j]);
  }
  
///////////////////////***////////////////////////////// Calculate determinant  
 
  determinant = a[0][0] * ((a[1][1]*a[2][2]) - (a[2][1]*a[1][2])) -a[0][1] * (a[1][0]
   * a[2][2] - a[2][0] * a[1][2]) + a[0][2] * (a[1][0] * a[2][1] - a[2][0] * a[1][1]);
 
///////////////////////***////////////////////////////// Print determinant 
 
  printf("\nDeterminant of 3X3 matrix: %ld\n", determinant);
  
///////////////////////***////////////////////////////// Calculate trace    
  
  long p;
  p = a[0][0] + a[1][1] + a[2][2];
  printf("The P in A^3 - PA^2 + QA + Det(matrix a) = %d\n", p);
  
///////////////////////***////////////////////////////// Calculate 2x2 matrix of the diagonal elements    
  
  long q;
  q = ((a[1][1] * a[2][2])-(a[1][2] * a[2][1])) + ((a[0][0] * a[2][2])-(a[0][2]*a[2][0])) + ((a[0][0]*a[1][1])-(a[0][1]*a[1][0]));
  printf("The Q in A^3 - PA^2 + QA + Det(matrix a) = %d\n", q);
  
  float eigenvalue[5];
  long factor[100];
  int count=-1, n;

///////////////////////***////////////////////////////// Calculate factor of the determinant

for(i=1; i <= determinant; i++){
	if(determinant % i == 0){
		count++;
		factor[count] = i;
		count++;
		factor[count] = -i;
	}	
}

///////////////////////***////////////////////////////// Print the factor of the determinant

printf("The factors of determinant are : \n");
for(j=0; j<=count; j++){
	printf("%d  ", factor[j]);
}

printf("\n");

for(i=count+1; i<=2*count+1; i++){
	factor[i] = -factor[i-count-1];
}

for(i=0; i <= 2*count+1; i++){
	printf("%d ", factor[i]);
}

int k;
for(i=0; i <= 2*count+1; i++){
	
	for(j=0; j <= 2*count+1; j++){
		
		for(k=0; k <= 2*count+1; k++){
			
			if(factor[i] + factor[j] + factor[k] == p){
				
				eigenvalue[0] = factor[i];
				eigenvalue[1] = factor[j];
				eigenvalue[2] = factor[k];
			}
			
		}
	
	}
	
}



printf("The EigenValues are : \n");

for(i=0; i<3; i++){
	printf("%.2f , ", eigenvalue[i]);
}






}
