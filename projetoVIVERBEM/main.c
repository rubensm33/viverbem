#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

//Verifica Código
int j = 0;

//Verificador para consulta
int n = 0, m = 0;

//Cadastro Cliente
int parar_cadastro = 2, i = 0, x = 0;

//Verificador para consulta médico
int s = 0, limpaVetor = 0;


struct tp_enderecoJMR
{
    char rua[40], bairro[40], cidade[40], estado[3];
    int numero;

};
struct tp_datanascimentoJMR
{
    int dia, mes, ano;
};

struct tp_cadastroClienteJMR
{

    int codigo_cliente;
    char nome_cliente[50];
    struct tp_enderecoJMR enderecoJMR;
    int telefone_cliente;
    struct tp_datanascimentoJMR datanascimentoJMR;
}
cad_cliente[50];

//Cadastro Médico

struct tp_cadastroMedicoJMR
{
    int codigo_medico, qtd_consultas;
    char nome_medico[50];
    int telefone_medico;
    char especialidade_medico[40];

}
cad_medico[50];

//Cadastro Consulta
struct tp_dataConsultaJMR
{
    int dia, mes, ano;
};
struct tp_horaConsultaJMR
{
    int hora, minuto;
};

struct tp_cadastroConsultaJMR
{
    int codigo_consulta;
    struct tp_dataConsultaJMR dataConsultaJMR;
    struct tp_horaConsultaJMR horaConsultaJMR;
    int codigo_cliente;
    int codigo_medico;
    char nome_medico[50];
    char especialidade_medico[40];
    char nome_cliente[50];



}cad_consulta[50];




FILE *arquivoClientes;
FILE *arquivoMedicos;
FILE *arquivoConsulta;


int main()
{
    setlocale(LC_ALL, "Portuguese");
    inicializaArquivos(arquivoClientes, arquivoMedicos, arquivoConsulta);


    int menu;
    do {
        printf("\n\n============================\n");
        printf("Selecione uma opção:\n");
        printf("1 - Cadastrar um Cliente\n");
        printf("2 - Imprimir Clientes\n");
        printf("3 - Cadastrar um Médico\n");
        printf("4 - Imprimir Médicos\n");
        printf("5 - Cadastrar uma Consulta\n");
        printf("6 - Imprimir Consultas\n");
        printf("7 - Apagar uma Consulta\n");
        printf("8 - Verificar Consultas\n");
        printf("9 - Verificar Consultas do Médico\n");
        printf("10 - Verificar Consultas do Cliente\n");
        printf("0 - Sair do programa\n");
        printf("Opcao: ");
        scanf("%d",&menu);
        printf("============================");
        switch(menu)
        {
            case 0:
                printf("Saindo... \n");
                break;
            case 1:
                cadastro_clienteJMR(arquivoClientes);
                break;
            case 2:
                imprimir_clienteJMR(arquivoClientes);
                break;
            case 3:
                cadastro_medicoJMR(arquivoMedicos);
                break;
            case 4:
                imprimir_medicoJMR(arquivoMedicos);
                break;
            case 5:
                cadastro_consultaJMR(arquivoClientes, arquivoMedicos, arquivoConsulta);
                break;
            case 6:
                imprimir_consultaJMR(arquivoConsulta);
                break;
            case 7:
                cancela_consultaJMR(arquivoConsulta);
                break;
            case 8:
                verificar_ConsultasDiaJMR(arquivoConsulta);
                break;
            case 9:
                imprimir_consultasMedicosJMR(arquivoConsulta);
                break;

            case 10:
                imprimir_consultasClientesJMR(arquivoConsulta);
            default:
                printf("Opção inválida.\n\n");
                break;
        }
    }while(menu != 0);




}





//Funções Clientes

