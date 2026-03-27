#define FREEGLUT_STATIC
#include <GL/freeglut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>


// ========= Global Variable =========
float eye_x, eye_y, eye_z;        // Camera position
float center_x, center_y, center_z;// Camera target point
float width, height;              // Window dimensions
float car_rotation = 0.0;         // Car rotation angle
float car_x = 0.0, car_z = 0.0;   // Car position
float car_speed = 0.1;            // Car movement speed
float camera_rotation = 0.0;      // Camera horizontal rotation angle
float camera_height = 3.0;        // Camera height
float camera_distance = 5.0;      // Distance from camera to target
float wheel_rotation = 0.0;       // Wheel rotation angle
float current_speed = 0.0;        // Current speed
float max_speed = 0.2;            // Maximum speed
float acceleration = 0.0015;      // Acceleration rate
float deceleration = 0.002;       // Deceleration rate (when braking)
float natural_deceleration = 0.0008; // Natural deceleration (when releasing keys)
bool w_pressed = false;           // W key pressed state
bool s_pressed = false;           // S key pressed state
bool follow_car = false;          // Camera follows car state
bool a_pressed = false;           // A key pressed state
bool d_pressed = false;           // D key pressed state
float turn_speed = 1.2;           // Turning speed (degrees/frame)
bool arrow_left_pressed = false;
bool arrow_right_pressed = false;
bool arrow_up_pressed = false;
bool arrow_down_pressed = false;
bool zoom_in_pressed = false;
bool zoom_out_pressed = false;
float camera_rotate_speed = 1.5;    // Camera rotation speed
float camera_height_speed = 0.15;   // Camera height adjustment speed
float camera_zoom_speed = 0.5;      // Camera zoom speed
float wheel_turn_angle = 0.0;       // Wheel steering angle
float max_wheel_turn = 30.0;        // Maximum steering angle
float camera_move_speed = 0.3;      // Camera movement speed
float camera_x = 20.0;              // Camera x coordinate
float camera_z = 20.0;              // Camera z coordinate
float camera_angle_y = 0.0;         // Camera horizontal angle
float camera_angle_x = 30.0;        // Camera vertical angle
bool h_pressed = false;             // H key pressed state
bool l_pressed = false;             // L key pressed state
float target_wheel_turn_angle = 0.0;  // Target wheel steering angle
float wheel_turn_smooth_factor = 0.15;  // Wheel steering smoothing factor
bool transitioning = false;           // Transition state
float transition_progress = 0.0f;     // Transition progress (0.0 to 1.0)
float transition_speed = 0.05f;       // Transition speed
float transition_start_x, transition_start_y, transition_start_z;
float transition_start_center_x, transition_start_center_y, transition_start_center_z;
bool first_person_view = false;     // First-person view flag
float driver_height = 1.2;          // Driver's eye height
float driver_forward_offset = 0.3;  // Driver's forward offset
float steering_wheel_rotation = 0.0;  // Steering wheel rotation angle
float steering_wheel_smooth_factor = 0.1;  // Steering wheel rotation smoothing factor
bool isNightMode = false;           // Night mode flag (default: off)
float garage_width = 5.0;           // Garage width
float garage_length = 6.0;          // Garage length
float garage_height = 3.0;          // Garage height
float garage_x = 8.0;               // Garage x coordinate (roadside)
float garage_z = 20.0;              // Garage z coordinate (roadside)
float plane_x = -25.0;              // Fighter jet x coordinate
float plane_y = 0.2;                // Fighter jet y coordinate (ground level)
float plane_z = 30.0;               // Fighter jet z coordinate
float plane_rotation = -45.0;       // Fighter jet initial orientation (degrees)

#define PI 3.14159265358979323846
#define WHEEL_RADIUS 0.3            // Wheel radius (matches scale value in drawWheel)
#define WHEEL_CIRCUMFERENCE (2.0 * PI * WHEEL_RADIUS)  // Wheel circumference

// 添加纹理相关的全局变量
GLuint groundTexture;    // Ground texture ID
GLuint skyTexture;       // Sky texture ID
GLuint highwayTexture;   // Highway texture ID
GLuint lakeTexture;      // Lake texture ID
GLuint grassTexture;     // Grass texture ID
GLuint grassTexture2;    // Second grass texture ID
GLuint grassTexture3;    // Third grass texture ID
GLuint brick2Texture;    // Brick2 texture ID
GLuint leafTexture;      // Leaf texture ID
GLuint leafTexture2;     // Second leaf texture ID
GLuint trunkTexture;     // Tree trunk texture ID
GLuint dayTexture;       // Daytime sky texture ID
GLuint floorTexture;     // Floor texture ID
GLuint pathTexture;
GLuint shirtTexture;
GLuint shirtTexture2;
GLuint photoTexture;
GLuint wallTexture;
GLuint wallTexture2;
GLuint wallTexture3;
GLuint roofTexture;
GLuint playgroundTexture;  // Playground texture ID
GLuint loadTexture(const char* filename);
GLfloat headlight_ambient[] = { 0.0, 0.0, 0.0, 1.0 };     // Weak ambient light
GLfloat headlight_diffuse[] = { 1.0, 1.0, 0.8, 1.0 };     // Yellowish diffuse light
GLfloat headlight_specular[] = { 1.0, 1.0, 0.8, 1.0 };    // Yellowish specular light
bool spotLightOn = false;                                  // Headlight switch state


// ============Methods============
void setupLights(void);
void setMaterial(void);
void setupCamera(void);
void display(void);
void drawScene(void);
void drawObjects(void);
void reshape(int w, int h);
void keyboard(unsigned char key, int x, int y);
void specialKeys(int key, int x, int y);
void keyboardUp(unsigned char key, int x, int y);
void update(int value);
void drawGround(void);
void drawCarBody(void);
void drawWheel(float turn_angle);
void drawCar(void);
void drawLampPost(float x, float z);
void drawBuilding(float x, float z, float height, float width);
void drawSkyBox(void);
void drawHighway(void);
void init(void);
void drawMountain(float x, float z, float height, float width);
void draw2DHUD(void);
void drawSteeringWheel(void);
void drawSpeedometer(void);
void drawCarWindows(void);
void drawLake(void);
void drawGrass(void);
void drawTrashBin(float x, float z);
void drawTree(float x, float z, float height, float trunk_radius);
void drawGarage(void);
void drawFighterJet(void);
void drawPark(void);
void drawParkPath(void);
void drawTrees();
void drawParkBench(float x, float z, float rotation);
void drawParkRocks();
void calculateBezierPoint(float t, float* result, float p0[], float p1[], float p2[], float p3[]);
void drawPlayground();
void drawSwingSet(float x, float y, float z);
void drawSlide(float x, float y, float z, float rotation);
void drawSeesaw(float x, float y, float z);
void drawMerryGoRound(float x, float y, float z);
void drawPlaygroundFence(float size);
void drawSoccerField();
void drawGoalNet(float width, float height, float depth, float z_direction);
void drawGoal(float width, float height, float depth, float direction);
void drawGarden();
void drawGardenBorder();
void drawFlowers();
void drawDaisy(float x, float z);
void drawRose(float x, float z);
void drawTulip(float x, float z);


//============ init =============
void init() {
    // 1. Basic setup
    glClearColor(0.3, 0.3, 0.3, 1.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);

    // 2. Set projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLdouble)width / (GLdouble)height, 0.1, 10000.0);

    // 3. Setup lighting
    setupLights();

    // Enable texturing
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Load ground texture
    groundTexture = loadTexture("textures/brick.bmp");
    brick2Texture = loadTexture("textures/brick2.bmp");
    floorTexture = loadTexture("textures/floor.bmp");
    
    // Load sky texture
    dayTexture = loadTexture("textures/sky.bmp");
    skyTexture = loadTexture("textures/nights.bmp");
    
    // Load highway texture
    highwayTexture = loadTexture("textures/highway.bmp");
    
    // Load lake texture
    lakeTexture = loadTexture("textures/lake.bmp");
    
    // Load grass texture
    grassTexture = loadTexture("textures/grass.bmp");
    grassTexture2 = loadTexture("textures/grass2.bmp");
    grassTexture3 = loadTexture("textures/grass3.bmp");

    // Load leaf texture
    leafTexture = loadTexture("textures/leaf.bmp");
    leafTexture2 = loadTexture("textures/leaf2.bmp");
    
    // Load trunk texture
    trunkTexture = loadTexture("textures/trunk.bmp");
    
    // Load path texture
    pathTexture = loadTexture("textures/path.bmp");
    
    // Load building texture
    shirtTexture = loadTexture("textures/shirt.bmp");
    shirtTexture2 = loadTexture("textures/shirt2.bmp");
    photoTexture = loadTexture("textures/photo.bmp");
    wallTexture = loadTexture("textures/wall.bmp");
    wallTexture2 = loadTexture("textures/wall2.bmp");
    wallTexture3 = loadTexture("textures/wall3.bmp");
    roofTexture = loadTexture("textures/roof.bmp");

    // Load playground texture
    playgroundTexture = loadTexture("textures/playground.bmp");
}

// Function for loading texture
GLuint loadTexture(const char* filename) {
    GLuint textureID;
    FILE* file = NULL;

    // Print current texture loading path
    printf("Attempting to load texture: %s\n", filename);

    errno_t err = fopen_s(&file, filename, "rb");
    if (err != 0 || !file) {
        printf("Error: Could not open texture file %s (Error code: %d)\n", filename, err);
        return 0;
    }

    // Read BMP file header
    unsigned char header[54];
    size_t bytesRead = fread(header, sizeof(unsigned char), 54, file);
    if (bytesRead != 54) {
        printf("Error: Invalid BMP file format (header size mismatch)\n");
        fclose(file);
        return 0;
    }

    // Get image information
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Print image information
    printf("Image dimensions: %dx%d\n", width, height);

    // Calculate actual bytes needed per row (including padding)
    int rowSize = (width * 3 + 3) & ~3;    // Round up to multiple of 4
    int totalSize = rowSize * height;       // Total size

    printf("Row size with padding: %d bytes\n", rowSize);
    printf("Total size with padding: %d bytes\n", totalSize);

    // Allocate memory for padded data
    unsigned char* paddedData = (unsigned char*)malloc(totalSize);
    if (!paddedData) {
        printf("Error: Failed to allocate memory for padded texture data\n");
        fclose(file);
        return 0;
    }

    // Read complete data (including padding)
    bytesRead = fread(paddedData, sizeof(unsigned char), totalSize, file);
    if (bytesRead != totalSize) {
        printf("Error: Failed to read texture data (expected %d bytes, got %zu)\n", totalSize, bytesRead);
        free(paddedData);
        fclose(file);
        return 0;
    }

    // Create data without padding
    unsigned char* unpackedData = (unsigned char*)malloc(width * height * 3);
    if (!unpackedData) {
        printf("Error: Failed to allocate memory for unpacked data\n");
        free(paddedData);
        fclose(file);
        return 0;
    }

    // Remove padding bytes
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < 3; c++) {
                unpackedData[(y * width + x) * 3 + c] =
                    paddedData[y * rowSize + x * 3 + c];
            }
        }
    }

    // Generate texture
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // Create texture and mipmaps using processed data without padding
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, width, height,
        GL_BGR_EXT, GL_UNSIGNED_BYTE, unpackedData);

    // Clean up memory
    free(paddedData);
    free(unpackedData);
    fclose(file);

    printf("Successfully loaded texture: %s (ID: %u)\n", filename, textureID);
    return textureID;
}

void setupLights() {
    if (isNightMode) {
        // Night lighting
        GLfloat ambient[] = { 0.2, 0.2, 0.2, 1.0 };
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);

        GLfloat light0_pos[] = { 10.0, 10.0, 10.0, 1.0 };
        GLfloat light0_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
        GLfloat light0_specular[] = { 1.0, 1.0, 1.0, 1.0 };

        glEnable(GL_LIGHT0);
        glLightfv(GL_LIGHT0, GL_POSITION, light0_pos);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);
    }
    else {
        // Daylight lighting
        GLfloat ambient[] = { 0.7, 0.7, 0.7, 1.0 };
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);

        GLfloat light0_pos[] = { -100.0, 100.0, 100.0, 1.0 };  // More distant light source
        GLfloat light0_diffuse[] = { 1.0, 1.0, 0.9, 1.0 };     // Slightly yellowish sunlight
        GLfloat light0_specular[] = { 1.0, 1.0, 0.9, 1.0 };

        glEnable(GL_LIGHT0);
        glLightfv(GL_LIGHT0, GL_POSITION, light0_pos);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);
    }

    // Configure headlights (GL_LIGHT1)
    glLightfv(GL_LIGHT1, GL_AMBIENT, headlight_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, headlight_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, headlight_specular);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 30.0);
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 10.0);
    glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.0);
    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.05);
    glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.002);
}

