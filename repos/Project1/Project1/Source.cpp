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
			printf("%d �N���e�B�J��\n", i);
		}
		else {
			printf("%d ����\n", i);
		}
	}
	else if (i > x) {
		if (i > 95) {
			printf("%d �t�@���u��\n", i);
		}
		else {
			printf("%d ���s\n", i);
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
			printf("6,6 �� 12 �N���e�B�J��\n");
		}
		else {
			for(y = 0; y < 2; y++){
			if(y == 1){
				printf("%d", i[y]);
			}else{
			printf("%d,", i[y]);
			}
			printf("�� %d ����\n", z);
			}
			
		}
	}else if (i < x) {
		if (i == 2) {
			printf("1,1 �� 2 �t�@���u��\n");
		}
		else {
			for(y = 0; y < 2; y++){
			if(y == 1){
				printf("%d", i[y]);
			}else{
			printf("%d,", i[y]);
			}
			printf("�� %d ���s\n", z);
			}
		}
	}
}

int main(void) {
	int a, b;
	do {
		printf("���[�h�I��:1D100�c0 2D6�c1 exit�c9:"); scanf("%d", &a);
		printf("\n");
		switch(a){
			case 0:
			do {
				CoC();
				printf("�߂�ꍇ��0:"); scanf("%d", &b);
				printf("\n");
			} while (!(b == 0));
			break;
			case 1:
			do {
				Shinobi();
				printf("�߂�ꍇ��0:"); scanf("%d", &b);
				printf("\n");
			} while (!(b == 0));
			break;
		}
	} while (!(a == 9));

	return 0;
}