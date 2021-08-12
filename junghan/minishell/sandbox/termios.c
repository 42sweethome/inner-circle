#include <termios.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	/* 터미널 옵션 제어 */
	struct termios term;
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ICANON;
	term.c_lflag &= ~ECHO;
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);

	int c = 0;

	while (read(0, &c, sizeof(c)) > 0)
	{
		printf("keycode: %d\n", c);
       		c = 0; // flush buffer
	}
}
