#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include "add_to_end.h"


int add_to_end(){
	int count;
	char file_name[20], str[225], help_str[20];
	printf("Введите полное название файла, который вы хотите открыть для редактирования (до 20 символов): ");
	scanf("%s", &file_name);
	while(strlen(file_name) >= 20){
		printf("Имя файла больше 20 символов, укажите имя файла до 20 символов: ");
		scanf("%s", &file_name);
	}
		
	schedule *data = new schedule[1];
	
	FILE* file_work;
	file_work = fopen(file_name, "r+");
	fseek(file_work, 0, SEEK_END);
	
	printf("\nВведите данные по примеру — Город Город 39349 верхнеее 325 рублей\n");
	
	fflush(stdin);
	fgets(str, 255, stdin);
	sscanf(str, "%s %s %d %s %s %s", &(data[0].city_from), &(data[0].city_finish), &(data[0].number), &(data[0].place_type), &(data[0].price), &help_str);
	strcat(data[0].price, " ");
	strcat(data[0].price, help_str);
	
	fprintf(file_work, "|  %-16s  |  %-16s  |  %5d  |  %-16s  |  %-16s  |\n",  data[0].city_from, data[0].city_finish, data[0].number, data[0].place_type, data[0].price);
	if(fprintf == 0) {
		printf("Ошибка записи данных!\n"); 	
	}
	
	fclose(file_work);	
	delete [] data;	
	return 0;
}
