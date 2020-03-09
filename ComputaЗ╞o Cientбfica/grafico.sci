E0 = 8.9D-12; 
q= 2D-5;
Q= 2D-5; 
a= 0.85;
F= 1.25;
x = linspace(0,a,100);
k = 1/(4*%pi*E0);
fx= (k*q*Q*x./((x.^2+a^2).^(3/2)))-F
xlabel('distância x');
ylabel('f(x)');
plot2d(x,fx,style=[color('blue4')]);
xgrid;
