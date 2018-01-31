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

void Shirobi(void) {
	int x, y, z;
	int i[] = {0, 0};
	printf("roll?\n");
	printf("2D6<="); scanf("%d", &x);
	for(y = 0; y < 2; y++){
	init_genrand((unsigned)time(NULL));
	i[y] = genrand_int32()%6+1;
	z += i[y];
	}
	
	if (z > x) {
		if (z == 12) {
			printf("6,6 → 12 クリティカル\n");
		}
		else {
			for(y = 0; y < 2; y++){
			if(y == 1){
				printf("%d", i[y]);
			}else{
			printf("%d,", i[y]);
			}
			printf("→ %d 成功\n", z);
			}
			
		}
	}else if (i < x) {
		if (i == 2) {
			printf("1,1 → 2 ファンブル\n");
		}
		else {
			for(y = 0; y < 2; y++){
			if(y == 1){
				printf("%d", i[y]);
			}else{
			printf("%d,", i[y]);
			}
			printf("→ %d 失敗\n", z);
			}
		}
	}
}

int main(void) {
	int a, b;
	do {
		printf("モード選択:1D100…0 2D6…1 exit…9:"); scanf("%d", &a);
		printf("\n");
		switch(a){
			case 0:
			do {
				CoC();
				printf("戻る場合は0:"); scanf("%d", &b);
				printf("\n");
			} while (!(b == 0));
			break;
			case 1:
			do {
				Shinobi();
				printf("戻る場合は0:"); scanf("%d", &b);
				printf("\n");
			} while (!(b == 0));
			break;
		}
	} while (!(a == 9));

	return 0;
}