void setMaterial() {
    // set up materials
    GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
    GLfloat mat_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void setupCamera() {
    if (transitioning) {
        float target_eye_x, target_eye_y, target_eye_z;
        float target_center_x, target_center_y, target_center_z;

        if (follow_car) {
            if (first_person_view) {
                // Calculate first-person view target position
                float car_angle_rad = car_rotation * PI / 180.0;
                target_eye_x = car_x + driver_forward_offset * cos(car_angle_rad);
                target_eye_z = car_z - driver_forward_offset * sin(car_angle_rad);
                target_eye_y = driver_height;

                // Target point in front of view
                target_center_x = car_x + (driver_forward_offset + 1.0) * cos(car_angle_rad);
                target_center_z = car_z - (driver_forward_offset + 1.0) * sin(car_angle_rad);
                target_center_y = driver_height;
            }
            else {
                // Original third-person follow camera calculation
                float car_angle_rad = car_rotation * PI / 180.0;
                target_eye_x = car_x - camera_distance * cos(car_angle_rad);
                target_eye_z = car_z + camera_distance * sin(car_angle_rad);
                target_eye_y = camera_height;
                target_center_x = car_x;
                target_center_z = car_z;
                target_center_y = 1.0;
            }
        }
        else {
            // Original free camera calculation
            float angle_y_rad = camera_angle_y * PI / 180.0;
            float angle_x_rad = camera_angle_x * PI / 180.0;
            float look_x = sin(angle_y_rad) * cos(angle_x_rad);
            float look_y = sin(angle_x_rad);
            float look_z = cos(angle_y_rad) * cos(angle_x_rad);
            target_eye_x = camera_x;
            target_eye_y = camera_height;
            target_eye_z = camera_z;
            target_center_x = camera_x + look_x;
            target_center_y = camera_height + look_y;
            target_center_z = camera_z + look_z;
        }

        // Use smooth interpolation
        eye_x = transition_start_x + (target_eye_x - transition_start_x) * transition_progress;
        eye_y = transition_start_y + (target_eye_y - transition_start_y) * transition_progress;
        eye_z = transition_start_z + (target_eye_z - transition_start_z) * transition_progress;
        center_x = transition_start_center_x + (target_center_x - transition_start_center_x) * transition_progress;
        center_y = transition_start_center_y + (target_center_y - transition_start_center_y) * transition_progress;
        center_z = transition_start_center_z + (target_center_z - transition_start_center_z) * transition_progress;

        // Update transition progress
        transition_progress += transition_speed;
        if (transition_progress >= 1.0f) {
            transitioning = false;
            transition_progress = 1.0f;
        }
    }
    else if (follow_car) {
        if (first_person_view) {
            // Direct first-person view calculation (no transition)
            float car_angle_rad = car_rotation * PI / 180.0;
            eye_x = car_x + driver_forward_offset * cos(car_angle_rad);
            eye_z = car_z - driver_forward_offset * sin(car_angle_rad);
            eye_y = driver_height;

            center_x = car_x + (driver_forward_offset + 1.0) * cos(car_angle_rad);
            center_z = car_z - (driver_forward_offset + 1.0) * sin(car_angle_rad);
            center_y = driver_height;
        }
        else {
            // Original third-person follow camera calculation
            float car_angle_rad = car_rotation * PI / 180.0;
            eye_x = car_x - camera_distance * cos(car_angle_rad);
            eye_z = car_z + camera_distance * sin(car_angle_rad);
            eye_y = camera_height;
            center_x = car_x;
            center_z = car_z;
            center_y = 1.0;
        }
    }
    else {
        // Original free camera calculation
        float angle_y_rad = camera_angle_y * PI / 180.0;
        float angle_x_rad = camera_angle_x * PI / 180.0;
        float look_x = sin(angle_y_rad) * cos(angle_x_rad);
        float look_y = sin(angle_x_rad);
        float look_z = cos(angle_y_rad) * cos(angle_x_rad);
        eye_x = camera_x;
        eye_y = camera_height;
        eye_z = camera_z;
        center_x = eye_x + look_x;
        center_y = eye_y + look_y;
        center_z = eye_z + look_z;
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eye_x, eye_y, eye_z,
        center_x, center_y, center_z,
        0.0, 1.0, 0.0);
}

void display() {
    // 1. Clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // 2. Setup camera
    setupCamera();

    // 3. Draw scene
    drawScene();

    // 4. Draw HUD
    draw2DHUD();

    // 5. Swap buffers
    glutSwapBuffers();
}

void drawScene() {
    glPushMatrix();

    // 1. First draw skybox
    drawSkyBox();

    // 2. Set materials
    setMaterial();

    // 3. Draw other objects
    drawObjects();

    glPopMatrix();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLdouble)w / (GLdouble)h, 0.1, 10000.0);
    glMatrixMode(GL_MODELVIEW);
}

void drawObjects() {
    // Draw the sky box first
    drawSkyBox();

    // Draw mountains
    float mountainSpacing = 11.5;  
    float mountainHeight = 9.2;   
    float mountainWidth = 15.4;    
    float mapSize = 50.0;         

    // Draw northern mountain range
    for (float x = -mapSize; x <= mapSize; x += mountainSpacing) {
        drawMountain(x, -mapSize, mountainHeight, mountainWidth);
    }

    // Draw southern mountain range
    for (float x = -mapSize; x <= mapSize; x += mountainSpacing) {
        drawMountain(x, mapSize, mountainHeight, mountainWidth);
    }

    // Draw western mountain range
    for (float z = -mapSize; z <= mapSize; z += mountainSpacing) {
        drawMountain(-mapSize, z, mountainHeight, mountainWidth);
    }

    // Draw eastern mountain range
    for (float z = -mapSize; z <= mapSize; z += mountainSpacing) {
        drawMountain(mapSize, z, mountainHeight, mountainWidth);
    }

    // Draw other elements
    drawGround();

    // Draw grass and lake (before buildings and roads)
    drawGrass();
    drawLake();

    // Then draw roads and other objects
    drawHighway();

    drawSoccerField();

    // Add lamp posts
    float lampSpacing = 10.0;  // Reduced lamp post spacing
    float roadWidth = 3.0;     // Reduced road width
    float roadLength = 50.0;   // Reduced road length
    float lampOffset = 1.618;  // Reduced lamp post offset

    // Add lamp posts on the left side of the road
    for (float z = -roadLength; z <= roadLength; z += lampSpacing) {
        drawLampPost(-(roadWidth + lampOffset), z);
    }

    // Add lamp posts on the right side of the road
    for (float z = -roadLength; z <= roadLength; z += lampSpacing) {
        drawLampPost(roadWidth + lampOffset, z);
    }

    // Add buildings
    drawBuilding(10.5, 0, 7, 5);
    drawBuilding(10.5, -6, 7, 5);
    drawBuilding(10.5, -12, 6, 5);
    drawBuilding(10.5, -18, 5, 5);
    drawBuilding(10.5, 6, 5, 5);

    // Add playground
    drawPlayground();

    // Draw car
    drawCar();

    // Adjust trash bin positions with offset
    for (float z = -45; z <= 45; z += 15) {
        drawTrashBin(-5.0, z);          // Left side trash bin
        drawTrashBin(5.0, z + 8.0);     // Right side trash bin offset by 8 units
    }

    // Draw garage
    drawGarage();

    // Add fighter jet
    drawFighterJet();

    // Add park
    drawPark();

    // Add garden
    drawGarden();

    // Add benches on both sides of the road
    float benchSpacing = 15.0;  // Spacing between benches
    float benchOffset = 2.618;  // Distance from bench to road edge

    // Add benches on the left side of the road
    for (float z = -40; z <= 40; z += benchSpacing) {
        drawParkBench(-(roadWidth + benchOffset), z, 90.0);  // Rotate 90 degrees to face the road
    }

    // Add benches on the right side of the road
    for (float z = -40 + benchSpacing / 2; z <= 40; z += benchSpacing) {  // Offset placement
        drawParkBench(roadWidth + benchOffset, z, -90.0);  // Rotate -90 degrees to face the road
    }

    // Add trees
    drawTrees();
}

// ================ Keyboard interaction ================

void keyboard(unsigned char key, int x, int y) {
    key = tolower(key);
    switch (key) {
    case 'w':
        w_pressed = true;
        s_pressed = false;
        break;
    case 's':
        s_pressed = true;
        w_pressed = false;
        break;
    case 'a':
        a_pressed = true;
        d_pressed = false;
        break;
    case 'd':
        d_pressed = true;
        a_pressed = false;
        break;
    case 'i':
        zoom_in_pressed = true;
        zoom_out_pressed = false;
        break;
    case 'o':
        zoom_out_pressed = true;
        zoom_in_pressed = false;
        break;
    case 'c':
        if (!transitioning) {
            transitioning = true;
            transition_progress = 0.0f;
            transition_start_x = eye_x;
            transition_start_y = eye_y;
            transition_start_z = eye_z;
            transition_start_center_x = center_x;
            transition_start_center_y = center_y;
            transition_start_center_z = center_z;
            follow_car = !follow_car;
            if (!follow_car) first_person_view = false;  // Exit first-person view when leaving follow mode
        }
        break;
    case 'v':
        if (follow_car && !transitioning) {  // Allow first-person view switch only in follow mode
            transitioning = true;
            transition_progress = 0.0f;
            transition_start_x = eye_x;
            transition_start_y = eye_y;
            transition_start_z = eye_z;
            transition_start_center_x = center_x;
            transition_start_center_y = center_y;
            transition_start_center_z = center_z;
            first_person_view = !first_person_view;
        }
        break;
    case 'h':
        h_pressed = true;
        l_pressed = false;  // Ensure l is not pressed
        break;
    case 'l':
        l_pressed = true;
        h_pressed = false;  // Ensure h is not pressed
        break;
    case 'm':
        isNightMode = !isNightMode;  // Toggle day/night mode
        if (isNightMode) {
            // Night mode ambient light and background color
            GLfloat ambient[] = { 0.4, 0.4, 0.4, 1.0 };
            glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);
            glClearColor(0.3, 0.3, 0.3, 1.0);
        }
        else {
            // Daylight mode ambient light and background color
            GLfloat ambient[] = { 0.8, 0.8, 0.8, 1.0 };
            glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);
            glClearColor(0.6, 0.8, 1.0, 1.0);
        }
        break;


    case 't': // Toggle headlights
        if (first_person_view) {  // Headlights can only be turned on in first-person view
            spotLightOn = !spotLightOn;
            if (spotLightOn) {
                glEnable(GL_LIGHT1);
                glEnable(GL_LIGHT2);
            }
            else {
                glDisable(GL_LIGHT1);
                glDisable(GL_LIGHT2);
            }
        }
        break;
    }
    glutPostRedisplay();
}

void keyboardUp(unsigned char key, int x, int y) {
    key = tolower(key);
    switch (key) {
    case 'w':
        w_pressed = false;
        break;
    case 's':
        s_pressed = false;
        break;
    case 'a':
        a_pressed = false;
        break;
    case 'd':
        d_pressed = false;
        break;
    case 'i':
        zoom_in_pressed = false;
        break;
    case 'o':
        zoom_out_pressed = false;
        break;
    case 'h':
        h_pressed = false;
        break;
    case 'l':
        l_pressed = false;
        break;
    }
    glutPostRedisplay();
}

void specialKeys(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT:
        arrow_left_pressed = true;
        arrow_right_pressed = false;  // Prevent simultaneous left-right press
        break;
    case GLUT_KEY_RIGHT:
        arrow_right_pressed = true;
        arrow_left_pressed = false;   // Prevent simultaneous left-right press
        break;
    case GLUT_KEY_UP:
        arrow_up_pressed = true;
        arrow_down_pressed = false;   // Prevent simultaneous up-down press
        break;
    case GLUT_KEY_DOWN:
        arrow_down_pressed = true;
        arrow_up_pressed = false;     // Prevent simultaneous up-down press
        break;
    }
}

void specialKeysUp(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT:
        arrow_left_pressed = false;
        break;
    case GLUT_KEY_RIGHT:
        arrow_right_pressed = false;
        break;
    case GLUT_KEY_UP:
        arrow_up_pressed = false;
        break;
    case GLUT_KEY_DOWN:
        arrow_down_pressed = false;
        break;
    }
}

// Add new helper functions
void accelerate() {
    current_speed = fmin(current_speed + acceleration, max_speed);
}

void brake() {
    current_speed = fmax(current_speed - deceleration, -max_speed / 2);
}

void naturalDecelerate() {
    if (current_speed > 0) {
        current_speed = fmax(0, current_speed - natural_deceleration);
    }
    else if (current_speed < 0) {
        current_speed = fmin(0, current_speed + natural_deceleration);
    }
}

