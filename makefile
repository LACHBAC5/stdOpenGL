VPATH = glad shader shape
DEPS = -I./

LIST= glad.o shader_program.o circle.o
LIBCMPLE=false

all: $(LIST) libcmple.out
	$(if $(filter $(LIBCMPLE), true), ./libcmple.out)

%.o: %.cpp
	g++ -o $@ -c $(DEPS) $<
	$(eval LIBCMPLE=true)

%.o: %.c
	gcc -o $@ -c $(DEPS) $<
	$(eval LIBCMPLE=true)

libcmple.out: libcmple.c
	gcc -o $@ -O3 $<