int cadastro_clienteJMR(FILE *arquivoClientes)
{
    do
    {

        if(parar_cadastro == 1)
        {
            i++;
            j++;
        }


        printf("\nCódigo do cliente: ");
        scanf("%d",& cad_cliente[i].codigo_cliente);

        if(cad_cliente[j].codigo_cliente == cad_cliente[j-1].codigo_cliente)
        {
            break;
        }



        printf("\nNome do cliente: ");
        fflush(stdin);
        gets(cad_cliente[i].nome_cliente);

        printf("\nDigite o número do endereço: ");
        scanf("%d",& cad_cliente[i].enderecoJMR.numero);

        printf("\nDigite a rua: ");
        fflush(stdin);
        gets(cad_cliente[i].enderecoJMR.rua);

        printf("\nDigite o bairro: ");
        fflush(stdin);
        gets(cad_cliente[i].enderecoJMR.bairro);


        printf("\nDigite a cidade: ");
        fflush(stdin);
        gets(cad_cliente[i].enderecoJMR.cidade);


        printf("\nDigite o estado: ");
        fflush(stdin);
        gets(cad_cliente[i].enderecoJMR.estado);

        printf("\nDigite o telefone: ");
        scanf("%d",& cad_cliente[i].telefone_cliente);

        printf("\nDigite o dia do nascimento: ");
        scanf("%d",& cad_cliente[i].datanascimentoJMR.dia);

        printf("\nDigite o mês do nascimento: ");
        scanf("%d",& cad_cliente[i].datanascimentoJMR.mes);

        printf("\nDigite o ano do nascimento: ");
        scanf("%d",& cad_cliente[i].datanascimentoJMR.ano);

        printf("\nDeseja cadastrar mais um cliente?\nDigite 1 para sim\nDigite 0 para não\n");
        scanf("%d",& parar_cadastro);
    }
    while(parar_cadastro != 0);
    printf("\nQuantidade de cadastros \n%d", i+1);
    return cad_cliente;
}

void imprimir_clienteJMR(FILE *arquivoClientes)
{
    for(x=0; x<=i; x++)
    {
        printf("\nCódigo Cliente: %d", cad_cliente[x].codigo_cliente);
        printf("\nNome do Cliente: %s", cad_cliente[x].nome_cliente);
        printf("\nNumero do Endereço do Cliente: %d", cad_cliente[x].enderecoJMR.numero);
        printf("\nRua do Cliente: %s", cad_cliente[x].enderecoJMR.rua);
        printf("\nBairro do Cliente: %s", cad_cliente[x].enderecoJMR.bairro);
        printf("\nCidade do Cliente: %s", cad_cliente[x].enderecoJMR.cidade);
        printf("\nEstado do Cliente: %s", cad_cliente[x].enderecoJMR.estado);
        printf("\nTelefone  do Cliente: %d", cad_cliente[x].telefone_cliente);
        printf("\nDia do Nascimento do Cliente: %d", cad_cliente[x].datanascimentoJMR.dia);
        printf("\nMês do Nascimento do Cliente: %d", cad_cliente[x].datanascimentoJMR.mes);
        printf("\nAno do Nascimento do Cliente: %d", cad_cliente[x].datanascimentoJMR.ano);

    }
}


//Funções Médicos

int cadastro_medicoJMR(FILE *arquivoMedicos)
{
    do
    {

        if(parar_cadastro == 1)
        {
            i++;
        }
        printf("\nCódigo do medico: ");
        scanf("%d",& cad_medico[i].codigo_medico);
        if(cad_medico[j].codigo_medico == cad_medico[j-1].codigo_medico)
        {
            break;
        }

        printf("\nNome do medico: ");
        fflush(stdin);
        gets(cad_medico[i].nome_medico);

        printf("\nDigite o telefone do médico: ");
        scanf("%d",& cad_medico[i].telefone_medico);

        printf("\nEspecialidade do médico ");
        fflush(stdin);
        gets(cad_medico[i].especialidade_medico);



        printf("\nDeseja cadastrar mais um médico?\nDigite 1 para sim\nDigite 0 para não\n");
        scanf("%d",& parar_cadastro);
    }
    while(parar_cadastro != 0);
    printf("\nQuantidade de cadastros \n%d", i+1);
    return cad_medico;
}

void imprimir_medicoJMR(FILE *arquivoMedicos)
{
    for(x=0; x<=i; x++)
    {
        printf("\nCódigo Médico: %d", cad_medico[x].codigo_medico);
        printf("\nNome do Médico: %s", cad_medico[x].nome_medico);
        printf("\nNumero de telefone: %d", cad_medico[x].telefone_medico);
        printf("\nEspecialidade do médico: %s", cad_medico[x].especialidade_medico);

    }
}

//Funções Consultas

