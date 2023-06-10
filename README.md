# Fractol Documentation

## Introduction

Fractol is a program that allows you to explore and visualize fractals. Fractals are complex mathematical patterns that exhibit self-similarity and are created through the repetition of simple mathematical equations. They have intricate and beautiful shapes that often exhibit fascinating and intricate detail when magnified.

This documentation will guide you through the usage of the Fractol program, explaining how to run it and explore the available fractals. Currently, the program supports two types of fractals: Julia and Mandelbrot.


## Support
+ [m] >>> Mandelbrot
+ [j] >>> Julia
## Installation

To run the Fractol program, please follow the steps below:

1. Clone the Fractol repository to your local machine:

```
git clone https://github.com/your-username/fractol.git
```

2. Navigate to the cloned repository:

```
cd fractol
```

3. Compile the Fractol program using the provided Makefile:

```
make
```

4. Once the compilation is complete, you can run the program using the following command:

```
./fractol [fractal-name]
```

Replace `[fractal-name]` with either "julia" or "mandelbrot" to select the desired fractal. For example:

```
./fractol julia
```

## Exploring Fractals

### Mandelbrot Fractal

The Mandelbrot fractal is a famous fractal that is generated by iterating a simple mathematical formula. It consists of a set of complex numbers that, when iterated through a specific formula, either escape to infinity or remain bounded. The points that remain bounded are part of the fractal set and are typically colored differently to visualize the intricate patterns.

To explore the Mandelbrot fractal using the Fractol program:

1. Run the Fractol program with the command:

```
./fractol mandelbrot
```

2. Use your mouse to navigate and zoom in/out on the fractal. Clicking the left mouse button will zoom in on the area under the cursor, while the right mouse button will zoom out. You can also use the arrow keys to move the fractal in different directions.

### Julia Fractal

The Julia fractal is another well-known fractal that is generated based on a fixed complex number. Similar to the Mandelbrot fractal, it involves iterating a mathematical formula, but the constant used in the iteration is different for each point of the complex plane. The resulting pattern displays unique and intricate structures.

To explore the Julia fractal using the Fractol program:

1. Run the Fractol program with the command:

```
./fractol julia real_constant imaginary_constant
```

2. Move your mouse to change the position of the Julia set. Each location in the window represents a different constant for the Julia fractal. The fractal will update in real-time as you move the mouse.

### Controls

In addition to the mouse interactions described above, you can use the following keyboard controls while exploring the fractals:

- **Arrow keys**: Move the fractal in different directions. Only works for Julia.
- **Spacebar**: Change the pallete scheme.
- **Scroll wheel**: Zoom in/out on the fractal.
- **Numpad +/-**: Increase or decrease the maximum number of iterations used to calculate the fractal. Higher values provide more detail but require more computation.
- **Esc**: Exit the Fractol program.

## Conclusion

Congratulations! You have successfully installed and explored the Fractol program, allowing you to visualize the captivating Mandelbrot and Julia fractals. Feel free to experiment with different zoom levels, positions, and constants to discover the intricate details and beauty hidden within these fractal