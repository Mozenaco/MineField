#include <iostream>//Biblioteca padrão.
#include <windows.h>//Para os comandos de BEEP, Sleep.
#include <cstdlib>//Para usar o gerador de numeros randomicos.(rand)
#include <ctime>//Para o comando de randomização.(srand)
#include <stdio.h>
using namespace std;//Faz isto porque as bibliotecas podem não estar divididas em namespaces.
//Irá Usar(using) o namespace std (standard, padrão) da biblioteca iostream.

int abertas[9][9], soma = 0, x, y;//Variáveis globais pois vou usá-las em várias funções

void titulo(void);//Função que aparece o titulo do jogo.
void colocarzeros(int mat[9][9]);//Função que coloca zeros na primeira matriz de inteiros.
void colocabombas(int mat[9][9]);//Função que coloca bombas na primeira matriz de inteiros.
void imprimirmatriz(int mat[9][9]);//Função que imprime a matriz inteira, necessária para verificação.
void tratarnumeros(int mat[9][9]);//Função que trata dos numeros em volta das bombas.
void colocarcifrao(char mat[9][9]);//Função que coloca os cifroes na matriz char.
void imprimirmatriz3(char mat[9][9]);//Função que imprime a matriz do jogo.
void escolha(int mat1[9][9],int mat2[9][9],char mat3[9][9]);//Função que olha a escolha do usuário.
void abrezeros(int mat1[9][9], int mat2[9][9], char mat3[9][9], int x, int y);//Função que abre os zeros em volta.
void nota(void);//Função que imprime a nota quando o usuário ganhar.

