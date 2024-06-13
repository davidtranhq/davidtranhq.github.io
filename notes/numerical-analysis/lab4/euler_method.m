function [t, y] = euler_method(f, tspan, y0, h)
    % Euler's method for solving first-order ODE
    % f: function handle representing the ODE dy/dt = f(t, y)
    % tspan: vector [t0, tf] representing the interval of integration
    % y0: initial condition
    % h: step size
    % Returns:
    % t: vector of time points
    % y: vector of solution values at corresponding time points

    % Initialize time vector
    t = tspan(1):h:tspan(2);

    % Initialize solution vector
    y = zeros(size(t));
    y(1) = y0;

    % Iterate over time points
    for i = 1:length(t)-1
        % Update solution using Euler's method
        y(i+1) = y(i) + h * f(t(i), y(i));
    end
end
