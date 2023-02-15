#include <iostream>

using namespace std;

void GaussElimination(int n, float matriz[20][20], float x[10])
{
    float conta;
    int linha, coluna, k;
    float somador = 0;

    // Zeroing elements below the main diagonal
    for(coluna = 1; coluna <= n; coluna++)
    {
        for(linha = 1; linha <= n; linha++)
        {
            if(linha > coluna)
            {
                conta = -(matriz[linha][coluna] / matriz[coluna][coluna]);
                for(k = 1; k <= (n+1); k++)
                {
                    matriz[linha][k] = conta * matriz[coluna][k] + matriz[linha][k];
                }	 
            }
        }
    }

    // Displaying the matrix after zeroing elements below the main diagonal
    cout << "\nMatrix after zeroing elements below the main diagonal:\n";
    for(linha = 1; linha <= n; linha++)
    {
        for(coluna = 1; coluna <= (n+1); coluna++)
        {
            cout << matriz[linha][coluna] << "  ";
        }
        cout << endl;
    }

    // Calculating the solution
    x[n] = matriz[n][n+1] / matriz[n][n];
    for(linha = (n-1); linha >= 1; linha--)
    {
        somador = 0;
        for(coluna = (linha+1); coluna <= n; coluna++)
        {
            somador = somador + matriz[linha][coluna] * x[coluna];
        }
        x[linha] = (matriz[linha][n+1] - somador) / (matriz[linha][linha]);
    }

    // Displaying the solution
    cout << "\nSolution:\n";
    for(linha = 1; linha <= n; linha++)
    {
        cout << "x[" << linha << "] = " << x[linha] << endl;
    }
}

int main(int argc, char *argv[])
{
    int n;
    float matriz[20][20];
    float x[10];

    cout << "Enter the order of the matrix: ";
    cin >> n;

    cout << "Enter the elements of the augmented matrix:\n\n";
    for(int linha = 1; linha <= n; linha++)
    {
        for(int coluna = 1; coluna <= (n+1); coluna++)
        {
            cout << "Matrix[" << linha << "][" << coluna << "] : ";
            cin >> matriz[linha][coluna];
        }
    }

    GaussElimination(n, matriz, x);

    return 0;
}
