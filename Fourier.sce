clc;
clear;
funcprot(0);
t = poly(0,"t");
L= input("Entre com o período: ");
W0= (2*%pi)/L;
a0=0;
k= input ("Entre com o número de parcelas que formam sua função: "); // F(t)= ft1+ft2... 
fx=zeros(1, k);

for j=1:k;
    fn = input("Entre com a parcela da função fn(t): ");
    ti = input("Entre com o limite inferior de fn(t) (tempo inicial): ");
    tf= input ("Entre com o limite superior de fn(t) (tempo final): ");
    deff('fn = f(t)','fn');
    a0=(1/L)*(integrate('f(t)','t',ti,tf,1e-5))+a0; 
  
    disp(a0);
    fx(j) = fn;
    txi(j)=ti;
    txf(j)=tf;
    // a0 ok
end

disp(fx, "fx= ");
printf("a0 = %f\n",a0);

i=input("Digite a quantidade de termos a serem somados: ");

a=zeros(1, i);
b=zeros(1, i);
A=zeros(1, i);
fi=zeros(1, i);

for n=1:i
    for j=1:k  
        y=fx(j);
        deff('y=ft(t)','y');
        a(n)=((2/L)*(integrate('ft(t)*cos(n*W0*t)','t',txi(j),txf(j),1e-5)))+ a(n);
        b(n)=((2/L)*(integrate('ft(t)*sin(n*W0 *t)','t',txi(j),txf(j),1e-5)))+ b(n);
    end
    A(n)= sqrt(a(n)^2 + b(n)^2)+ A(n);
    fi(n)= atan(b(n)/a(n))+ fi(n);
    printf("a(%d)=%f,b(%d)=%f, A(%d)= %f, fi(%d)= %f\n",n, a(n), n, b(n), n, A(n), n, fi(n));

end


// plota forma de onda (função desejada); Tensão
Vs =a0;
function Vs=f(t)
    for n=1:i;
        Vs = Vs+(a(n)*cos(n*W0*t)+b(n)*sin(n*W0*t));
        y=fft(Vs);
        //  plot(abs(y));
    end
endfunction
t=-10:0.1:10;
plot(t,f(t));
xlabel("t");
ylabel("f(t)");




//Vo=a0/2;
//printf ("COMPONENTE CC DE Vo= %f",Vo);
//function Vo=s(t)
//   for n=1:i;
//      Vo = Vo+(z2(n)*(a(n)*cos(n*W0*t)+b(n)*sin(n*W0*t))/(z1(n)+z2(n)));
//      y=fft(Vo);
// //  plot(abs(y));
// end
//endfunction
//t=-10:0.01:10;
//plot(t,s(t));




