#include <stdio.h>
#include "ft_select.h"
#include <unistd.h>
#include "ft_ori.h"

static	int ft_ret_for_27(char buffer[])
{
	if (buffer[1] == 91 && buffer[2] == 51) //delete
		return (DELETE);
	else if (buffer[2] == 65)
		return (TOP); // haut
	else if (buffer[2] == 66)
		return (BOTTOM); //bas
	else if (buffer[2] == 67)
		return (RIGHT); //droite
	else if (buffer[2] == 68)
		return (LEFT); // gauche
	else if (buffer[0] == 4) //ctrl_d
		return (CTRLD);
	else if (buffer[1] == 0 && buffer[2] == 0)
		return (ESC);
	else
		return (BAD);
}

int	ft_found_code_key(void)
{
	char buffer[3];

	ft_memset(buffer, 0, 3);
	read (0, buffer, 3);
	if (buffer[0] == 27)
		return (ft_ret_for_27(buffer));
	else if(buffer[0] == 32) //
		return (SPACE); //space
	else if (buffer[0] == 10)
		return (ENTER);
	else if (buffer[0] == 127)
		return (BACKSPACE);
	else
		return (BAD);
}
