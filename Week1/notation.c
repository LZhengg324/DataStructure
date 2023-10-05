#include<stdio.h>
#include<string.h>
int main()
{
	char s[10001]; 
	char a[10001];   
	int i,j,k=0;
	int n=0, m=0; 
	scanf("%s",s);  
	if (s[0] == '0'){  
		for (i=2; s[i] != '\0'; i++)  
		{
			if (s[i] != '0'){
				n=i-1;  
				a[0] = s[i];
				a[1] = '.';
				strcat(a, &s[i+1]);
				if (strlen(a)==2){
					a[1]='e';
					a[2]='-';
					a[3]='\0';
				} else {
					m=strlen(a);
					a[m]='e';
					a[m+1]='-';
					a[m+2]='\0'; 
				}
				break;
			}
		}
	} else if (s[0] > '0'){   
		a[0]=s[0];
		a[1]='.';
		for (j=1, k=2; s[j] !='\0'; j++)
		{
			if (s[j] != '.')
			{
				a[k++] = s[j];
			}else{
				n=j-1; 
				strcat(a,&s[j+1]);
				break;
			}
		}
		m=strlen(a); 
		a[m]='e';
		a[m+1]='\0';
	}
	printf("%s%d",a,n);
	return 0;
 } 
