//Funtion to find anagram O(n).
#include<iostream>
using namespace std;
bool anagram(string s1,string s2)
{
	//Check the length of string if not same directly return false
	if(s1.length()!=s2.length())
	{
	return false;
	}
	int count[256]={0};//Initializing a array to store the counts of the char.(0-255)
	//Traversing through 1st string and storing its char counts as ascii values
		for(int i=0;i<s1.length();i++)
	{
		 count[s1[i]]++;
		 cout<<s1[i]<<count[s1[i]]<<"\n";
	}
	//Traversing the second string and decrementing the count of char.
	for(int j=0;j<s2.length();j++)
	{
		count[s2[j]]--;
		cout<<s2[j]<<count[s2[j]]<<" S2\n";
	}
	//Finally checking that the count for each char. should be zero
	for(int i=0;i<256;i++)
	{
		if(count[i]!=0)
		return false;
	}
	return true;
}
//Driver code
int main()
{
	string s1="abbbcc";
	string s2="abbabc";
	if(anagram(s1,s2))
	cout<<"anagram\n";
	else
	cout<<"Not anagram\n";
	return 0;
}
