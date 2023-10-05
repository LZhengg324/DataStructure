#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	char s[10001], t[10001], op[10001];
	int num[10001];
	int i, j, k, l; 
	int num1=0, num2=0, num3=0;
	char op1, op2, op3; 
	int m=1;
	gets(s);
	for (i=0, j=0; i<strlen(s); i++){  //ȥ���ո� 
		if (s[i] != ' '){
			t[j++]=s[i];
		}
	}
	strcpy(s,t);
	if (s[0]<'0'){
		m=-1;
		strcpy(t,&s[1]);
		s[0]='\0';
		strcpy(s,t);
	} 	
	for (i=0, j=0, k=0; i<strlen(s); i++){   //��������������� 
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='='){
			op[j++]=s[i];
		} else if (s[i]>= '0' && s[i]<='9'){
			num[k]=s[i]-48;
			for (l=1; l<10; l++){
				if(s[i+l]>= '0' && s[i+l]<='9'){
					num[k]=num[k]*10+s[i+l]-48;
				} else {
					break;
				}
			}
			k++;
			i=i+l-1; 
		}
	}
	num1=0;
	op1='+';
	num2=num[0]*m;
	op2=op[0];
	for(i=1; op2 != '='; i++){
		num3=num[i];
		op3=op[i];
		switch(op2){  //�ж��������42��*��43��+��45��-��47��/��
			case 42:
				num2=num2*num3;
				op2=op3; 
				break;
			case 43:
			case 45:
				if (op1=='+'){
					num1=num1+num2;
					op1=op2;
					num2=num3;
					op2=op3;
				} else if (op1=='-'){
					num1=num1-num2;
					op1=op2;
					num2=num3;
					op2=op3;
				}
				break;
			case 47:
				num2=floor(num2/num3);
				op2=op3; 
				break;
		}
	}
	if (op1 == '+'){
		num1=num1+num2;
	} else if (op1 == '-'){
		num1=num1-num2;
	}
	printf("%d",num1);
	return 0;
}
