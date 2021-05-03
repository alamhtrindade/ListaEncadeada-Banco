#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


/* SISTEMA DE GESTÃO BANCÁRIA */



// BEGIN ALGORITM SYSTEM
typedef struct cliente {
    char nome[50];
    char cpf[12];
    char nascimento[15];
    char endereco[50];
    char bairro[20];
    char cidade[20];
    char estado[20];
    char telefone[20];
    struct cliente *prox;
}cliente;

typedef struct conta {
    char cpf_cliente[20];
    char agencia_bancaria[50];
    char numero_da_conta[50];
    char tipo_de_conta[20];
    int preferencial;
    double saldo;
    struct conta *prox;
}conta;

typedef struct atendimento {
    int id;
    char cpf[12];
    char numero_conta[20];
    int tipo_de_atendimento; //1-mesa | 2 - caixa
    char data_atual[15];
    int senha;
    struct atendimento *prox;
}atendimento;

// MENU PRINCIPAL
int menuPrincipal(){
    int opcao;
    printf("***************************************************************************\n");
    printf("*                    SISTEMA BASICO DE GESTAO BANCARIO                    *\n");
    printf("***************************************************************************\n");
    printf("*    1 - CLIENTES   |   2 - CONTAS   |   3 - ATENDIMENTO   |   4 - SAIR   *\n");
    printf("***************************************************************************\n");
    printf("\n");
    printf("OPCAO:  ");
    scanf("%d",&opcao);
    return opcao;
}

// MENU CLIENTES
int menuClientes(){
    int opcao;
    printf("***************************************************************************\n");
    printf("*                                CLIENTES                                 *\n");
    printf("***************************************************************************\n");
    printf("* 1-PESQ. POR CPF | 2-PESQ. POR NOME | 2 - CADASTRAR CLIENTE | 0 - VOLTAR *\n");
    printf("***************************************************************************\n");
    printf("\n");
    printf("OPCAO:  ");
    scanf("%d",&opcao);
    return opcao;
}

// SUB-MENU CLIENTES
int menuSubMenuClientes(int opcao){
    switch(opcao){
        case 1:{
            printf("***************************************************************************\n");
            printf("*                          PESQUISAR POR CPF                             *\n");
            printf("***************************************************************************\n");
            printf("\n");
            return opcao;
        }
        break;
        case 2:{
            printf("***************************************************************************\n");
            printf("*                          PESQUISAR POR NOME                             *\n");
            printf("***************************************************************************\n");
            printf("\n");
            return opcao;
        }
        break;
        case 3:{
            printf("***************************************************************************\n");
            printf("*                               CADASTRAR                                 *\n");
            printf("***************************************************************************\n");
            printf("\n");
            return opcao;
        }
        break;
        default:{
            printf("OPCAO INVALIDA\n");
            printf("\n");
            opcao = 0;
            return opcao;
        }
    }
}

//MENU CONTAS
int menuContas(){
    int opcao;
    printf("***************************************************************************\n");
    printf("*                                 CONTAS                                  *\n");
    printf("***************************************************************************\n");
    printf("*  1 - PESQ. POR CPF | 2 - PESQ. NUM. CONTA | 3 - CADASTRAR | 0 - VOLTAR  *\n");
    printf("***************************************************************************\n");
    printf("\n");
    printf("OPCAO:  ");
    scanf("%d",&opcao);
    return opcao;
}

//SUB-MENU CONTAS
int menuSubMenuContas(int opcao){
    switch(opcao){
        case 1:{
            printf("***************************************************************************\n");
            printf("*                    PESQUISAR POR CPF DO CLIENTE                         *\n");
            printf("***************************************************************************\n");
            printf("\n");
            return opcao;
        }
        break;
        case 2:{
            printf("***************************************************************************\n");
            printf("*                    PESQUISAR POR NUMERO DA CONTA                        *\n");
            printf("***************************************************************************\n");
            printf("\n");
            return opcao;
        }
        break;
        case 3:{
            printf("***************************************************************************\n");
            printf("*                         CADASTRAR NOVA CONTA                            *\n");
            printf("***************************************************************************\n");
            printf("\n");
            return opcao;
        }
        break;
        default:{

            printf("OPCAO INVALIDA\n");
            printf("\n");

            opcao = 0;
            return opcao;
        }
    }
}

