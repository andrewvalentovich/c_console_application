#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include "delete_data.h"

int delete_data(){
	int count, delete_count;
	char file_name[20], str[225], help_str[20];
	printf("������� ������ �������� �����, ������� �� ������ ������� ��� �������������� (�� 20 ��������): ");
	scanf("%s", &file_name);
	while(strlen(file_name) >= 20){
		printf("��� ����� ������ 20 ��������, ������� ��� ����� �� 20 ��������: ");
		scanf("%s", &file_name);
	}
		
	schedule *data = new schedule[1];
	
	FILE* file_work;
	file_work = fopen(file_name, "r+");
	fseek(file_work, 0, SEEK_SET);
	
	if(file_work == NULL){
		printf("������!\n");
		return 0;
	}
	else{
		while(!feof(file_work)){
			data = add_new_field_in_arr(data, count);			
			fscanf(file_work, "|  %s  |  %s  |  %d  |  %s  |  %s %s  |\n", &(data[count].city_from), &(data[count].city_finish), &(data[count].number), &(data[count].place_type), &(data[count].price), &str);
			strcat(data[count].price, " ");
			strcat(data[count].price, str);
			if(fscanf == 0){
				printf("������ ������ �����!\n"); 
			}	
			count++;
		}
		
		for(int i = 0; i < count; i++){
			printf("|  %-16s  |  %-16s  |  %5d  |  %-16s  |  %-16s  |\n", data[i].city_from, data[i].city_finish, data[i].number, data[i].place_type, data[i].price);	
		}
	}		
	fclose(file_work);	
	
	file_work = fopen(file_name, "w+");
	if(file_work == NULL){
		printf("������ �������� �����!\n");
		return 0;
	}
	else{		
		printf("������� ����� ������, ������� ������ ������� "); 	
		scanf("%d", &delete_count);
		while(delete_count > count || delete_count <= 0){
			printf("����� ������ �� ����������, ������� ���������� ����� ������ "); 	
			scanf("%d", &delete_count);			
		}
		delete_count -= 1;	
		
		for(int i = delete_count; i < count; i++){
			data[i] = data[i+1];
		}
		for(int i = 0; i < count-1; i++){
			fprintf(file_work, "|  %-16s  |  %-16s  |  %5d  |  %-16s  |  %-16s  |\n", data[i].city_from, data[i].city_finish, data[i].number, data[i].place_type, data[i].price);
			if(fprintf == 0) {
				printf("������ ������ ������!\n"); 	
			}
		}
	}	
	fclose(file_work);
	
	delete [] data;	
	return 0;
}