int cadastro_consultaJMR(FILE *arquivoConsulta)
{
    int cancelaConsulta = 0;
    do
    {

        if(parar_cadastro == 1)
        {
            i++;
        }
        printf("\nCódigo do paciente que irá consultar: ");
        scanf("%d",& n);
        cad_consulta[i].codigo_cliente = cad_cliente[n].codigo_cliente;
        do
        {


            printf("\nCódigo do médico que irá atender a consulta: ");
            scanf("%d",& n);
            cad_consulta[i].codigo_medico = cad_medico[n].codigo_medico;

            cad_medico[n].qtd_consultas ++;
          //  if(cad_medico[n].qtd_consultas > 2)
            //{
              //  printf("O máximo de consultas para o médico %d foi atingido, por favor, selecione outro médico", n);
            //}

            for(m = 0; m<50; m++)
            {
                if(cad_medico[n].qtd_consultas > 2 && cad_consulta[m].dataConsultaJMR.mes == cad_consulta[n].dataConsultaJMR.mes && cad_consulta[m].dataConsultaJMR.dia == cad_consulta[n].dataConsultaJMR.dia && cad_consulta[m].dataConsultaJMR.ano == cad_consulta[n].dataConsultaJMR.ano)
                {
                    cancelaConsulta++;
                }
                if(cancelaConsulta>3)
                {
                    printf("O máximo de consultas para o médico %d foi atingido, por favor, selecione outro médico", n);
                    break;
                }
            }
            //if(cad_medico[n].qtd_consultas > 2 && cad_consulta[m].dataConsultaJMR.mes == cad_consulta[o].dataConsultaJMR.mes && cad_consulta[m].dataConsultaJMR.dia == cad_consulta[o].dataConsultaJMR.dia && cad_consulta[m].dataConsultaJMR.ano == cad_consulta[o].dataConsultaJMR.ano){

            // }
        }
        while(cad_medico[n].qtd_consultas > 2);
strcpy(cad_consulta[i].nome_medico, cad_medico[n].nome_medico);
strcpy(cad_consulta[i].especialidade_medico, cad_medico[n].especialidade_medico);
strcpy(cad_consulta[i].nome_cliente, cad_cliente[n].nome_cliente);

        printf("\nDigite o dia da consulta: ");
        scanf("%d",& cad_consulta[i].dataConsultaJMR.dia);
//cad_consulta[i].dataConsultaJMR.dia[1]++;

        printf("\nDigite o mês da consulta: ");
        scanf("%d",& cad_consulta[i].dataConsultaJMR.mes);
        // cad_consulta[i].dataConsultaJMR.mes[1]++;

        printf("\nDigite o ano 0da consulta: ");
        scanf("%d",& cad_consulta[i].dataConsultaJMR.ano);
        // cad_consulta[i].dataConsultaJMR.ano[1]++;



        printf("\nCódigo da Consulta: ");
        scanf("%d",& cad_consulta[i].codigo_consulta);





        printf("\nDeseja cadastrar mais uma consulta?\nDigite 1 para sim\nDigite 0 para não\n");
        scanf("%d",& parar_cadastro);
    }
    while(parar_cadastro != 0);
    printf("\nQuantidade de cadastros \n%d", i+1);
    return cad_medico;
}
void imprimir_consultaJMR(FILE *arquivoConsulta)
{
    for(x=0; x<=i; x++)
    {
        printf("\nCódigo Consulta: %d", cad_consulta[x].codigo_consulta);
        printf("\nCódigo do Médico: %d", cad_consulta[x].codigo_medico);
        printf("\nCódigo do Cliente: %d", cad_consulta[x].codigo_cliente);
        printf("\nEspecialidade do médico: %s\n", cad_medico[x].especialidade_medico);

    }
}