//MENU ATENDIMENTO
int menuAtendimento(){
    int opcao;
    printf("***************************************************************************\n");
    printf("*                        ATENDIMENTO AO CLIENTE                           *\n");
    printf("***************************************************************************\n");
    printf("*   1 - REGISTRAR SENHA CLIENTE      |     2 - EMITIR SENHA P/ CAIXA      *\n");
    printf("*   3 - EMITIR SENHA P/ MESA         |     0 - VOLTAR                     *\n");
    printf("***************************************************************************\n");
    printf("\n");
    printf("OPCAO:  ");
    scanf("%d",&opcao);
    return opcao;
}

//SUB-MENU ATENDIMENTO
int menuSubMenuAtendimento(int opcao){
    switch(opcao){
        case 1:{
            printf("***************************************************************************\n");
            printf("*                          JA POSSUI CONTA ? 1 - SIM | 0 - NAO            *\n");
            printf("***************************************************************************\n");
            printf("\n");
            return opcao;
        }
        break;
        case 2:{

            printf("***************************************************************************\n");
            printf("*                  SENHAS PARA O ATENDIMENTO NO CAIXA                     *\n");
            printf("***************************************************************************\n");
            printf("\n");
            return opcao;
        }
        break;
        case 3:{

            printf("***************************************************************************\n");
            printf("*                 SENHAS PARA O ATENDIMENTO NA MESA                       *\n");
            printf("***************************************************************************\n");
            printf("\n");
            return opcao;
        }
        break;
        default:{

            printf("OPCAO INVALIDA\n");
            printf("\n");

            opcao = 0;
            return opcao;
        }
    }
}

















































































void insereProduto(produto **prod,produto celula){
	produto *p,*q,*novo;
	q=NULL;
	for(p=*prod;p!=NULL;q=p,p=p->prox){
        if(strcmp(p->codigo,celula.codigo)==0){
            printf("ESTE CODIGO JA EXISTE PARA O PRODUTO %s \n",p->descricao);
            return 0;
        }
	}
	novo=(produto*) malloc(sizeof(produto));
	if(novo !=NULL){
        strcpy(novo->codigo, celula.codigo);
        strcpy(novo->descricao, celula.descricao);
        strcpy(novo->fornecedor, celula.fornecedor);
        strcpy(novo->dataValidade, celula.dataValidade);
        novo->quantidade=celula.quantidade;
        novo->preco=celula.preco;
        novo->prox=NULL;
        if(q==NULL){
            *prod=novo;
        }else if(p==NULL){
            q->prox=novo;
        }
        produto *salvar;
        FILE *arq;
        arq=fopen("produtosTemp.csv","w");
        if(arq == NULL){
            printf("NAO FOI POSSIVEL ABRIR O ARQUIVO \n");
            fclose(arq);
            return 0;
        }else{
            salvar=novo;
            fprintf(arq,"%s;",salvar->codigo);
            fprintf(arq,"%s;",salvar->descricao);
            fprintf(arq,"%s;",salvar->fornecedor);
            fprintf(arq,"%s;",salvar->dataValidade);
            fprintf(arq,"%d;",salvar->quantidade);
            fprintf(arq,"%.2lf;\n",salvar->preco);
        }
        fclose(arq);
        puts("PRODUTO INSERIDO COM SUCESSO!\n");
	}else{
		puts("NAO FOI POSSIVEL A INSERCAO\n");
	}
}

