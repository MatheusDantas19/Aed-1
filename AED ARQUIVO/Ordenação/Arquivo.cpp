#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <string>

using namespace std;

typedef struct par{
	int a,b;

}par;


int main(){
	int **p=new int*[10];
	for (int i = 0; i < 10; i++)
	{
		p[i]=new int[10];
	}
	string z;
	char* b = (char* )malloc(sizeof(char)*2);
	char* c = (char* )malloc(sizeof(char)*2);
	//strcpy(b,c,sizeof(char)*2)
	c[0]='1';
	c[1]='2';
	for (int i = 0; i < 2; ++i)
	{
		cout<<c[i];
	}
	cout<<"\n";
	strcpy(b,c);
	for (int i = 0; i < 2; ++i)
	{
		z+=b[i];
	}
	int x=atoi(z.c_str());
	cout<<z<<endl;
	cout<<"/"<<x<<"/"<<endl;
	//scanf("%s", b);
	//int a = atoi(b);



}


	/*int **m;
	m=(int**)malloc(sizeof(int*)*10);
	for (int i = 0; i < 10; i++){
		m[i]=(int*)malloc(sizeof(int)*10);
	}

	for (int i = 0; i < 10; i++){
		for(int j=0; j<10;j++){
			//m[i][j]=i+j;
			*(*(m+i)+j);
		}
	}
	for (int i = 0; i < 10; i++){
		for(int j=0; j<10;j++){
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}*/
	