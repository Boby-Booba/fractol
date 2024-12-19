# 🌌 **Fract'ol - Interactive Fractal Viewer**

**Fract'ol** is a graphical project using the **MiniLibX** library that allows you to explore stunning fractal patterns. The program supports real-time visualization and manipulation of **Julia** and **Mandelbrot** sets, offering smooth zooming and color effects.

---

## 📋 **Table of Contents**

1. [Features](#features)  
2. [Installation](#installation)  
3. [Usage](#usage)  
4. [Controls](#controls)  
5. [Customization](#customization)  
6. [Example Screenshots](#example-screenshots)  

---

## 🛠️ **Features**

- **Julia and Mandelbrot Sets**: Display and explore these famous fractal sets.
- **Infinite Zoom**: Zoom in and out using the mouse scroll wheel.
- **Customizable Julia Sets**: Generate different variations of the Julia set by passing parameters at runtime.
- **Color Effects**: Visualize the depth of fractals with rich color schemes, including psychedelic effects.

---

## 💻 **Installation**

1. **Install MiniLibX** (if not already installed):  
   ```bash
   git clone https://github.com/42Paris/minilibx-linux.git
   cd minilibx-linux
   make
   ```

2. **Clone the Project Repository**:  
   ```bash
   git clone <repository-url>
   cd fractol
   ```

3. **Compile the Program**:  
   ```bash
   make
   ```

---

## 🚀 **Usage**

Run the program by specifying the type of fractal you want to visualize:

```bash
./fractol <fractal_type>
```

### Available Fractals:

- **Mandelbrot Set**:  
  ```bash
  ./fractol mandelbrot
  ```

- **Julia Set** with custom parameters:  
  ```bash
  ./fractol julia <parameter1> <parameter2>
  ```

If no parameter or an invalid parameter is provided, the program will display the available options and exit.

---

## 🎮 **Controls**

- **Mouse Scroll**:  
  - **Zoom In**: Scroll up  
  - **Zoom Out**: Scroll down  

- **Keyboard**:  
  - **ESC**: Quit the program  

- **Window Management**:  
  - Click the **close button** (X) to exit the program gracefully.

---

## ⚙️ **Customization**

When launching the Julia set, you can pass different parameters to change the fractal's appearance. Example:

```bash
./fractol julia -0.7 0.27015
```

This will create a Julia set based on the given values.

---

## 🖼 **Screenshots**

**Mandelbrot Set** 
![Mandelbrot](https://github.com/Boby-Booba/fractol/blob/main/screenshots/3.png)

**Julia Set**
![Julia](https://github.com/Boby-Booba/fractol/blob/main/screenshots/2.png)

**Burning_ship Set**
![Burning_ship](https://github.com/Boby-Booba/fractol/blob/main/screenshots/1.png)


---

## 📝 **License**

This project is licensed under the **MIT License**.
