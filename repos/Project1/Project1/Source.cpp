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

int main(void) {
	int a, b;
	do {
		printf("���[�h�I��:1D100�c0 exit�c9:"); scanf("%d", &a);
		printf("\n");
		switch(a){
			case 0:
			do {
				CoC();
				printf("�߂�ꍇ��0:"); scanf("%d", &b);
				printf("\n");
			} while (!(b == 0));
			break;
		}
	} while (!(a == 9));

	return 0;
}