// Modify update function
void update(int value) {
    if (!follow_car) {
        // WASD camera movement control in free view mode
        float angle_rad = camera_angle_y * PI / 180.0;

        // Calculate expected new position
        float new_camera_x = camera_x;
        float new_camera_z = camera_z;

        if (w_pressed) {
            new_camera_x += sin(angle_rad) * camera_move_speed;
            new_camera_z += cos(angle_rad) * camera_move_speed;
        }
        if (s_pressed) {
            new_camera_x -= sin(angle_rad) * camera_move_speed;
            new_camera_z -= cos(angle_rad) * camera_move_speed;
        }
        if (a_pressed) {
            new_camera_x += cos(angle_rad) * camera_move_speed;
            new_camera_z -= sin(angle_rad) * camera_move_speed;
        }
        if (d_pressed) {
            new_camera_x -= cos(angle_rad) * camera_move_speed;
            new_camera_z += sin(angle_rad) * camera_move_speed;
        }

        // Set boundary limits (slightly smaller than map size to keep camera out of mountains)
        float boundary = 45.0;  // Slightly smaller than mapSize
        float min_distance_to_mountain = 3.0;  // Minimum distance to maintain from mountains

        // Check if near mountain boundaries
        bool near_mountain = false;

        // Check northern mountain range
        if (new_camera_z < -boundary + min_distance_to_mountain) {
            near_mountain = true;
        }
        // Check southern mountain range
        if (new_camera_z > boundary - min_distance_to_mountain) {
            near_mountain = true;
        }
        // Check western mountain range
        if (new_camera_x < -boundary + min_distance_to_mountain) {
            near_mountain = true;
        }
        // Check eastern mountain range
        if (new_camera_x > boundary - min_distance_to_mountain) {
            near_mountain = true;
        }

        // Update position only when not near mountains
        if (!near_mountain) {
            camera_x = new_camera_x;
            camera_z = new_camera_z;
        }

        // Arrow keys control camera rotation (unchanged)
        if (arrow_left_pressed) {
            camera_angle_y += camera_rotate_speed;
        }
        if (arrow_right_pressed) {
            camera_angle_y -= camera_rotate_speed;
        }
        if (arrow_up_pressed) {
            camera_angle_x = fmin(89.0, camera_angle_x + camera_rotate_speed);
        }
        if (arrow_down_pressed) {
            camera_angle_x = fmax(-89.0, camera_angle_x - camera_rotate_speed);
        }

        // Camera height control (unchanged)
        if (h_pressed) {
            camera_height += camera_height_speed;
        }
        if (l_pressed) {
            camera_height = fmax(1.0, camera_height - camera_height_speed);
        }
    }
    else {
        // Vehicle control in follow mode (unchanged)
        if (w_pressed) {
            accelerate();
        }
        else if (s_pressed) {
            brake();
        }
        else {
            naturalDecelerate();
        }

        // Update target steering angle
        if (a_pressed) {
            target_wheel_turn_angle = max_wheel_turn;
        }
        else if (d_pressed) {
            target_wheel_turn_angle = -max_wheel_turn;
        }
        else {
            target_wheel_turn_angle = 0.0;
        }

        // Smooth interpolation of current steering angle
        wheel_turn_angle += (target_wheel_turn_angle - wheel_turn_angle) * wheel_turn_smooth_factor;

        // Only change vehicle direction when moving and wheels are turned
        if (fabs(current_speed) > 0.001) {  // Vehicle is moving
            // Calculate steering effect based on wheel angle and speed
            float turn_factor = (wheel_turn_angle / max_wheel_turn) * turn_speed;
            // Adjust steering effect based on speed (higher speed = reduced steering)
            float speed_factor = fmax(0.5, 1.0 - (fabs(current_speed) / max_speed) * 0.5);
            turn_factor *= speed_factor;

            // Adjust steering direction based on forward/reverse movement
            if (current_speed > 0) {
                car_rotation += turn_factor;
            }
            else {
                car_rotation -= turn_factor;  // Reverse steering when backing up
            }

            // Keep angle between 0-360 degrees
            if (car_rotation >= 360.0) car_rotation -= 360.0;
            if (car_rotation < 0.0) car_rotation += 360.0;
        }

        // Add boundary checking when updating car position
        if (current_speed != 0) {
            float movement_angle = car_rotation * PI / 180.0;
            float new_x = car_x + current_speed * cos(movement_angle);
            float new_z = car_z - current_speed * sin(movement_angle);

            // Set boundary limits (slightly smaller than map size to prevent hitting mountains)
            float boundary = 42.8;  // Slightly smaller than mapSize
            float car_size = 1.0;   // Assume car size is 1.0 units

            // Only update position when within boundaries
            if (new_x >= -boundary + car_size && new_x <= boundary - car_size) {
                car_x = new_x;
            }
            else {
                current_speed = 0;  // Stop when hitting boundary
            }

            if (new_z >= -boundary + car_size && new_z <= boundary - car_size) {
                car_z = new_z;
            }
            else {
                current_speed = 0;  // Stop when hitting boundary
            }
        }

        // Update wheel rotation
        if (current_speed != 0) {
            // Calculate angle wheel should rotate
            // Current speed / circumference = proportion of rotation
            // Multiply by 360 degrees to get angle
            float rotation_delta = (current_speed / WHEEL_CIRCUMFERENCE) * 360.0;
            wheel_rotation -= rotation_delta;

            // Keep angle between 0-360 degrees
            if (wheel_rotation >= 360.0) wheel_rotation -= 360.0;
            if (wheel_rotation < 0.0) wheel_rotation += 360.0;
        }
    }

    // Add gradual transition effect for camera control
    float camera_smooth_factor = 0.1;  // Adjust this value to change smoothness

    // Only respond to left/right rotation in non-follow mode
    if (!follow_car) {
        if (arrow_left_pressed) {
            camera_rotation += camera_rotate_speed * camera_smooth_factor;
        }
        if (arrow_right_pressed) {
            camera_rotation -= camera_rotate_speed * camera_smooth_factor;
        }
    }

    // These controls are active in all modes
    if (arrow_up_pressed) {
        camera_height += camera_height_speed;
    }
    if (arrow_down_pressed) {
        camera_height = fmax(1.0, camera_height - camera_height_speed);
    }
    if (zoom_in_pressed) {
        camera_distance = fmax(2.0, camera_distance - camera_zoom_speed * camera_smooth_factor);
    }
    if (zoom_out_pressed) {
        camera_distance = fmin(20.0, camera_distance + camera_zoom_speed * camera_smooth_factor);
    }

    // Keep angle between 0-360 degrees
    if (camera_rotation >= 360.0) camera_rotation -= 360.0;
    if (camera_rotation < 0.0) camera_rotation += 360.0;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}



// =============== Draw =================

// Modify drawGround to support texture
void drawGround() {
    glPushMatrix();

    // set material
    GLfloat ground_color[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, ground_color);

    glTranslatef(0.0, 0.0, 0.0);

    // Define road boundaries
    float roadWidth = 3.0;   // Highway width
    float borderWidth = 5.0; // Border width

    // Set different texture repeat values for different areas
    float mainTexRepeat = 30.0;    // Texture repeat count for main ground area

    // Left inner area
    glBindTexture(GL_TEXTURE_2D, grassTexture); 
    glEnable(GL_TEXTURE_2D);

    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0, 0.0);

    glTexCoord2f(0.0, 0.0);
    glVertex3f(-50.0, 0.0, -50.0);
    glTexCoord2f(mainTexRepeat / 2, 0.0);
    glVertex3f(-(roadWidth + borderWidth), 0.0, -50.0);
    glTexCoord2f(mainTexRepeat / 2, mainTexRepeat);
    glVertex3f(-(roadWidth + borderWidth), 0.0, 50.0);
    glTexCoord2f(0.0, mainTexRepeat);
    glVertex3f(-50.0, 0.0, 50.0);
    glEnd();

    // Right inner area
    glBindTexture(GL_TEXTURE_2D, brick2Texture);
    glEnable(GL_TEXTURE_2D);

    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0, 0.0);

    glTexCoord2f(0.0, 0.0);
    glVertex3f(roadWidth + borderWidth, 0.0, -50.0);
    glTexCoord2f(mainTexRepeat / 2, 0.0);
    glVertex3f(50.0, 0.0, -50.0);
    glTexCoord2f(mainTexRepeat / 2, mainTexRepeat);
    glVertex3f(50.0, 0.0, 50.0);
    glTexCoord2f(0.0, mainTexRepeat);
    glVertex3f(roadWidth + borderWidth, 0.0, 50.0);
    glEnd();

    // Draw outer areas
    glBindTexture(GL_TEXTURE_2D, groundTexture);

    glBegin(GL_QUADS);
    // Left outer area
    float texRepeatZ = 30.0;  // Number of texture repeats in Z direction
    float texRepeatX = 1.0;   // Number of texture repeats in X direction

    // Left outer area
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-(roadWidth + borderWidth), 0.0, -50.0);
    glTexCoord2f(texRepeatX, 0.0);
    glVertex3f(-roadWidth, 0.0, -50.0);
    glTexCoord2f(texRepeatX, texRepeatZ);
    glVertex3f(-roadWidth, 0.0, 50.0);
    glTexCoord2f(0.0, texRepeatZ);
    glVertex3f(-(roadWidth + borderWidth), 0.0, 50.0);

    // Right outer area
    glTexCoord2f(0.0, 0.0);
    glVertex3f(roadWidth, 0.0, -50.0);
    glTexCoord2f(texRepeatX, 0.0);
    glVertex3f(roadWidth + borderWidth, 0.0, -50.0);
    glTexCoord2f(texRepeatX, texRepeatZ);
    glVertex3f(roadWidth + borderWidth, 0.0, 50.0);
    glTexCoord2f(0.0, texRepeatZ);
    glVertex3f(roadWidth, 0.0, 50.0);
    glEnd();

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void drawLampPost(float x, float z) {
    // Lamp post
    GLfloat pole_color[] = { 0.4, 0.4, 0.4, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, pole_color);

    glPushMatrix();
    glTranslatef(x, 1.5, z);

    // Main pole
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    glScalef(0.1, 4.0, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    // Lamp head
    GLfloat light_color[] = { 1.0, 1.0, 0.8, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 0.8, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, light_color);
    glMaterialfv(GL_FRONT, GL_SPECULAR, light_specular);

    glPushMatrix();
    glTranslatef(0.0, 2.0, 0.0);
    glScalef(0.3, 0.2, 0.3);
    glutSolidCube(1.0);
    glPopMatrix();

    glPopMatrix();
}

void drawBuilding(float x, float z, float height, float width) {
    GLfloat building_color[] = { 0.7, 0.7, 0.8, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, building_color);

    glPushMatrix();
    glTranslatef(x, 0 + height / 2, z);
    glRotatef(-90.0, 0.0, 1.0, 0.0);
    glScalef(width, height, width);

    // Enable texture
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, wallTexture);  

    // Draw front, left and right faces
    glBegin(GL_QUADS);
    // Front face
    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, -0.5f, 0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, 0.5f, 0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 0.5f, 0.5f);

    // Left face
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f, 0.5f, 0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 0.5f, -0.5f);

    // Right face
    glNormal3f(1.0f, 0.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.5f, -0.5f, 0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, -0.5f, -0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, 0.5f, -0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.5f, 0.5f, 0.5f);

    // Top face
    glNormal3f(0.0f, 1.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, 0.5f, 0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, 0.5f, 0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, 0.5f, -0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 0.5f, -0.5f);
    glEnd();

    // Draw bottom face (no texture needed)
    glDisable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);

    // Bottom face
    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glEnd();

    // Set texture environment parameters to ignore material color
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

    // Utilize different textures for different location
    if (z == 0) {
        glBindTexture(GL_TEXTURE_2D, shirtTexture);
    }
    else if (z == -18) {
        glBindTexture(GL_TEXTURE_2D, photoTexture);  
    }
    else if (z == -12) {
        glBindTexture(GL_TEXTURE_2D, wallTexture2);  
    }
    else if (z == -6) {
        glBindTexture(GL_TEXTURE_2D, shirtTexture2); 
    }
    else {
        glBindTexture(GL_TEXTURE_2D, wallTexture);  
    }

    glEnable(GL_TEXTURE_2D);

    // Set texture wrap mode to CLAMP
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, -1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f, 0.5f, -0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.5f, 0.5f, -0.5f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.5f, -0.5f, -0.5f);
    glEnd();

    // Set texture environment parameters to ignore material color
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    glDisable(GL_TEXTURE_2D);


    // Add door drawing before windows
    // Set door material and color
    GLfloat door_color[] = { 0.4, 0.2, 0.1, 1.0 };  // Dark brown door
    glMaterialfv(GL_FRONT, GL_DIFFUSE, door_color);

    // Door dimensions
    float door_width = 0.2;
    float door_height = 0.3;

    // Draw door
    glPushMatrix();
    glTranslatef(0.0, -0.5 + door_height / 2, 0.501);  // Place at bottom front of building
    glScalef(door_width, door_height, 0.02);
    glutSolidCube(1.0);
    glPopMatrix();

    // Add door handle
    GLfloat handle_color[] = { 0.8, 0.8, 0.1, 1.0 };  // Golden door handle
    glMaterialfv(GL_FRONT, GL_DIFFUSE, handle_color);

    glPushMatrix();
    glTranslatef(door_width / 4, -0.5 + door_height / 2, 0.512);
    glutSolidSphere(0.02, 8, 8);  // Small spherical door handle
    glPopMatrix();


    // Windows
    GLfloat window_color[] = { 0.9, 0.9, 0.2, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, window_color);

    float window_size = 0.1;
    float window_spacing = 0.25;
    for (float y = 0; y < 0.4; y += window_spacing) {
        for (float x = -0.4; x < 0.4; x += window_spacing) {
            // Forward windows
            glPushMatrix();
            glTranslatef(x, y, 0.501);
            glScalef(window_size, window_size, 0.01);
            glutSolidCube(1.0);
            glPopMatrix();
        }
    }

    // Add air conditioner unit
    GLfloat ac_color[] = { 0.4, 0.4, 0.4, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, ac_color);

    glPushMatrix();
    glTranslatef(0.25, 0.5, -0.25);  // Place at opposite corner of roof
    glScalef(0.15, 0.1, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    glPopMatrix();  
}

