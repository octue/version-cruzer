# Programs
PYTHON = python3
CMAKE = cmake
POETRY = poetry
PIP = pip3

MAKEFILE_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

.PHONY: all
all: compile test
.PHONY: compile
compile: wrapper.cc
	$(POETRY) build --format=wheel -vvv --output=$(MAKEFILE_DIR)/dist

.PHONY: test
test: test.py
	$(PIP) install --target=$(MAKEFILE_DIR)/build dist/pycruzer-*.whl
	$(PYTHON) $<
