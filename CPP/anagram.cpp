#include<iostream>
using namespace std;

string anagram(string s1, string s2){
	int n1 = s1.length();
	int n2 = s2.length();
	if(n1!=n2){
		return "NO";
	}
	int arr[26] = {0};
	for(int i=0;i<n1;i++){
		arr[s1[i]-'a']++;
	}
	for(int i=0;i<n2;i++){
		if(arr[s2[i]-'a']==0){
			return "NO";
		}
		arr[s2[i]-'a']--;
	}
	return "YES";
}

int main(){
	string s1,s2;
	s1 = "hello";
	s2 = "olehl";
	cout<<anagram(s1,s2);
}