void drawSkyBox() {
    glPushMatrix();

    glDepthMask(GL_FALSE);
    glDisable(GL_LIGHTING);

    glTranslatef(eye_x, eye_y, eye_z);

    float radius = 80.0;  // Radius of the skybox

    // Select texture based on mode
    if (isNightMode) {
        glBindTexture(GL_TEXTURE_2D, skyTexture);  // Night sky texture
    }
    else {
        glBindTexture(GL_TEXTURE_2D, dayTexture);  // Daytime texture
    }
    glEnable(GL_TEXTURE_2D);

    int segments = 32;
    int rings = 32;

    // Draw
    for (int i = 0; i < rings; i++) {
        // Modify angle range to -PI/2 to PI/2, covering the entire sphere
        float phi1 = ((float)i / rings) * PI - PI / 2;
        float phi2 = ((float)(i + 1) / rings) * PI - PI / 2;

        glBegin(GL_QUAD_STRIP);
        for (int j = 0; j <= segments; j++) {
            float theta = ((float)j / segments) * 2 * PI;

            // Improve texture coordinate calculation
            float s = (float)j / segments;
            // Use cosine to improve texture distribution
            float t1 = 0.5 + sin(phi1) * 0.5;
            float t2 = 0.5 + sin(phi2) * 0.5;

            // First point
            float x1 = radius * cos(phi1) * cos(theta);
            float y1 = radius * sin(phi1);
            float z1 = radius * cos(phi1) * sin(theta);

            // Second point
            float x2 = radius * cos(phi2) * cos(theta);
            float y2 = radius * sin(phi2);
            float z2 = radius * cos(phi2) * sin(theta);

            // Only draw upper hemisphere and small portion of lower hemisphere
            if (y1 > -radius * 0.3 && y2 > -radius * 0.3) {
                glTexCoord2f(s, t1);
                glVertex3f(x1, y1, z1);
                glTexCoord2f(s, t2);
                glVertex3f(x2, y2, z2);
            }
        }
        glEnd();
    }

    // Draw bottom transition area
    glBegin(GL_TRIANGLE_FAN);
    // Use slightly darker color for bottom
    glColor4f(0.3f, 0.3f, 0.4f, 1.0f);
    glVertex3f(0.0f, -radius * 0.3f, 0.0f);  // Center point

    // Create smooth color transition
    for (int i = 0; i <= segments; i++) {
        float theta = ((float)i / segments) * 2 * PI;
        float x = radius * cos(theta);
        float z = radius * sin(theta);
        // Gradually transition color to transparent
        glColor4f(0.3f, 0.3f, 0.4f, 0.0f);
        glVertex3f(x, -radius * 0.3f, z);
    }
    glEnd();

    // Restore states
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);  // Reset color
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);

    // Restore depth writing
    glDepthMask(GL_TRUE);

    glPopMatrix();
}

void drawCar() {
    glPushMatrix();
    glTranslatef(car_x, 0.68, car_z);
    glRotatef(car_rotation, 0.0, 1.0, 0.0);

    // Draw carbody
    GLfloat car_color[] = { 0.8, 0.1, 0.1, 1.0 };  // Red
    glMaterialfv(GL_FRONT, GL_DIFFUSE, car_color);
    drawCarBody();

    // Calculate inner and outer wheel steering angles (adjust coefficients for realism)
    float outer_wheel_angle = wheel_turn_angle;
    float inner_wheel_angle = wheel_turn_angle * 1.2f;  // Reduce angle difference between inner and outer wheels

    GLfloat wheel_color[] = { 0.2, 0.2, 0.2, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, wheel_color);

    // Front wheels: determine inner/outer based on steering direction
    if (wheel_turn_angle > 0) {  // Turning left
        // Front left wheel (inner)
        glPushMatrix();
        glTranslatef(0.7, -0.3, 0.6);
        drawWheel(inner_wheel_angle);
        glPopMatrix();

        // Front right wheel (outer)
        glPushMatrix();
        glTranslatef(0.7, -0.3, -0.6);
        drawWheel(outer_wheel_angle);
        glPopMatrix();
    }
    else {  // Turning right
        // Front left wheel (outer)
        glPushMatrix();
        glTranslatef(0.7, -0.3, 0.6);
        drawWheel(outer_wheel_angle);
        glPopMatrix();

        // Right wheel (inner)
        glPushMatrix();
        glTranslatef(0.7, -0.3, -0.6);
        drawWheel(inner_wheel_angle);
        glPopMatrix();
    }

    // Rear wheels (no steering)
    glPushMatrix();
    glTranslatef(-0.7, -0.3, 0.6);
    drawWheel(0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.7, -0.3, -0.6);
    drawWheel(0);
    glPopMatrix();

    glPopMatrix();
}

// Add helper function for drawing sports car
void drawCarBody() {
    glPushMatrix();
    glScalef(2.0, 0.5, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    // Car roof
    glPushMatrix();
    glTranslatef(-0.2, 0.3, 0.0);
    glScalef(1.0, 0.4, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    // Define fixed light offsets relative to car
    const float LIGHT_FORWARD = 1.0;   // Forward offset
    const float LIGHT_SIDE = 0.4;      // Side offset
    const float LIGHT_HEIGHT = 0.0;    // Height offset

    // Add headlights
    GLfloat headlight_color[] = { 1.0, 1.0, 0.0, 1.0 };
    GLfloat headlight_specular[] = { 1.0, 1.0, 0.0, 1.0 };
    GLfloat headlight_shininess[] = { 100.0 };

    glMaterialfv(GL_FRONT, GL_DIFFUSE, headlight_color);
    glMaterialfv(GL_FRONT, GL_SPECULAR, headlight_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, headlight_shininess);

    // Left headlight
    glPushMatrix();
    glTranslatef(LIGHT_FORWARD, LIGHT_HEIGHT, LIGHT_SIDE);
    glScalef(0.1, 0.1, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    // Right headlight
    glPushMatrix();
    glTranslatef(LIGHT_FORWARD, LIGHT_HEIGHT, -LIGHT_SIDE);
    glScalef(0.1, 0.1, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();
}

void drawWheel(float turn_angle) {
    glPushMatrix();
    // Apply steering angle first
    glRotatef(turn_angle, 0.0, 1.0, 0.0);
    // Keep remaining parts unchanged
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glRotatef(wheel_rotation, 0.0, 0.0, 1.0);
    glScalef(0.3, 0.3, 0.15);

    // Draw basic tire first
    glutSolidTorus(0.25, 0.8, 15, 15);

    // Add wheel spokes
    GLfloat spoke_color[] = { 0.2, 0.2, 0.2, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, spoke_color);

    for (int i = 0; i < 3; i++) {
        glPushMatrix();
        glRotatef(i * 120.0, 0.0, 0.0, 1.0);
        glScalef(0.1, 1.5, 0.1);
        glutSolidCube(1.0);
        glPopMatrix();
    }

    glPopMatrix();
}
// First-person view
void draw2DHUD() {
    if (!first_person_view) return;  // Only display under the first-person mode

    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, width, height, 0, -1, 1);  // 2D orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    // Draw car window frame first
    drawCarWindows();

    // Draw steering wheel
    drawSteeringWheel();

    // Draw speedometer only
    drawSpeedometer();

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glPopAttrib();
}

void drawSteeringWheel() {
    // Smoothly interpolate steering wheel rotation
    float target_rotation = -wheel_turn_angle * 2;  // Calculate target rotation based on wheel steering angle
    steering_wheel_rotation += (target_rotation - steering_wheel_rotation) * steering_wheel_smooth_factor;

    glPushMatrix();

    // Position steering wheel at bottom center of screen
    glTranslatef(width / 2, height - height / 4, 0);
    glRotatef(steering_wheel_rotation, 0, 0, 1);

    // Disable lighting to ensure correct color display
    glDisable(GL_LIGHTING);

    // Set steering wheel color
    glColor4f(0.5, 0.5, 0.5, 1.0);  // Fully opaque

    // Increase line width
    glLineWidth(5.0);  // Thicker lines

    // Draw steering wheel outer ring
    float wheel_radius = height / 6;
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i += 10) {
        float angle = i * PI / 180.0;
        glVertex2f(cos(angle) * wheel_radius, sin(angle) * wheel_radius);
    }
    glEnd();

    // Draw steering wheel spokes (thickened)
    glLineWidth(4);  // Slightly thinner for spokes
    glBegin(GL_LINES);
    for (int i = 0; i < 360; i += 45) {
        float angle = i * PI / 180.0;
        glVertex2f(0, 0);  // Center point
        glVertex2f(cos(angle) * wheel_radius, sin(angle) * wheel_radius);
    }
    glEnd();

    // Restore lighting state
    glEnable(GL_LIGHTING);

    glLineWidth(1.0);  // Restore default line width
    glPopMatrix();
}

void drawSpeedometer() {
    glPushMatrix();

    // Position speedometer in bottom right corner
    float speedo_x = width - width / 6;
    float speedo_y = height - height / 6;
    float speedo_radius = height / 8;

    glTranslatef(speedo_x, speedo_y, 0);

    // Disable lighting to ensure correct color display
    glDisable(GL_LIGHTING);

    // Draw speedometer outer ring
    glColor4f(1.0, 1.0, 1.0, 1.0);
    glLineWidth(2.5);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i += 10) {
        float angle = i * PI / 180.0;
        glVertex2f(cos(angle) * speedo_radius, sin(angle) * speedo_radius);
    }
    glEnd();

    // Draw scale markings
    glLineWidth(2.0);
    glBegin(GL_LINES);
    // Major scale marks
    for (int i = 0; i <= 270; i += 27) {
        float angle = (45 - i) * PI / 180.0;
        float outer_point_x = cos(angle) * speedo_radius;
        float outer_point_y = sin(angle) * speedo_radius;
        float inner_point_x = cos(angle) * (speedo_radius - 10);
        float inner_point_y = sin(angle) * (speedo_radius - 10);

        glVertex2f(outer_point_x, outer_point_y);
        glVertex2f(inner_point_x, inner_point_y);
    }

    // Draw the speedometer needle
    float speed_angle = (135.0 + (current_speed / max_speed) * 270.0) * PI / 180.0;
    glColor4f(1.0, 0.0, 0.0, 1.0);
    glLineWidth(2.0);

    float pointer_length = speedo_radius - 20;
    float pointer_width = 2.0;  // Make the pointer slender

    glBegin(GL_TRIANGLES);
    // Needle tip
    glVertex2f(cos(speed_angle) * pointer_length,
        sin(speed_angle) * pointer_length);

    // Needle base two points
    float base_angle = speed_angle + PI / 2;
    glVertex2f(cos(base_angle) * pointer_width,
        sin(base_angle) * pointer_width);
    glVertex2f(cos(base_angle + PI) * pointer_width,
        sin(base_angle + PI) * pointer_width);
    glEnd();

    // Draw central point
    glColor4f(0.8, 0.8, 0.8, 1.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0, 0);
    for (int i = 0; i <= 360; i += 10) {
        float angle = i * PI / 180.0;
        glVertex2f(cos(angle) * 5, sin(angle) * 5);
    }
    glEnd();

    // Restore states
    glEnable(GL_LIGHTING);
    glLineWidth(1.0);
    glPopMatrix();
}

// Add function to draw car window frame
void drawCarWindows() {
    if (!first_person_view) return;

    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);

    // Set window frame color
    glColor4f(0.8, 0.1, 0.1, 1.0);  // same as the car body

    // Draw A-pillars (sides of front windshield)
    float pillar_width = width * 0.03;  // A-pillar width
    float windshield_height = height * 0.4;  // Windshield height

    // Left A-pillar
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(pillar_width, 0);
    glVertex2f(pillar_width * 1.5, windshield_height);
    glVertex2f(0, windshield_height);
    glEnd();

    // Right A-pillar
    glBegin(GL_QUADS);
    glVertex2f(width - pillar_width, 0);
    glVertex2f(width, 0);
    glVertex2f(width, windshield_height);
    glVertex2f(width - pillar_width * 1.5, windshield_height);
    glEnd();

    // Upper crossbeam
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(width, 0);
    glVertex2f(width, pillar_width);
    glVertex2f(0, pillar_width);
    glEnd();

    // Dashboard
    glColor4f(0.1, 0.1, 0.1, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(0, height * 0.7);
    glVertex2f(width, height * 0.7);
    glVertex2f(width, height);
    glVertex2f(0, height);
    glEnd();

    glPopAttrib();
}

void drawHighway() {
    glPushMatrix();

    // Bind texture
    glBindTexture(GL_TEXTURE_2D, highwayTexture);
    glEnable(GL_TEXTURE_2D);

    // Set material
    GLfloat highway_color[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, highway_color);

    glTranslatef(0.0, 0.02, 0.0);

    // Draw
    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0, 0.0);

    // Use smaller texture repeat count for more realistic road surface
    float texRepeat = 10.0;  
    float roadWidth = 4.0;   
    float roadLength = 50.0; 

    glTexCoord2f(0.0, 0.0);
    glVertex3f(-roadWidth, 0.0, -roadLength);

    glTexCoord2f(1.0, 0.0);
    glVertex3f(roadWidth, 0.0, -roadLength);

    glTexCoord2f(1.0, texRepeat);
    glVertex3f(roadWidth, 0.0, roadLength);

    glTexCoord2f(0.0, texRepeat);
    glVertex3f(-roadWidth, 0.0, roadLength);

    glEnd();

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void drawMountain(float x, float z, float height, float width) {
    // Save current state
    glPushAttrib(GL_ALL_ATTRIB_BITS);

    // Ensure mountains are always drawn on the inside of the skybox
    glDepthMask(GL_TRUE);
    glEnable(GL_DEPTH_TEST);

    GLfloat mountain_color[] = { 0.5, 0.35, 0.05, 1.0 };  // Brown color
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mountain_color);  // Add BACK face material

    glPushMatrix();
    glTranslatef(x, 0.0, z);

    // Enable double-sided rendering
    glDisable(GL_CULL_FACE);

    // Draw mountain body (using triangles)
    glBegin(GL_TRIANGLES);

    // Front face
    glNormal3f(0.0, 0.5, 1.0);
    glVertex3f(-width / 2, 0.0, -width / 2);    // Left bottom
    glVertex3f(width / 2, 0.0, -width / 2);     // Right bottom
    glVertex3f(0.0, height, 0.0);               // Peak

    // Back face
    glNormal3f(0.0, 0.5, -1.0);
    glVertex3f(width / 2, 0.0, width / 2);      // Right bottom
    glVertex3f(-width / 2, 0.0, width / 2);     // Left bottom
    glVertex3f(0.0, height, 0.0);               // Peak

    // Left face
    glNormal3f(-1.0, 0.5, 0.0);
    glVertex3f(-width / 2, 0.0, width / 2);     // Back bottom
    glVertex3f(-width / 2, 0.0, -width / 2);    // Front bottom
    glVertex3f(0.0, height, 0.0);               // Peak

    // Right face
    glNormal3f(1.0, 0.5, 0.0);
    glVertex3f(width / 2, 0.0, -width / 2);     // Front bottom
    glVertex3f(width / 2, 0.0, width / 2);      // Back bottom
    glVertex3f(0.0, height, 0.0);               // Peak

    glEnd();
    glPopMatrix();

    // Restore previous state
    glPopAttrib();
}