void insereCliente(cliente **clie,cliente celula){
	cliente *p,*q,*novo;
	q=NULL;
	for(p=*clie;p!=NULL;q=p,p=p->prox){
        if(strcmp(p->cpf,celula.cpf)==0){
            printf("ESTE CPF JA EXISTE PARA O CLIENTE %s \n",p->cpf);
            return 0;
        }
	}
	novo=(cliente*) malloc(sizeof(cliente));
	if(novo !=NULL){
        strcpy(novo->nome, celula.nome);
        strcpy(novo->cpf, celula.cpf);
        strcpy(novo->endereco, celula.endereco);
        strcpy(novo->bairro, celula.bairro);
        strcpy(novo->cidade, celula.cidade);
        strcpy(novo->estado, celula.estado);
        strcpy(novo->telefone, celula.telefone);
        novo->prox=NULL;
        if(q==NULL){
            *clie=novo;
        }else if(p==NULL){
            q->prox=novo;
        }
        cliente *salvar;
        FILE *arq;
        arq=fopen("clientesTemp.csv","w");
        if(arq == NULL){
            printf("NAO FOI POSSIVEL ABRIR O ARQUIVO\n");
            fclose(arq);
            return 0;
        }else{
            salvar=novo;

            fprintf(arq,"%s;",salvar->nome);
            fprintf(arq,"%s;",salvar->cpf);
            fprintf(arq,"%s;",salvar->endereco);
            fprintf(arq,"%s;",salvar->bairro);
            fprintf(arq,"%s;",salvar->cidade);
            fprintf(arq,"%s;",salvar->estado);
            fprintf(arq,"%s;\n",salvar->telefone);

        }
        fclose(arq);
        puts("CLIENTE INSERIDO COM SUCESSO!\n");
	}else{
		puts("NAO FOI POSSIVEL A INSERCAO\n");
	}
}

void insereCompra(compra **comp,compra celula){

	compra *p,*q,*novo;
	q=NULL;

	novo=(compra*) malloc(sizeof(compra));

	if(novo !=NULL){

        novo->id=celula.id;
        strcpy(novo->cpf, celula.cpf);
        strcpy(novo->codigo, celula.codigo);
        novo->quantidade=celula.quantidade;
        novo->preco=celula.preco;
        novo->total=celula.total;
        novo->prox=NULL;
        if(q==NULL){
            *comp=novo;
        }else if(p==NULL){
            q->prox=novo;
        }
        compra *salvar;
        FILE *arq;
        arq=fopen("comprasTemp.csv","w");
        if(arq == NULL){
            printf("NAO FOI POSSIVEL ABRIR O ARQUIVO\n");
            fclose(arq);
            return 0;
        }else{
            salvar=novo;
            fprintf(arq,"%d;",salvar->id);
            fprintf(arq,"%s;",salvar->cpf);
            fprintf(arq,"%s;",salvar->codigo);
            fprintf(arq,"%d;",salvar->quantidade);
            fprintf(arq,"%.2lf;",salvar->preco);
            fprintf(arq,"%.2lf;\n",salvar->total);

            printf("\n\n************* TICKET *************\n");
            printf("ID DA COMPRA: %d\n",salvar->id);
            printf("CPF DO CLIENTE: %s\n",salvar->cpf);
            printf("CODIGO DO PRODUTO: %s\n",salvar->codigo);
            printf("QUANTIDADE: %d\n",salvar->quantidade);
            printf("PRECO DO PRODUTO: %.2lf\n",salvar->preco);
            printf("TOTAL DA COMPRA: %.2lf\n",salvar->total);
            printf("**********************************\n");


        }
        fclose(arq);
        puts("\n\nOBRIGADO POR TER COMPRADO CONOSCO! VOLTE SEMPRE! \n");
	}else{
		puts("NAO FOI POSSIVEL REALIZAR A COMPRA\n");
	}
}