int main()//Função principal.
{
    system ("title CAMPO MINADO BY MATEUS");//Coloca um título na janela do MS-DOS.
    int matriz[9][9],matriz2[9][9];//Matriz de numeros e matriz do numeros pela tabela ASCII.
    char matriz3[9][9], resp, resposta;//Matriz de caracteres e respostas para entrar no jogo e jogar denovo.
    soma = 0;//Iguala a 0, pois se o jogo for chamado denovo deve começar denovo a contagem.
    fflush (stdin);//Limpar o buffer do teclado para jogos anteriores nao afetarem os próximos.
    system("color 2F");//Primeira letra corresponde ao BACKGROUND e a segunda a cor da letra.

    while((resp!=49) || (resp!=50) || (resp!=51))
    {
        //Aparece o menu o jogo e enquanto a resposta digitada for diferente que 1, 2 ou 3, irá repetir.
        system("cls");
        cout<<"\t\t    \xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB"<<endl;
        cout <<"\t\t    \xBA                 MENU DO JOGO                \xBA"<<endl;
        cout<<"\t\t    \xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC"<<endl;
        cout <<"\t\t       \xBA---------------------------------------\xBA"<<endl;
        cout <<"\t\t       \xBA           Digite sua opcao:           \xBA"<<endl;
        cout <<"\t\t       \xBA---------------------------------------\xBA"<<endl;
        cout <<"\t\t       \xBA----------- 1. Entrar no Jogo ---------\xBA"<<endl;
        cout <<"\t\t       \xBA----------- 2. Creditos ---------------\xBA"<<endl;
        cout <<"\t\t       \xBA----------- 3. Sair -------------------\xBA"<<endl;
        cout<<"\t\t       \xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC"<<endl;
        cout <<"\t\t\t";
        cin>>resp;//Pega a resposta digitada pelo usuário.
        if (resp==50)//Se a resposta dele for igual a 2(pela tabela ASCII).
        {
            system("cls");
            cout <<"   PLANEJAMENTO: Mateus de Oliveira Andrade"<<endl;
            Sleep(800);//O processamento faz uma pausa de 800 milisegundos.
            cout <<endl<<"\t   DIGITACAO: Mateus de Oliveira Andrade"<<endl<<endl;
            Sleep(800);
            cout <<"\t\t   FORMATACAO: Mateus de Oliveira Andrade"<<endl<<endl;
            Sleep(800);
            cout <<"\t\t\t   ACABAMENTO: Mateus de Oliveira Andrade"<<endl<<endl;
            Sleep(800);
            cout <<"\t\t\t\t   ARTES GRAFICAS: Mateus de Oliveira Andrade"<<endl<<endl;
            Sleep(800);
            cout <<endl<<"\t\t      ";
            system("pause");
            system("cls");
            resp = 51;//Iguala a 3(pela tabela ASCII), para nao interfirir se quiser sair depois.
            main();//Mostra os créditos e volta a função principal.
        }
        if (resp==51) return (EXIT_SUCCESS);
        //Se a reposta for 3(pela tabela ASCII), sai do jogo.
        if(resp==49)//Se a reposta for 1(pela tabela ASCII) inicia o jogo.
        {

            titulo();//Função título sem parâmetros, visto que ela é VOID.
            colocarzeros(matriz);//Função colocarzeros coloca zeros na matriz de inteiros.
            colocarzeros(abertas);//Função colocarzeros coloca zeros na matriz de contagem dos abertos.
            colocabombas(matriz);//Função colocarbombas coloca bombas na matriz de inteiros.
            tratarnumeros(matriz);//Função tratarnumeros coloca numeros em volta das bombas.
            colocarcifrao(matriz3);//Função colocarcifrao coloca cifroes na matriz do jogo.
            imprimirmatriz3(matriz3);//Imprime a matriz do jogo.
            escolha(matriz, matriz2,matriz3);//A escola do usuário recebe como parametros a matriz de inteiros, a de inteiros pela tabela ASCII e a matriz caractere do jogo.
            while((resposta!=49) || (resposta!=50))//Enquanto a resposta for diferente de 1 ou 2.
            {
                cout << endl<< "\t\t\t      Deseja jogar denovo ?" << endl << endl << endl << "   1-SIM, ESSE JOGO E MUITO BOM !!!\t\t2-NAO, JA JOGUEI MUITO !!!"<<endl;
                cout <<endl<<"\t\t\t           RESPOSTA:";
                cin >> resposta;//Resposta para quando o jogo acabar e quiser jogar denovo.
                if (resposta==49)//Se a resposta for SIM(1), limpa a tela e começa o jogo denovo.
                {
                    system("cls");
                    main();
                    resposta = 50;//Iguala a 50(2) porque na proxima vez que executar resposta vai vir com resposta = 49(1);
                }
                if (resposta==50)//Se a resposta for NÃO(2), sai do jogo.
                {
                    return (EXIT_SUCCESS);
                }

                else//E caso nao for digitado nem 1 e nem 2.
                {
                    cout <<endl<<"\t\t\t      DIGITE APENAS 1 OU 2"<<endl<<endl<<"\t\t      ";
                    fflush (stdin);//Limpa o buffer do teclado, no caso do usuário digitar outras entradas.
                    system("pause");
                    system("cls");
                }
            }
        }
        else//Se ele nao escolher entre entrar no jogo ou ver créditos ou sair.
        {
            cout <<"\t\t\t      DIGITE APENAS 1 OU 2 OU 3"<<endl<<endl<<"\t\t      ";
            fflush (stdin);
            system("pause");
            system("cls");
        }
    }
}
void titulo(void)//Função que aparece o titulo do jogo.
{
    system("cls");
    cout << "            ********************************************************" << endl<< endl;
    cout << "            ________________ CAMPO MINADO DA FORTUNA ______________" << endl<< endl;
    cout <<"                      Nao Deixe Que As Verdinhas Explodam !!!!         "<<endl;
    cout << "            ********************************************************" << endl<< endl;
    cout <<endl;
}
void colocarzeros(int mat[9][9])
{
    int i, j;
    for(i = 0; i < 9; i++)
        for(j = 0; j < 9; j++)
        {
            mat[i][j] = 0;// Percorre toda a matriz adicionando zeros.
        }
}
void colocabombas(int mat[][9])//Coloca as bombas
{

    int i, x, y;
    srand(time (NULL));
    for (i = 0; i<10; i++)
    {
        x = rand()%9;
        y = rand()%9;
        if (mat[x][y]==0) mat[x][y] = -1;
        else i--;//se a posicao possuir bomba, sortear outra vez
    }
}

