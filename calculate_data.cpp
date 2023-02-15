#include <fstream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include "calculate_data.h"


int calculate_data(){
	int count;
	long int max_price = 0, price, averange_price = 0, min_price = 99999;
	char file_name[20], str[225];
	printf("������� ������ �������� �����, ������� �� ������ ������� (�� 20 ��������): ");
	scanf("%s", &file_name);
	while(strlen(file_name) >= 20){
		printf("��� ����� ������ 20 ��������, ������� ��� ����� �� 20 ��������: ");
		scanf("%s", &file_name);
	}
		
	schedule *data = new schedule[1];
	
	FILE* file_work;
	file_work = fopen(file_name, "r");
	
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
			price = atoi(data[i].price);
			if(price < min_price){
				min_price = price;
			}
			if(price > max_price){
				max_price = price;
			}
			averange_price += price;
		}		
		averange_price /= count;
		
		printf("����������� ���� = %ld, ������������ ���� = %ld, ������� ���� = %ld\n", min_price, max_price, averange_price);
	}		
	fclose(file_work);
	delete [] data;	
	return 0;
}
