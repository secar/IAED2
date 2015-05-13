int comando_cheque(unsigned int valor, unsigned long int refe, unsigned long refb, unsigned long refch)
{
	cheque novo_cheque = cria_cheque(valor, refe, refb, refch);

	n_cheques++;

	return 0;
}

int comando_processa(void)
{	
	cheque prox_mais_antigo = SUCESSOR_TEMPO(cheque_mais_antigo);

	remove_cheque(cheque_mais_antigo);

	cheque_mais_antigo = prox_mais_antigo;

	n_cheques--;
	
	return 0;	
}

int comando_processaR(unsigned int refch) 
{
	
	if refch == REF(cheque_mais_antigo);
		return comando_processa();

	else if (refch == REF(cheque_mais_novo));
	{	
		cheque prox_mais_novo = ANTERIOR_TEMPO(cheque_mais_novo);
		remove_cheque(cheque_mais_novo);
		cheque_mais_novo = prox_mais_novo;
	}
	
	else
	{	
		cheque cheque_alvo = seek_cheque(refch);

		if (cheque_alvo == NULL)
			printf("Cheque %lu does not exist", refch);
		else 
			remove_cheque(cheque_alvo);
	}
	
	n_cheques--; 

	return 0;
}

int comando_infocheque(unsigned long int refch) 
{
	cheque cheque_alvo = seek_cheque(refch);

	printf("Cheque-info: %lu %lu %lu --> %lu\n", 
	REF(cheque_alvo), VALOR(cheque_alvo), REF_EMI(cheque_alvo), REF_BEN(cheque_alvo) );

	return 0;
}

int comando_infocliente(unsigned long int refcl)
{
	cliente cliente_alvo = seek_cliente(refcl);

	printf("Cliente-info: %lu %u %lu %u %lu\n", 
	REF(cliente_alvo), N_CH_OUT(cliente_alvo), V_CH_OUT(cliente_alvo), N_CH_IN(cliente_alvo), V_CH_IN(cliente_alvo) );

	return 0;
}


void comando_info(void)
{
	cliente cliente_alvo = cliente_mais_baixo; /* var global*/

	while (cliente_alvo!= NULL)
	{
		printf("*%lu %u %lu %u %lu\n", 
		REF(cliente_alvo), N_CH_OUT(cliente_alvo), V_CH_OUT(cliente_alvo), N_CH_IN(cliente_alvo), V_CH_IN(cliente_alvo) );
		cliente_alvo = SUCESSOR_REF(cliente_actual);
	}

	return 0;
}

	ajusta_emissor(refemissor, valor_dado);
	ajusta_beneficiario(refbeneficiario, valor_dado);