void leituraProdutosTEMP(){
	produto *leitura;
	FILE *arq,*arq1;
	arq=fopen("produtosTemp.csv","r");
	arq1=fopen("produtos.csv","a");
	if(arq == NULL){
	}else{
		getc(arq);
		fflush(stdin);
		if (feof(arq)){
            fclose(arq);
            return;
		}
		rewind(arq);
		leitura=(produto *) malloc(sizeof(produto));
		if(leitura == NULL){
				puts("PROBLEMA COM A GRAVACAO\n");
				fclose(arq1);
				fclose(arq);
				return;
		}else{
            while(!feof(arq)){
				fflush(stdin);
				fscanf(arq," %[^;]; %[^;]; %[^;]; %[^;]; %d; %lf; \n", &leitura->codigo, &leitura->descricao, &leitura->fornecedor, &leitura->dataValidade, &leitura->quantidade, &leitura->preco);
				fflush(stdin);
				fprintf(arq1,"%s;",leitura->codigo);
				fprintf(arq1,"%s;",leitura->descricao);
				fprintf(arq1,"%s;",leitura->fornecedor);
				fprintf(arq1,"%s;",leitura->dataValidade);
				fprintf(arq1,"%d;",leitura->quantidade);
				fprintf(arq1,"%.2lf;\n",leitura->preco);
				}
			}
	}
	fclose(arq1);
	fclose(arq);
	remove("produtosTemp.csv");
}

void leituraProdutos(produto **prod){
	produto *leitura,*novo;
	FILE *arq;
	arq=fopen("produtos.csv","r");
	if(arq == NULL){

	}else{
		getc(arq);
		fflush(stdin);
		if (feof(arq)){
            fclose(arq);
            return;
		}
		rewind(arq);
		while(!feof(arq)){
			leitura=(produto *) malloc(sizeof(produto));
			if(leitura == NULL){
				puts("NÃO FOI POSSIVEL REALIZAR A OPERACAO\n");
				fclose(arq);
				return;
			}else{
				fflush(stdin);
				fscanf(arq," %[^;]; %[^;]; %[^;]; %[^;]; %d; %lf; \n", &leitura->codigo, &leitura->descricao, &leitura->fornecedor, &leitura->dataValidade, &leitura->quantidade, &leitura->preco);
				fflush(stdin);
				leitura->prox=NULL;
				if(*prod==NULL){
					*prod=leitura;
					novo=leitura;
				}else{
					for(novo=*prod;novo->prox!=NULL;novo=novo->prox);

					novo->prox=leitura;
				}
			}
		}
	}
	fclose(arq);
}

void pesquisaProdutoPorDescricao(produto *prod, char pesquisa[]){
	produto *p;
	int cont=0;
	if(prod==NULL){
		printf("NAO EXISTEM PRODUTOS CADASTRADOS\n");
	}else{
	    p=prod;
		while(p!=NULL){
            if(strcmp(p->descricao,pesquisa)==0){
                imprimirProduto(p);
                cont++;
            }
            p=p->prox;
        }
        if(cont==0){
            printf("PRODUTO NAO ENCONTRADO! \n");
            return 0;
        }
	}
}

void pesquisaProdutoPorFornecedor(produto *prod, char pesquisa[]){
	produto *p;
	int cont=0;
	if(prod==NULL){
		printf("NAO EXISTEM PRODUTOS CADASTRADOS\n");
	}else{
	    p=prod;

		while(p!=NULL){
            if(strcmp(p->fornecedor,pesquisa)==0){
                imprimirProduto(p);
                cont++;
            }
            p=p->prox;
        }
        if(cont==0){
            printf("PRODUTO NAO ENCONTRADO! \n");
            return 0;
        }
	}
}

void imprimirProduto(produto *prod){
	printf("*****************************************************\n");
	printf("* CODIGO: %s\n",prod->codigo);
	printf("* DESCRICAO: %s\n",prod->descricao);
	printf("* FORNECEDOR: %s\n",prod->fornecedor);
	printf("* DATA DE VALIDADE: %s\n",prod->dataValidade);
	printf("* QUANTIDADE: %d\n",prod->quantidade);
	printf("* PRECO: %.2lf\n",prod->preco);
	printf("*****************************************************\n");
}

