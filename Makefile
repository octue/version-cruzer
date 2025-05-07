# Programs
CMAKE = cmake
CTEST = ctest
PYTHON = python3

# Options
PRESET = Debug

all: configure compile test

configure: .always
	$(CMAKE) -S . -B ./build \
		-DCMAKE_BUILD_TYPE:STRING=$(PRESET) \
		-DCMAKE_COMPILE_WARNING_AS_ERROR:BOOL=ON \
		-DCRUZER_TESTS:BOOL=ON \
		-DCRUZER_PYTHON:BOOL=OFF \
		-DBUILD_SHARED_LIBS:BOOL=OFF

compile: .always
	$(CMAKE) --build ./build --config $(PRESET) --target clang_format
	$(CMAKE) --build ./build --config $(PRESET) --parallel 4

test: .always
	$(CTEST) --test-dir ./build --build-config $(PRESET) \
		--output-on-failure --parallel

clean: .always
	$(CMAKE) -E rm -R -f build \
		bindings/webassembly/build \
		bindings/webassembly/dist \
		bindings/python/build \
		bindings/python/dist

webassembly: .always
	$(MAKE) -C bindings/webassembly

python: .always
	$(MAKE) -C bindings/python

.always:
