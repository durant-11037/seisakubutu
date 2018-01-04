#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include "MT.h"

void CoC(void) {
	int i, x;
	printf("roll?\n");
	printf("1D100<="); scanf("%d", &x);
	init_genrand((unsigned)time(NULL));
	i = genrand_int32()%100+1;
	
	if (i < x) {
		if (i < 6) {
			printf("%d クリティカル\n", i);
		}
		else {
			printf("%d 成功\n", i);
		}
	}
	else if (i > x) {
		if (i > 95) {
			printf("%d ファンブル\n", i);
		}
		else {
			printf("%d 失敗\n", i);
		}
	}
}

int main(void) {
	int a, b;
	do {
		printf("モード選択:1D100…0 exit…9:"); scanf("%d", &a);
		printf("\n");
		switch(a){
			case 0:
			do {
				CoC();
				printf("戻る場合は0:"); scanf("%d", &b);
				printf("\n");
			} while (!(b == 0));
			break;
		}
	} while (!(a == 9));

	return 0;
}