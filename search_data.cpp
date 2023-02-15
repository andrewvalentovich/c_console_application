#include <fstream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include "search_data.h"


int search_data(){
	int count;
	unsigned int search_str;
	char file_name[20], str[225];
	printf("Введите полное название файла, который вы хотите открыть (до 20 символов): ");
	scanf("%s", &file_name);
	while(strlen(file_name) >= 20){
		printf("Имя файла больше 20 символов, укажите имя файла до 20 символов: ");
		scanf("%s", &file_name);
	}
		
	schedule *data = new schedule[1];
	
	FILE* file_work;
	file_work = fopen(file_name, "r");
	
	if(file_work == NULL){
		printf("Ошибка!\n");
		return 0;
	}
	else{
		while(!feof(file_work)){
			data = add_new_field_in_arr(data, count);			
			fscanf(file_work, "|  %s  |  %s  |  %d  |  %s  |  %s %s  |\n", &(data[count].city_from), &(data[count].city_finish), &(data[count].number), &(data[count].place_type), &(data[count].price), &str);
			strcat(data[count].price, " ");
			strcat(data[count].price, str);
			if(fscanf == 0){
				printf("Ошибка чтения файла!\n"); 
			}	
			count++;
		}
		
		printf("Введите номер билета для поиска, пример - 44444 (до 65 535)\t");
		scanf("%d", &search_str);
		while(search_str >= 65535){
			printf("Имя файла больше 65 535, укажите имя файла до 65 535: ");
			scanf("%s", &search_str);
		}
		
		int* search_arr = new int[count];
		
		for(int i = 0; i < count; i++){
			if(search_str == (data[i].number)){
				search_arr[i] = i;
			}
		}
			
		for(int i = 0; i < count; i++){
			if(i == search_arr[i]){
				printf("|  %-16s  |  %-16s  |  %5d  |  %-16s  |  %-16s  |\n", data[i].city_from, data[i].city_finish, data[i].number, data[i].place_type, data[i].price);	
			}				
		}
		
		delete [] search_arr;
	}		
	fclose(file_work);
	delete [] data;	
	return 0;
}