void drawLake() {
    glPushMatrix();

    // Bind lake texture
    glBindTexture(GL_TEXTURE_2D, lakeTexture);
    glEnable(GL_TEXTURE_2D);

    // Set material
    GLfloat lake_ambient[] = { 0.0, 0.1, 0.2, 0.8 };
    GLfloat lake_diffuse[] = { 0.0, 0.4, 0.6, 0.8 };
    GLfloat lake_specular[] = { 0.8, 0.8, 0.8, 1.0 };
    GLfloat lake_shininess[] = { 100.0 };

    glMaterialfv(GL_FRONT, GL_AMBIENT, lake_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lake_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, lake_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, lake_shininess);

    // Enable blending for transparency effects
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Raise lake slightly to avoid z-fighting with ground
    glTranslatef(-38.0, 0.05, -30.0);  // Adjust lake position

    // Draw irregular shaped lake
    glBegin(GL_POLYGON);
    glNormal3f(0.0, 1.0, 0.0);

    // Use more points to create irregular shape
    float points[][2] = {
        {2.0, 2.0},      // Starting point
        {5.0, 2.0},
        {12.0, 1.0},
        {15.0, 3.0},
        {18.0, 8.0},
        {20.0, 12.0},
        {18.0, 15.0},
        {15.0, 18.0},
        {10.0, 20.0},
        {5.0, 18.0},
        {2.0, 15.0},
        {0.0, 12.0},
        {1.0, 8.0},
        {2.0, 2.0}
    };

    int numPoints = sizeof(points) / sizeof(points[0]);
    for (int i = 0; i < numPoints; i++) {
        glTexCoord2f(points[i][0] / 20.0, points[i][1] / 20.0);
        glVertex3f(points[i][0], 0.0, points[i][1]);
    }

    glEnd();

    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void drawGrass() {
    glPushMatrix();

    // Bind grass texture
    glBindTexture(GL_TEXTURE_2D, grassTexture2);
    glEnable(GL_TEXTURE_2D);

    // Set material
    GLfloat grass_color[] = { 0.7, 0.8, 0.7, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, grass_color);

    // Ensure same position as lake
    glTranslatef(-40.0, 0.02, -30.0);  // Adjust grass position

    glBegin(GL_POLYGON);
    glNormal3f(0.0, 1.0, 0.0);

    // Expanded grass coordinate points
    float points[][2] = {
        {-3.0, -3.0},     // Starting point
        {8.0, -3.0},
        {15.0, -2.0},
        {18.0, 0.0},
        {22.0, 5.0},
        {25.0, 10.0},
        {25.0, 15.0},
        {22.0, 20.0},
        {18.0, 21.0},
        {12.0, 24.0},
        {6.0, 23.0},
        {0.0, 20.0},
        {-3.0, 15.0},
        {-4.0, 10.0},
        {-5.0, 5.0},
        {-3.0, -3.0}      // Close loop back to starting point
    };

    int numPoints = sizeof(points) / sizeof(points[0]);
    for (int j = 0; j < numPoints; j++) {
        glTexCoord2f(points[j][0] / 10.0, points[j][1] / 10.0);
        glVertex3f(points[j][0], 0.0, points[j][1]);
    }

    glEnd();

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void drawTrashBin(float x, float z) {
    glPushMatrix();
    glTranslatef(x, 0.0, z);

    // Trash can body
    GLfloat bin_color[] = { 0.2, 0.2, 0.2, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, bin_color);

    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    glScalef(0.4, 2.0, 0.4);
    glutSolidCube(1.0);
    glPopMatrix();

    // Trash can lid
    GLfloat lid_color[] = { 0.3, 0.3, 0.3, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lid_color);

    glPushMatrix();
    glTranslatef(0.0, 1.0, 0.0);
    glScalef(0.45, 0.1, 0.45);
    glutSolidCube(1.0);
    glPopMatrix();

    glPopMatrix();
}

void drawTree(float x, float z, float height, float trunk_radius, int leafType) {
    glPushMatrix();
    glTranslatef(x, 0.0, z);

    glBindTexture(GL_TEXTURE_2D, trunkTexture);
    glEnable(GL_TEXTURE_2D);
    GLfloat trunk_color[] = { 0.6, 0.4, 0.2, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, trunk_color);

    GLUquadricObj* trunk = gluNewQuadric();
    gluQuadricTexture(trunk, GL_TRUE);
    gluQuadricNormals(trunk, GLU_SMOOTH);

    glPushMatrix();
    float trunk_height = height * 0.4;
    glRotatef(-90, 1.0, 0.0, 0.0);
    gluCylinder(trunk, trunk_radius, trunk_radius * 0.8, trunk_height, 12, 1);
    glPopMatrix();

    // Utilize different textures for different kinds of leaves
    if (leafType == 1) {
        glBindTexture(GL_TEXTURE_2D, leafTexture);
    }
    else {
        glBindTexture(GL_TEXTURE_2D, leafTexture2); 
    }

    GLfloat leaf_ambient[] = { 0.2, 0.3, 0.1, 1.0 };
    GLfloat leaf_diffuse[] = { 0.3, 0.7, 0.2, 0.9 };
    GLfloat leaf_specular[] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat leaf_shininess[] = { 50.0 };

    glMaterialfv(GL_FRONT, GL_AMBIENT, leaf_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, leaf_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, leaf_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, leaf_shininess);

    float leaf_start_height = trunk_height * 0.7;
    float leaf_radius = trunk_radius * 6.0;
    int leaf_layers = 3;
    int segments = 8;  

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Create multiple layers of leaves
    for (int layer = 0; layer < leaf_layers; layer++) {
        float layer_height = leaf_start_height + layer * (height - leaf_start_height) / leaf_layers;
        float current_radius = leaf_radius * (1.0f - layer * 0.2f);
        float next_height = layer_height + (height - leaf_start_height) / leaf_layers;
        float next_radius = current_radius * 0.7f;

        glPushMatrix();
        glTranslatef(0.0, layer_height, 0.0);

        // Draw leaf cone sides using triangle strips
        for (int i = 0; i < segments; i++) {
            float angle1 = (float)i / segments * 2.0f * PI;
            float angle2 = (float)(i + 1) / segments * 2.0f * PI;

            float x1 = cos(angle1) * current_radius;
            float z1 = sin(angle1) * current_radius;
            float x2 = cos(angle2) * current_radius;
            float z2 = sin(angle2) * current_radius;

            // Draw side triangles
            glBegin(GL_TRIANGLES);
            // Calculate normal
            float nx = cos((angle1 + angle2) / 2);
            float nz = sin((angle1 + angle2) / 2);
            glNormal3f(nx, 0.5f, nz);

            // First triangle
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(x1, 0.0f, z1);

            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(x2, 0.0f, z2);

            glTexCoord2f(0.5f, 1.0f);
            glVertex3f(0.0f, next_height - layer_height, 0.0f);
            glEnd();

            // Draw bottom triangles
            glBegin(GL_TRIANGLES);
            glNormal3f(0.0f, -1.0f, 0.0f);

            glTexCoord2f(0.5f, 0.5f);
            glVertex3f(0.0f, 0.0f, 0.0f);

            glTexCoord2f(0.5f + cos(angle1) * 0.5f, 0.5f + sin(angle1) * 0.5f);
            glVertex3f(x1, 0.0f, z1);

            glTexCoord2f(0.5f + cos(angle2) * 0.5f, 0.5f + sin(angle2) * 0.5f);
            glVertex3f(x2, 0.0f, z2);
            glEnd();
        }

        glPopMatrix();
    }

    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);

    gluDeleteQuadric(trunk);
    glPopMatrix();
}

// Add garage drawing function
void drawGarage() {
    glPushMatrix();
    glTranslatef(garage_x, 0.0, garage_z);
    glRotatef(-90, 0.0, 1.0, 0.0);

    // Set base material
    GLfloat base_color[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, base_color);

    // Enable texture
    glBindTexture(GL_TEXTURE_2D, wallTexture3);
    glEnable(GL_TEXTURE_2D);

    // Back wall
    glBegin(GL_QUADS);
    glNormal3f(0.0, 0.0, -1.0);
    glTexCoord2f(2.0, 0.0); glVertex3f(garage_width / 2, 0.0, -garage_length);
    glTexCoord2f(0.0, 0.0); glVertex3f(-garage_width / 2, 0.0, -garage_length);
    glTexCoord2f(0.0, 2.0); glVertex3f(-garage_width / 2, garage_height, -garage_length);
    glTexCoord2f(2.0, 2.0); glVertex3f(garage_width / 2, garage_height, -garage_length);
    glEnd();

    // Left wall
    glBegin(GL_QUADS);
    glNormal3f(-1.0, 0.0, 0.0);
    glTexCoord2f(2.0, 0.0); glVertex3f(-garage_width / 2, 0.0, -garage_length);
    glTexCoord2f(0.0, 0.0); glVertex3f(-garage_width / 2, 0.0, 0.0);
    glTexCoord2f(0.0, 2.0); glVertex3f(-garage_width / 2, garage_height, 0.0);
    glTexCoord2f(2.0, 2.0); glVertex3f(-garage_width / 2, garage_height, -garage_length);
    glEnd();

    // Right wall
    glBegin(GL_QUADS);
    glNormal3f(1.0, 0.0, 0.0);
    glTexCoord2f(2.0, 0.0); glVertex3f(garage_width / 2, 0.0, 0.0);
    glTexCoord2f(0.0, 0.0); glVertex3f(garage_width / 2, 0.0, -garage_length);
    glTexCoord2f(0.0, 2.0); glVertex3f(garage_width / 2, garage_height, -garage_length);
    glTexCoord2f(2.0, 2.0); glVertex3f(garage_width / 2, garage_height, 0.0);
    glEnd();

    // Top (using roof texture)
    glBindTexture(GL_TEXTURE_2D, roofTexture);
    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0, 0.0);
    glTexCoord2f(0.0, 0.0); glVertex3f(-garage_width / 2, garage_height, -garage_length);
    glTexCoord2f(3.0, 0.0); glVertex3f(garage_width / 2, garage_height, -garage_length);
    glTexCoord2f(3.0, 3.0); glVertex3f(garage_width / 2, garage_height, 0.0);
    glTexCoord2f(0.0, 3.0); glVertex3f(-garage_width / 2, garage_height, 0.0);
    glEnd();

    glDisable(GL_TEXTURE_2D);

    // Fixed garage door
    GLfloat door_color[] = { 0.6, 0.6, 0.6, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, door_color);

    glBegin(GL_QUADS);
    glNormal3f(0.0, 0.0, 1.0);
    glVertex3f(-garage_width / 2, 0.0, 0.0);
    glVertex3f(garage_width / 2, 0.0, 0.0);
    glVertex3f(garage_width / 2, garage_height, 0.0);
    glVertex3f(-garage_width / 2, garage_height, 0.0);
    glEnd();

    glPopMatrix();
}

