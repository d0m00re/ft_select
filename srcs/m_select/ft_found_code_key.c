#include <stdio.h>
#include "ft_select.h"
#include <unistd.h>

int	ft_found_code_key(void)
{
	char buffer[3];

	read (0, buffer, 3);
	if (buffer[0] == 27)
	{
		if (buffer[2] == 65)
			return (TOP); // haut
		else if (buffer[2] == 66)
			return (BOTTOM); //bas
		else if (buffer[2] == 67)
			return (RIGHT); //droite
		else if (buffer[2] == 68)
			return (LEFT); // gauche
		else if (buffer[0] == 4) //ctrl_d
			return (CTRLD);
		else
		{
			printf ("\nCode touche : %d|%d|%d", buffer[0], buffer[1], buffer[2]);
			return (BAD);
		}
	}
	else if(buffer[0] == 32)
		return (SPACE); //space
	else if (buffer[0] == 10 || buffer[0] == 127)
		return (ENTER);
	else
	{
		printf ("Code touche : %d|%d|%d\n", buffer[0], buffer[1], buffer[2]);
		return (BAD);
	}
}
