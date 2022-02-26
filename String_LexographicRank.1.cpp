//Find the lexographic Rank of a given string. O(n).
#include<iostream>
using namespace std;
int fact(int n) //Factorial Recursive funtion.
{	
	if(n==0)
	{
		return 1;
	}
	return fact(n-1)*n;
}
//lexographic Rank calculating function
int lexo_rank(string str)
{
	int n=str.length();
	int mul=fact(n);
	int count[256]={0};
	int rank =0;
	for(int i=0;i<str.length();i++)//Calculating frequency of each character
	{
		count[str[i]]++;
	}
	for(int i=0;i<256;i++)
	{
		count[i]=count[i]+count[i-1];//Calculating cumulative frequency
	}
	for(int i=0;i<str.length();i++)
	{
		mul=mul/(n-i);
		rank=rank+(count[str[i]-1]*mul);
		for(int j=str[i];j<256;j++)//decreasing the count from character from the greater character;
		{						   //string we do not consider "s" again when we are at "t" 
									//so we delete the count for t by one.
			count[j]--;
		}
	}
	return rank+1;
}

//Driver code
int main()
{
	cout<<lexo_rank("string")<<"\n";
	//cout<<fact(6);
	return 0;
}

