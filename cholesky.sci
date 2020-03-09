function x = cholesky(A,b)
//Resolução de sistemas usando a Fatoração de Cholesky
//onde x é o vetor solução
//A é a matriz de coeficientes e b é o vetor de estímulos(termos independentes)
[m,n] = size(A);
if m~=n then
    error("A matriz deve ser quadrada");        
end
m = length(b);
if m~=n then
    error("Vetor b incoerente");        
end
U = eye(n,n); //criar matriz identidade
soma = 0;
for i=1:n
    for j=i:n
        if i==j then
            for k = 1:i-1
                soma = soma + (U(k,i))^2;
            end
            U(i,i) = sqrt(A(i,i) - soma);
        else
            for k = 1:i-1
                soma = soma + U(k,i)*U(k,j);
            end
            U(i,j) = (A(i,j)-soma)/U(i,i);
        end
        soma = 0;
    end
end
    //disp(U,'U = ');

//substituição progressiva
for i = 1:n
    for k = 1:i-1
        soma = soma + U(k,i)*d(k);
    end
    d(i) = (b(i) - soma)/U(i,i);
    soma = 0;
end 
//substituição regressiva
x = zeros(n,1); //vetor coluna
x(n) = d(n)/U(n,n);
for i = n-1:-1:1
    x(i) = (d(i) - U(i,(i+1):n)*x((i+1):n))/U(i,i);
end
endfunction
