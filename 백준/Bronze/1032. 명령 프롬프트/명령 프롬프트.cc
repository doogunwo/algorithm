#include <stdio.h>


int main() {

	int n, i, j;
	char str1[100]; 
	char str2[100];
	scanf("%d", &n);
	scanf("%s", str1);
	for (i = 0; i < n-1; i++) {
		scanf("%s", str2);
		
		for (j = 0; str2[j]; j++) {
			if (str1[j] != str2[j]) str1[j] = '?';
		}
	}
	printf("%s", str1);
}