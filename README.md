# Cheques
Projecto de IAED 2 para fazer com o Chaves.

# AINDA PARA FAZER:
- Tudo da programação. O algoritmo em si é fácil e parecido com o do último projecto.


# Descrição

NÃO HÁ VARIÁVEIS GLOBAIS DADO QUE ESSAS COMPLICAM O CÓDIGO. DIVERTE-TE A FAZER FUNÇÕES COM MONTES DE ARGUMENTOS, EU DEIXO.
Existem cheques e clientes.

Cheques:
- Podem ser criados. Sempre que são criados deve-se também criar os clientes se não existirem. Só assim podem aparecer novos clientes!
- Podem ser processados (removidos). Esta operação deve ser eficiente.
- Podem ser procurados. Esta operação deve ser eficiente.
-- LOGO IREMOS USAR HASHTABLES (A SÉRIO).
- Cada objecto 'cheque' deverá ter: ref_emissor, ref_beneficiario, ref_cheque (dele mesmo), endereco do proximo cheque na hash table, endereco do cheque anterior na hash_table,  endereco do que foi adicionado temporalmente depois dele, endereco do que adicionado temporalmente antes dele. Sim, listas quadruplamente ligadas! Bem fixe! É necessário isso tudo para os comandos de proecessar.

Clientes:
- Não podem ser criados directamente.
- Podem ser procurados. Esta operação deve ser eficiente. Logo, hashes.
- Cada objecto 'cliente' deverá ter: total cheques recebidos, total cheques emitidos, valor total dos cheques recebidos, valor total dos cheques emitidos, próximo na hash, anterior na hash, próximo EM ORDEM CRESCENTE, anterior EM ORDEM CRESCENTE.

E outros...Boa sorte.
