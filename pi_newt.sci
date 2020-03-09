function ye=pi_newt(x,y,xe)
    //onde:
    //ye é o valor interpolado da variável dependente;
    //x é um vetor com os valores conhecidos da var. independente;
    //y é um vetor com os valores conhecidos da var. dependente;
    //xe é o valor da variável independente onde a interpolação é
    //calculada.
    n = length(x);
    k=0;
    A(:,1) = x';
    A(:,2) = y';
    for j=3:n+1
        for i=n-k:-1:2 
            A(i-1,j) = (A(i,j-1)-A(i-1,j-1))/(A(i+k,1)-A(i-1,1));
            disp(A)
        end
        k = k + 1;
    end 
    xt=1;
    ye = y(1); //A(1,2)
    for j=1:n-1
        xt = xt*(xe - x(j));
        ye = ye + A(1,j+2)*xt;
    end
endfunction
