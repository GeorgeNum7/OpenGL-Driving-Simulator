# OpenGL Interactive 3D Driving Simulator 🚗🏙️

> A comprehensive interactive 3D driving simulation built with OpenGL, demonstrating advanced computer graphics techniques including hierarchical modeling, dynamic lighting, and texture mapping. Developed as the Assessment 2 project for the CPT205 course.

![Demo](docs/demo.gif) *(建议：在此处放一张汽车行驶、视角切换或昼夜交替的 GIF 动图)*

## 📖 Overview

This project implements a realistic driving environment where users can control a detailed 3D car model while exploring a carefully designed urban and natural landscape. It effectively incorporates a wide range of graphics techniques, utilizing OpenGL's geometric primitives, matrix transformations, and advanced lighting systems to create a fully interactive experience.

## ✨ Key Features

### 🎥 Dynamic Camera System
* **Multiple View Modes:** Supports Free camera mode for environment exploration, Third-person follow mode with dynamic positioning, and First-person driver view.
* **Smooth Transitions:** Implements smooth interpolation for gradual camera movement between mode switches, preventing jarring visual transitions.
* **Interactive Controls:** Comprehensive camera manipulation options including user-adjustable viewing distance, height, and dynamic rotation capabilities.

### 💡 Advanced Rendering & Graphics Techniques
* **Lighting System:** Implements ambient, diffuse, and specular lighting components. Features a dynamic day/night cycle system (affecting ambient lighting and sky textures) and functional car headlights (spot lighting).
* **Texture Mapping:** Extensive use of textures with mipmapping support and appropriate wrapping modes (repeat, clamp) for ground, architectural, and environmental elements.
* **Hierarchical Modeling:** Extensively used for complex structures like the car model (managing car body and wheels as a single entity), playground equipment, and trees.

### 🏎️ Vehicle Physics & Animation
* **Realistic Handling:** Features progressive deceleration due to friction, natural acceleration, and an opposite steering behavior when reversing.
* **Advanced Mechanics:** Wheel rotation is precisely calculated based on wheel circumference, and turning radius reduces at higher speeds for stability.
* **Animations:** Includes dynamic steering wheel animation responding to turns, an active speedometer in first-person view, and animated playground elements like a merry-go-round and seesaw.
* **Collision Detection:** Implements collision detection with mountain boundaries.

### 🏙️ Rich Environmental Design
* **Urban Elements:** Multi-story buildings with clamped texturing, textured highways with lamp posts, and a regulation-style soccer field.
* **Natural Landscapes:** Natural lake with transparent water effects, multi-textured grass areas, and garden paths generated using Bézier curve algorithms.

## 🎮 Controls

### Global & View Controls
| Key | Action |
| :--- | :--- |
| `M` | Toggle between Day and Night modes |
| `C` | Toggle between Free camera and Third-person view |
| `V` | Toggle between Third-person and First-person view |

### Driving Controls (Third/First-Person Modes)
| Key | Action |
| :--- | :--- |
| `W` / `S` | Accelerate forward / Brake & Reverse |
| `A` / `D` | Steer left / Steer right |
| `L` / `T` | Switch on/off headlights (First-person mode) |

### Camera Controls (Free / Third-Person Modes)
| Key | Action |
| :--- | :--- |
| `W` / `S` / `A` / `D` | Move camera forward/backward/left/right (Free Camera) |
| `Arrow Keys` | Rotate camera up/down/left/right |
| `H` / `L` | Increase/Decrease camera height (Free Camera) |
| `I` / `O` | Zoom in / Zoom out (Third-Person) |

## 📸 Screenshots

*(建议：挑选3张报告中最精彩的截图放在这里，例如：带有反光效果的湖面、第一人称驾驶视角、昼夜交替的街道)*
<p align="center">
  <img src="docs/screenshot_lake.png" width="30%" />
  <img src="docs/screenshot_firstperson.png" width="30%" />
  <img src="docs/screenshot_night.png" width="30%" />
</p>

## 🛠️ Technologies Used

* **C++** * **OpenGL** (Graphics rendering API)
* **freeglut** (Window management and interaction)

---
*Developed by Zhuozhi Li*
