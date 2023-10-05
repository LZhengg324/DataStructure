#include<stdio.h>
#include<string.h>
int main()
{
	char s[81];
	char a[81];
	char t[81]; 
	char ans[81];
	int i, j, k, l, m, n ;
	int ret=0;
	int lens = 0, lena = 0;
	scanf("%s", s);
	scanf("%s", a);
	lens = strlen(s);
	lena = strlen(a);
	if (lens > lena){  
		strcpy(t,a);
		for(i=0; i<(lens-lena); i++){
			a[i]='0';
			a[i+1]='\0';
		}
		strcat(a,t);
	} else if (lens < lena){
		strcpy(t,s);
		for(j=0; j<(lena-lens); j++){
			s[j]='0';
			s[j+1]='\0';
		}
		strcat(s,t);
	}
	for(m=0 ; s[m] != '\0' && a[m] != '\0'; m++){
		if (s[m] > a[m]){ 
			ret=1; 
			for(k=lens-1; k>=0; k--){
				t[k]=s[k]-a[k]+48;
				if(t[k]<'0'|| t[k]>'9'){
				t[k] = t[k]+10;
				s[k-1]--;
				}
			}
			t[lens]='\0'; 
			break;
		}else if (s[m] < a[m]){ 
			ret=-1;
			for(l=lena-1; l>=0; l--){
				t[l]=a[l]-s[l]+48;
				if(t[l]<'0'||t[l]>'9'){
					t[l]=t[l]+10;
					a[l-1]--;
				}	
			}
			t[lena]='\0'; 
			break;
		}
	}
	if(ret==1||ret==-1){
		for(n=0; t[n] != '\0'; n++){
			if (t[n] != '0'){
				strcpy(ans,&t[n]);
				break; 
			}
		}
	}
	if(ret == 1){
		printf("%s", ans);
	}else if (ret == -1) {
		printf("-");
		printf("%s", ans);
	}else{
		printf("0");
	}
	return 0;
}
