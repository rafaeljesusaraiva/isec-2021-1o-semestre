#ifndef CONSTANTES_H
#define CONSTANTES_H

// CONSTANTES DE INFORMAÇÃO (OU VERIFICAÇÂO)
#define MINPLAYERS 2
#define MAXDEFINEDPLAYERS 30    // Valor máx. da var. de ambiente MAXPLAYERS 

// CONSTANTES DE SAIDA
#define FIM_BOM 0               // Arbitro saiu corretamente
// [10-20] Sao saidas (de erro) iniciais do arbitro
#define ERRO_FALTA_ENV 11       // Arbitro saiu por nao haver(em) variaveis de ambiente
#define ERRO_MAXPLAYERS_EXCEDIDO 12 // Arbitro saiu por var. amb. exceder limite

#endif // CONSTANTES_H