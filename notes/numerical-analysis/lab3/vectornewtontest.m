clear
clc

f1 = @(x)[
    2*x(1)^2 - 4*x(1) + x(2)^2 + 3*x(3)^2 + 6*x(3) + 2;
    x(1)^2 + x(2)^2 - 2*x(2) + 2*x(3)^2 - 5;
    3*x(1)^2 - 12*x(1) + x(2)^2 + 3*x(3)^2 + 8
];

Df1 = @(x)[
    4*x(1) - 4, 2*x(2), 6*x(3) + 6;
    2*x(1), 2*x(2) - 2, 4*x(3);
    6*x(1) - 12, 2*x(2), 6*x(3)
];

[x1_soln, iters1] = vectornewton(f1, Df1, [0; 0; 0], 10^(-12), 100)


f2 = @(x)[
    x(2) - x(1)^3 ;
    x(1)^2 + x(2)^2 - 1
];
Df2 = @(x)[
    -3* x(1)^2 , 1 ;
    2*x(1) , 2* x(2)
];
[x2_soln , iters1] = vectornewton(f2 , Df2 , [ 1 ; 2 ], 10^(-12) ,10)