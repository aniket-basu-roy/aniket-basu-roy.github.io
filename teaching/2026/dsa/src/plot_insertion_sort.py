import matplotlib.pyplot as plt
import csv
import numpy as np

# Read data from CSV
sizes = []
times = []

with open('insertion_sort_times.csv', 'r') as file:
    reader = csv.reader(file)
    next(reader)  # Skip header
    for row in reader:
        sizes.append(int(row[0]))
        times.append(int(row[1]))

# Convert to numpy arrays
sizes = np.array(sizes)
times = np.array(times)

# Fit a quadratic curve (since insertion sort is O(n^2))
coeffs = np.polyfit(sizes, times, 2)
fitted_times = np.polyval(coeffs, sizes)

# Plot the data and the fitted curve
plt.figure(figsize=(10, 6))
plt.scatter(sizes, times, color='b', label='Actual data')
plt.plot(sizes, fitted_times, color='r', label=f'Fitted quadratic: {coeffs[0]:.2e}x² + {coeffs[1]:.2e}x + {coeffs[2]:.2e}')
plt.title('Insertion Sort Performance with Quadratic Fit')
plt.xlabel('Array Size')
plt.ylabel('Time (nanoseconds)')
plt.legend()
plt.grid(True)
plt.savefig('insertion_sort_plot_with_fit.png')
plt.show()