function[y,t]=rk4(fun,ti,tf,h,y0)
//Resolução de sisteemas de EDOs por Runge-Kutta 4
//onde y é o vetor solução para a variável dependente
//t é o vetor da variável independente
//ti é o instante inicial, tf é o instante final
//h é o tamanho do passo
//y0 vetor valor inicial da variável dependente

//fun = '[ya(2),9.81-(0.25/68.1)*ya(2)^2]'

//vetor de tempos; y é uma matriz de y pelo tempo
// a primeira linha de y são as condições iniciais
//ta é para a avaliação literal das funções
//y0 vetor linha
t(1) = ti; y(1,:) = y0; i = 1; ta = ti;
//início do processo iterativo
while ta < tf do
    ya = y(i,:);
    k1 = evstr(fun);
    ya = (y(i,:) + k1*h/2);
    ta = ta + h/2;
    k2 = evstr(fun);
    ya = (y(i,:) + k2*h/2);
    k3 = evstr(fun);
    ya = (y(i,:) + k3*h);
    ta = ta + h/2;
    k4 = evstr(fun);
    y(i+1,:) = y(i,:) + (k1 + 2*k2 + 2*k3 + k4)*h/6;
    t(i+1) = ta;
    i = i+1;
end
endfunction
//plot(t,y(:,1))  velocidade
//plot(t,y(:,2))  distância
