#include <stdlib.h>

#include <stdio.h>

#include <string.h>
#include "cliente.h"
#include "cheque.h"

#define BUFFER_SIZE 128

#define HASH_SIZE 196613 /* http://planetmath.org/goodhashtableprimes */

unsigned long int n_clientes;
unsigned long int n_cheques;
unsigned long int v_cheques;
cheque cheque_mais_antigo;
cliente cliente_mais_baixo;
cliente HT_clientes[HASH_SIZE];
cheque HT_cheques[HASH_SIZE];


main()

{

	char flag_saida = 0;

	char linha[BUFFER_SIZE];
	while (flag_saida != 1)
	{
		fgets(linha, BUFFER_SIZE, stdin);

		flag_saida = processa_linha(linha);
	}

	return EXIT_SUCCESS;

}