void leituraClientesTEMP(){
	cliente *leitura;
	FILE *arq,*arq1;
	arq=fopen("clientesTemp.csv","r");
	arq1=fopen("clientes.csv","a");
	if(arq == NULL){
	}else{
		getc(arq);
		fflush(stdin);
		if (feof(arq)){
            fclose(arq);
            return;
		}
		rewind(arq);
		leitura=(cliente *) malloc(sizeof(cliente));
		if(leitura == NULL){
				puts("PROBLEMA COM A GRAVACAO\n");
				fclose(arq1);
				fclose(arq);
				return;
		}else{
            while(!feof(arq)){
				fflush(stdin);
				fscanf(arq," %[^;]; %[^;]; %[^;]; %[^;]; %[^;]; %[^;]; %[^;]; \n", &leitura->nome, &leitura->cpf, &leitura->endereco, &leitura->bairro, &leitura->cidade, &leitura->estado, &leitura->telefone);
				fflush(stdin);
				fprintf(arq1,"%s;",leitura->nome);
				fprintf(arq1,"%s;",leitura->cpf);
				fprintf(arq1,"%s;",leitura->endereco);
				fprintf(arq1,"%s;",leitura->bairro);
				fprintf(arq1,"%s;",leitura->cidade);
				fprintf(arq1,"%s;",leitura->estado);
                fprintf(arq1,"%s;\n",leitura->telefone);
				}
			}
	}
	fclose(arq1);
	fclose(arq);
	remove("clientesTemp.csv");
}

void leituraClientes(cliente **clie){
	cliente *leitura,*novo;
	FILE *arq;
	arq=fopen("clientes.csv","r");
	if(arq == NULL){

	}else{
		getc(arq);
		fflush(stdin);
		if (feof(arq)){
            fclose(arq);
            return;
		}
		rewind(arq);
		while(!feof(arq)){
			leitura=(cliente *) malloc(sizeof(cliente));
			if(leitura == NULL){
				puts("NÃO FOI POSSIVEL REALIZAR A OPERACAO\n");
				fclose(arq);
				return;
			}else{
				fflush(stdin);
				fscanf(arq," %[^;]; %[^;]; %[^;]; %[^;]; %[^;]; %[^;]; %[^;]; \n", &leitura->nome, &leitura->cpf, &leitura->endereco, &leitura->bairro, &leitura->cidade, &leitura->estado, &leitura->telefone);
				fflush(stdin);
				leitura->prox=NULL;
				if(*clie==NULL){
					*clie=leitura;
					novo=leitura;
				}else{
					for(novo=*clie;novo->prox!=NULL;novo=novo->prox);

					novo->prox=leitura;
				}
			}
		}
	}
	fclose(arq);
}

void pesquisaClientePorNome(cliente *clie, char pesquisa[]){
	cliente *p;
	int cont=0;
	if(clie==NULL){
		printf("NAO EXISTEM CLIENTES CADASTRADOS\n");
	}else{
	    p=clie;
		while(p!=NULL){
            if(strcmp(p->nome,pesquisa)==0){
                imprimirCliente(p);
                cont++;
            }
            p=p->prox;
        }
        if(cont==0){
            printf("CLIENTE NAO ENCONTRADO! \n");
            return 0;
        }
	}
}

void imprimirCliente(cliente *clie){
	printf("*****************************************************\n");
	printf("* NOME: %s\n",clie->nome);
	printf("* CPF: %s\n",clie->cpf);
	printf("* ENDERECO: %s\n",clie->endereco);
	printf("* BAIRRO: %s\n",clie->bairro);
	printf("* CIDADE: %s\n",clie->cidade);
	printf("* ESTADO: %s\n",clie->estado);
	printf("* TELEFONE: %s\n",clie->telefone);
	printf("*****************************************************\n");
}

