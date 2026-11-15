#include <string>
#include "word-by-word.h"
using namespace std;
string solve(){
	string rasp;
	char rf[6];
	int cd[10];
	cd[0]=0;
	cd[5]=26;
	for(int i=1;i<=25;i+=5){
		string q;
		for(int j=i;j<i+5;j++){
			q+='a'+j-1;
		}
		q=guess(q);
		for(int j=1;j<=5;j++){
			if(q[j-1]!='W'){
				cd[0]++;
				cd[cd[0]]=i+j-1;
			}
		}
	}
	for(int i=1;i<=5;i++){
		rf[i]='a'+cd[5]-1;
	}
	if(cd[0]==5){
		cd[0]=4;
	}
	for(int i=1;i<=cd[0];i++){
		string q;
		for(int j=1;j<=5;j++){
			q+='a'+cd[i]-1;
		}
		q=guess(q);
		for(int j=1;j<=5;j++){
			if(q[j-1]=='G'){
				rf[j]='a'+cd[i]-1;
			}
		}
	}
	for(int i=1;i<=5;i++){
		rasp+=rf[i];
	}
	return rasp;
}
