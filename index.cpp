
#include <iostream>

using namespace std;

int i = 0;

struct Produto {
    int id;
    string nome;
    float custo;
    float preco;
    int estoque;
    
};

void menu(){
    cout << "____________________________________________\n" << endl;
    cout <<"\t      LOJA DO SEU ZE"<<endl;
    cout << "____________________________________________" << endl;
    cout <<"0 => Criar base de dados" << endl;
    cout <<"1 => Imprimir base de dados" << endl;
    cout <<"2 => Inserir produto" << endl;
    cout <<"3 => Procurar pro nome" << endl;
    cout <<"4 => Listar produtos abaixo do estoque" <<endl;
    cout <<"5 => Atualizar todos os dados" <<endl;
    cout <<"6 => Atualizar produto" << endl;
    cout <<"7 => Comprar produto"<< endl;
    cout <<"8 => Vender produto" << endl;
    cout <<"9 => Sair\n" <<endl;
    cout <<"*********************"<<endl;
    cout <<"Escolha uma opcção:"<<endl;
    cout <<"*********************"<<endl;
}
void imprimirProdutos(Produto *p,int limite_estoque){
    int contador = 0;
    while(contador < limite_estoque){
        if(p[contador].id > 0){
            cout <<"\nid:"<< p[contador].id << endl;
            cout <<"nome:"<< p[contador].nome << endl;
            cout <<"preço:"<< p[contador].preco << endl;
            cout <<"custo:"<< p[contador].custo << endl;
            cout <<"estoque:"<< p[contador].nome << endl;
            contador++;
        }
    }
}

bool verificaProdutoDuplicado(Produto *p, Produto produto, int limite_estoque){
    int contador = 0;
    while(contador < limite_estoque){
        if(p[contador].nome == produto.nome){
            return false;
        }
        contador++;
    }
    return true;
}
void inserirProduto(Produto *p, int limite_estoque){
    Produto produto;
    produto.id = i + 1;
    
    //criar produto
    cout <<"Indforme o nome do produto:";
    cin >> produto.nome;
    cout <<"Informe o custo do produto:";
    cin >> produto.custo;
    cout <<"Informe o valor do produto:";
    cin >> produto.preco;
    cout <<"Informe o estoque do produto:";
    cin >> produto.estoque;
    
    //Verifica
    bool existProduct = verificaProdutoDuplicado(p, produto, limite_estoque);
    
    //Joga no array
    if(existProduct){
        p[i] = produto;
        i++;
    }else{
        cout <<"produto já existente"<< endl;
    }
    
    
}

int criarBaseDados(){
    int limite_estoque;
    cout <<"QUAL LIMITE DO ESTOQUE:";
    cin >> limite_estoque;
    
    return limite_estoque;
}

int main()
{
    Produto  *p;
    int opcao = 0;
    int limite_estoque;
    while(opcao != 9){
        menu();
    
        cin >> opcao;
    
        if (opcao == 0){
            limite_estoque = criarBaseDados();
            p = new Produto[limite_estoque];
        
        }if(opcao == 1){
            imprimirProdutos(p,limite_estoque);
        }
        if(opcao == 2){
            inserirProduto(p, limite_estoque);
        }
    }
    return 0;
}