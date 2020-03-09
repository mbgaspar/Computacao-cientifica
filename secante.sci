function [raiz, iter]= sec_mod(funcao, dxi, es, maxi)
// Cálculo das raizes por Newton-Raphson
// function [raiz,iter]=new_raphson(funcao, derivada, x0, es, it)
// onde raiz é a raiz procurada de funcao
// iter é o n. de iterações realizadas para o erro especificado
// funcao é a função de entrada literal em x
// dxi é a perturbação em torno de xi e é opcional
// es é o criterio de parada que é opcional
// maxi é o numero maximo de iterações
// A cond. inicial x0 é escolhida com auxilio de um gráfico
// Exemplo de chamada:
//
// fun = 'log(x) + x'
// dxdt = '(1 ./x) + 1' 
//operdor ponto por causa do gráfico
// [raiz,iter]=sec_mod(fun, dxdt, 0.0001,50)
//
// Construção do gráfico da função
 a = input("Entre com o limite inferior de x a = ");
 b = input("Entre com o limite superior de x b = ");
 x = linspace(a,b,100); //cria espaço linear
 f = evstr(funcao)
 plot2d(x,f);
 xgrid;
// escolha do valor inicial
 x0 = input("Entre com o valor inicial x0 = ");
 i = 0; x = x0; ea=100; 
 
 // se dxi nao foi estabelecido usa 1d-6
 if argn(2) < 3 then
 dxi = 1d-6;
 end
 // se es nao foi estabelecido usa 0.0001%
 if argn(2) < 3 then
 es = 0.0001;
 end
 // se maxi nao foi estabelecido usa 50
 if argn(2) < 4 then
 maxi = 50;
 end
 printf("Iter\tRaiz\terro aproximado %% \n");
 // inicio do processo iterativo
 
 while ea > es & i < maxi do
 fxi = evstr(funcao);
 p = x*dxi; //calcula a perturbação 
 x= x+p;  //soma x com a perturbação
 fdxi = evstr(funcao);
 x= x-p; // desconta perturbação
 xi = x - (fxi*p/(fdxi - fxi));
 i= i+1;
 if xi ~=0 then // xi não pode ser zero
 ea = abs((xi - x)/xi)*100;
 end
 printf("%d\t%.10f\t%f\n",i,xi,ea);
 x = xi;
end

if i == maxi then
 raiz = 'divergiu';
 else
 raiz = xi;
 end
 iter = i;
endfunction
