#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include "add_to_end.h"


int add_to_end(){
	int count;
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
	fseek(file_work, 0, SEEK_END);
	
	printf("\n������� ������ �� ������� � ����� ����� 39349 �������� 325 ������\n");
	
	fflush(stdin);
	fgets(str, 255, stdin);
	sscanf(str, "%s %s %d %s %s %s", &(data[0].city_from), &(data[0].city_finish), &(data[0].number), &(data[0].place_type), &(data[0].price), &help_str);
	strcat(data[0].price, " ");
	strcat(data[0].price, help_str);
	
	fprintf(file_work, "|  %-16s  |  %-16s  |  %5d  |  %-16s  |  %-16s  |\n",  data[0].city_from, data[0].city_finish, data[0].number, data[0].place_type, data[0].price);
	if(fprintf == 0) {
		printf("������ ������ ������!\n"); 	
	}
	
	fclose(file_work);	
	delete [] data;	
	return 0;
}
