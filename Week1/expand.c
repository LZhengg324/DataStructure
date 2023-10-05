#include<stdio.h>
#include<string.h> 
#include<ctype.h>
int judge(char a, char b)
{
	int ret;
	if (((isdigit(a) && isdigit(b)) || (islower(a) && islower(b)) || (isupper(a) && isupper(b))) && (b-a)>1){
	ret = 1;
	} else {
	ret = 0;
	}
	return ret;
}
int main() 
{
	char s[10001];
	char a[10001];
	int i, j;
	int cnt;
	scanf("%s", s);
	for (i = 1; s[i] != '\0'; i++){ 
		if (s[i] == '-' && (judge(s[i - 1], s[i + 1]) == 1)){
			cnt = s[i + 1]-s[i - 1];
			strcpy(a, &s[i + 2]);
			for (j = i; cnt>0; j++){
				s[j] = s[j - 1] + 1;
				s[j + 1] = '\0';
				cnt--;
			 }
			strcat(s, a);
		} else if (s[i] == '-' && (s[i + 1] - s[i - 1] == 1)){
			strcpy(a, &s[i + 1]);
			s[i] = '\0';
			strcat(s, a);
		}
	}
	printf("%s", s);
	return 0;
}
