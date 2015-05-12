int executa_comando(char linha[])

{

	linha[strlen(linha)-1] = ' '; /* Para compreensao da funcao strtok. 

					 Substitui o '\n' de fgets. */



	char** linha_dividida = divide_linha(linha);

	char* comando = linha_dividida[0];



	#define eq_string(A,B) !strcmp(A,B)



	if (eq_string("cheque", comando))

	{

		unsigned long int = linha_dividida[1];

		unsigned long int = linha_dividida[2];

		unsigned long int = linha_dividida[3];

		unsigned long int = linha_dividida[4];



		if (linha_dividida[1] != NULL && linha_dividida[2] != NULL 

		&& linha_dividida[3] != NULL && linha_divida[4] != NULL)

			insere_cheque(cria_cheque());

			

			n_cheques++;

			return 0;

	}

		

	if (eq_string("processa", comando))

		return comando_processa();

	

	else if (eq_string("processaR", comando))

	{

		unsigned long int ref = linha_dividida[1];

		if (ref != NULL)

			return processaR(ref);		

	}



	else if (eq_string("infocheque", comando))

	{

		unsigned long int ref = linha_dividida[1];

		if (ref != NULL)

			return comando_infocheque(ref);

	}



	else if (eq_string("infocliente", comando))

	{

		unsigned long int ref = linha_dividida[1];

		if (ref != NULL)

			return comando_infocliente(ref);



	}



	else if (eq_string("info", comando))

		return comando_info();

		





	else if (eq_string("sair", comando))

	{

		printf("%lu %lu %lu", );

		return 1;

	}



        else

                return -1;



}





char** divide_linha(char linha[])

{	

	#define MAX_NIL 4 /* Numero de informacoes por linha excepto o comando */

	static char* tokens[MAX_NIL+1]; 

	char* token;

	char i;

	token = strtok(linha, " "); /* este token e o letra do comando */



	for (i = 0 ; i < MAX_NIL; i++)

	{

		tokens[i] = token;		

		token = strtok(NULL, " ");

	}

	return tokens;

}
