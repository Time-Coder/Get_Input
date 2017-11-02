MainSource := example.cpp
MainObject := example.o
MainExe := example

GetInputPath := ../../Get_Input
GetInputHead := getinput.h
GetInputSource := getinput.cpp
GetInputObject := getinput.o
GetInputLib := readline

INCLUDE := -I${GetInputPath}
DEPEND := ${MainObject} ${GetInputObject}

ifeq ($(shell uname), Linux)
	ifeq ($(shell getconf LONG_BIT), 32)
		LIBS = -L ${GetInputPath}/x86_lib -l${GetInputLib}
	else
		LIBS = -L ${GetInputPath}/x64_lib -l${GetInputLib}
	endif
	Build = g++ *.o -o ${MainExe} ${LIBS} -Wl,-rpath,${GetInputPath}
else
	DEPEND = ${MainObject} ${GetInputObject}
	Build = g++ *.o -o ${MainExe}
endif

${MainExe}: ${DEPEND}
	${Build}
	
${MainObject}: ${MainSource} ${MathFuncPath}/${MathFuncHead}
	g++ -std=c++11 ${INCLUDE} -c ${MainSource}

${GetInputObject}: ${GetInputPath}/${GetInputSource} ${GetInputPath}/${GetInputHead}
	g++ -std=c++11 ${INCLUDE} -c ${GetInputPath}/${GetInputSource}
 
clean:
	rm *.o