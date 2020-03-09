function [x,iter]=gauss_seidel(A,b,lam,es,maxi)
    //resolução de sistemas pelo método de Gauss-Seidel
    //A é a matriz de coeficientes, b é o vetor de estímulos
    //lam é o fator de relaxamento(opcional)
    //es é o critério de parada(opcional)
    //maxi é o número máximo de iterações (opcional)
    [m,n]=size(A);
    if m~=n then
        error("Amatriz A deve ser quadrada");
    end
    m = size(b);
    if m~=n   then
        error("Vetor b inconsistente");
    end
    if argn(2)<3 then
        lam = 1;
    end
     if argn(2)<4 then
        es = 0.00001;
    end
     if argn(2)<5 then
        maxi = 50;
    end
    //montagem da matriz C em cima da matriz A,
    //vetores d (b)e x inicial
    for i = 1:n
        for j = 1:n 
            if i==j then
                x(i)=0;
                b(i)=b(i)/A(i,i);
            else 
                A(i,j)=A(i,j)/A(i,i);
            end
        end
        A(i,i)=0;
    end
    //início do método iterativo
    iter=0;
    while 1 do
        for i = 1:n
           xold = x(i);
           x(i)= b(i)-A(i,:)*x(:);
           x(i)=x(i)*lam + (1-lam)*xold;
           ea(i)= abs((x(i)-xold)/x(i))*100;
        end
        disp(x);
        iter = iter+1;
        if max(ea)<= es | iter > maxi then
            break;
        end
    end
     if iter > maxi then
            x = 'Divergiu';
        end
endfunction
