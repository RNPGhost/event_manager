include config.mk
include rules.mk

# Conventionally, "make all" builds everything a makefile knows how to build.
all: bin/event_manager

# Specify the object files needed to generate the binary. These are always the
# same name as the cc files.
bin/event_manager: $(patsubst src/%.cc, obj/%.o, $(wildcard src/*.cc))
