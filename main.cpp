#include <cstdlib>
#include <iostream>
#include "Classe_hash.h"
#include <fstream>

using namespace std;

void menu()
{
  cout << "Implementação do Hash" << endl;
  cout << "1 - Reiniciar" << endl;
  cout << "2 - Inserir" << endl;
  cout << "3 - Remover" << endl;
  cout << "4 - Consultar Específico - pelo côdigo" << endl;
  cout << "5 - Consultar Específico - pelo nome" << endl;
  cout << "6 - Listar" << endl;
  cout << "0 - Sair" << endl
       << endl;
}

main()
{

  int op;
  pessoa p;
  int codigo;
  string nome;
  Classe_hash *tabela = new Classe_hash();
  do
  {

    menu();
    cout << "Informe a opcao: ";
    cin >> op;

    switch (op)
    {
    case 0:
      exit(0);
      break;
    case 1:
    {
      delete tabela;
      tabela = new Classe_hash();
      fstream arq("dados_pessoa.txt", ios ::trunc);
      remove("dados_pessoa.txt");
      arq.close();
    }
    break;

    case 2:
    {
      cout << "Informe o seu codigo: ";
      cin >> codigo;
      cout << "Informe o seu nome: ";
      cin >> nome;
      p.setcodigo(codigo);
      p.setnome(nome);
      tabela->insere(p);

      fstream arq;

      arq.open("dados_pessoa.txt", ios::app | ios ::out);
      arq << p.getcodigo() << "\t" << p.getnome() << "\n";

      arq.close();
    }
    break;

    case 3:
    {
      cout << "Informe o seu codigo: ";
      cin >> codigo;
      tabela->remove(codigo);

      fstream arq("dados_pessoa.txt", ios::in | ios ::out);

      if (arq.fail() == 1)
      {
        cout << "O arquivo a ser lido nao esta gravado em disco" << endl;
      }

      else
      {
        while (!arq.eof())
        {
        }
      }
    }
    break;

    case 4:
      cout << "Informe o seu codigo: ";
      cin >> codigo;
      tabela->consulta(codigo);
      break;

    case 5:
      cout << "Informe o seu nome: ";
      cin >> nome;
      tabela->consultanome(nome);
      break;

    case 6:
      tabela->imprimirhash();
      break;
    }
    // system("Pause");
    getchar();
    cout << "\n\n\n\n";
  } while (op != 0);
}
