#include <stdio.h>

int main() {
	double arr[50];
	double new[50];
	int n;

	printf("Enter number of elements: ");
	scanf("%d", &n);

	printf("Enter %d elements:\n", n);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &arr[i]);
	}

	int j = 0;

	for (int i = 0; i < n; i++) {
		if (i == 0 || arr[i] != arr[i - 1]) {
			new[j++] = arr[i];
		}
	}

	printf("Array after removing adjacent duplicates:\n");
	for (int i = 0; i < j; i++) {
		printf("%lf ", new[i]);
	}
	printf("\n");

	return 0;
}