void leituraComprasTEMP(){
	compra *leitura;
	FILE *arq,*arq1;
	arq=fopen("comprasTemp.csv","r");
	arq1=fopen("compras.csv","a");
	if(arq == NULL){
	}else{
		getc(arq);
		fflush(stdin);
		if (feof(arq)){
            fclose(arq);
            return;
		}
		rewind(arq);
		leitura=(compra *) malloc(sizeof(compra));
		if(leitura == NULL){
				puts("PROBLEMA COM A GRAVACAO\n");
				fclose(arq1);
				fclose(arq);
				return;
		}else{
            while(!feof(arq)){
				fflush(stdin);
				fscanf(arq," %d; %[^;]; %[^;]; %d; %lf; %lf;  \n", &leitura->id, &leitura->cpf, &leitura->codigo, &leitura->quantidade, &leitura->preco, &leitura->total);
				fflush(stdin);
				fprintf(arq1,"%d;",leitura->id);
				fprintf(arq1,"%s;",leitura->cpf);
				fprintf(arq1,"%s;",leitura->codigo);
				fprintf(arq1,"%d;",leitura->quantidade);
				fprintf(arq1,"%lf;",leitura->preco);
				fprintf(arq1,"%lf;\n",leitura->total);
				}
			}
	}
	fclose(arq1);
	fclose(arq);
	remove("comprasTemp.csv");
}

void leituraCompras(compra **comp){
	compra *leitura,*novo;
	FILE *arq;
	arq=fopen("compras.csv","r");
	if(arq == NULL){

	}else{
		getc(arq);
		fflush(stdin);
		if (feof(arq)){
            fclose(arq);
            return;
		}
		rewind(arq);
		while(!feof(arq)){
			leitura=(compra *) malloc(sizeof(compra));
			if(leitura == NULL){
				puts("NÃO FOI POSSIVEL REALIZAR A OPERACAO\n");
				fclose(arq);
				return;
			}else{
				fflush(stdin);
				fscanf(arq," %d; %[^;]; %[^;]; %d; %lf; %lf;  \n", &leitura->id, &leitura->cpf, &leitura->codigo, &leitura->quantidade, &leitura->preco, &leitura->total);
				fflush(stdin);
				leitura->prox=NULL;
				if(*comp==NULL){
					*comp=leitura;
					novo=leitura;
				}else{
					for(novo=*comp;novo->prox!=NULL;novo=novo->prox);

					novo->prox=leitura;
				}
			}
		}
	}
	fclose(arq);
}

void pesquisaCompraPorCpf(compra *comp, char pesquisa[]){
	compra *p;
	int cont=0;
	if(comp==NULL){
		printf("NAO EXISTEM COMPRAS CADASTRADAS\n");
	}else{
	    p=comp;
		while(p!=NULL){
            if(strcmp(p->cpf,pesquisa)==0){
                imprimirCompra(p);
                cont++;
            }
            p=p->prox;
        }
        if(cont==0){
            printf("NAO FORAM ENCONTRADAS COMPRAS PARA ESTE CPF! \n");
            return 0;
        }
	}
}

void pesquisaCompraPorCodigo(compra *comp, char pesquisa[]){
	compra *p;
	int cont=0;
	if(comp==NULL){
		printf("NAO EXISTEM COMPRAS CADASTRADAS\n");
	}else{
	    p=comp;
		while(p!=NULL){
            if(strcmp(p->codigo,pesquisa)==0){
                imprimirCompra(p);
                cont++;
            }
            p=p->prox;
        }
        if(cont==0){
            printf("NAO FORAM ENCONTRADAS COMPRAS PARA ESTE CODIGO DE PRODUTO! \n");
            return 0;
        }
	}
}

