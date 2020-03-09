function [fx, term]=eps_da_maq(fun, E)
    //
    // Cálculo de funções com serie de potências
    // function [fx,term]=series(funcao, x, n_sig)
    // onde fx é o valor da função em x
    // term é o número de termos usados para o erro especificado
    // fun é a função de entrada literal em x e n
    // x é o número no qual se deseja obter o valor da função
    // n é o numero do termo
    // n_sig é o numero de alg. significativos da resposta -
    // opcional
    // Exemplo de chamada:
    // exec('path\series.sci',-1)
    // fun ='(E/2)'
    // [fx,term]=eps_da_maq(fun, 1)
    //


    n = 0; vreal=2.220*10^-16;
    printf("Termo fx et %% erro %%\n");

    while 1 do
        e= E+1
        if(e <= 1) then
            break;
        end
        fx = evstr(fun);
        erro = abs((fx - E)/fx)*100;
        errot = abs((vreal - fx)/vreal)*100;
        printf("%-8d %10.12f %10.6f %10.6f\n",n+1,fx,errot,erro);


        E = fx;
        n = n + 1;
    end
    fx= 2*fx;
    term = n+1;
endfunction
