#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
//#include <malloc.h>
#include "edit_data.h"

schedule* edit_field(schedule* edit_trains, int count, FILE* file_work, char* file_name);

int edit_data(){
	int count;
	char file_name[20];
	printf("Введите полное название файла, который вы хотите открыть для редактирования (до 20 символов): ");
	scanf("%s", &file_name);
	char str[20];
	while(strlen(file_name) >= 20){
		printf("Имя файла больше 20 символов, укажите имя файла до 20 символов: ");
		scanf("%s", &file_name);
	}
		
	schedule *data = new schedule[1];
	
	FILE* file_work;
	file_work = fopen(file_name, "r+");
	
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
		
		fscanf(file_work, "|  %s  |  %s  |  %d  |  %s  |  %s %s  |\n", &(data[0].city_from), &(data[0].city_finish), &(data[0].number), &(data[0].place_type), &(data[0].price), &str);
		strcat(data[0].price, " ");
		strcat(data[0].price, str);
		if(fscanf == 0){	
			printf("Ошибка чтения файла!\n"); 
		}
		for(int i = 0; i < count; i++){
			printf("|  %-16s  |  %-16s  |  %5d  |  %-16s  |  %-16s  |\n", data[i].city_from, data[i].city_finish, data[i].number, data[i].place_type, data[i].price);	
		}		
		fclose(file_work);
		edit_field(data, count, file_work, file_name);
	}	
	delete [] data;
	return 0;
}

schedule* edit_field(schedule* edit_trains, int count, FILE* file_work, char* file_name){
	int edit_count;
	char help_str[20], str[255];
	printf("Введите номер записи, которую хотите отредактировать: ");
	scanf("%d", &edit_count);
	while(edit_count > count || edit_count <= 0){
		printf("Такой записи не существует, введите корректный номер записи "); 	
		scanf("%d", &edit_count);			
	}
	edit_count--;
	
	printf("\nВведите данные по примеру — %s %s %d %s %s\n", edit_trains[edit_count].city_from, edit_trains[edit_count].city_finish, edit_trains[edit_count].number, edit_trains[edit_count].place_type, edit_trains[edit_count].price);
	
	fflush(stdin);
	fgets(str, 255, stdin);
	sscanf(str, "%s %s %d %s %s %s", &(edit_trains[edit_count].city_from), &(edit_trains[edit_count].city_finish), &(edit_trains[edit_count].number), &(edit_trains[edit_count].place_type), &(edit_trains[edit_count].price), &help_str);
	strcat(edit_trains[edit_count].price, " ");
	strcat(edit_trains[edit_count].price, help_str);
	
	file_work = fopen(file_name, "w+");
	for(int i = 0; i < count; i++){
		fprintf(file_work, "|  %-16s  |  %-16s  |  %5d  |  %-16s  |  %-16s  |\n", edit_trains[i].city_from, edit_trains[i].city_finish, edit_trains[i].number, edit_trains[i].place_type, edit_trains[i].price);
		if(fprintf == 0) {
			printf("Ошибка записи данных!\n"); 	
		}
	}
	fclose(file_work);	
	return edit_trains;
}
