#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sieve(int end){
	int nums = (int)(end*log(end)*1.15);
	char arr[nums];
	int i = nums;
	while(i+1){
		arr[i] = 0;
		i--;
	}

	int iter = 0;
	int counter = 2;
	int prime_num = end;
	int current_check = 2;
	while(prime_num){
		if(counter == current_check && !arr[iter]){
			printf("prime %d: %d\n", prime_num, current_check);
			prime_num--;
			arr[iter] = 1;
		}
		else if(!arr[iter] && (counter)%current_check == 0){
			arr[iter] = 1;
		}
		if(counter == nums){
			counter = current_check;
			current_check++;
			iter = current_check - 3;
		}
		counter++;
		iter++;
	}
	return current_check;
}

int main(){
	printf("%d\n", sieve(1000000));
}