void imprimirmatriz(int mat[][9])//Imprimir a matriz inteira. É necessária para fazer a checagem. 
{

    int i, j;
    cout<<endl<<"\t\t     X    0   1   2   3   4   5   6   7   8"<<endl<<endl<<endl;
    for (int i=0; i<9; i++)
    {
        if(i==0)cout<<"\t\t     0    ";
        if(i==1)cout<<"\t\t     1    ";
        if(i==2)cout<<"\t\t     2    ";
        if(i==3)cout<<"\t\t     3    ";
        if(i==4)cout<<"\t\t     4    ";
        if(i==5)cout<<"\t\t     5    ";
        if(i==6)cout<<"\t\t     6    ";
        if(i==7)cout<<"\t\t     7    ";
        if(i==8)cout<<"\t\t     8    ";
        for (int j=0; j<9; j++)
        {
            if(mat[i][j]==-1) cout <<mat[i][j] << "  ";
            else cout <<mat[i][j] << "   ";
        }
        cout <<endl << endl;
    }
}

void tratarnumeros(int mat[][9])//Se a possiçao for igual a -1, percorre e conta +1 ao redor.
{
    int i, j, linha, coluna;
    for( i = 0 ; i < 9; i++)
        for( j = 0 ; j < 9; j++)
            if(mat[i][j] == -1)
                for(linha = i - 1 ; linha < i + 2 ; linha++)
                    for(coluna = j - 1 ; coluna < j + 2 ; coluna++)
                        if(mat[linha][coluna]!=-1 && linha>=0 && linha<9 && coluna>=0 && coluna<9)
                            mat[linha][coluna]++;
}

void colocarcifrao(char mat[][9])//Coloca os cifroes na matriz de caracteres.
{
    int i, j;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            mat[i][j]= 36;//Cifrao em código ASCII
        }
}
void imprimirmatriz3(char mat[][9])
{//Imprime a matriz do jogo.

    int i, j;
    cout<<endl<<"\t\t     X    0   1   2   3   4   5   6   7   8"<<endl<<endl<<endl;
    for (i = 0; i < 9; i++)
    {
        if(i==0)cout<<"\t\t     0    ";
        if(i==1)cout<<"\t\t     1    ";
        if(i==2)cout<<"\t\t     2    ";
        if(i==3)cout<<"\t\t     3    ";
        if(i==4)cout<<"\t\t     4    ";
        if(i==5)cout<<"\t\t     5    ";
        if(i==6)cout<<"\t\t     6    ";
        if(i==7)cout<<"\t\t     7    ";
        if(i==8)cout<<"\t\t     8    ";
        for (j = 0; j < 9; j++)
        {
            cout <<mat[i][j] << "   ";
        }
        cout <<endl << endl;
    }
}

void nota(void)//Nota que aparece quando ganha o jogo.
{
    cout<<"\t\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB"<<endl;
    cout<<"\t\xBA                                                             \xBA"<<endl;
    cout<<"\t\xBA             *            *****              *****           \xBA"<<endl;
    cout<<"\t\xBA           ***         ***     ***        ***     ***        \xBA"<<endl;
    cout<<"\t\xBA         *****        ***       ***      ***       ***       \xBA"<<endl;
    cout<<"\t\xBA       *******        ***       ***      ***       ***       \xBA"<<endl;
    cout<<"\t\xBA     *********        ***       ***      ***       ***       \xBA"<<endl;
    cout<<"\t\xBA          ****        ***       ***      ***       ***       \xBA"<<endl;
    cout<<"\t\xBA          ****        ***       ***      ***       ***       \xBA"<<endl;
    cout<<"\t\xBA          ****        ***       ***      ***       ***       \xBA"<<endl;
    cout<<"\t\xBA          ****        ***       ***      ***       ***       \xBA"<<endl;
    cout<<"\t\xBA          ****         ***     ***        ***     ***        \xBA"<<endl;
    cout<<"\t\xBA      ***********         *****              *****           \xBA"<<endl;
    cout<<"\t\xBA                                                             \xBA"<<endl;
    cout<<"\t\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC"<<endl;
}

