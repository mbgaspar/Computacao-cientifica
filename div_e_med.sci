function [fx, term]=div_e_med(fun, a, n_sig)
//
// Cálculo da raiz quadrada de um número a por divisão e média
// function [fa,term]=div_e_med(xi, a, n_sig)
// onde fx é o valor da função em x
// term é o número de termos usados para o erro especificado
// xi é a função de entrada literal em x e n
// a é o número no qual se deseja obter o valor da função
// n_sig é o numero de alg. significativos da resposta -
// opcional
// Exemplo de chamada:
// exec('path\div_e_med.sci',-1)
// fun ='(fx_old+ a/fx_old)/2'
// [fx,term]=div_e_med(fun, 16, 4)
//

if argn(2) < 3 then
 n_sig = 3;
end
//
// argn fornece os números de parâmetros de entrada (argn(2)) e
// saída (argn(1)) passados à função quando esta é chamada. Aqui
// está sendo usada para lidar com parâmetros opcionais.
//
es = 0.5*10^(2-n_sig); // condição de parada relativa %

fx_old = 1; fx = 0;n = 0; vreal=sqrt(a);
printf("Termo fa et %% erro %%\n");

while 1 do
 fx = evstr(fun);
 erro = abs((fx - fx_old)/fx)*100;
 errot = abs((vreal - fx)/vreal)*100;
 printf("%-8d %10.6f %10.6f %10.6f\n",n+1,fx,errot,erro);
 if(erro <= es) then
 break;
 end
 fx_old = fx;
 n = n + 1;
end
term = n+1;
endfunction
