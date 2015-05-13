
char executa_comando(char linha[])
{

	char** linha_dividida;
	char* comando;

	linha[strlen(linha)-1] = ' '; /* Para compreensao da funcao strtok. 
					 Substitui o '\n' de fgets. */
	linha_dividida = divide_linha(linha);
	comando = linha_dividida[0];

	#define eq_string(A,B) !strcmp(A,B) /*conveniencia*/

	if (eq_string("cheque", comando))
	{
		char* valor_str = linha_dividida[1];
		char* refe_str = linha_dividida[2];
		char* refb_str = linha_dividida[3];
		char* refch_str = linha_dividida[4];

		if (valor_str != NULL && refe_str != NULL && refb_str != NULL && refch_str != NULL)
		{
			unsigned int valor = (unsigned int) strtoul(valor_str, NULL, 10);

			unsigned long int refe = strtoul(refe_str, NULL, 10);
			unsigned long int refb = strtoul(refb_str, NULL, 10);
			unsigned long int refch = strtoul(refc_str, NULL, 10);

			return comando_cheque(valor, refe, refb, refch);
		}
	}
		
	else if (eq_string("processa", comando))
		return comando_processa();
	
	else if (eq_string("processaR", comando))
	{
		char* refch_str = linha_dividida[1];

		if (refch_str != NULL)
		{
			unsigned long int refch = strtoul(refch_str, NULL, 10);

			return comando_processaR(refch);
		}		
			 		
	}

	else if (eq_string("infocheque", comando))
	{
		char* refch_str = linha_dividida[1];

		if (refch_str != NULL)
		{
			unsigned long int refch = strtoul(refch_str, NULL, 10);
	
			return comando_infocheque(refch);
		}
	}

	else if (eq_string("infocliente", comando))
	{
		char* refcl_str = linha_dividida[1];

		if (refcl_str != NULL)
		{	
			unsigned long int refcl = strtoul(refcl_str, NULL, 10);

			return comando_infocliente(refcl);

		}
	}

	else if (eq_string("info", comando))

		return comando_info();		

	else if (eq_string("sair", comando))

		return comando_sair();

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