void abrezeros(int mat1[9][9], int mat2[9][9], char mat3[9][9], int x, int y)
{//Função para abrir os zeros ao redor de outros zeros.
    if (mat1[x][y]==0)
    {
        for(int i = x - 1 ; i < x + 2 ; i++)
            for(int j = y - 1 ; j < y + 2 ; j++)
                if(mat1[i][j]!= -1 && i >= 0 && i < 9 && j >= 0 && j < 9 && mat1[i][j]==0 && mat3[i][j]!=15)
                {
                    mat3[i][j] = mat2[i][j];
                    abertas[i][j] = 1;

                    if(mat1[i][j]!= -1 && i > 0 && i < 8 && j > 0 && j < 8 && mat1[i][j]==0 && mat3[i][j]!=15)
                    {//Abre uma posição além do zero aberto.
                        mat3[i-1][j] = mat2[i-1][j];
                        abertas[i-1][j] = 1;
                        mat3[i+1][j] = mat2[i+1][j];
                        abertas[i+1][j] = 1;
                        mat3[i][j-1] = mat2[i][j-1];
                        abertas[i][j-1] = 1;
                        mat3[i][j+1] = mat2[i][j+1];
                        abertas[i][j+1] = 1;
                        mat3[i-1][j-1] = mat2[i-1][j-1];
                        abertas[i-1][j-1] = 1;
                        mat3[i+1][j+1] = mat2[i+1][j+1];
                        abertas[i+1][j+1] = 1;
                        mat3[i+1][j-1] = mat2[i+1][j-1];
                        abertas[i+1][j-1] = 1;
                        mat3[i-1][j+1] = mat2[i-1][j+1];
                        abertas[i-1][j+1] = 1;
                    }
                }
    }
}

