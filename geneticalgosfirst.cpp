//GA program for cognitive science
#include<iostream>
using namespace std;
int main()
{
	//creating a parent chromosome array
	//and filling it with random numbers till 50
	int parent[100][4];
	int fitness[100];
	int crossover[100][4];
	
	//looping for 100 thousand times
	for(int l=0;l<100000;l++)
	{
	for (int i=0;i<100;i++)
	{
		for(int j=0;j<4;j++)
		{
			parent[i][j] = rand()% 50;
		}
	}
	//calculating the absolute of w3+x3 and y3+z3
	for(int a=0;a<100;a++)
	{
		int l= parent[a][0]*parent[a][0]*parent[a][0]+parent[a][1]*parent[a][1]*parent[a][1];
		int m= parent[a][2]*parent[a][2]*parent[a][2]+parent[a][3]*parent[a][3]*parent[a][3];
		fitness[a]=abs(l-m);
		}
	//finding the chromosome with fitness = 0;
	for(int a=0;a<100;a++)
	{
		if(fitness[a]==0)
		{	
			if(parent[a][0]==parent[a][1]==parent[a][2]==parent[a][3] || 
			(parent[a][0]==parent[a][3] && parent[a][1]==parent[a][2]) || 
			(parent[a][0]==parent[a][2] && parent[a][1]==parent[a][3]))
			{
				//cout<<"No right fit\n";
			}
			else
			{
				int x=0;
				x++;
				cout<<"fitness is 0 at\t"<<a<<" and\n";
				cout<<"correspoding array is: "<<parent[a][0]<<" "<<parent[a][1]<<" "<<parent[a][2]<<" "<<parent[a][3]<<"\n";
			}
		}
	}
	//crossover the population
	for(int k=0;k<49;k++)
	{
		int cross = rand() % 100 + 50;
		crossover[k][0]=parent[k][0];
		crossover[k][1]=parent[k][1];
		crossover[k][2]=parent[cross][2];
		crossover[k][3]=parent[cross][3];
		crossover[cross][0]=parent[cross][0];
		crossover[cross][1]=parent[cross][1];
		crossover[cross][2]=parent[k][2];
		crossover[cross][3]=parent[k][3];

	}
	getchar();
}
}