void cancela_consultaJMR(FILE *arquivoConsulta){
    int cancelaConsulta;
printf("\nDigite o código da consulta que deseja cancelar");
scanf("%d",& cancelaConsulta);
cad_consulta[cancelaConsulta].codigo_cliente = 0;
cad_consulta[cancelaConsulta].codigo_medico = 0;
cad_consulta[cancelaConsulta].dataConsultaJMR.dia = 0;
cad_consulta[cancelaConsulta].dataConsultaJMR.mes = 0;
cad_consulta[cancelaConsulta].dataConsultaJMR.ano = 0;
cad_consulta[cancelaConsulta].codigo_consulta = 0;
strcpy(cad_consulta[cancelaConsulta].especialidade_medico, "0");
strcpy(cad_consulta[cancelaConsulta].nome_medico,"0");


printf("A consulta %d foi cancelada", cancelaConsulta);

}
void verificar_ConsultasDiaJMR(FILE *arquivoConsulta, FILE *arquivoMedicos, FILE *arquivoClientes){
    int verfica_dia, verfica_mes, verfica_ano;
        printf("\nDigite o dia da consulta: ");
        scanf("%d",& verfica_dia);


        printf("\nDigite o mês da consulta: ");
        scanf("%d",& verfica_mes);


        printf("\nDigite o ano da consulta: ");
        scanf("%d",& verfica_ano);
         for(m = 0; m<50; m++){
        if(cad_consulta[m].dataConsultaJMR.mes == verfica_mes && cad_consulta[m].dataConsultaJMR.dia == verfica_dia && cad_consulta[m].dataConsultaJMR.ano == verfica_ano){
            printf("Consultas para a data %d/%d/%d: \nCódigo da Consulta: %d\nCódigo do Cliente: %d\nCódigo do Médico: %d\nNome do Cliente: %s\nNome do Médico: %s\nEspecialidade do Médico: %s\n2", verfica_dia,verfica_mes,verfica_ano, cad_consulta[m].codigo_consulta,cad_consulta[m].codigo_cliente,cad_consulta[m].codigo_medico, cad_consulta[m].nome_cliente, cad_consulta[m].nome_medico , cad_consulta[m].especialidade_medico);
        }


         }
}
void imprimir_consultasClientesJMR(FILE *arquivoConsulta){
    printf("\nDigite o código do cliente: ");
    scanf("%d",& s);


    for(m = 0; m<50; m++){
    if(cad_consulta[m].codigo_cliente == cad_consulta[s].codigo_cliente){
    printf("\nAs consultas do médico são:\nCódigo da Consulta: %d\nCódigo do médico: %d\nCódigo do Cliente: %d\nNome do médico %s\n", cad_consulta[m].codigo_consulta, cad_consulta[m].codigo_medico, cad_consulta[m].codigo_cliente, cad_consulta[m].nome_medico);
    }
    }

}
void imprimir_consultasMedicosJMR(FILE *arquivoConsulta){
    printf("\nDigite o código do médico: ");
    scanf("%d",& s);
for(m = 2; m<50; m++){
    cad_consulta[m].codigo_medico = 9;
}

    for(m = 0; m<50; m++){
    if(cad_consulta[m].codigo_medico == cad_consulta[s].codigo_medico){
    printf("\nAs consultas do médico são:\nCódigo da Consulta: %d\nCódigo do médico: %d\nCódigo do Cliente: %d\nNome do médico %s\n", cad_consulta[m].codigo_consulta, cad_consulta[m].codigo_medico, cad_consulta[m].codigo_cliente, cad_consulta[m].nome_medico);
    }
    }

}

void inicializaArquivos(){ //Função para inicializar todos os arquivos de registro
    if ((arquivoClientes=fopen("arquivoClientes.txt","r+b"))==NULL)
    {
        printf("Criando arquivo de clientes...\n");
        if ((arquivoClientes=fopen("arquivoClientes.txt","a+b"))==NULL)
        {
            printf("Erro na criação do arquivo de clientes!!\n");
            exit(1);
        }
    }

    if ((arquivoMedicos=fopen("arquivoMedicos.txt","r+b"))==NULL)
    {
        printf("Criando arquivo de médicos...\n");
        if ((arquivoMedicos=fopen("arquivoMedicos.txt","a+b"))==NULL)
        {
            printf("Erro na criação do arquivo de médicos!!\n");
            exit(1);
        }
    }

    if ((arquivoConsulta=fopen("arquivoConsulta.txt","r+b"))==NULL)
    {
        printf("Criando arquivo de consultas...\n");
        if ((arquivoConsulta=fopen("arquiConsultas.txt","a+b"))==NULL)
        {
            printf("Erro na criação do arquivo de consultas!!\n");
            exit(1);
        }
    }

    return;
}



