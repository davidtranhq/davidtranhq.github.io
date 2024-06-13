tspan = [0, 1]; % time span
y0 = 1; % initial condition
h = 0.1; % step size
f = @(t, y) t * y + t^3;
[t, y] = euler_method(f, tspan, y0, h)

% Plot the solution
plot(t, y);
xlabel('t');
ylabel('y');
title('Solution of dy/dt = ty + t^3 using Euler''s method');
