all:
	g++ src/glad.c src/main.cpp src/Shader.cpp src/stb_image.cpp src/Camera.cpp -std=c++17 -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl -o out

