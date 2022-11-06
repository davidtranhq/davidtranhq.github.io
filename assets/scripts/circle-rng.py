import numpy as np
import matplotlib.pyplot as plt

def init_plot():
    _, ax = plt.subplots(1)
    ax.set_aspect(1)
    return ax

def draw_circle(ax, r=1.0):
    # generate contour points from polar coordinates
    theta = np.linspace(0, 2 * np.pi, 100)
    x = r * np.cos(theta)
    y = r * np.sin(theta)

    ax.plot(x, y, 'r')

def naive_points(ax):
    """Generate points by uniformly sampling (r,theta)."""
    num_pts = 2000

    r = np.random.rand(num_pts) # [0, 1]
    theta = np.random.rand(num_pts) * 2 * np.pi # [0, 2pi]

    x = r * np.cos(theta)
    y = r * np.sin(theta)

    ax.plot(x, y, 'b.')

def uniform_points(ax):
    """Generate points by uniformly sampling from the inverse cumulative."""
    num_pts = 2000

    u = np.random.rand(num_pts)
    r = np.sqrt(u) # u from U(0, 1)
    theta = np.random.rand(num_pts) * 2 * np.pi # [0, 2pi]

    x = r * np.cos(theta)
    y = r * np.sin(theta)

    ax.plot(x, y, 'b.')

ax_naive = init_plot()
draw_circle(ax_naive)
naive_points(ax_naive)
plt.show()

ax_uniform = init_plot()
draw_circle(ax_uniform)
uniform_points(ax_uniform)
plt.show()