void imprimirCompra(compra *comp){
	printf("*****************************************************\n");
	printf("* ID DA COMPRA: %d\n",comp->id);
	printf("* CPF: %s\n",comp->cpf);
	printf("* CODIGO DO PRODUTO: %s\n",comp->codigo);
	printf("* QUANTIDADE: %d\n",comp->quantidade);
	printf("* PRECO: %.2lf\n",comp->preco);
	printf("* TOTAL: %.2lf\n",comp->total);
	printf("*****************************************************\n");
}








int retornaEstoque(produto *prod, char pesquisa[]){
	produto *p;
	int cont=0;
	int estoque = 0;
	if(prod==NULL){
		return 0;
	}else{
	    p=prod;
		while(p!=NULL){
            if(strcmp(p->codigo,pesquisa)==0){
                estoque = p->quantidade;
                return estoque;
                cont++;
            }
            p=p->prox;
        }

        if(cont==0){
            return 0;
        }
	}
}

double retornaPreco(produto *prod, char pesquisa[]){
	produto *p;
	int cont=0;
	double preco = 0;
    if(prod==NULL){
		return 0;
	}else{
	    p=prod;
		while(p!=NULL){
            if(strcmp(p->codigo,pesquisa)==0){
                preco = p->preco;
                return preco;
                cont++;
            }
            p=p->prox;
        }

        if(cont==0){
            return 0;
        }
	}
}


int retornaId(compra *comp){
	compra *p;
	int cont=0;
	if(comp==NULL){
		return 0;
	}else{
        p=comp;
		while(p!=NULL){
            cont++;
            p=p->prox;
        }
	}
	//AQUI ELE CHEGA COM O ID QUE ESTÁ LÁ DENTRO

	// AQUI ELE AUMENTA O ID PRA RETORNAR
	cont++;
	return cont;
}






