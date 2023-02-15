#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
//#include <malloc.h>
#include "read_data.h"

schedule Console_out(int x, schedule* arr);

int read_data(){
	int count = 0;
	char file_name[20];
	printf("Введите полное название файла, который вы хотите открыть (до 20 символов): ");
	scanf("%s", &file_name);
	char str[20];
	while(strlen(file_name) >= 20){
		printf("Имя файла больше 20 символов, укажите имя файла до 20 символов: ");
		scanf("%s", &file_name);
	}
	
	schedule *data = new schedule[1];
	
	FILE* file_work;
	file_work = fopen(file_name, "r");
	
	if(file_work == NULL){
		printf("Ошибка! Такого файла не существует\n");
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
	}	
	Console_out(count, data);
	delete [] data;
	fclose(file_work);
	return 0;
}

schedule Console_out(int x, schedule* arr) {
	for(int i = 0; i < x; i++){
		printf("|  %-16s  |  %-16s  |  %5d  |  %-16s  |  %-16s  |\n", arr[i].city_from, arr[i].city_finish, arr[i].number, arr[i].place_type, arr[i].price);	
	}
	return *arr;
}
