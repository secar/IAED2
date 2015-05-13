#ifndef cheque
#define

struct _cheque
{
	unsigned long int ref; 
	unsigned long int valor;
	cliente emissor;
	cliente beneficiario;
	struct _cheque* anterior_hash;
	struct _cheque* sucessor_hash;
	struct _cheque* anterior_tempo;
	struct _cheque* sucessor_tempo;
};

typedef struct _cheque* cheque;

#define REF(A) { A->ref }
#define VALOR(A) { A->valor }
#define EMISSOR(A) { A->emissor}
#define BENIFICIARIO(A) { A->beneficiario }
#define ANTERIOR_HASH(A) { A->anterior_hash }
#define SUCESSOR_HASH(A) { A->sucessor_hash }
#define ANTERIOR_TEMPO(A) { A->anterior_tempo }
#define SUCESSOR_TEMPO(A) { A->sucessor_tempo }

#define HASH_SIZE 196613 /* http://planetmath.org/goodhashtableprimes */

static cheque HT_cheques[HASH_SIZE];
static cheque cheque_mais_antigo;

cheque cria_cheque(unsigned int valor, unsigned long refch, unsigned long ref_emi, unsigned long ref_ben)
{
	cheque novo_cheque = (cheque) malloc(sizeof(struct _cheque));
	REF(novo_cheque) = refch;

	VALOR(novo_cheque) = valor;

	cliente emissor = procura_cliente(ref_emi);

	cliente beneficiario = procura_cliente(ref_ben);

	if (emissor == NULL) 
		emissor = cria_cliente(ref_emi, valor, 'e');

	if (beneficiario == NULL)
		beneficiario = cria_cliente(ref_ben, valor, 'b');

	EMISSOR(novo_cheque) = emissor;
	BENEFICIARIO(novo_cheque) = beneficiario;

	return novo_cheque;
}


void insere_cheque(cheque cheque_alvo)
{
	/* 1º: Insere na hash table (HT) de cheques utilizando a hash function (HF). */
	ANTERIOR_HASH(cheque_alvo) = NULL;
	SUCESSOR_TEMPO(cheque_alvo) = NULL;
	unsigned int hash = HF_cheques(cheque_alvo);
	cheque primeiro_cheque_hash = HT_cheques[hash];

	if (primeiro_cheque_hash == NULL)
	{
		HT_cheques[hash] = cheque_alvo;
		SUCESSOR_HASH(cheque_alvo) = NULL;
	}
	else 
	{
		ANTERIOR
	}
		
		

}

void apaga_cheque(cheque cheque_alvo)
{
	SUCESSOR_HASH(ANTERIOR_HASH(cheque_alvo) = SUCESSOR_HASH(cheque_alvo); 
	ANTERIOR_HASH(SUCESSOR_HASH(cheque_alvo)) = ANTERIOR_HASH(cheque_alvo);
	SUCESSOR_TEMPO(ANTERIOR_HASH(cheque_alvo)) = SUCESSOR_TEMPO(cheque_alvo); 
	ANTERIOR_TEMPO(SUCESSOR_HASH(cheque_alvo)) = ANTERIOR_TEMPO(cheque_alvo);
	free(cheque_alvo);
}


cheque seek_cheque(unsigned long int ref)
{
	cheque cheque_alvo = HT_cheques[HF_cheques(ref)];
	while (REF(cheque_alvo) != ref && cheque_alvo != NULL)
		cheque_alvo = SUCESSOR_HASH(cheque_alvo);
	return cheque_alvo;
}

unsigned long int HF_clientes(cliente cliente_alvo)
{	return REF(cliente_alvo)*(REF(cliente_alvo) + 3) % HASH_SIZE 	}
/*
http://www.cs.hmc.edu/~geoff/classes/hmc.cs070.200101/homework10/hashfuncs.html
*/

#endif
