function ye = pi_Lagr(x, y, xe)
//onde:
//ye é o valor interpolado da variável dependente;
//x é um vetor com os valores conhecidos da var. independente;
//y é um vetor com os valores conhecidos da var. dependente;
//xe é o valor da variável independente onde a interpolação é
//calculada.
n = length(x);
ye = 0;
for i=1:n
    produto =y(i);
    for j=1:n
        if (j~=i) then
            produto = produto*(xe-x(j))/(x(i)-x(j));
        end
    end
    ye = ye + produto;
end
endfunction
