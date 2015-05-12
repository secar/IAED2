#ifndef cliente
#define
struct _cliente
{
	unsigned long int ref; 
	unsigned long int nche;
	unsigned long int vche;
	unsigned long int nchb;
	unsigned long int vchb;
	struct _cliente* anterior_hash;
	struct _cliente* sucessor_hash;
	struct _cliente* anterior_ref;
	struct _cliente* sucessor_ref;

};

#define REF(A) { A->ref }
#define N_CH_OUT(A) { A->nche }
#define N_CH_IN(A) { A->nchb }
#define V_CH_OUT(A) { A->vche }
#define V_CH_IN(A) { A->vchb }
#define ANTERIOR_HASH(A) { A->anterior_hash }
#define ANTERIOR_HASH(A) { A->sucessor_hash }
#define ANTERIOR_REF(A) { A->anterior_ref }
#define SUCESSOR_REF(A) { A->sucessor_ref }

typedef _cliente* cliente;

cliente cria_cliente(unsigned long int ref, unsigned long int valor, char tipo)
/* Um cliente e criado se nao existir apos um cheque recem-criado referencia-lo. */
{
	cliente novo_cliente = (cliente) malloc(sizeof(struct _cliente));

	REF(novo_cliente) = ref;

	switch (tipo)
	{
		case 'b':
			N_CH_IN(novo_cliente) = 1;
			V_CH_IN(novo_cliente) = valor;
			N_CH_OUT(novo_cliente) = 0;
			V_CH_OUT(novo_cliente) = 0;
			break;
		case 'e':
			N_CH_OUT(novo_cliente) = 1;
			V_CH_OUT(novo_cliente) = valor;
			N_CH_IN(novo_cliente) = 0;
			V_CH_IN(novo_cliente) = 0;
	}

	return novo_cliente;
	
}


cliente seek_cliente(unsigned long int referencia_alvo)
}
	cliente cliente_alvo = HT_clientes[HF_clientes(referencia_alvo)];

	while (cliente_alvo != NULL && REF(cliente_alvo) != referencia_alvo)
		cliente_alvo = SUCESSOR_HASH(cliente_alvo);

	return cliente_alvo;
}

void apaga_cliente(cliente cliente_alvo)
{
	sucessor_ref(anterior_ref(cliente_alvo)) = sucessor_ref(cliente_alvo);

	anterior_ref(sucessor_ref(cliente_alvo)) = anterior_ref(cliente_alvo);

	sucessor_hash(anterior_hash(cliente_alvo)) = sucessor_hash(cliente_alvo);

	anterior_hash(sucessor_hash(cliente_alvo)) = anterior_hash(cliente_alvo);

	free(cliente_alvo);		
}

ajusta_emissor(unsigned long int ref_emi, long int* valor_dado)
{
	cliente emissor = seek_cliente(ref_emi);
	
	if (emissor == NULL)
		cria_cliente(ref_emi);

	else {

		(emissor->nche)++;

		(emissor->vche) = (emissor->vche) + (*valor_dado);

	} 	

}


#endif
