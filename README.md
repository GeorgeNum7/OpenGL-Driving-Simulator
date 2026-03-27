# OpenGL Interactive 3D Driving Simulator 🚗🏙️

> [cite_start]A comprehensive interactive 3D driving simulation built with OpenGL, demonstrating advanced computer graphics techniques including hierarchical modeling, dynamic lighting, and texture mapping[cite: 8, 16, 24, 26]. [cite_start]Developed as the Assessment 2 project for the CPT205 course[cite: 1].

![Demo](docs/demo.gif) *(建议：在此处放一张汽车行驶、视角切换或昼夜交替的 GIF 动图)*

## 📖 Overview

[cite_start]This project implements a realistic driving environment where users can control a detailed 3D car model while exploring a carefully designed urban and natural landscape[cite: 9]. [cite_start]It effectively incorporates a wide range of graphics techniques, utilizing OpenGL's geometric primitives, matrix transformations, and advanced lighting systems to create a fully interactive experience[cite: 15, 24, 226].

## ✨ Key Features

### 🎥 Dynamic Camera System
* [cite_start]**Multiple View Modes:** Supports Free camera mode for environment exploration, Third-person follow mode with dynamic positioning, and First-person driver view[cite: 40, 41, 44].
* [cite_start]**Smooth Transitions:** Implements smooth interpolation for gradual camera movement between mode switches, preventing jarring visual transitions[cite: 65, 66, 67].
* [cite_start]**Interactive Controls:** Comprehensive camera manipulation options including user-adjustable viewing distance, height, and dynamic rotation capabilities[cite: 69, 70, 71].

### 💡 Advanced Rendering & Graphics Techniques
* [cite_start]**Lighting System:** Implements ambient, diffuse, and specular lighting components[cite: 24]. [cite_start]Features a dynamic day/night cycle system (affecting ambient lighting and sky textures) and functional car headlights (spot lighting)[cite: 24, 46, 48, 49].
* [cite_start]**Texture Mapping:** Extensive use of textures with mipmapping support and appropriate wrapping modes (repeat, clamp) for ground, architectural, and environmental elements[cite: 26, 27].
* [cite_start]**Hierarchical Modeling:** Extensively used for complex structures like the car model (managing car body and wheels as a single entity), playground equipment, and trees[cite: 16, 17, 18].

### 🏎️ Vehicle Physics & Animation
* [cite_start]**Realistic Handling:** Features progressive deceleration due to friction, natural acceleration, and an opposite steering behavior when reversing[cite: 82, 86, 87].
* [cite_start]**Advanced Mechanics:** Wheel rotation is precisely calculated based on wheel circumference, and turning radius reduces at higher speeds for stability[cite: 78, 89].
* [cite_start]**Animations:** Includes dynamic steering wheel animation responding to turns, an active speedometer in first-person view, and animated playground elements like a merry-go-round and seesaw[cite: 28, 142, 146, 206, 207].
* [cite_start]**Collision Detection:** Implements collision detection with mountain boundaries[cite: 214].

### 🏙️ Rich Environmental Design
* [cite_start]**Urban Elements:** Multi-story buildings with clamped texturing, textured highways with lamp posts, and a regulation-style soccer field[cite: 99, 100, 118, 119, 131].
* [cite_start]**Natural Landscapes:** Natural lake with transparent water effects, multi-textured grass areas, and garden paths generated using Bézier curve algorithms[cite: 93, 108, 112].

## 🎮 Controls

### Global & View Controls
| Key | Action |
| :--- | :--- |
| `M` | [cite_start]Toggle between Day and Night modes [cite: 160, 227] |
| `C` | [cite_start]Toggle between Free camera and Third-person view [cite: 179, 204, 227] |
| `V` | [cite_start]Toggle between Third-person and First-person view [cite: 193, 203, 227] |

### Driving Controls (Third/First-Person Modes)
| Key | Action |
| :--- | :--- |
| `W` / `S` | [cite_start]Accelerate forward / Brake & Reverse [cite: 182, 183, 197, 198, 227] |
| `A` / `D` | [cite_start]Steer left / Steer right [cite: 186, 199, 227] |
| `L` / `T` | [cite_start]Switch on/off headlights (First-person mode) [cite: 200, 227] |

### Camera Controls (Free / Third-Person Modes)
| Key | Action |
| :--- | :--- |
| `W` / `S` / `A` / `D` | [cite_start]Move camera forward/backward/left/right (Free Camera) [cite: 167, 168, 169, 170, 171, 227] |
| `Arrow Keys` | [cite_start]Rotate camera up/down/left/right [cite: 172, 173, 174, 190, 227] |
| `H` / `L` | [cite_start]Increase/Decrease camera height (Free Camera) [cite: 175, 176, 177, 227] |
| `I` / `O` | [cite_start]Zoom in / Zoom out (Third-Person) [cite: 187, 188, 189, 227] |

## 📸 Screenshots

*(建议：挑选3张报告中最精彩的截图放在这里，例如：带有反光效果的湖面、第一人称驾驶视角、昼夜交替的街道)*
<p align="center">
  <img src="docs/screenshot_lake.png" width="30%" />
  <img src="docs/screenshot_firstperson.png" width="30%" />
  <img src="docs/screenshot_night.png" width="30%" />
</p>

## 🛠️ Technologies Used

* [cite_start]**C++** * **OpenGL** (Graphics rendering API) [cite: 8, 234]
* [cite_start]**freeglut** (Window management and interaction) [cite: 234]

---
[cite_start]*Developed by Zhuozhi Li* [cite: 2]
