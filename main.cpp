#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include "create_data.h"
#include "read_data.h"
#include "add_to_end.h"
#include "delete_data.h"
#include "sort_data.h"
#include "search_data.h"
#include "calculate_data.h"


schedule* add_new_field_in_arr(schedule* edit_trains, int count);
int create_data(schedule *trains, int count);
int read_data();
int	edit_data();
int add_to_end();
int delete_data();
int sort_data();
int search_data();
int calculate_data();

int main(int argc, char** argv) {
	system("chcp 1251");
	int action = 99;	
	while(action != 0){
		printf("1 � ������ �� �����\n2 � ������ ������ � ����\n3 � ������������� ������\n4 � �������� ������ � ����� �����\n5 � ������� ������\n6 � ���������� ������\n7 � ����� ������\n8 � �������\n0 � ���������� ������\n");
		scanf("%d", &action);
		printf("%d\n", action);
		switch(action){
			case 1:{
				read_data();
				break;
			}
						
			case 2:{	
				short int count;
				printf("������� ���������� �������: ");
				scanf("%d", &count);
				schedule trains[count];
				create_data(trains, count);
				break;
			}
				
			case 3:{
				edit_data();
				break;
			}
								
			case 4:{
				add_to_end();
				break;
			}
								
			case 5:{
				delete_data();
				break;
			}
								
			case 6:{
				sort_data();
				break;
			}
								
			case 7:{
				search_data();
				break;
			}
								
			case 8:{
				calculate_data();
				break;
			}
				
			case 0:{
				printf("������ ���������\n");
				break;
			}
				
			default: {
				printf("������ �������� �� ����������\n");
				break;
			}	
		}
	}
	return 0;
}


schedule* add_new_field_in_arr(schedule* edit_trains, int count){
	if(count == 0){
		edit_trains = new schedule[count + 1];
	}
	else{
		schedule* temp_trains = new schedule[count + 1];
		for(int i = 0; i < count; i++){
			temp_trains[i] = edit_trains[i];
		}
		delete [] edit_trains;
		
		edit_trains = temp_trains;
	}
	return edit_trains;
}

