function [raiz, i]=bissecao(funcao, xl, xu, es)
    // Cálculo das raizes pelo processo da bisseção
    // function [raiz,iter]=bissecao(funcao, xl, xu, es)
    // onde raiz é a raiz procurada de funcao
    // i é o num de iterações para o erro especificado
    // funcao é a função de entrada literal em x
    // xl é o limite inferior do intervalo de busca
    // xu é o limite superior do intervalo de busca
    // es é o criterio de parada que é opcional
    // Exemplo de chamada:
    // exec('path\ bissecao.sci',-1)
    // fun = 'log(x) + x'
    // [raiz,iter]=bissecao(fun, 0.1, 2, 0.1)
    //
    // verifica se há raízes no intervalo
    x = xu;
    fu = evstr(funcao);
    x = xl;
    fl = evstr(funcao);
    if (fu*fl >= 0) then
        error('Nenhuma raiz no intervalo dado');
    end
    i = 0; ea=100; xr_novo = xl;
    // se es nao foi estabelecido usa 0.0001%
    if argn(2) < 4 then
        es = 0.0001;
    end 

    // inicio do processo iterativo
    printf("Iter\tErro aprox.%%\tRaiz\n");
    while ea > es do
        xr_velho = xr_novo;
        xr_novo = (xu + xl)/2;
        if xr_novo ~=0 then // xr_novo não pode ser zero
            ea = abs((xr_novo - xr_velho)/xr_novo)*100;
        end
        i=i+1;
        printf("%d\t%f\t%f\n",i,ea,xr_novo);
        x=xr_novo;
        fr = evstr(funcao);
        x = xl;
        fl = evstr(funcao);

        if(fl*fr < 0) then
            xu = xr_novo;
        elseif(fl*fr > 0) then
            xl = xr_novo;
        else
            break;
        end
    end
    raiz = xr_novo;
endfunction
