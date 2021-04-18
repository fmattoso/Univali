#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

/*
  Obtém a entrada dos valores e faz as validações conforme a base
*/
bool validaNum(vector <char> &num, int base) {
   bool erro = 0;
   bool cancel = 0;
   char digito;

   cout << "Para cancelar digite '*' + Enter." << endl;
   do {
      cout << "\n  Informe o numero em ";
      switch (base) {
         case 2: {cout << "binario: "; break;}
         case 10:{cout << "decimal: "; break;}
      }
      erro = 0;
      // Lê caracteres do teclado até que se digite "Enter"
      digito = cin.get();
      cout << endl;
      while (digito != '\n') {
         if (digito == '*') {
            cancel = 1;
         }
         // Se deu erro, continua "lendo" para esvaziar o buffer
         if (erro || cancel) {
            digito = cin.get();
            continue;
         }
         switch (base) {
            // Base 2, binários, apenas números 0 e 1
            case 2: {
              if (digito == '0' || digito == '1') {
                  num.push_back(digito);
                  //num.insert(num.begin(), digito); // invertido
              }
              else {
                  erro = 1;
              }
              break;
            }
            // Decimais, digitos 0 a 9
            case 10: {
              if (isdigit(digito)) {
                num.push_back(digito);
              } else {
                  erro = 1;
              }
              break;
            }
         }
         // Puxa o próximo caracter do buffer do teclado
         digito = cin.get();
      }
      if (erro) {
         num.clear();
         cout << "  Numero invalido!" << endl;
      }
   }
   while (erro && !cancel); /* Continua no loop enquanto o numero estiver errado
                               ou até que a operação seja cancelada */
   return (!cancel);
}

void convBin2Dec(vector <char> num) {
   int idx;
   int soma = 0;
   int tmo = num.size();
   cout << "  Resultado: ";
   for (idx = 0; idx < tmo; idx ++) {
      /* Converte de caracter para inteiro e faz a conversão
        dígito a digito */
      soma += pow(2,tmo-idx-1) * (num[idx] - '0');
      cout << num[idx];
   }
   cout << "b = " << soma << "d\n" << endl;
}

void convDec2Bin(vector <char> num) {
   vector<char> result;
   int div = 0;
   int idx = 0;

   cout << "  Resultado: ";
   /* Converter o vetor para inteiro */
   for (idx = 0; idx < num.size(); idx ++) {
      div += pow(10, num.size()-1-idx) * (num[idx] - '0');
      cout << num[idx];
   }

   while (div > 0) {
      /* Obtendo o resto da divisão do valor atual por 2
        e convertendo para caracter */
      result.insert(result.begin(), '0' + div % 2);
      div = div / 2;
   }

    cout << "d = ";
    for (idx = 0; idx < result.size(); idx++) {
        cout << result[idx];
    }
    cout << "b\n" << endl;
}

int main()
{
    int iOp = 1;
    vector <char> num;

    while (iOp > 0) {
        cout << "Menu Inicial" << endl;
        cout << "1 - binario para decimais" << endl;
        cout << "2 - decimal para binario" << endl;
        cout << ">";
        cin >> iOp;
        cin.ignore(); // Remove o "Enter" do buffer
        num.clear(); // limpa o vetor;
        system("clear||cls"); // Limpa a tela
        switch (iOp) {
            case 1: {
                if (!validaNum(num, 2)) {
                    cout << "\n**Cancelado!**" << endl;
                    break;
                }
                convBin2Dec(num);
                break;
            }
            case 2: {
                if (!validaNum(num, 10)) {
                    cout << "\n**Cancelado!**" << endl;
                    break;
                }
                convDec2Bin(num);
                break;
            }
            default: {
                cout << "\nFim!" << endl;
                iOp = 0;
                break;
            }
        }
        cout << "\n--------------------------------------------------------------------------------" << endl;
        cin.clear();
    }

    return 0;
}
