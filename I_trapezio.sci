function I = trap(a,b,fun,n)
    // a - limite inferior da integração 
    // b - limete superior da integração
    // n - número de segmentos
    // fun- função literal caso exista o argumento n
    //    - vetor com os pontos caso não seja passado n
    if argn(2)< 4 then
        fx = fun;
        n = length(fun) - 1; //obtendo o n° de segmentos
    else 
        x = linspace(a,b,n+1);
        fx = evstr(fun);
    end
    soma = 0;
    for i=2:n
        soma = soma + fx(i);
    end
    I = ((b-a)*(fx(1) + 2*soma + fx(n+1)))/(2*n);
endfunction
