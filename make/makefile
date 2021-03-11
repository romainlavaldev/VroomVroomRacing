vvr: MainMenu.o easySDL.o VVR.o SoloCircuitMenu.o SoloVoitureMenu.o
	gcc -o ../bin/VroomVroomRacingMakeFile MainMenu.o SoloCircuitMenu.o SoloVoitureMenu.o easySDL.o VVR.o -I ../include -L ../lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_mixer

MainMenu.o: ../src/MainMenu.c
	gcc -o MainMenu.o -c ../src/MainMenu.c -I ../include

SoloCircuitMenu.o: ../src/SoloCircuitMenu.c
	gcc -o SoloCircuitMenu.o -c ../src/SoloCircuitMenu.c -I ../include

SoloVoitureMenu.o: ../src/SoloVoitureMenu.c
	gcc -o SoloVoitureMenu.o -c ../src/SoloVoitureMenu.c -I ../include

easySDL.o: ../src/easySDL.c
	gcc -o easySDL.o -c ../src/easySDL.c -I ../include

VVR.o: ../src/VVR.c
	gcc -o VVR.o -c ../src/VVR.c -I ../include


