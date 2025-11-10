#include <bits/stdc++.h>
using namespace std;

/*
 * vai dar uma string, de tamanho n, onde n é uma potencia de dois
  a string é considerada c good se:  
    1- o tamanho da strig é 1 e só tem um caracter
    2- O tamanho é maior que 1 e a primeira parte da string é igual ao mesmo char e a segunda parte é char +1
    3- O contrario da 2

    como vamos verificar se todas as strings sao iguais?
      pega no meio?

    todas as trings tem que ser a-boas

    calcula o custo para deixae metade a-boa, calcula o  custo pra outra metade
      chama pra metade a, chama pra metade b
        segue pro lado que seja menos custaoso
        volta dois passos
          faz isso pra

    A string nao precisa estar toda aboa, somente metade dela,
*/

char a = 'a';

void solve(int mod, string /*vector<char>*/ cs, int l, int r){
  cout << cs << endl;
  if(cs.size() == 1) mod += cs[0] == a ? 0 : 1; 
  solve(mod,cs,l,r/2);
  solve(mod,cs,r/2+1,r);
  cout << mod << endl;
  return;
}


int main(){
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    int mod=0,l=0,r=n;
    string cs;
    cin >> cs;
    //while(n--){char tmp; cin >> tmp; cs.push_back(tmp);}
    solve(mod,cs,l,r);
  }

}
