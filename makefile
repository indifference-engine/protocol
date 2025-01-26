ifeq ($(OS),Windows_NT)
	CC = x86_64-w64-mingw32-gcc
else
	CC = clang
endif

CFLAGS = -Wall -Wextra -Werror -std=c99 -nostdlib -ffreestanding -O3 -pedantic -ffp-contract=off

# Unfortunately, I have found that make quite often selects the wrong shell
# (e.g. PowerShell), so commands like "find" won't work unless we explicitly
# specify bash.  You also can't use a variable for this (e.g. $(SHELL)) as make
# inexplicably tries to read something from the PATH and fails.  So hardcoding a
# reference to bash seems to be the only way to get a working build.
C_FILES = $(shell bash -c "find src -type f -iname ""*.c""") $(shell bash -c "find tests/helpers -type f -iname ""*.c""")
H_FILES = $(shell bash -c "find src -type f -iname ""*.h""") $(shell bash -c "find tests/helpers -type f -iname ""*.h""")
O_FILES = $(patsubst %.c,obj/%.o,$(C_FILES))
TOTAL_REBUILD_FILES = makefile $(H_FILES)

TEST_CASES = $(patsubst tests/cases/%, %, $(shell bash -c "find tests/cases -mindepth 1 -maxdepth 1 -type d"))

test: $(patsubst %, tests/cases/%/passed, $(TEST_CASES))

dist/%: tests/cases/%/main.c $(O_FILES)
	mkdir -p $(dir $@)
	$(CC) $(CLAGS) -flto $^ -o $@

obj/%.o: %.c $(TOTAL_REBUILD_FILES)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

tests/cases/%/passed: dist/%
	$<
	touch $@

clean:
	rm -rf obj dist $(patsubst %, tests/cases/%/passed, $(TEST_CASES))
