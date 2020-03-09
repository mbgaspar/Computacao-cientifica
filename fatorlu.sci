function x= fatorlu(A,b)//x=A\b para conferir resultado
    //resolução de sistemas com fatoração LU com pivotamento parcial
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
    
    P = eye(n,n); //matriz de pivotamento
    
    //Algoritmo de eliminação progressiva
    for i=1:n-1 //i linha e j coluna
        //PIVOTAMENTO PARCIAL
        //i é linha
        [maior,k]=max(abs(A(i:n,i)))//maior valor dos elementos da matriz
        l = k+i-1;
        if l~=i then
             A([l,i],:)= A([i,l],:)//inverte as linhas
              P([l,i],:)= P([i,l],:)//inverte as linhas
        end
        //---
        for j=i+1:n
          A(j,i) = A(j,i)/A(i,i); //multiplicador guardado onde fica 0
         // for k =i+1:n //k=i+1 pois vai ser 0 em k=i
             // A(j,k)= A(j,k)-A(i,k)*A(j,i);
          //end
          //ou FOR IMPLÍCITO-------
           A(j,i+1:n)= A(j,i+1:n)-A(i,i+1:n)*A(j,i);
          disp(A,'A');
          disp(P,'P');
          
        end           
    end
    //algoritmo de substituição progressiva 
    b= P*b;
    //d=zeros(n,1) para o for implicito
    d(1)=b(1);
    for i=2:n
        //for j=1:i-1
            //d(i)=d(i)-A(i,j)*d(j);
        //end
        d(i)= b(i)-A(i,1:i-1)*d(1:i-1);
    end
    disp(d,'d');
    //substituição regressiva
    x = zeros(n,1);
    x(n)= d(n)/A(n,n);
    for i= n-1:-1:1
        //for j=i+1:n
          // x(i)= x(i)+ A(i,j)*x(j); 
        //end
        
        //Com FOR IMPLÍCITO
        x(i)= (d(i)-A(i,i+1:n)*x(i+1:n))/A(i,i);
    end
    
endfunction
