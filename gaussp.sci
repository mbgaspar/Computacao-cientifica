function x = gaussp(A,b)
    //Eliminação de Gauss com pivotamento parcial
    //onde x é o vetor solução
    //  A é a matriz de coeficientes
    //  b é o vetor de estímulos
    [m,n] = size(A);
    if m~=n then
        error("A matriz deve ser quadrada");
    end
    m = length(b);
    if m~=n then
        error("Erro na dimenção de vetor b");
    end
    nb = n+1;
    A = [A b];
    //eliminação progressiva
    for i = 1: n-1
        //pivotamento parcial
        [maior,k] = max(abs(A(i:n,i))); //acha a linha do maior elemento na submatriz
        l = i+k-1;  //ajusta para a linha da matriz original
        if l~=i then 
            A([l,i],:) = A([i,l],:);
        end
        //final do pivotamento
        for j = i+1: n
            A(j,i) = A(j,i)/A(i,i);
            //for k = i: nb   //
            //    A(j,k) = A(j,k) - A(i,k)*mult;
            //end
            A(j,i+1:nb) = A(j,i+1:nb)-A(i,i+1:nb)*A(j,i); //for implicito
            disp(A);
        end
    end
    //eliminação regressiva
    x = zeros(n,1);
    x(n) = A(n,nb)/A(n,n);
    for i = n-1:-1:1
        //for j = i+1:n
        //    x(i) = x(i)+A(i,j)*x(j);
        //end
        //x(i) = (A(i,nb)-x(i))/A(i,i);
        //usando for implícito
        x(i) = (A(i, nb)-A(i, i+1:n)*x(i+1:n))/A(i,i);
    end
endfunction
