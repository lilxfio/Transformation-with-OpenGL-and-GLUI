
# Viewing Transformation with OpenGL and GLUI

## Introduction
This project implements 3D viewing transformations using OpenGL and GLUI libraries. It features a graphical user interface (GUI) that allows users to apply and visualize transformations such as translation, scaling, rotation, and perspective projection on a 3D object (a cube). The project is an educational tool for understanding the basics of computer graphics transformations.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Dependencies](#dependencies)
- [Code Structure](#code-structure)
- [Configuration](#configuration)
- [Examples](#examples)
- [Troubleshooting](#troubleshooting)
- [Contributors](#contributors)
- [License](#license)

## Features
- **3D Transformations**: Apply translation, scaling, and rotation on a 3D object interactively.
- **Perspective Projection**: Visualize the effect of perspective projection on a 3D object.
- **Graphical User Interface**: Use GLUI-based panels, spinners, and text boxes for intuitive control.
- **Reset and Set Controls**: Reset transformations or apply custom settings with a single click.

## Installation

### Prerequisites
Ensure you have the following installed:
- OpenGL development libraries
- GLUT (OpenGL Utility Toolkit)
- GLUI (OpenGL User Interface Library)
- A C++ compiler (e.g., GCC)

### Build Instructions
1. Clone the repository:
   ```bash
   git clone https://github.com/your-repo/viewing-transformations.git
   cd viewing-transformations
   ```
2. Compile the project:
   ```bash
   g++ -o viewing_transformations main.cpp transformations.cpp -lGL -lGLU -lglut -lglui -lm
   ```
3. Run the application:
   ```bash
   ./viewing_transformations
   ```

## Usage
1. Launch the application.
2. Use the **Transformations Panel** to:
   - Modify translation (`dx`, `dy`, `dz`).
   - Adjust scaling factors (`sx`, `sy`, `sz`).
   - Rotate around axes (`thetax`, `thetay`, `thetaz`).
3. Use the **Projection Panel** to:
   - Set the projection angle.
   - Modify the aspect ratio, near, and far plane values.
4. Click **Set** to apply changes or **Reset** to revert to default values.

## Dependencies
- **OpenGL**: For rendering the 3D graphics.
- **GLUT**: For windowing and event handling.
- **GLUI**: For creating the graphical user interface.
- **Math Library**: For trigonometric calculations (`math.h`).

## Code Structure
### Main Components
- **`main.cpp`**: Initializes the OpenGL and GLUI components and starts the main loop.
- **`transformations.h`**: Contains transformation logic and mathematical utilities.
- **`transformations.cpp`**: Implements core transformation functions (e.g., rotation, scaling, perspective projection).
- **GLUI GUI Initialization**: Creates interactive panels for controlling transformations and projections.

### Key Functions
- **Transformation Functions**:
  - `translate(point3D *p)`
  - `scale(point3D *p)`
  - `rotateX(point3D *p)`
  - `rotateY(point3D *p)`
  - `rotateZ(point3D *p)`
- **Projection Function**:
  - `perspective_projection(point3D *p)`
- **Helper Functions**:
  - `set_identity_matrix(matrix4x4 &mat)`
  - `mult(matrix4x4 mat, point3D &p)`

## Configuration
Default configuration values can be adjusted in the `init_val()` function:
- Window size: `WINDOW_WIDTH`, `WINDOW_HEIGHT`.
- Initial angles, translation, scaling, and projection settings.

## Examples
- To apply a 45° rotation around the X-axis:
  - Set `X Transformation Angle` spinner to 45°.
  - Click the **Set** button.
- To scale the object to twice its size:
  - Set `X Scale`, `Y Scale`, and `Z Scale` to 2.
  - Click the **Set** button.

## Troubleshooting
- **GLUI Window Doesn't Appear**:
  Ensure that the GLUI library is correctly installed and linked during compilation.
- **Display Issues**:
  Verify the near and far plane settings. Incorrect values can result in clipping or distortion.
- **Compilation Errors**:
  Check the include paths for OpenGL, GLUT, and GLUI headers.

## Contributors
- **Fiordi Toska** - Project Developer

## License
This project is licensed under the MIT License. See the `LICENSE` file for details.
