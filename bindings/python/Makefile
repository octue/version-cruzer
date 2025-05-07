# Programs
PYTHON = python3
CMAKE = cmake

MAKEFILE_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

.PHONY: all
all: compile test
.PHONY: compile
compile: wrapper.cc
	$(CMAKE) -S ../.. -B ./build \
		-DCMAKE_BUILD_TYPE:STRING=Release \
		-DCRUZER_TESTS:BOOL=OFF \
		-DCRUZER_PYTHON:BOOL=ON \
		-DBUILD_SHARED_LIBS:BOOL=OFF
	$(CMAKE) --build ./build --config Release --parallel 4
	$(CMAKE) --install ./build --prefix ./dist --config Release \
		--verbose --component pycruzer

.PHONY: test
test: test.py
	PYTHONPATH=$(MAKEFILE_DIR)/dist/lib:$$PYTHONPATH $(PYTHON) $<
