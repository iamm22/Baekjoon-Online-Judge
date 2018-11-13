#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b))

int main()
{
	int r1, r2, c1, c2;
	int max; //���° �簢������ ����
	int maxDigit = 0;
	int i, j;
	int tmp; //sum[i-1]�� ���� �� ����
	int maxValue = -1;
	int xy[50][5];
	int num[5001]; //num[i] : i��° �簢���� ���� ���� 
	int sum[5001]; //sum[i] : i��° �簢���� ���� ū ����

	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
	
	max = MAX(MAX(abs(r1), abs(c1)), MAX(abs(r2), abs(c2)));
	num[0] = 1;
	sum[0] = 1;
	for (i = 1; i <= max; i++) {
		num[i] = 8 * i;
		sum[i] = sum[i - 1] + num[i];
	}

	for (i = r1; i <= r2; i++) {
		for (j = c1; j <= c2; j++) {
			max = MAX(abs(i), abs(j));
			if (max > 0) {
				if (i < j && i < -j) {
					//��
					tmp = 2 * max + abs(max - j);
				}
				else if (i < j && i > -j) {
					//������
					tmp = abs(max - i);
				}
				else if (i > j && i < -j) {
					//����
					tmp = 4 * max + abs(- max - i);
				}
				else if (i > j && i > -j) {
					//�Ʒ�
					tmp = 6 * max + abs(- max - j);
				}
				else {
					if (i > 0 && j > 0)tmp = 8 * max;
					else if (i > 0 && j < 0) tmp = 6 * max;
					else if (i < 0 && j < 0) tmp = 4 * max;
					else if (i < 0 && j > 0)tmp = 2 * max;
				}
				xy[i - r1][j - c1] = sum[max - 1] + tmp;
			}
			else {
				xy[i - r1][j - c1] = 1;
			}
			if (maxValue < xy[i - r1][j - c1])
				maxValue = xy[i - r1][j - c1];
		}
	}
	while (maxValue > 0) {
		maxDigit++;
		maxValue /= 10;
	}
	for (i = r1; i <= r2; i++) {
		for (j = c1; j < c2; j++) {
			printf("%*d ", maxDigit, xy[i - r1][j - c1]);
		}
		printf("%*d", maxDigit, xy[i - r1][j - c1]);
		printf("\n");
	}
}