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

int create_data(schedule *trains, int count);

#endif

