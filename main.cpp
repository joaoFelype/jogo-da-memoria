#include<iostream>
#include<time.h>
#include <locale.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL)); //gerar números aleatórios

    string nomes[8] = {"Paulo", "Pedro", "Paloma", "Priscila", "Inácio", "Itamar", "Irineu", "Isaías"};
    string mp[4][4]; //matriz principal
    int mj[4][4]; //matriz do jogo

    // Preenche a matriz principal e a matriz do jogo
    int contagem[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            int indice;
            do {
                indice = rand() % 8; // Gera um índice aleatório entre 0 e 7
            } while(contagem[indice] == 2); // Continua gerando índices até encontrar um nome que ainda não foi usado duas vezes

            mp[i][j] = nomes[indice]; // Atribui o nome selecionado à posição atual na matriz
            mj[i][j] = i * 4 + j + 1; // Inicialmente, todas as cartas estão viradas para baixo
            contagem[indice]++; // Incrementa a contagem para o nome selecionado
        }
    }

    //menu de inicio
    int opcprejogo;
    do {
        cout<<"Bem vindo(a) ao nosso jogo da memória..\n";
        cout<<"Pressione 1 para começar ou 2 para sair.\n";
        cin>>opcprejogo;

        if (opcprejogo == 1){
            //iniciar jogo

            int jogadas = 0;
            int acertos = 0;
            while(jogadas < 24 && acertos < 16){
                // Mostra a matriz do jogo
                for(int i = 0; i < 4; i++){
                    for(int j = 0; j < 4; j++){
                        if (mj[i][j] != 0){
                            cout<<"["<<mj[i][j]<<"] ";
                        } else{
                            cout<<"["<<mp[i][j]<<"] ";
                        }
                    }
                    cout<<"\n";
                }

                int carta1,carta2;
                do {
                    cout<<"\n Digite um número entre 1 e 16 para virar a primeira carta: ";
                    cin>>carta1;
                    if(carta1 < 1 || carta1 > 16){
                        cout<<"Número inválido. ";
                    }
                } while(carta1 < 1 || carta1 > 16);

                cout<<"\n A primeira carta é: "<<mp[(carta1-1)/4][(carta1-1)%4]<<"\n";
                mj[(carta1-1)/4][(carta1-1)%4] = 0; // Vira a primeira carta

                // Mostra a matriz do jogo com a primeira carta virada
                for(int i = 0; i < 4; i++){
                    for(int j = 0; j < 4; j++){
                        if (mj[i][j] != 0){
                            cout<<"["<<mj[i][j]<<"] ";
                        } else {
                            cout<<"["<<mp[i][j]<<"] ";
                        }
                    }
                    cout<<"\n";
                }

                do {
                    cout<<"\n Digite um número entre 1 e 16 para virar a segunda carta: ";
                    cin >> carta2;
                    if(carta2 < 1 || carta2 > 16 || carta2 == carta1) {
                        cout<<"\n Número inválido. \n";
                    }
                } while(carta2 < 1 || carta2 > 16 || carta2 == carta1);

                cout<<"\n A segunda carta é: "<<mp[(carta2-1)/4][(carta2-1)%4]<<"\n";
                mj[(carta2-1)/4][(carta2-1)%4] = 0; // Vira a segunda carta

                // Mostra a matriz do jogo com a segunda carta virada
                for(int i = 0; i < 4; i++){
                    for(int j = 0; j < 4; j++){
                        if (mj[i][j] != 0) {
                            cout<<"["<< mj[i][j]<<"] ";
                        } else {
                            cout<<"["<<mp[i][j]<<"] ";
                        }
                    }
                    cout<<"\n";
                }

                if(mp[(carta1-1)/4][(carta1-1)%4] == mp[(carta2-1)/4][(carta2-1)%4]) {
                    cout<<"\n Certa resposta amigão! \n";
                    acertos += 2;
                } else {
                    cout<<"\n Resposta incorreta amigo! \n";
                    // Se o jogador errou, vira as cartas para baixo novamente
                    mj[(carta1-1)/4][(carta1-1)%4] = carta1;
                    mj[(carta2-1)/4][(carta2-1)%4] = carta2;
                }

                jogadas++;
                cout<<"\n Jogadas realizadas: "<<jogadas<<"\n";
                system("pause");
                system("cls");
            }

            if(acertos == 16) {
                cout<<"\n Você achou todos, parabéns!\n";
            } else if(jogadas == 24){
                cout<<"\n Não foi dessa vez, você perdeu!\n";
            }

        }else if (opcprejogo == 2){
            //sair do jogo
            cout<<"adeus amigo.... :(";
            return 0;
        }else{
            //opção inválida
            cout<<"\n Não entendi amigão... Digite novamente. \n";
        }
    } while(opcprejogo != 1 && opcprejogo != 2);

    return 0;
}

