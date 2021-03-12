test: TestOpenGLGLFW.o RawModel.o Renderer.o list.o
	gcc -o ../bin/testGLGLFW TestOpenGLGLFW.o RawModel.o Renderer.o list.o -I ../include -L ../lib -lmingw32 -lglew32 -lglfw3 -lgdi32 -lopengl32

TestOpenGLGLFW.o: ../src/TestOpenGLGLFW.c
	gcc -o TestOpenGLGLFW.o -c ../src/TestOpenGLGLFW.c -I ../include 

RawModel.o: ../src/RawModel.c
	gcc -o RawModel.o -c ../src/RawModel.c -I ../include 

list.o: ../src/list.c
	gcc -o list.o -c ../src/list.c -I ../include 

Renderer.o: ../src/Renderer.c
	gcc -o Renderer.o -c ../src/Renderer.c -I ../include 
	