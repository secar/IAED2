cheque comando_processa(void)
{	
	cheque novo_mais_antigo = sucessor_tempo(cheque_mais_antigo); /* variavel global */

	remove_cheque(cheque_mais_antigo);	

	return novo_mais_antigo;	
}

void comando_processaR(unsigned int refch) 
{
	cheque cheque_alvo = seek_cheque(refch);

	if (cheque_alvo == NULL)
		printf("Cheque %lu does not exist", refch);
	else remove_cheque(cheque_alvo);
}

void comando_infocheque(unsigned long int refch) 
{
	cheque alvo = seek_cheque(refch);

	printf("Cheque-info: %lu %lu %lu --> %lu\n", 
	ref(alvo), valor(alvo), ref_emi(alvo), ref_ben(alvo) );
}

void comando_infocliente(unsigned long int refcl)
{
	cliente alvo = seek_cliente(refcl);

	printf("Cliente-info: %lu %lu %lu --> %lu\n", ref(alvo), 

	valor(alvo), ref_emi(alvo), ref_ben(alvo) );
}


void comando_info(void)
{
	cliente cliente_actual = cliente_mais_baixo;

	while (cliente_actual != NULL)
	{
		printf("*%lu %lu %lu --> %lu\n", 

		ref(alvo), valor(alvo), ref_emi(alvo), ref_ben(alvo) );
		
		cliente_actual = SUCESSOR_REF(cliente_actual);
	}
}

	ajusta_emissor(refemissor, valor_dado);
	ajusta_beneficiario(refbeneficiario, valor_dado);
