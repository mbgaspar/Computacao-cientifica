function [a,b,c,d,ye] = splinesn(x,y,xe)
//  a,b,c,d são os coeficientes das (n-1) splines cubicas naturais
//ye é o valor procurado da variavel dependente no ponto xe
//x é o vetor de pontos amostrados da variavel independente 
//y é o vetor de pontos amostrados da variavel dependente
n = length(x);
if n~= length(y) then
   error("Vetores x e y não possuem a mesma dimensão");
end
//calculo das diferenças finitas 
for i = 1:n-1
    h(i) = x(i+1) - x(i);
    ddf(i) = (y(i+1) - y(i))/h(i);
end
// montar as matrizes A (tridiagonal)e o vetor coluna e
//[A]{c}={e}
A = zeros(n-2,n-2);
e = zeros(n-2,1);
for i = 1:n-2
    for j = 1:n-2
        if i==j then 
            A(i,j) = 2*(h(i)+h(i+1));
        elseif j==i+1 then
            A(i,j)=h(j);
        elseif i==j+1 then
            A(i,j)=h(i);
        end
    end
    e(i) = 3*(ddf(i+1)-ddf(i));
end
f = A\e;
c =zeros(n,1);
c(2:n-1,1)=f;
for i=1:n-1
    d(i) = (c(i+1)-c(i))/(3*h(i));
    b(i) = ddf(i)-(h(i)/3)*(2*c(i)+c(i+1));
    //aproveitando para determinar em que segmento está o ponto interpolado
    if xe>x(i) & xe<x(i+1) then 
        j = i; // j será o número do segmento
    end
end
    //calculando o ponto interpolado
v = xe - x(j);
a = y;
ye = a(j) + b(j)*v + c(j)*v^2 + d(j)*v^3;
//desenhando as splines
for j = 1:n-1
    xp = linspace(x(j),x(j+1),100);
    v = xp - x(j);
    yp = a(j) + b(j)*v + c(j)*v.^2 + d(j)*v.^3;
    ylabel('Splins naturais');
    xlabel('x');
    plot(xp,yp);
end
xgrid;
endfunction