void drawFighterJet() {
    glPushMatrix();

    // Fighter jet position
    glTranslatef(plane_x, plane_y, plane_z);
    glRotatef(plane_rotation, 0.0, 1.0, 0.0);  // Keep only horizontal rotation
    // Remove tilt angle, maintain horizontal position

    // Set fighter jet material
    GLfloat jet_color[] = { 0.5, 0.5, 0.5, 1.0 };
    GLfloat jet_specular[] = { 0.7, 0.7, 0.7, 1.0 };
    GLfloat jet_shininess[] = { 50.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, jet_color);
    glMaterialfv(GL_FRONT, GL_SPECULAR, jet_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, jet_shininess);

    // Fuselage (main body)
    glPushMatrix();
    glScalef(4.0, 0.4, 0.8);
    glutSolidCube(1.0);
    glPopMatrix();

    // Nose cone
    glPushMatrix();
    glTranslatef(2.2, 0.0, 0.0);
    glRotatef(90.0, 0.0, 1.0, 0.0);
    GLUquadricObj* nose = gluNewQuadric();
    gluCylinder(nose, 0.4, 0.0, 1.0, 12, 1);
    gluDeleteQuadric(nose);
    glPopMatrix();

    // Wings
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    // Left wing
    glVertex3f(-1.0, 0.0, 0.4);
    glVertex3f(1.0, 0.0, 0.4);
    glVertex3f(0.0, 0.0, 3.0);
    // Right wing
    glVertex3f(-1.0, 0.0, -0.4);
    glVertex3f(1.0, 0.0, -0.4);
    glVertex3f(0.0, 0.0, -3.0);
    glEnd();
    glPopMatrix();

    // Tail
    glPushMatrix();
    glTranslatef(-2.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    // Vertical stabilizer
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(-0.8, 0.0, 0.0);
    glVertex3f(-0.4, 1.2, 0.0);
    // Left horizontal stabilizer
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(-0.8, 0.0, 0.0);
    glVertex3f(-0.4, 0.0, 1.0);
    // Right horizontal stabilizer
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(-0.8, 0.0, 0.0);
    glVertex3f(-0.4, 0.0, -1.0);
    glEnd();
    glPopMatrix();

    // Cockpit
    GLfloat cockpit_color[] = { 0.2, 0.3, 0.8, 0.8 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, cockpit_color);
    glPushMatrix();
    glTranslatef(0.5, 0.3, 0.0);
    glScalef(1.0, 0.3, 0.4);
    glutSolidCube(1.0);
    glPopMatrix();

    glPopMatrix();
}

// Add new park drawing function
void drawPark() {
    float parkX = -30.0;
    float parkZ = -15.0;

    glPushMatrix();
    glTranslatef(parkX, 0.05, parkZ);

    // Draw winding path
    drawParkPath();

    // Add decorative rocks
    drawParkRocks();

    glPopMatrix();
}

// Add Bezier curve calculation function
void calculateBezierPoint(float t, float* result, float p0[], float p1[], float p2[], float p3[]) {
    float u = 1 - t;
    float tt = t * t;
    float uu = u * u;
    float uuu = uu * u;
    float ttt = tt * t;

    result[0] = uuu * p0[0] + 3 * uu * t * p1[0] + 3 * u * tt * p2[0] + ttt * p3[0];
    result[1] = uuu * p0[1] + 3 * uu * t * p1[1] + 3 * u * tt * p2[1] + ttt * p3[1];
}

void drawParkPath() {
    glPushMatrix();

    // Bind path texture
    glBindTexture(GL_TEXTURE_2D, floorTexture);
    glEnable(GL_TEXTURE_2D);

    // Set material
    GLfloat path_color[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, path_color);

    // Modify control points to create an elegant curve from highway to lakeside
    float controlPoints[][2] = {
        {10.0, 3.5},
        {13.0, 7.0},
        {10.0, 10.0},
        {10.0, 15.0},
        {10.0, 20.0},
        {12.0, 25.0},
        {15.5, 30.0},
        {19.0, 35.0},
        {15.5, 39.0},
        {22.0, 39.0}
    };

    float pathWidth = 1.2;
    int segments = 90;
    float textureRepeat = 5.0;

    // Draw main path
    for (int section = 0; section < 3; section++) {
        // Get four control points for current section
        float p0[2] = { controlPoints[section * 3][0], controlPoints[section * 3][1] };
        float p1[2] = { controlPoints[section * 3 + 1][0], controlPoints[section * 3 + 1][1] };
        float p2[2] = { controlPoints[section * 3 + 2][0], controlPoints[section * 3 + 2][1] };
        float p3[2] = { controlPoints[section * 3 + 3][0], controlPoints[section * 3 + 3][1] };

        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= segments; i++) {
            float t = (float)i / segments;
            float point[2];
            float nextPoint[2];

            calculateBezierPoint(t, point, p0, p1, p2, p3);
            calculateBezierPoint(t + 0.01f, nextPoint, p0, p1, p2, p3);

            float dx = nextPoint[0] - point[0];
            float dz = nextPoint[1] - point[1];
            float length = sqrt(dx * dx + dz * dz);
            if (length > 0) {
                dx /= length;
                dz /= length;
            }

            // Gradual path width variation
            float currentWidth = pathWidth;
            if (section == 0 && t < 0.2) {
                currentWidth = pathWidth * (1.3 - t * 1.5);
            }
            else if (section == 2 && t > 0.8) {
                currentWidth = pathWidth * (0.9 + (1.0 - t) * 0.5);
            }

            float texCoordY = t + section;
            glNormal3f(0.0, 1.0, 0.0);

            // Adjust texture coordinates for better visual effect
            glTexCoord2f(0.0, texCoordY * textureRepeat);
            glVertex3f(point[0] - dz * currentWidth, 0.02, point[1] + dx * currentWidth);
            glTexCoord2f(1.0, texCoordY * textureRepeat);
            glVertex3f(point[0] + dz * currentWidth, 0.02, point[1] - dx * currentWidth);
        }
        glEnd();
    }

    // Add decorative pebbles or flowers along path edges
    glDisable(GL_TEXTURE_2D);
    srand(42); // Fix random seed for consistency

    GLfloat stone_color[] = { 0.7, 0.7, 0.7, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, stone_color);

    for (int section = 0; section < 3; section++) {
        float p0[2] = { controlPoints[section * 3][0], controlPoints[section * 3][1] };
        float p1[2] = { controlPoints[section * 3 + 1][0], controlPoints[section * 3 + 1][1] };
        float p2[2] = { controlPoints[section * 3 + 2][0], controlPoints[section * 3 + 2][1] };
        float p3[2] = { controlPoints[section * 3 + 3][0], controlPoints[section * 3 + 3][1] };

        for (int i = 0; i < 12; i++) {
            float t = (float)i / 12.0;
            float point[2];
            calculateBezierPoint(t, point, p0, p1, p2, p3);

            // Randomly add decorations on both sides of path
            for (int side = -1; side <= 1; side += 2) {
                if (rand() % 3 == 0) {
                    glPushMatrix();
                    float offset = (float)(rand() % 15) / 10.0 + 1.3; // Offset range: 1.3-2.8
                    glTranslatef(point[0] + side * offset, 0.0, point[1]);
                    float scale = (float)(rand() % 15) / 100.0 + 0.05; // Size range: 0.05-0.2
                    glScalef(scale, scale * 0.3, scale);
                    glutSolidDodecahedron();
                    glPopMatrix();
                }
            }
        }
    }

    glEnable(GL_TEXTURE_2D);
    glPopMatrix();
}

void drawTrees() {
    drawTree(-30.0, -10.0, 5.0, 0.25, 1);
    drawTree(-25.0, -10.0, 4.0, 0.2, 2);
    drawTree(-17.0, -15.0, 6.0, 0.3, 1);
    drawTree(-22.0, -25.0, 4.0, 0.2, 2);
    drawTree(-37.0, -11.0, 4.0, 0.2, 1);
    drawTree(-15.0, -17.0, 6.0, 0.3, 2);
    drawTree(-33.0, -33.0, 4.0, 0.2, 1);
    drawTree(-38.0, -34.0, 6.0, 0.3, 2);
    drawTree(-32.0, -31.0, 4.0, 0.2, 1);
    drawTree(-37.0, -20.0, 4.0, 0.2, 2);
    drawTree(-36.0, -17.0, 6.0, 0.3, 1);
    drawTree(-41.0, -31.0, 4.0, 0.2, 2);
}

void drawParkBench(float x, float z, float rotation) {
    glPushMatrix();
    glTranslatef(x, 0.0, z);
    glRotatef(rotation, 0.0, 1.0, 0.0);

    // Bench material
    GLfloat bench_color[] = { 0.3, 0.2, 0.1, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, bench_color);

    // Seat surface
    glPushMatrix();
    glTranslatef(0.0, 0.5, 0.0);
    glScalef(1.5, 0.1, 0.5);
    glutSolidCube(1.0);
    glPopMatrix();

    // Backrest
    glPushMatrix();
    glTranslatef(0.0, 0.7, -0.2);
    glRotatef(-15.0, 1.0, 0.0, 0.0);
    glScalef(1.5, 0.5, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    // Legs
    for (int i = -1; i <= 1; i += 2) {
        glPushMatrix();
        glTranslatef(i * 0.6, 0.25, 0.0);
        glScalef(0.1, 0.5, 0.5);
        glutSolidCube(1.0);
        glPopMatrix();
    }

    glPopMatrix();
}

void drawParkRocks() {
    glPushMatrix();

    // Rock material
    GLfloat rock_color[] = { 0.6, 0.6, 0.6, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, rock_color);

    // Add decorative rocks
    for (int i = 0; i < 5; i++) {
        float x = (float)(rand() % 30) - 15.0;
        float z = (float)(rand() % 30) - 15.0;
        float scale = 0.3 + (float)(rand() % 40) / 100.0;

        glPushMatrix();
        glTranslatef(x, 0.0, z);
        glRotatef(rand() % 360, 0.0, 1.0, 0.0);
        glScalef(scale, scale, scale);
        glutSolidDodecahedron();
        glPopMatrix();
    }

    glPopMatrix();
}


//============= Draw Playground =============
void drawPlayground() {
    glPushMatrix();

    // Position playground in appropriate location
    glTranslatef(27.0, 0.05, 20.0);

    // Draw playground surface
    glBindTexture(GL_TEXTURE_2D, pathTexture);
    glEnable(GL_TEXTURE_2D);

    // Set material
    GLfloat ground_color[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, ground_color);

    // Draw playground ground surface
    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0, 0.0);
    float size = 12.0;
    float texRepeat = 3.0;  // Texture repeat count

    // Modify texture coordinates to ensure texture alignment
    glTexCoord2f(0.0, texRepeat);        // Left back
    glVertex3f(-size, 0.0, -size);
    glTexCoord2f(0.0, 0.0);             // Left front
    glVertex3f(-size, 0.0, size);
    glTexCoord2f(texRepeat, 0.0);       // Right front
    glVertex3f(size, 0.0, size);
    glTexCoord2f(texRepeat, texRepeat); // Right back
    glVertex3f(size, 0.0, -size);
    glEnd();

    glDisable(GL_TEXTURE_2D);

    // Draw swing set
    drawSwingSet(-6.0, 0.0, 0.0);

    // Draw slide
    drawSlide(6.0, 0.0, -0.0, 45.0);

    // Draw seesaw
    drawSeesaw(0.0, 0.0, 6.0);

    // Draw merry-go-round
    drawMerryGoRound(0.0, 0.0, -6.0);

    // Draw fence
    drawPlaygroundFence(size);

    glPopMatrix();
}

// Draw swing set
void drawSwingSet(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);

    // Swing frame material
    GLfloat frame_color[] = { 0.4, 0.4, 0.4, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, frame_color);

    // Top crossbeam
    glPushMatrix();
    glTranslatef(0.0, 3.0, 0.0);
    glScalef(4.0, 0.2, 0.2);
    glutSolidCube(1.0);
    glPopMatrix();

    // Support posts
    for (float i = -1.8; i <= 1.8; i += 3.6) {
        glPushMatrix();
        glTranslatef(i, 1.5, 0.0);
        glScalef(0.2, 3.0, 0.2);
        glutSolidCube(1.0);
        glPopMatrix();
    }

    // Swing seats and chains
    GLfloat seat_color[] = { 0.8, 0.2, 0.2, 1.0 };
    for (float i = -1.0; i <= 1.0; i += 2.0) {
        // Chains
        glPushMatrix();
        glTranslatef(i, 2.0, 0.0);
        glScalef(0.05, 2.0, 0.05);
        glutSolidCube(1.0);
        glPopMatrix();

        // Seats
        glMaterialfv(GL_FRONT, GL_DIFFUSE, seat_color);
        glPushMatrix();
        glTranslatef(i, 1.0, 0.0);
        glScalef(0.4, 0.1, 0.4);
        glutSolidCube(1.0);
        glPopMatrix();
    }

    glPopMatrix();
}