void escolha(int mat1[][9],int mat2[][9],char mat3[][9])
{//Função que vai tratar da escolha da posiçao do usuario
    int i, j;

    for (i = 0; i < 9; i++)//Primeiramente transforma os numeros da matriz2 em numeros de código ASCII.
        for (j = 0; j < 9; j++)
        {
            mat2[i][j]= mat1[i][j];
            if(mat2[i][j] == 1)  mat2[i][j] = 49;//Ex: Na posiçao[i][j], se for 1, troque por 49.
            if(mat2[i][j] == 2)  mat2[i][j] = 50;
            if(mat2[i][j] == 3)  mat2[i][j] = 51;
            if(mat2[i][j] == 4)  mat2[i][j] = 52;
            if(mat2[i][j] == 5)  mat2[i][j] = 53;
            if(mat2[i][j] == 6)  mat2[i][j] = 54;
            if(mat2[i][j] == 7)  mat2[i][j] = 55;
            if(mat2[i][j] == 8)  mat2[i][j] = 56;
            if(mat2[i][j] == -1) mat2[i][j] = 15;
            if(mat2[i][j] == 0)  mat2[i][j] = 48;
        }
    do
    {
        fflush (stdin);//Limpar buffer do teclado para as jogadas anteriores nao interferirem nas próximas.
        cout << endl<<"\t\t\t<<< DIGITE NUMEROS ENTRE 0 e 8 >>>" <<endl<<endl<< "\t\t\tDigite uma posicao para a LINHA: ";
        cin >> x;
        while ((x < 0) || (x > 8))
        {
            cout << endl << "\t\t\tDIGITE UM NUMERO PARA X ENTRE 0 e 8 : ";
            cin >> x;
            fflush (stdin);
        }
        cout << endl<< "\t\t\tDigite uma posicao para a COLUNA: ";
        cin >> y;
        while ((y < 0) || (y > 8))
        {
            cout << endl << "\t\t\tDIGITE UM NUMERO PARA Y ENTRE 0 e 8 : ";
            cin >> y;
            fflush (stdin);
        }
        system("cls");
        mat3[x][y]= mat2[x][y];//Iguala o cotecuda da matriz2 para a matriz do jogo.
        titulo();
        abrezeros(mat1, mat2, mat3, x, y);//Executa a função para abrir os zeros em volta.

        if((mat1[x][y]==1)||(mat1[x][y]==2)||(mat1[x][y]==3)||(mat1[x][y]==4)||(mat1[x][y]==5)||(mat1[x][y]==6)||(mat1[x][y]==7)||(mat1[x][y]==8))
            abertas[x][y] = 1;//Se a posição escolhida conter 1,2,3,4,5,6,7,8 apenas atribua a matriz abertas o valor "1".
            //Esta matriz abertas vai guardando as posições que foram reveladas.
        for (i = 0; i < 9; i++)
            for (j = 0; j < 9; j++)
            {//Depois eh feito a soma dela para saber se o usuário chegou ou nao ao fim do jogo.
                soma = soma + abertas[i][j];
            }
        if (soma>10)//9*9=81-10(bombas)=71
        {
            cout<<endl<<endl<<endl<<"\t\t\t  VC CONSEGUIU SALVAR AS NOTAS !!!"<<endl<<endl<<"\t\t      ";
            system("pause");
            goto ganhar;//vai para a linha que esta estabelescida como ganhar.
        }

        else soma = 0;

        //imprimirmatriz(mat1);Para conferir as jogadas
        imprimirmatriz3(mat3);

    }
    while(mat1[x][y]!=-1);

    if(mat1[x][y]==-1)//Se abrir uma casa que contém bomba, a tela pisca.
    {
        system("color F2");
        Sleep(200);
        system("color 2F");
        Sleep(200);
        system("color F2");
        Sleep(200);
        system("color 2F");
        Sleep(150);
        system("color F2");
        Sleep(150);
        system("color 2F");
        Sleep(150);
        system("color F2");
        Sleep(100);
        system("color 2F");
        Sleep(100);
        system("color F2");
        Sleep(50);
        system("color 2F");
        for (i = 0; i  <9; i++)
            for (j = 0; j < 9; j++)
            {
                mat3[i][j] = mat2[i][j];//Para poder mostrar o jogo com todos os espaços completos.
            }
        cout <<endl<<endl<<"\t\tAS NOTAS VOARAM PELOS ARES E VOCE PERDEU TUDO !!!"<<endl<<endl;
        cout <<"\t\t      ";
        system("pause");
        system("cls");
        titulo();
        imprimirmatriz3(mat3);//Imprime a matriz do jogo com as posições reveladas.
        cout<<endl<<"\t\t\t\t  "<<mat3[x][y]<<" = BOMBAS!!!"<<endl;
        Beep(523,200);//Faz um som com uma frequenca de 523 Hertz e com duraçao de 200 milisegundos.
        Beep(494,200);
        Beep(440,200);
        Beep(392,200);
        Beep(349,200);
        Beep(330,200);
        Beep(294,200);
        Beep(272,200);
        Beep(262,200);
    }
    if(soma>10)//Se a soma da matriz abertas for 71, entao ganhou.
    {
ganhar:
        system("cls");
        nota();//Aparece a nota.
        cout<<endl<<"\tPARABENS, VOCE SALVOU AS NOTAS E MERECE RECEBER ESTE PREMIO !!!"<<endl<<endl;
        Beep(550,200);
        Beep(594,200);
        Beep(660,400);
        Beep(634,200);
        Beep(660,200);
        Beep(704,400);
        Beep(660,200);
        Beep(704,200);
        Beep(844,400);
        Beep(734,800);
        Beep(550,200);
        Beep(594,200);
        Beep(660,400);
        Beep(734,200);
        Beep(660,200);
        Beep(495,400);
        Beep(594,200);
        Beep(550,200);
        Beep(440,800);

    }
}








