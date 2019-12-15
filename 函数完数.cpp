//����Ҫ��ʵ��һ�������������Ӻ͵ļ򵥺�������������ʵ����һ�������������������m��n��0<m��n��10000��֮�������������
//��ν�������Ǹ���ǡ�õ��ڳ������������֮�͡����磺6=1+2+3
#include <stdio.h>

int factorsum( int number );
void PrintPN( int m, int n );
	
int main()
{
    int i, m, n;

    scanf("%d %d", &m, &n);
    if ( factorsum(m) == m ) printf("%d is a perfect number\n", m);
    if ( factorsum(n) == n ) printf("%d is a perfect number\n", n);
    PrintPN(m, n);

    return 0;
}
int factorsum( int number )
{
    int sum=0;
	int i;
	if(number==1)
	{
		sum=1;
	}
	for(i=1;i<number;i++)
	{
		if(number%i==0)
		{
            sum+=i;
		}
	}
	return sum;
}

void PrintPN( int m, int n )
{
    int i,j;
	int flag=0;
	for(i=m;i<=n;i++)
	{
		if( factorsum(i)==i )
		{
			flag=1;
			printf("%d =",i);
			if(i==1)
			{
				printf(" 1");
			}
			for(j=1;j<i;j++)
			{
				if(i%j==0)
				{
					if(j==1)
					{
						printf(" 1");
					}
					else
					{
						printf(" + %d",j);
					}
				}
			}
			printf("\n");
		}
	}
	if(flag==0)
	{
		printf("No perfect number");
	}
}