int main (void){

    int opcao = 0, verificaCodigo = 0;

	char pesquisa1[100],pesquisa2[100];

	produto *prod, produto_inserir;

	cliente *clie, cliente_inserir;
	compra *comp, compra_inserir;

	prod = NULL;
	clie = NULL;
	comp = NULL;

    int estoque = 0, quant = 0, id = 0;
    double preco;

    leituraProdutosTEMP();
    leituraProdutos(&prod);

    leituraClientesTEMP();
    leituraClientes(&clie);

    leituraComprasTEMP();
    leituraCompras(&comp);


    while(opcao!=4){

        opcao = menuPrincipal();

        switch(opcao){
            case 1:{
                opcao = menuProdutos();
                if(opcao != 0){
                    opcao = menuSubMenuProdutos(opcao);
                    if(opcao == 1){
                        printf("DESCRICAO: ");
						scanf(" %[^\n]s",pesquisa1);
						fflush(stdin);
						pesquisaProdutoPorDescricao(prod,pesquisa1);
                        puts("");

                    }
                    if(opcao == 2){
                        printf("FORNECEDOR: ");
						scanf(" %[^\n]s",pesquisa1);
						fflush(stdin);
						pesquisaProdutoPorFornecedor(prod,pesquisa1);
                        puts("");

                    }
                    if(opcao == 3){
                        fflush(stdin);
						printf("CODIGO: ");
						scanf(" %[^\n]s",&produto_inserir.codigo);
						fflush(stdin);
						printf("DESCRICAO: ");
						scanf(" %[^\n]s",&produto_inserir.descricao);
						fflush(stdin);
						printf("FORNECEDOR: ");
						scanf(" %[^\n]s",&produto_inserir.fornecedor);
						fflush(stdin);
                        printf("DATA DE VALIDADE: ");
						scanf(" %[^\n]s",&produto_inserir.dataValidade);
						fflush(stdin);
                        printf("QUANTIDADE: ");
						scanf(" %d",&produto_inserir.quantidade);
						fflush(stdin);
						printf("PRECO: ");
						scanf("%lf",&produto_inserir.preco);
						fflush(stdin);
                        insereProduto(&prod,produto_inserir);
						puts("");

                    }
                }

            }
            break;
            case 2:{
                opcao = menuClientes();
                if(opcao != 0){
                    opcao = menuSubMenuClientes(opcao);
                    if(opcao == 1){
                        printf("NOME: ");
						scanf(" %[^\n]s",pesquisa1);
						fflush(stdin);
						pesquisaClientePorNome(clie,pesquisa1);
                        puts("");

                    }
                    if(opcao == 2){
                        fflush(stdin);
						printf("NOME: ");
						scanf(" %[^\n]s",&cliente_inserir.nome);
						fflush(stdin);
						printf("CPF: ");
						scanf(" %[^\n]s",&cliente_inserir.cpf);
						fflush(stdin);
						printf("ENDERECO: ");
						scanf(" %[^\n]s",&cliente_inserir.endereco);
						fflush(stdin);
                        printf("BAIRRO: ");
						scanf(" %[^\n]s",&cliente_inserir.bairro);
						fflush(stdin);
                        printf("CIDADE: ");
						scanf(" %[^\n]s",&cliente_inserir.cidade);
						fflush(stdin);
						printf("ESTADO: ");
						scanf(" %[^\n]s",&cliente_inserir.estado);
						fflush(stdin);
						printf("TELEFONE: ");
						scanf(" %[^\n]s",&cliente_inserir.telefone);
						fflush(stdin);
                        insereCliente(&clie,cliente_inserir);
						puts("");


                    }

                }
            }
            break;
            case 3:{
                opcao = menuCompras();
                if(opcao != 0){
                    opcao = menuSubMenuCompras(opcao);
                    if(opcao == 1){
                        printf("CPF: ");
						scanf(" %[^\n]s",pesquisa1);
						fflush(stdin);
						pesquisaCompraPorCpf(comp,pesquisa1);
                        puts("");

                    }
                    if(opcao == 2){
                        printf("CODIGO DO PRODUTO: ");
						scanf(" %[^\n]s",pesquisa1);
						fflush(stdin);
						pesquisaCompraPorCodigo(comp,pesquisa1);
                        puts("");

                    }
                    if(opcao == 3){
                        id = retornaId(comp);
                        fflush(stdin);
						compra_inserir.id = id;
						fflush(stdin);
						printf("CPF: ");
						scanf(" %[^\n]s",&compra_inserir.cpf);
						fflush(stdin);
						printf("CODIGO DO PRODUTO: ");
						scanf(" %[^\n]s",&compra_inserir.codigo);
						fflush(stdin);
                        printf("QUANTIDADE: ");
						scanf(" %d",&compra_inserir.quantidade);

                        quant = compra_inserir.quantidade;

                        estoque = retornaEstoque(prod,compra_inserir.codigo);
                        if(quant > estoque){
                           printf("QUANTIDADE INDISPONIVEL EM ESTOQUE PARA ESTA PRODUTO");

                           break;
                        }
                        else{
                            fflush(stdin);
                            preco = retornaPreco(prod,compra_inserir.codigo);
                            if(preco == 0){
                               printf("NAO FOI POSSIVEL REALIZAR A COMPRA PARA O PRODUTO INFORMADO");

                               break;
                            }
                            else{
                                compra_inserir.preco = preco;
                                compra_inserir.preco = preco;
                                compra_inserir.total = (quant) * (preco);
                                fflush(stdin);

                                insereCompra(&comp,compra_inserir);

                                puts("");

                            }
                        }
                    }
                }
            }
            break;
            case 4:{
                leituraProdutosTEMP();
                leituraProdutos(&prod);

                leituraClientesTEMP();
                leituraClientes(&clie);

                leituraComprasTEMP();
                leituraCompras(&comp);

                printf("\n");
                printf("OBRIGADO POR UTILIZAR ESSA PORCARIA!\n");
                printf("\n");
                return 0;
            }
            break;
            default:{
                printf("\n");
                printf("OPCAO INVALIDA !\n");
                opcao = 0;
                printf("\n");

            }
            break;
        }
    }

}
