#include <bits/stdc++.h>

using namespace std;

const int UNDEFINED = -1;
const int FALSE = 0;

class Solution
{

public:
    bool isMatch(string s, string p)
    {
        vector<vector<int>> M(s.length() + 1, vector<int>(p.length() + 1, UNDEFINED));

        return solve(M, s, p, 0, 0);
    }

    bool solve(vector<vector<int>> &M, string &s, string &p, int i, int j)
    {

        if (i == s.length() && j == p.length()) // se s e p estao vazios juntos, entao p gera s
            return true;
        if (i != s.length() && j == p.length()) // se regex terminou e s nao, entao p nao gera s
        {
            M[i][j] = FALSE; // salva como falso
            return false;
        }

        if (i == s.length() && j != p.length()) // se s ja chegou ao fim
        {
            if (p.length() % 2 == 1) // verifica se paridade impar => ao menos uma letra nao pode ser eliminada com *
            {
                M[i][j] = FALSE;
                return false;
            }
            if (p[j + 1] == '*')              // se for paridade par => pode ocorrer de tudo ser o par {char,*} que seria valido
                if (M[i][j + 2] == UNDEFINED) // se ainda nao foi calculado
                {
                    if (solve(M, s, p, i, j + 2)) // retorna se der certo
                        return true;
                }
            M[i][j] = FALSE; // salva como falso se der errado
            return false;
        }

        if (s[i] == p[j] || p[j] == '.') // se os caracteres atuais batem
        {
            if (j < p.length() - 1 && p[j + 1] == '*') // checa se p tem mais caracteres e se pode gerar mais letras iguais
            {
                if (M[i + 1][j] == UNDEFINED && solve(M, s, p, i + 1, j)) // testa o caminho de gerar mais letras iguais
                    return true;
                M[i + 1][j] = FALSE;

                if (M[i][j + 2] == UNDEFINED && solve(M, s, p, i, j + 2)) // testa o caminho de nao gerar mais letras iguais
                    return true;
                M[i][j + 2] = FALSE;
            }

            if (M[i + 1][j + 1] == UNDEFINED && solve(M, s, p, i + 1, j + 1))
                return true;
            M[i + 1][j + 1] = FALSE;
            return false;
        }
        else
        {
            if (j < p.length() - 1 && p[j + 1] == '*' && solve(M, s, p, i, j + 2))
                return true;
            M[i][j + 2] = FALSE;
        }

        M[i][j] = FALSE;
        return false;
    }
};