void drawSlide(float x, float y, float z, float rotation) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(rotation, 0.0, 1.0, 0.0);

    // Material definitions
    GLfloat slide_color[] = { 0.2, 0.6, 0.8, 1.0 };  // Blue for slide
    GLfloat frame_color[] = { 0.3, 0.3, 0.3, 1.0 };  // Dark gray for frame

    // Basic parameters
    float slide_angle = 30.0;      // Slide incline angle
    float height = 2.0;            // Total height
    float platform_size = 1.2;     // Platform size
    float slide_width = 0.8;       // Slide width
    float slide_length = 3.5;      // Slide length

    // 1. Draw center support post
    glMaterialfv(GL_FRONT, GL_DIFFUSE, frame_color);
    glPushMatrix();
    glTranslatef(0.0, height / 2, 0.0);
    glScalef(0.1, height, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    // 2. Draw top platform
    glPushMatrix();
    glTranslatef(0.0, height, 0.0);
    glScalef(platform_size, 0.1, platform_size);
    glutSolidCube(1.0);
    glPopMatrix();

    // 3. Draw base
    glPushMatrix();
    glTranslatef(0.0, 0.05, 0.0);
    glScalef(platform_size, 0.1, platform_size);
    glutSolidCube(1.0);
    glPopMatrix();

    // 4. Draw slide (starting from platform edge)
    glMaterialfv(GL_FRONT, GL_DIFFUSE, slide_color);
    glPushMatrix();
    // Move to platform edge
    glTranslatef(0.0, height, platform_size / 2);
    glRotatef(slide_angle, 1.0, 0.0, 0.0);

    // Slide body
    glPushMatrix();
    glTranslatef(0.0, 0.0, slide_length / 2);
    glScalef(slide_width, 0.1, slide_length);
    glutSolidCube(1.0);
    glPopMatrix();

    // Slide guardrails
    float rail_height = 0.2;
    for (int side = -1; side <= 1; side += 2) {
        glPushMatrix();
        glTranslatef(side * (slide_width / 2 - 0.05), rail_height / 2, slide_length / 2);
        glScalef(0.05, rail_height, slide_length);
        glutSolidCube(1.0);
        glPopMatrix();
    }
    glPopMatrix();

    // 5. Draw ladder (from base to platform)
    glMaterialfv(GL_FRONT, GL_DIFFUSE, frame_color);
    glPushMatrix();
    // Move to base edge
    glTranslatef(0.0, 0.1, -1.75);

    // Ladder side supports
    float ladder_length = sqrt(height * height + (platform_size * platform_size));
    float ladder_angle = 30;

    glRotatef(ladder_angle, 1.0, 0.0, 0.0);

    // Support posts
    for (int side = -1; side <= 1; side += 2) {
        glPushMatrix();
        glTranslatef(side * slide_width / 3, ladder_length / 2, 0.0);
        glScalef(0.05, ladder_length, 0.05);
        glutSolidCube(1.0);
        glPopMatrix();
    }

    // Ladder steps
    int num_steps = 6;
    float step_spacing = ladder_length / (num_steps + 1);
    for (int i = 1; i <= num_steps; i++) {
        glPushMatrix();
        glTranslatef(0.0, i * step_spacing, 0.0);
        glScalef(slide_width * 0.8, 0.05, 0.15);
        glutSolidCube(1.0);
        glPopMatrix();
    }
    glPopMatrix();

    glPopMatrix();
}

// Draw seesaw
void drawSeesaw(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);

    // Calculate current angle for animation
    float angle = 15.0 * sin(glutGet(GLUT_ELAPSED_TIME) / 1000.0);
    float rad_angle = angle * PI / 180.0;

    // Seesaw materials
    GLfloat seesaw_color[] = { 0.8, 0.3, 0.3, 1.0 };
    GLfloat handle_color[] = { 0.6, 0.2, 0.2, 1.0 }; // Darker color for handles
    GLfloat person_color[] = { 0.9, 0.7, 0.5, 1.0 };  // Skin color
    GLfloat clothes_color[] = { 0.2, 0.4, 0.8, 1.0 }; // Blue clothes
    GLfloat hair_color[] = { 0.2, 0.2, 0.2, 1.0 };    // Black hair
    glMaterialfv(GL_FRONT, GL_DIFFUSE, seesaw_color);

    // Support pivot
    glPushMatrix();
    glTranslatef(0.0, 0.5, 0.0);
    glScalef(0.3, 1.0, 0.3);
    glutSolidCube(1.0);
    glPopMatrix();

    // Rotate entire seesaw board and figures together
    glPushMatrix();
    glTranslatef(0.0, 1.0, 0.0);
    glRotatef(angle, 0.0, 0.0, 1.0);

    // Seesaw board
    glPushMatrix();
    glScalef(4.0, 0.1, 0.5);
    glutSolidCube(1.0);
    glPopMatrix();

    // Add handles - positioned in front of figures
    glMaterialfv(GL_FRONT, GL_DIFFUSE, handle_color);

    // Left handle
    glPushMatrix();
    glTranslatef(-1.4, 0.3, 0.0);  // Move to front
    // Vertical bar
    glPushMatrix();
    glScalef(0.05, 0.4, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();
    // Horizontal bar
    glPushMatrix();
    glTranslatef(0.0, 0.2, 0.0);
    glScalef(0.05, 0.05, 0.4);
    glutSolidCube(1.0);
    glPopMatrix();
    glPopMatrix();

    // Right handle
    glPushMatrix();
    glTranslatef(1.4, 0.3, 0.0);  // Move to front
    // Vertical bar
    glPushMatrix();
    glScalef(0.05, 0.4, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();
    // Horizontal bar
    glPushMatrix();
    glTranslatef(0.0, 0.2, 0.0);
    glScalef(0.05, 0.05, 0.4);
    glutSolidCube(1.0);
    glPopMatrix();
    glPopMatrix();

    // Add left figure
    glPushMatrix();
    glTranslatef(-1.6, 0.25, 0.0);
    glRotatef(90, 0.0, 1.0, 0.0);

    // Body
    glMaterialfv(GL_FRONT, GL_DIFFUSE, clothes_color);
    glPushMatrix();
    glTranslatef(0.0, 0.2, 0.0);
    glScalef(0.2, 0.3, 0.2);
    glutSolidCube(1.0);
    glPopMatrix();

    // Head
    glMaterialfv(GL_FRONT, GL_DIFFUSE, person_color);
    glPushMatrix();
    glTranslatef(0.0, 0.47, 0.0);
    glutSolidSphere(0.1, 8, 8);
    glPopMatrix();

    // Legs
    glMaterialfv(GL_FRONT, GL_DIFFUSE, clothes_color);
    for (int i = -1; i <= 1; i += 2) {
        glPushMatrix();
        glTranslatef(i * 0.06, 0.0, 0.0);
        glScalef(0.06, 0.2, 0.06);
        glutSolidCube(1.0);
        glPopMatrix();
    }

    // Arms
    for (int i = -1; i <= 1; i += 2) {
        glPushMatrix();
        glTranslatef(i * 0.15, 0.25, 0.1);
        glRotatef(90, 1.0, 0.0, 0.0);
        glScalef(0.06, 0.15, 0.06);
        glutSolidCube(1.0);
        glPopMatrix();
    }
    glPopMatrix();

    // Add right figure
    glPushMatrix();
    glTranslatef(1.6, 0.25, 0.0);
    glRotatef(-90, 0.0, 1.0, 0.0);

    // Body
    glMaterialfv(GL_FRONT, GL_DIFFUSE, clothes_color);
    glPushMatrix();
    glTranslatef(0.0, 0.2, 0.0);
    glScalef(0.2, 0.3, 0.2);
    glutSolidCube(1.0);
    glPopMatrix();

    // Head
    glMaterialfv(GL_FRONT, GL_DIFFUSE, person_color);
    glPushMatrix();
    glTranslatef(0.0, 0.47, 0.0);
    glutSolidSphere(0.1, 8, 8);
    glPopMatrix();

    // Legs
    glMaterialfv(GL_FRONT, GL_DIFFUSE, clothes_color);
    for (int i = -1; i <= 1; i += 2) {
        glPushMatrix();
        glTranslatef(i * 0.06, 0.0, 0.0);
        glScalef(0.06, 0.2, 0.06);
        glutSolidCube(1.0);
        glPopMatrix();
    }

    // Arms
    for (int i = -1; i <= 1; i += 2) {
        glPushMatrix();
        glTranslatef(i * 0.15, 0.25, 0.1);
        glRotatef(-90, 1.0, 0.0, 0.0);
        glScalef(0.06, 0.15, 0.06);
        glutSolidCube(1.0);
        glPopMatrix();
    }

    glPopMatrix();

    glPopMatrix();  // End seesaw rotation

    glPopMatrix();
}

// Draw Merry-Go-Round
void drawMerryGoRound(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);

    // Merry-go-round material
    GLfloat merry_color[] = { 0.7, 0.7, 0.2, 1.0 };
    GLfloat pole_color[] = { 0.8, 0.8, 0.8, 1.0 };  // Silver poles

    // Base - non-rotating
    glMaterialfv(GL_FRONT, GL_DIFFUSE, merry_color);
    glPushMatrix();
    glTranslatef(0.0, 0.1, 0.0);
    glScalef(2.5, 0.2, 2.5);
    glutSolidCube(1.0);
    glPopMatrix();

    // Top decoration
    glMaterialfv(GL_FRONT, GL_DIFFUSE, merry_color);
    glPushMatrix();
    glTranslatef(0.0, 3.0, 0.0);
    glScalef(1.5, 0.2, 1.5);
    glutSolidCube(1.0);
    glPopMatrix();

    // Start rotation from here
    glRotatef(-glutGet(GLUT_ELAPSED_TIME) / 50.0, 0.0, 1.0, 0.0);

    // Center pole
    glMaterialfv(GL_FRONT, GL_DIFFUSE, pole_color);
    glPushMatrix();
    glTranslatef(0.0, 1.5, 0.0);
    glScalef(0.3, 3.0, 0.3);
    glutSolidCube(1.0);
    glPopMatrix();

    // Rotating arms
    float support_angle = -25.0;  // Support rod inclination angle
    float support_length = 2.4;   // Support rod length

    for (int i = 0; i < 6; i++) {
        glPushMatrix();
        glTranslatef(0.0, 2.0, 0.0);  // Move to rotation center point
        glRotatef(i * 60.0, 0.0, 1.0, 0.0);

        // Calculate seat position
        float angle_rad = support_angle * PI / 180.0;
        float seat_x = support_length * cos(angle_rad);
        float seat_y = support_length * sin(angle_rad);

        // Seat assembly - keep horizontal
        GLfloat seat_color[] = { 0.8, 0.2, 0.2, 1.0 };
        glMaterialfv(GL_FRONT, GL_DIFFUSE, seat_color);

        glPushMatrix();
        glTranslatef(seat_x + 0.1, seat_y, 0.0);

        // Seat body
        glPushMatrix();
        glScalef(0.4, 0.2, 0.4);
        glutSolidCube(1.0);
        glPopMatrix();

        // Seat backrest
        glPushMatrix();
        glTranslatef(0.0, 0.3, -0.15);
        glScalef(0.4, 0.4, 0.1);
        glutSolidCube(1.0);
        glPopMatrix();

        glPopMatrix();

        // Diagonal support rod - connecting to backrest top
        glMaterialfv(GL_FRONT, GL_DIFFUSE, pole_color);
        glPushMatrix();
        glRotatef(support_angle, 0.0, 0.0, 1.0);

        // Calculate support rod endpoint position (backrest top)
        float backrest_height = 0.4;  // Backrest height
        float connection_point_y = backrest_height * 0.75;  // Connection point at 3/4 of backrest

        // Adjust support rod length to precisely connect to backrest
        float adjusted_length = sqrt(
            pow(seat_x, 2) +
            pow(seat_y + connection_point_y, 2)
        );

        glTranslatef(adjusted_length / 2, 0.0, 0.0);
        glScalef(adjusted_length, 0.1, 0.1);
        glutSolidCube(1.0);
        glPopMatrix();


        glPopMatrix();
    }

    glPopMatrix();
}

// Draw Playground Fence
void drawPlaygroundFence(float size) {
    GLfloat fence_color[] = { 0.6, 0.4, 0.2, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, fence_color);

    float fence_height = 1.0;
    float post_spacing = 2.0;

    // Draw fence posts and rails
    for (float x = -size; x <= size; x += post_spacing) {
        // Front and back fences
        for (float z = -size; z <= size; z += size * 2) {
            // Vertical posts
            glPushMatrix();
            glTranslatef(x, fence_height / 2, z);
            glScalef(0.1, fence_height, 0.1);
            glutSolidCube(1.0);
            glPopMatrix();

            // Horizontal rails
            if (x < size) {
                glPushMatrix();
                glTranslatef(x + post_spacing / 2, fence_height * 0.8, z);
                glScalef(post_spacing, 0.05, 0.05);
                glutSolidCube(1.0);
                glPopMatrix();
            }
        }

        // Left and right fences
        for (float x = -size; x <= size; x += size * 2) {
            for (float z = -size + post_spacing; z < size; z += post_spacing) {
                // Vertical posts
                glPushMatrix();
                glTranslatef(x, fence_height / 2, z);
                glScalef(0.1, fence_height, 0.1);
                glutSolidCube(1.0);
                glPopMatrix();

                // Horizontal rails
                if (z < size - post_spacing) {
                    glPushMatrix();
                    glTranslatef(x, fence_height * 0.8, z + post_spacing / 2);
                    glScalef(0.05, 0.05, post_spacing);
                    glutSolidCube(1.0);
                    glPopMatrix();
                }
            }
        }
    }
}

