function x= gauss_i(A,b)//x=A\b para conferir resultado
    //Eliminação de Gauss ingênua
    // onde: x é o vetor solução
    // A é a matriz de coeficientes
    // b é o vetor coluna de estímulos
    [m,n]=size(A); //dimensão da matriz que deve ser quadrada
    if m~=n then
        error("A matriz deve ser quadrada");
    end
    
    m = length(b);//comprimento de b
    if m~=n then
        error("Erro na dimensão do vetor b");
    end
    //1° passo: aumentar a matriz A
    nb = n+1;
    A= [A b]; //criando a matriz aumentada
    
    //Algoritmo de eliminação progressiva
    for i=1:n-1 //i linha e j coluna
        for j=i+1:n
          A(j,i) = A(j,i)/A(i,i); //multiplicador guardado onde fica 0
         // for k =i+1:nb //k=i+1 pois vai ser 0 em k=i
             // A(j,k)= A(j,k)-A(i,k)*A(j,i);
          //end
          //ou FOR IMPLÍCITO-------
           A(j,i+1:nb)= A(j,i+1:nb)-A(i,i+1:nb)*A(j,i);
          disp(A);
        end           
    end
    
    //substituição regressiva
    x = zeros(n,1);
    x(n)= A(n,nb)/A(n,n);
    for i= n-1:-1:1
        //for j=i+1:n
          // x(i)= x(i)+ A(i,j)*x(j); 
        //end
        
        //Com FOR IMPLÍCITO
        x(i)= (A(i,nb)-A(i,i+1:n)*x(i+1:n))/A(i,i);
    end
    
endfunction
