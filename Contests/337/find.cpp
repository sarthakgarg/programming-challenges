#include<stdio.h>
#include"iostream"
#include<string.h>
using namespace std;
int main(){
	char course[200][30], cse[200][30], name[40];
	int n, m, i=0, j=0;
	while(1){
		scanf("%s", name);
		strcat(name, ",");
		if(strcmp(name, "demark,") == 0) break;
		strcpy(course[i++], name);
	}
	while(1){
		scanf("%s", name);
		if(strcmp(name, "end") == 0) break;
		strcpy(cse[j++], name);
	}
	int ct = 0;
	for(int k = 0; k < j; k++){
		for(int l = 0; l < i; l++){
			if(strcmp(cse[k], course[l]) == 0){
				cout << cse[k] << "\n";
				ct++;
				break;
			}
		}
	}
	cout << ct << "\n";
	return 0;
}