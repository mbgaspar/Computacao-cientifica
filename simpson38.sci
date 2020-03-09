function I = simpson38(a,b,fun,n)
    // a - limite inferior da integração 
    // b - limete superior da integração
    // n - número de segmentos
    // fun- função literal caso exista o argumento n
    //    - vetor com os pontos caso não seja passado n
    if argn(2)< 4 then
        fx = fun;
        n = length(fun) - 1; //obtendo o n° de segmentos
        if modulo(n,2)~= 1 then
            error("O número de segmentos não pode ser par");
        end
    else 
        if modulo(n,2)~= 1 then
            error("O número de segmentos não pode ser par");
        end
        x = linspace(a,b,n+1);
        fx = evstr(fun);
    end
    soma1 = 0; soma2 = 0;
    for i=2:3:n
        soma1 = soma1 + fx(i);
    end
    for i=3:3:n-1
        soma2 = soma2 + fx(i);
    end
    I = ((b-a)*(fx(1) + 3*soma1 + 3*soma2 + fx(n+1)))/8;
endfunction