// =============== Draw Soccer Field =================
void drawSoccerField() {
    glPushMatrix();

    // Position the soccer field in an appropriate location
    glTranslatef(27.0, 0.05, -15.0);  // Adjust position to fit the scene

    // Set materials
    GLfloat field_color[] = { 1.0, 1.0, 1.0, 1.0 };  // White base color, will be covered by texture
    GLfloat line_color[] = { 1.0, 1.0, 1.0, 1.0 };   // White lines
    GLfloat goal_color[] = { 0.8, 0.8, 0.8, 1.0 };   // Goal color

    // Draw field grass
    glMaterialfv(GL_FRONT, GL_DIFFUSE, field_color);
    glBindTexture(GL_TEXTURE_2D, grassTexture3);  // Use grass4 texture
    glEnable(GL_TEXTURE_2D);

    float field_width = 22.0;   // Field width
    float field_length = 33.0;  // Field length
    float tex_repeat = 10.0;    // Texture repeat count

    // Draw grass ground
    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0, 0.0);
    glTexCoord2f(0.0, tex_repeat);
    glVertex3f(-field_width / 2, 0.0, -field_length / 2);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-field_width / 2, 0.0, field_length / 2);
    glTexCoord2f(tex_repeat, 0.0);
    glVertex3f(field_width / 2, 0.0, field_length / 2);
    glTexCoord2f(tex_repeat, tex_repeat);
    glVertex3f(field_width / 2, 0.0, -field_length / 2);
    glEnd();

    glDisable(GL_TEXTURE_2D);

    // Draw field lines
    glMaterialfv(GL_FRONT, GL_DIFFUSE, line_color);
    glLineWidth(3.0);  // Thicken lines

    // Outer boundary
    glBegin(GL_LINE_LOOP);
    glVertex3f(-field_width / 2, 0.1, -field_length / 2);
    glVertex3f(-field_width / 2, 0.1, field_length / 2);
    glVertex3f(field_width / 2, 0.1, field_length / 2);
    glVertex3f(field_width / 2, 0.1, -field_length / 2);
    glEnd();

    // Center line
    glBegin(GL_LINES);
    glVertex3f(-field_width / 2, 0.1, 0.0);
    glVertex3f(field_width / 2, 0.1, 0.0);
    glEnd();

    // Center circle
    float center_circle_radius = 5.0;
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i += 10) {
        float angle = i * PI / 180.0;
        glVertex3f(cos(angle) * center_circle_radius, 0.1, sin(angle) * center_circle_radius);
    }
    glEnd();

    // Goal areas (both ends)
    float goal_area_width = 12.0;
    float goal_area_depth = 5.0;

    // Goals
    glMaterialfv(GL_FRONT, GL_DIFFUSE, goal_color);
    float goal_width = 6.0;
    float goal_height = 2.5;
    float goal_depth = 1.5;

    // Modified: Explicitly specify positions for both goals
    // North end goal
    glPushMatrix();
    glTranslatef(0.0, 0.0, field_length / 2);
    drawGoal(goal_width, goal_height, goal_depth, 1.0);
    glPopMatrix();

    // South end goal
    glPushMatrix();
    glTranslatef(0.0, 0.0, -field_length / 2);
    drawGoal(goal_width, goal_height, goal_depth, -1.0);
    glPopMatrix();

    glPopMatrix();
}

void drawGoal(float width, float height, float depth, float direction) {
    glLineWidth(3.0);
    // Back frame
    glBegin(GL_LINES);
    // Vertical posts
    glVertex3f(-width / 2, 0.0, direction * depth);
    glVertex3f(-width / 2, height, direction * depth);
    glVertex3f(width / 2, 0.0, direction * depth);
    glVertex3f(width / 2, height, direction * depth);
    // Crossbar
    glVertex3f(-width / 2, height, direction * depth);
    glVertex3f(width / 2, height, direction * depth);
    glEnd();

    // Connecting bars
    glBegin(GL_LINES);
    glVertex3f(-width / 2, height, 0.0);
    glVertex3f(-width / 2, height, direction * depth);
    glVertex3f(width / 2, height, 0.0);
    glVertex3f(width / 2, height, direction * depth);
    glEnd();

    // Front posts
    glBegin(GL_LINES);
    glVertex3f(-width / 2, 0.0, 0.0);
    glVertex3f(-width / 2, height, 0.0);
    glVertex3f(width / 2, 0.0, 0.0);
    glVertex3f(width / 2, height, 0.0);
    glEnd();

    // Draw goal net
    drawGoalNet(width, height, depth, direction);
}

void drawGoalNet(float width, float height, float depth, float z_direction) {
    // Grid density
    int horizontal_segments = 12;  // Number of horizontal segments
    int vertical_segments = 8;     // Number of vertical segments
    int depth_segments = 6;        // Number of depth segments

    // Net material - slightly transparent white
    GLfloat net_color[] = { 1.0, 1.0, 1.0, 0.6 };
    GLfloat net_specular[] = { 0.2, 0.2, 0.2, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, net_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, net_specular);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Draw vertical grid lines
    glLineWidth(1.0);

    // Back net
    for (int i = 0; i <= horizontal_segments; i++) {
        float x = -width / 2 + (width * i) / horizontal_segments;
        glBegin(GL_LINE_STRIP);
        for (int j = 0; j <= vertical_segments; j++) {
            float y = (height * j) / vertical_segments;
            glVertex3f(x, y, z_direction * depth);
        }
        glEnd();
    }

    for (int j = 0; j <= vertical_segments; j++) {
        float y = (height * j) / vertical_segments;
        glBegin(GL_LINE_STRIP);
        for (int i = 0; i <= horizontal_segments; i++) {
            float x = -width / 2 + (width * i) / horizontal_segments;
            glVertex3f(x, y, z_direction * depth);
        }
        glEnd();
    }

    // Top net
    for (int i = 0; i <= depth_segments; i++) {
        float z = (depth * i) / depth_segments;
        glBegin(GL_LINE_STRIP);
        for (int j = 0; j <= horizontal_segments; j++) {
            float x = -width / 2 + (width * j) / horizontal_segments;
            glVertex3f(x, height, z_direction * z);
        }
        glEnd();
    }

    for (int j = 0; j <= horizontal_segments; j++) {
        float x = -width / 2 + (width * j) / horizontal_segments;
        glBegin(GL_LINE_STRIP);
        for (int i = 0; i <= depth_segments; i++) {
            float z = (depth * i) / depth_segments;
            glVertex3f(x, height, z_direction * z);
        }
        glEnd();
    }

    // Side nets
    for (int i = 0; i <= depth_segments; i++) {
        float z = (depth * i) / depth_segments;
        glBegin(GL_LINE_STRIP);
        for (int j = 0; j <= vertical_segments; j++) {
            float y = (height * j) / vertical_segments;
            glVertex3f(-width / 2, y, z_direction * z);
        }
        glEnd();

        glBegin(GL_LINE_STRIP);
        for (int j = 0; j <= vertical_segments; j++) {
            float y = (height * j) / vertical_segments;
            glVertex3f(width / 2, y, z_direction * z);
        }
        glEnd();
    }

    for (int j = 0; j <= vertical_segments; j++) {
        float y = (height * j) / vertical_segments;
        glBegin(GL_LINE_STRIP);
        for (int i = 0; i <= depth_segments; i++) {
            float z = (depth * i) / depth_segments;
            glVertex3f(-width / 2, y, z_direction * z);
        }
        glEnd();

        glBegin(GL_LINE_STRIP);
        for (int i = 0; i <= depth_segments; i++) {
            float z = (depth * i) / depth_segments;
            glVertex3f(width / 2, y, z_direction * z);
        }
        glEnd();
    }

    glDisable(GL_BLEND);
}

// ============== Draw Garden ===============
// Garden structure
void drawGarden() {
    glPushMatrix();

    // Place the garden in an appropriate position
    glTranslatef(-20.0, 0.0, 20.0);

    // Draw garden border
    drawGardenBorder();

    // Draw flowers and plants
    drawFlowers();

    glPopMatrix();
}

// Garden border
void drawGardenBorder() {
    // Garden border material - brick red
    GLfloat border_color[] = { 0.7, 0.3, 0.2, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, border_color);

    float border_height = 0.3;  // Border height
    float inner_radius = 3.0;   // Inner circle radius
    float outer_radius = 4.0;   // Outer circle radius
    int segments = 36;          // Number of circle segments

    // Draw outer border
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= segments; i++) {
        float angle = (float)i / segments * 2.0 * PI;
        float x = cos(angle);
        float z = sin(angle);

        // Outer circle vertices
        glNormal3f(x, 0.0, z);
        glVertex3f(x * outer_radius, border_height, z * outer_radius);
        glVertex3f(x * outer_radius, 0.0, z * outer_radius);
    }
    glEnd();

    // Draw inner border
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= segments; i++) {
        float angle = (float)i / segments * 2.0 * PI;
        float x = cos(angle);
        float z = sin(angle);

        // Inner circle vertices
        glNormal3f(-x, 0.0, -z);
        glVertex3f(x * inner_radius, border_height, z * inner_radius);
        glVertex3f(x * inner_radius, 0.0, z * inner_radius);
    }
    glEnd();

    // Draw top surface
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= segments; i++) {
        float angle = (float)i / segments * 2.0 * PI;
        float x = cos(angle);
        float z = sin(angle);

        glNormal3f(0.0, 1.0, 0.0);
        glVertex3f(x * outer_radius, border_height, z * outer_radius);
        glVertex3f(x * inner_radius, border_height, z * inner_radius);
    }
    glEnd();
}

// Draw flowers and plants
void drawFlowers() {
    srand(42); // Fix random seed for consistency

    // Generate flowers at random positions within the garden
    for (int i = 0; i < 60; i++) {
        // Generate random polar coordinates
        float angle = (float)(rand() % 360) * PI / 180.0;
        float radius = 3.0 * sqrt((float)(rand() % 100) / 100.0); // Use sqrt for more uniform distribution

        float x = cos(angle) * radius;
        float z = sin(angle) * radius;

        // Randomly select flower type
        int flower_type = rand() % 3;

        switch (flower_type) {
        case 0:
            drawDaisy(x, z);
            break;
        case 1:
            drawRose(x, z);
            break;
        case 2:
            drawTulip(x, z);
            break;
        }
    }
}

// Draw Daisy
void drawDaisy(float x, float z) {
    glPushMatrix();
    glTranslatef(x, 0.1, z);

    // Stem
    GLfloat stem_color[] = { 0.2, 0.8, 0.2, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, stem_color);

    glPushMatrix();
    glRotatef(-90, 1.0, 0.0, 0.0);
    GLUquadricObj* stem = gluNewQuadric();
    gluCylinder(stem, 0.02, 0.02, 0.4, 8, 1);
    gluDeleteQuadric(stem);
    glPopMatrix();

    // Petals (White)
    GLfloat petal_color[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, petal_color);

    glTranslatef(0.0, 0.4, 0.0);
    for (int i = 0; i < 8; i++) {
        glRotatef(45, 0.0, 1.0, 0.0);
        glPushMatrix();
        glScalef(0.15, 0.02, 0.05);
        glutSolidSphere(1.0, 8, 8);
        glPopMatrix();
    }

    // Center (Yellow)
    GLfloat center_color[] = { 1.0, 1.0, 0.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, center_color);
    glutSolidSphere(0.06, 8, 8);

    glPopMatrix();
}

// Draw Rose
void drawRose(float x, float z) {
    glPushMatrix();
    glTranslatef(x, 0.1, z);

    // Stem
    GLfloat stem_color[] = { 0.2, 0.8, 0.2, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, stem_color);

    glPushMatrix();
    glRotatef(-90, 1.0, 0.0, 0.0);
    GLUquadricObj* stem = gluNewQuadric();
    gluCylinder(stem, 0.02, 0.02, 0.5, 8, 1);
    gluDeleteQuadric(stem);
    glPopMatrix();

    // Flower (Red)
    GLfloat rose_color[] = { 0.8, 0.1, 0.1, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, rose_color);

    glTranslatef(0.0, 0.5, 0.0);

    // Multiple layers of petals
    for (int layer = 0; layer < 3; layer++) {
        float scale = 1.0 - layer * 0.2;
        for (int i = 0; i < 6; i++) {
            glRotatef(60, 0.0, 1.0, 0.0);
            glPushMatrix();
            glRotatef(45, 1.0, 0.0, 1.0);
            glScalef(0.12 * scale, 0.02, 0.12 * scale);
            glutSolidSphere(1.0, 8, 8);
            glPopMatrix();
        }
        glTranslatef(0.0, 0.05, 0.0);
    }

    glPopMatrix();
}

// Draw Tulip
void drawTulip(float x, float z) {
    glPushMatrix();
    glTranslatef(x, 0.1, z);

    // Stem
    GLfloat stem_color[] = { 0.2, 0.8, 0.2, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, stem_color);

    glPushMatrix();
    glRotatef(-90, 1.0, 0.0, 0.0);
    GLUquadricObj* stem = gluNewQuadric();
    gluCylinder(stem, 0.02, 0.02, 0.45, 8, 1);
    gluDeleteQuadric(stem);
    glPopMatrix();

    // Flower (Pink)
    GLfloat tulip_color[] = { 1.0, 0.4, 0.7, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, tulip_color);

    glTranslatef(0.0, 0.45, 0.0);

    // Petals
    for (int i = 0; i < 6; i++) {
        glRotatef(60, 0.0, 1.0, 0.0);
        glPushMatrix();
        glRotatef(30, 1.0, 0.0, 0.0);
        glScalef(0.08, 0.2, 0.08);
        glutSolidSphere(1.0, 8, 8);
        glPopMatrix();
    }

    glPopMatrix();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    // Create window
    width = 800;
    height = 600;
    glutInitWindowSize(width, height);
    glutCreateWindow("3D Car Scene");

    // Initialize camera position - adjust to face the vehicle
    camera_x = 0.0;
    camera_z = 10.0;
    camera_angle_y = -180.0;
    camera_angle_x = -20.0;   // Slightly downward view
    camera_height = 6.0;

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboardUp);
    glutSpecialFunc(specialKeys);
    glutSpecialUpFunc(specialKeysUp);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}