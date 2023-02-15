#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include "create_data.h"


int create_data(schedule *trains, int count){
	char str[255], help_str[20];
	fflush(stdin);
	for(int i = 0; i < count; i++){
		printf("������� ������\n");
		fgets(str, 255, stdin);
		sscanf(str, "%s %s %d %s %s %s", &(trains[i].city_from), &(trains[i].city_finish), &(trains[i].number), &(trains[i].place_type), &(trains[i].price), &help_str);
		strcat(trains[i].price, " ");
		strcat(trains[i].price, help_str);
	} 

	
	printf("*---------------------------------------------------------------------------------------------------------------------*");
	for(int i = 0; i < count; i++){
		sprintf(str, "\n|  %-16s  |  %-16s  |  %5d  |  %-16s  |  %-16s  |", trains[i].city_from, trains[i].city_finish, trains[i].number, trains[i].place_type, trains[i].price);
		puts(str);
	} 
	printf("*---------------------------------------------------------------------------------------------------------------------*\n");
	
	char file_name[20];
	printf("������� ������ �������� �����, � ������� �� ������ �������� ������ (�� 20 ��������): ");
	scanf("%s", &file_name);	
	while(strlen(file_name) >= 20){
		printf("��� ����� ������ 20 ��������, ������� ��� ����� �� 20 ��������: ");
		scanf("%s", &file_name);
	}
	
	FILE* file_work;
	file_work = fopen(file_name, "w+");
	
	if(file_work == NULL){
		printf("������ �������� �����!\n");
		return 0;
	}
	else{
		for(int i = 0; i < count; i++){
			fprintf(file_work, "|  %-16s  |  %-16s  |  %5d  |  %-16s  |  %-16s  |\n", trains[i].city_from, trains[i].city_finish, trains[i].number, trains[i].place_type, trains[i].price);
			if(fprintf == 0) {
				printf("������ ������ �����!\n"); 
			}
		}
	}	
	fclose(file_work);
	return 0;
} 

