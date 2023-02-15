#ifndef FUNC
#define FUNC

struct schedule
{
	char city_from[26];
	char city_finish[26];
	unsigned int number;
	char place_type[10];
	char price[26];
};

schedule* add_new_field_in_arr(schedule* edit_trains, int count);
int edit_data();

#endif
