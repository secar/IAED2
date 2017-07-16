#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#define BUFFER_SIZE 128

void do_cheque(char* args)
{
	char* endptr;
	long value = strtol(args, &endptr, 10);
	long creditor = strtol(endptr, &endptr, 10);
	long debtor = strtol(endptr, &endptr, 10);
	long check = strtol(endptr, &endptr, 10);
	printf("%ld %ld %ld %ld\n", value, creditor, debtor, check);
}

void do_processa(char* args)
{
	puts("Nothing to process");
}

void do_processaR(char* args)
{
	long ref = strtol(args, NULL, 10);
	printf("Cheque %ld does not exist\n", ref);
}

void do_infocheque(char* args)
{
	long ref = strtol(args, NULL, 10);
	printf("%ld\n", ref);
}

void do_infocliente(char* args)
{
	long ref = strtol(args, NULL, 10);
	printf("%ld\n", ref);
}

void do_info(char* args)
{
	puts("No active clients");
}

void do_sair(char *args)
{
	exit(0);
}

void execute(char* line)
{
	char* commands[] = { 
		"cheque",
		"processa",
		"processaR",
		"infocheque",
		"infocliente",
		"info",
		"sair"
	};
	void (*functions[])(char*) = {	
		do_cheque,
		do_processa,
		do_processaR,
		do_infocheque,
		do_infocliente,
		do_info,
		do_sair
	};	
	int i;

	strtok(line, "\n\t ");
	for (i = 0; i < sizeof(commands)/sizeof(*commands); ++i) {
        	if (!strcmp(line, commands[i])) {
			char* args = line + strlen(line) + 1;
			functions[i](args);
			return;
		}
	}
	puts("Command not found.");
}

void readloop(void)
{
	char line[BUFFER_SIZE];
	for (;;) {
		printf("> ");
		if (fgets(line, sizeof(line), stdin))
			execute(line);
		else
			return;
	}
}

int main(void)
{
	readloop();
	return 0;
}
