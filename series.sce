function [fx, term]=series(fun, x, n_sig)
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
    // fun ='(-1)^(n)*x^(2*n)/factorial(2*n)' função literal
    // [fx,term]=series(fun, %pi/3, 3)
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
    fx_old = 0; fx = 0;n = 0; vreal=cos(x);
    printf("Termo fx et %% erro %%\n");

    while 1 do
        fx = fx + evstr(fun);
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
