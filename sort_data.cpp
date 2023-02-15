#include <fstream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include "sort_data.h"


int sort_data(){
	int count, sort_count;
	char file_name[20], str[225];
	printf("¬ведите полное название файла, который вы хотите открыть (до 20 символов): ");
	scanf("%s", &file_name);
	while(strlen(file_name) >= 20){
		printf("»м€ файла больше 20 символов, укажите им€ файла до 20 символов: ");
		scanf("%s", &file_name);
	}
		
	schedule *data = new schedule[1];
	
	FILE* file_work;
	file_work = fopen(file_name, "r");
	
	if(file_work == NULL){
		printf("ќшибка!\n");
		return 0;
	}
	else{
		while(!feof(file_work)){
			data = add_new_field_in_arr(data, count);			
			fscanf(file_work, "|  %s  |  %s  |  %d  |  %s  |  %s %s  |\n", &(data[count].city_from), &(data[count].city_finish), &(data[count].number), &(data[count].place_type), &(data[count].price), &str);
			strcat(data[count].price, " ");
			strcat(data[count].price, str);
			if(fscanf == 0){
				printf("ќшибка чтени€ файла!\n"); 
			}	
			count++;
		}
		
		int firts_arg, second_arg;
		schedule help_str;	
		printf("0 Ч сортировка по возрастанию цены\t1 Ч сортировка по убыванию цены\n");
		scanf("%d", &sort_count);
		switch(sort_count){
			case 0:{		
				for (int i = 0; i < count; i++){
			        for (int n = 0; n < count - 1; n++){
			        	firts_arg = atoi(data[n].price);
						second_arg = atoi(data[n + 1].price);				
			            if (firts_arg > second_arg){
			                help_str = data[n];
			                data[n] = data[n + 1];
			                data[n + 1] = help_str;
			            }
			        }
			    }
				break;
			}
			case 1:{		
				for (int i = 0; i < count; i++){
			        for (int n = 0; n < count - 1; n++){
			        	firts_arg = atoi(data[n].price);
						second_arg = atoi(data[n + 1].price);				
			            if (firts_arg < second_arg){
			                help_str = data[n];
			                data[n] = data[n + 1];
			                data[n + 1] = help_str;
			            }
			        }
			    }
				break;
			}
			default:{
				printf("“акого действи€ не существует\n");
				break;
			}
		}
		
		for(int i = 0; i < count; i++){
			printf("|  %-16s  |  %-16s  |  %5d  |  %-16s  |  %-16s  |\n", data[i].city_from, data[i].city_finish, data[i].number, data[i].place_type, data[i].price);	
		}
	}		
	fclose(file_work);
	delete [] data;	
	return 0;
}
