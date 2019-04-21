#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Portuguese");//colocando os caracteres em portugues
	
	int linha;
	int coluna;
	int k;
	int n;//n representa a ordem da minha matriz
	float matriz[20][20];//matriz para a aplicação do método
	float conta;
	float x[10];//x representara o resultado das variaveis x,y,z...
	float somador = 0;
	
	//pedindo para o usuario informar a ordem da matriz, e guardando esse numero na variavel n
	cout << "Digite a ordem da matriz: ";
	cin >> n;
	
	cout << "Digite os elementos da matriz ampliada: \n\n";
	for(linha = 1; linha <= n; linha ++ )//este comando percorrerá as linhas da matriz até que ela seje <= ao n(numero da ordem da matriz)
	{
		for(coluna = 1; coluna <= (n+1); coluna++)//ja este percorrerá as colunas até que seja <= a (n+1) ou seja <= numero da ordem + 1 que é o resultado de cada sistema
		{
			//aqui estou preenchendo a matriz ampliada com os valores
			cout << "Matriz[" << linha << "][" << coluna << "] : ";
			cin >> matriz[linha][coluna];
		}
	}
	
	//zerando os elementos abaixo da diagonal principal
	
	for(coluna = 1; coluna <= n; coluna++)//comando que percorrera as colunas da matriz
	{
		for(linha = 1; linha <= n; linha++)//comando que percorrera as linhas da matriz
		{
			if(linha > coluna)//se linha for maior que a coluna, isso servira para eu conseguir acessar os elementos abaixo da diagonal principal
			{
				//conta recebera a fração negativa gerada com o numero a ser zerado dividido pelo seu pivo da diagonal principal
				conta = -(matriz[linha][coluna] / matriz[coluna][coluna]);
				
				for(k = 1; k <= (n+1); k++)//este comando percorrera as colunas
				{
					//aqui multiplicaremos a "conta" com a linha de cima e somaremos com a linha do numero a ser zerado
					matriz[linha][k] = conta * matriz[coluna][k] + matriz[linha][k];
				}	 
			}
		}
	}
	
	cout << "\n";
	//mostrando a matriz após ser zerado os elementos abaixo da diagonal principal
	
	for(linha = 1; linha <= n; linha++)
	{
		for(coluna = 1; coluna <= (n+1); coluna++)
		{
			if(coluna != (n+1))//se a coluna nao for a ultima eu mostro sem pular linha apenas com espaço
			{
				cout << matriz[linha][coluna] << "  ";
			}
			else //se nao eu mostro e pulo uma linha, para mostrar o outro sistema
			{
				cout << matriz[linha][coluna] << "\n";
			}
		}
	}
	
	//meu vetor "x" esta recebendo o resultado do sistema dividido pelo numero que multiplicava a variavel
	//entao aqui descobrimos nossa primeira variavel que ficara contida em "x[n]"
	x[n] = matriz[n][n+1] / matriz[n][n];
	
	for(linha = (n-1); linha >= 1; linha--)//percorrendo as linhas de baixo para cima
	{
		somador = 0;
		for(coluna = (linha+1); coluna <= n; coluna++)//percorrendo as colunas da linha, enquanto a coluna for menor que a ordem
		{
			//somador ira armazenararele mesmo e o numero contido na posição da matriz multiplicado pela variavel ja descoberta
			somador = somador + matriz[linha][coluna] * x[coluna];
		}
		
		//aqui o "x[]" recebe a descoberta da nova variavel em questao, 
		//aqui o x recebe o resultado do sistema menos os numero que estavao antes do "=" 
		//dividido pelo numero que multiplicava a variavel a ser descoberta
		x[linha] = (matriz[linha][n+1] - somador) / (matriz[linha][linha]);
	}
	
	//exibindo a solucao do sistema
	for(linha = 1; linha <= n; linha++)
	{
		cout << "\nx[" << linha << "] = " << x[linha];
	}
	
	
	
	return 0;
}
