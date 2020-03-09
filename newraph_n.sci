function [x,i] = newraph_n(fun,jac,x0,es,maxi)
//onde
//x é o vetor de raízes;
//x0 é o vetor com a solução inicial proposta
//iter é o número de iterações realizadas;
//fun é uma função que retorna f
//jac é uma função que retorna J;
[m,n]=size(jac);
    if m~=n then
        error("A matriz jacobiana deve ser quadrada");
    end
    m = size(fun);
    if m~=n   then
        error("Vetor função inconsistente");
    end
     if argn(2)<4 then
        es = 0.00001;
    end
     if argn(2)<5 then
        maxi = 50;
    end
    ea = ones(n,1); i=0; x=x0;
    while max(ea)>es & i<=maxi do
        f = evstr(fun);
        J = evstr(jac);
        y = J\f;
        xi = x - y;
        i = i+1;
        if xi ~=0 then
            ea = max(abs(y./xi))*100;
        end
        x = xi;
    end
    
    if i>= maxi then
        x = 'Divergiu';
    end
end
