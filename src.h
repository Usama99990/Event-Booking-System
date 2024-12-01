#include <stdio.h>
#include "design.h"
void design (void)
{
	int initial_fg_color = getfgcolor();
	int initial_bg_color = getbgcolor();
	printf("\n");
	setbgcolor( white );
	setfgcolor( light_red );
	printf("\n\n\n\n");
	printf("#######################################################################################################################\n");
	printf("################                              *****************                                     ###################\n");
	printf("################   W E L C O M E   T O   H O R N E T S   E V E N T   B O O K I N G   S E R V I C E  ###################\n");
	printf("################                               M A I N    M E N U                                   ###################\n");
	printf("#######################################################################################################################\n");
}
