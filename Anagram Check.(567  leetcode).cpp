// C++ program to search all anagrams of a pattern in a text
#include<iostream>
using namespace std;
 bool AreSame(int countS1[],int countS2[])
        {
        for(int i=0;i<26;i++)
        {
            if(countS1[i]!=countS2[i])
            {  // cout<<countS1[i]<<" "<<countS2[i]<<" In aresame \n";
                return false;
            }
           // cout<<countS1[i]<<" "<<countS2[i]<<" if same count \n";
        }
        return true;
            
        }        

    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())
            return false;
        //cout<<s1.length()<<" "<<s2.length()<<"length \n";
        int countS1[26]={0};
        int countS2[26]={0};
        for(int i=0;i<s1.length();i++)
        {
            countS1[s1[i]-'a']++;
            countS2[s2[i]-'a']++;
            //cout<<s1[i]<<countS1[s1[i]-'a']<<" "<<s2[i]<<countS2[s2[i]-'a']<<" Intitial \n";
        }
        for(int i=s1.length();i<s2.length();i++)
        {
            if(AreSame(countS1,countS2))
                return true;
            countS2[s2[i]-'a']++;
            countS2[s2[i-s1.length()]-'a']--;
        }
        if(AreSame(countS1,countS2))//Explicitly checking the last condition as the above loop does not do that
        return true;
        
		return false;
    }
int main()
{
	cout<<checkInclusion("ad","cda");
	return 0;
}
