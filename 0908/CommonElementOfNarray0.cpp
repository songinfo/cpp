#include <stdio.h>
#include <malloc.h>

int Cmp_Equal_Ele(int* a[], int m, int *n){
	int max = n[0], k;
	int *b = a[0];
	//ÿ�αȽ��������飬����ͬԪ�ظ��Ƶ���һ�������У����趨����max
	for (k = 1; k < m; k++){
		//i��j�ֱ�Ϊ����������α꣬����ɨ������
		int i = 0, j = 0, count = 0;
		int *c = a[k];
		//ֱ��������������һ��ɨ�����
		while (i < max && j < n[k]){
			//��������α���ָ��ֵ��ȣ��򱣴�����������������α궼����
			if (b[i] == c[j]){
				b[count] = c[j];
				count++;
				i++;
				j++;
			}
			//����ֵС��������α�����
			else
				b[i]>c[j] ? j++ : i++;
		}
		//������ֵ����Ŀ��Ϊ����
		max = count;
	}
	return max;
}

//��������
void Q_S(int s[], int low, int high){
	int privotKey = s[low];
	int l_tmp = low;
	int h_tmp = high;
	while (low < high){
		while (low < high && s[high] >= privotKey){
			high--;
		}
		s[low] = s[high];
		while (low < high && s[low] <= privotKey){
			low++;
		}
		s[high] = s[low];
	}
	s[low] = privotKey;
	if (low != l_tmp)
		Q_S(s, l_tmp, low - 1);
	if (high != h_tmp)
		Q_S(s, high + 1, h_tmp);
}

int main(int argc, char *argv[]){
	/*����������Ӧ�����3,5,6
	int a[10] = { 1, 3, 3, 4, 5, 6, 6, 6, 8, 9 };
	int b[10] = { 0, 3, 3, 5, 6, 6, 7, 7, 9, 9 };
	int c[10] = { 1, 3, 3, 5, 6, 7, 8, 9, 9, 9 };
	int d[10] = { 1, 1, 3, 5, 5, 6, 6, 7, 7, 8 };*/

	int m, i, j, temp = 0;//��Ǳ�������ʱ����������ѭ���ͻ�ȡ����
	printf("Array numbers:\n");
	scanf("%d", &m);
	int *(*s)[], *n;
	s = (int *(*)[])malloc(m * sizeof(int));//��̬��������ĸ���
	n = (int*)malloc(m * sizeof(int));//����ÿ������Ԫ�صĸ���
	//ѭ����ȡ��������Ԫ�ص�����
	for (i = 0; i < m; i++){
		printf("The %dth array nmbers:\n", i + 1);
		scanf("%d", &n[i]);
		(*s)[i] = (int*)malloc(n[i] * sizeof(int));
		printf("Input numbers:\n");
		for (j = 0; j < n[i]; j++){
			scanf("%d", &temp);
			(*s)[i][j] = temp;
		}
		//��������
		Q_S((*s)[i], 0, n[i] - 1);
	}
	int count;
	count = Cmp_Equal_Ele(*s, m, n);
	if (count == 0){
		printf("No Common Elements!\n");
		return 0;
	}
	printf("Common Elements:\n");
	for (i = 0; i < count; i++){
		printf("%d ", (*s)[0][i]);
	}
	printf("\n");
	//system("pause");
}