% Evaluate F(x) using the first n terms of its Taylor series.
function T = F(x, n)
    % Initialize sum as 0
    T = 0;
    % Loop over terms in series
    for k = 0:n
        T += (-1)^k * x.^k ./ factorial(k + 2);
    end
end

% Plot F(x).