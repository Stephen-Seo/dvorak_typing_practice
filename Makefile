ifdef RELEASE
CXX_FLAGS = -Wall -Wextra -Wpedantic -O3 -DNDEBUG
else
CXX_FLAGS = -Wall -Wextra -Wpedantic -Og -g
endif

OBJDIR = objects

SOURCES = src/main.cc

OBJECTS = $(addprefix ${OBJDIR}/,$(subst .cc,.o,${SOURCES}))

all: dvorak_typing_practice

dvorak_typing_practice: ${OBJECTS}
	${CXX} ${CXX_FLAGS} -o dvorak_typing_practice $^ -lraylib

${OBJDIR}/%.o: %.cc
	@mkdir -p $$(dirname $@)
	${CXX} ${CXX_FLAGS} -c -o $@ $<

.PHONY: clean

clean:
	rm -rf ${OBJDIR}
	rm -f dvorak_typing_practice
