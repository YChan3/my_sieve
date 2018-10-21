#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sieve(int end){
	int nums = (int)(end*log(end)*1.15);
	char * arr = calloc(1, nums);

	int counter = 2;
	int current_check = 2;

	while(end){
		if(counter == current_check){
			//printf("prime %d: %d\n", end, current_check);
			if(!--end){
				return current_check;
			}

			int c2 = counter;
			while(c2 < nums){
				//printf("c2 %d\n", c2);
				arr[c2] = 1;
				c2 += counter;
			}

			for(int i = current_check; i < nums; i++){
				//printf("i %d\n", i);
				if(arr[i] == 0){
					current_check = i;
					break;
				}
			}
			counter = current_check;
		}
	}
	return current_check;
}
