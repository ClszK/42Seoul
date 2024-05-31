#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define rep(i, a, b) for(int i=(a); i<(b);++i)
extern unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
char	*randstr()
{
	int n = rand()%10 + 1;
	char *ret = (char *) malloc(sizeof(char)*1000);
	rep(i,0,n)ret[i] = rand()%26 + 'a';
	ret[n] = '\0';
	return ret;
}
int main(void)
{
	srand((unsigned int) time(NULL));
	int cnt = 10000;
	rep(i,1,cnt+1)
	{
		char *s1 = randstr();
		int n = strlen(s1);
		char *s2 = (char *)malloc(sizeof(char)*1000);
		strcpy(s2, s1);
		char *d1 = randstr();
		int m = strlen(s2);
		char *d2 = (char *)malloc(sizeof(char)*1000);
		strcpy(d2, d1);
		int k = rand()%(n+m+5);
		int ret1 = strlcat(d1, s1, k);
		int ret2 = ft_strlcat(d2, s2, k);
		if(ret1!=ret2 || strcmp(d1, d2)){
			printf("when k is %d:\n", k);
			printf("%dth case hit\n[ret]\ncorrect %d\nincorrect %d\n\n[str]\ncorrect %s\nincorrect %s\n\n\n", i, ret1, ret2, d1, d2);
		}
		free(s1);free(s2);free(d1);free(d2);
		if(i%(cnt/10) == 0){
			printf("%dth case correct\n", i);
		}
	}
	return (0);
}
