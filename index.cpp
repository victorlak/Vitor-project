
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
    cout <<"0 => Criar base de dados" << endl; //FEITO
    cout <<"1 => Imprimir base de dados" << endl;//FEITO
    cout <<"2 => Inserir produto" << endl;//FEITO
    cout <<"3 => Procurar pro nome" << endl;//FEITO
    cout <<"4 => Listar produtos abaixo do estoque" <<endl;//FEITO
    cout <<"5 => Atualizar todos os dados" <<endl;
    cout <<"6 => Atualizar produto" << endl;
    cout <<"7 => Comprar produto"<< endl;
    cout <<"8 => Vender produto" << endl;
    cout <<"9 => Sair\n" <<endl;
    cout <<"*********************"<<endl;
    cout <<"Escolha uma opcção:"<< endl;
    cout <<"*********************"<<endl;
}
void atualizarProduto(Produto *p,int limite_estoque){
    int verificaProduto = 0;
    string nome = "";
    int contador = 0;
    cout <<"Insira o nome do produto que deseja atualizar:\n";
    cin >> nome;
    
    while(contador < limite_estoque){
        if(p[contador].nome == nome){
            cout<<"Informações atuais:"<<endl;
            cout <<"\nID:"<< p[contador].id << endl;
            cout <<"nome:"<< p[contador].nome << endl;
            cout <<"preço:"<< p[contador].preco << endl;
            cout <<"custo:"<< p[contador].custo << endl;
            cout <<"estoque:"<< p[contador].nome << endl;
            cout <<"Insira as atualizações."<<endl;
            
            cout<<"Nome:";
            cin>>p[contador].nome;
            cout<<"Custo:";
            cin>>p[contador].custo;
            cout<<"Preço:";
            cin>>p[contador].preco;
            cout<<"Estoque:";
            cin>>p[contador].estoque;
            
        }
        contador++;
}
}
void atualizarTodosDados(Produto *p, int limite_estoque){
    int contador = 0;
    while(contador < limite_estoque){
        
        cout<<"=========================" <<endl;
        cout <<"ID do produto:"<<p[contador].id <<endl;
        cout<<"=========================" <<endl;
        cout<<"Insira os novos dados referente ao id apresentado:"<<endl;
        cout<<"Nome:";
        cin>>p[contador].nome;
        cout<<"Custo:";
        cin>>p[contador].custo;
        cout<<"Preço:";
        cin>>p[contador].preco;
        cout<<"Estoque:";
        cin>>p[contador].estoque;
        contador++;
    }
}
void abaixoDoEstoque(Produto *p, int limite_estoque){
    int contador = 0;
    int verificaEstoque = 0;
    while(contador < limite_estoque){
        
        if(p[contador].estoque == 0){
            cout<<p[contador].nome <<":Esgotado"<<endl;
            verificaEstoque++;
        }
        contador++;
    }
    if(verificaEstoque == 0){
        cout<<"Temos todos produtos em estoque" <<endl;
    }
}
void imprimirProdutos(Produto *p,int limite_estoque){
    int contador = 0;
    cout<<"\t>>Dados dos produtos:<<\n";
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
void procurarPorNome(Produto *p, int limite_estoque){
    int verificaProduto = 0;
    string nome = "";
    int contador = 0;
    cout <<"Insira o nome que deseja achar:\n";
    cin >> nome;
    
    while(contador < limite_estoque){
        if(p[contador].nome == nome){
            cout <<"ID:"<<p[contador].id<<endl;
            cout <<"NOME:"<<p[contador].nome <<endl;
            cout <<"CUSTO:"<<p[contador].custo<<endl;
            cout <<"PREÇO:"<<p[contador].preco<<endl;
            cout <<"ESTOQUE:"<<p[contador].estoque<<endl;
            verificaProduto++;
        }
        contador++;
    }
    if(verificaProduto == 0){
        cout<<"Produto inexistente"<<endl;
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
        cout <<"Produto já existente"<< endl;
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
        if(opcao == 4){
            abaixoDoEstoque(p,limite_estoque);
        }
        if(opcao == 3){
            procurarPorNome(p,limite_estoque);
        }
        if(opcao == 5){
            atualizarTodosDados(p,limite_estoque);
        }
        if(opcao == 6){
            atualizarProduto(p,limite_estoque);
        }
    }
    delete[] p;
    return 0;
}
