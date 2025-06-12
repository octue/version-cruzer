# Programs
PYTHON = python3
CMAKE = cmake
UV = uv
PIP = pip3

MAKEFILE_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

.PHONY: all
all: compile test
.PHONY: compile
compile: wrapper.cc
	$(UV) build --wheel -v --directory=../.. --out-dir=$(MAKEFILE_DIR)/dist

.PHONY: test
test: test.py
	$(PIP) install dist/pycruzer-*.whl
	$(PYTHON) $<
