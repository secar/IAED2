#ifndef cheque
#define

struct _cheque
{
	unsigned long int ref; 
	unsigned long int valor;
	cliente emissor;
	cliente receptor;
	struct _cheque* anterior_hash;
	struct _cheque* sucessor_hash;
	struct _cheque* anterior_tempo;
	struct _cheque* sucessor_tempo;
};

#define REF(A) { A->ref }
#define VALOR(A) { A->valor }
#define EMISSOR(A) { A->emissor}
#define BENIFICIARIO(A) { A->beneficiario }
#define ANTERIOR_HASH(A) { A->anterior_hash }
#define SUCESSOR_HASH(A) { A->sucessor_hash }
#define ANTERIOR_TEMPO(A) { A->anterior_tempo }
#define SUCESSOR_TEMPO(A) { A->sucessor_tempo }

typedef struct _cheque* cheque;

cheque cria_cheque
(unsigned long int valor, unsigned long int ref,
cliente emissor, cliente beneficiario)
{
	REF(novo_cheque) = ref;
	cheque novo_cheque = (cheque) malloc(sizeof(struct _cheque));
	VALOR(novo_cheque) = valor;
	EMISSOR(novo_cheque) = emissor;
	BENEFICIARIO(novo_cheque) = beneficiario;
	return novo_cheque;
}

void guarda_cheque(cheque cheque_alvo)
{
	/* 1º: Insere na hash table (HT) de cheques utilizando a hash function (HF). */

	cheque ultimo_cheque_hash = HT_cheques[HF_cheques(cheque_alvo);];

	while (SUCESSOR_HASH(ultimo_cheque_hash) != NULL)
		ultimo_cheque_hash = SUCESSOR_HASH(ultimo_cheque_hash);

	SUCESSOR_HASH(ultimo_cheque_hash) = cheque_alvo;
	ANTERIOR_HASH(cheque_alvo) = ultimo_cheque_hash; 



}


void apaga_cheque(cheque cheque_alvo)
{
	SUCESSOR_HASH(ANTERIOR_HASH(cheque_alvo) = SUCESSOR_HASH(cheque_alvo); 
	ANTERIOR_HASH(SUCESSOR_HASH(cheque_alvo)) = ANTERIOR_HASH(cheque_alvo);
	SUCESSOR_TEMPO(ANTERIOR_HASH(cheque_alvo)) = SUCESSOR_TEMPO(cheque_alvo); 
	ANTERIOR_TEMPO(SUCESSOR_HASH(cheque_alvo)) = ANTERIOR_TEMPO(cheque_alvo);
	free(cheque_alvo);
}


cheque procura_cheque(unsigned long int ref)
{
	cheque cheque_alvo = HT_cheques[HF_cheques(ref)];
	while (REF(cheque_alvo) != ref && cheque_alvo != NULL)
		cheque_alvo = SUCESSOR_HASH(cheque_alvo);
	return cheque_alvo;
}

unsigned long int HF_clientes(cliente cliente_alvo)
{	return REF(cliente_alvo)*(ref(cliente_alvo) + 3) % HASH_SIZE 	}
/*
http://www.cs.hmc.edu/~geoff/classes/hmc.cs070.200101/homework10/hashfuncs.html
*/

#endif
