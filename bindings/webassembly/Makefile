# Programs
EMCC ?= emcc
EMCMAKE ?= emcmake
MKDIR ?= mkdir
NODE ?= node
CMAKE ?= cmake

# Misc
ROOT := ../..
BUILD := build
CMAKE_BUILD := $(BUILD)/cmake

# Flags
CXXFLAGS ?= -O3 -std=c++23 -flto \
	-I$(ROOT)/src/include \
	-I$(CMAKE_BUILD)/src/include \
	-I$(ROOT)/vendor/core/src/core/json/include \
	-I$(ROOT)/vendor/core/src/core/jsonpointer/include \
	-I$(ROOT)/vendor/core/src/core/jsonschema/include \
	-I$(ROOT)/vendor/core/src/core/regex/include \
	-I$(ROOT)/vendor/core/src/core/uri/include \
	-I$(ROOT)/vendor/core/src/core/ip/include \
	-I$(ROOT)/vendor/core/src/core/unicode/include \
	-I$(ROOT)/vendor/core/src/lang/numeric/include \
	-I$(ROOT)/vendor/core/src/lang/io/include \
	-I$(ROOT)/vendor/core/src/lang/preprocessor/include \
	-I$(CMAKE_BUILD)/vendor/core/src/core/json/include \
	-I$(CMAKE_BUILD)/vendor/core/src/core/jsonpointer/include \
	-I$(CMAKE_BUILD)/vendor/core/src/core/jsonschema/include \
	-I$(CMAKE_BUILD)/vendor/core/src/core/regex/include \
	-I$(CMAKE_BUILD)/vendor/core/src/core/uri/include \
	-I$(CMAKE_BUILD)/vendor/core/src/core/ip/include \
	-I$(CMAKE_BUILD)/vendor/core/src/core/unicode/include \
	-I$(CMAKE_BUILD)/vendor/core/src/lang/numeric/include \
	-I$(CMAKE_BUILD)/vendor/core/src/lang/io/include

# Static libraries built by the CMake configure step below, in link order
# (dependents first). `octue_cruzer` depends on the vendor libraries, and
# those in turn depend on PCRE2 and each other.
STATIC_LIBS := \
	$(CMAKE_BUILD)/src/liboctue_cruzer.a \
	$(CMAKE_BUILD)/vendor/core/src/core/jsonschema/libsourcemeta_core_jsonschema.a \
	$(CMAKE_BUILD)/vendor/core/src/core/jsonpointer/libsourcemeta_core_jsonpointer.a \
	$(CMAKE_BUILD)/vendor/core/src/core/regex/libsourcemeta_core_regex.a \
	$(CMAKE_BUILD)/vendor/core/libpcre2.a \
	$(CMAKE_BUILD)/vendor/core/src/core/uri/libsourcemeta_core_uri.a \
	$(CMAKE_BUILD)/vendor/core/src/core/ip/libsourcemeta_core_ip.a \
	$(CMAKE_BUILD)/vendor/core/src/core/json/libsourcemeta_core_json.a \
	$(CMAKE_BUILD)/vendor/core/src/core/unicode/libsourcemeta_core_unicode.a \
	$(CMAKE_BUILD)/vendor/core/src/lang/numeric/libsourcemeta_core_numeric.a \
	$(CMAKE_BUILD)/vendor/core/src/lang/io/libsourcemeta_core_io.a

# See https://emscripten.org/docs/tools_reference/settings_reference.html
LDFLAGS ?= -lembind -s EXPORT_NAME=cruzer -DNDEBUG \
					 -s EVAL_CTORS=2 -s WASM=1 -s NO_EXIT_RUNTIME=1 -s ASSERTIONS=0 \
					 -s MODULARIZE=1 -s EXPORT_ES6=1 -s ENVIRONMENT=node

.PHONY: all
all: compile test
.PHONY: compile
compile: dist/wrapper.js
.PHONY: test
test: test.js
	$(NODE) $<

$(BUILD): ; $(MKDIR) $@
dist: ; $(MKDIR) $@

$(CMAKE_BUILD)/CMakeCache.txt: | $(BUILD)
	$(EMCMAKE) $(CMAKE) -S $(ROOT) -B $(CMAKE_BUILD) \
		-DCMAKE_BUILD_TYPE=Release \
		-DCRUZER_TESTS=OFF \
		-DCRUZER_PYTHON=OFF \
		-DBUILD_SHARED_LIBS=OFF \
		-DCMAKE_COMPILE_WARNING_AS_ERROR=OFF \
		-DSOURCEMETA_CORE_LANG_PARALLEL=OFF \
		-DSOURCEMETA_CORE_LANG_PROCESS=OFF \
		-DSOURCEMETA_CORE_LANG_ERROR=OFF \
		-DSOURCEMETA_CORE_LANG_OPTIONS=OFF \
		-DSOURCEMETA_CORE_PUNYCODE=OFF \
		-DSOURCEMETA_CORE_TIME=OFF \
		-DSOURCEMETA_CORE_CRYPTO=OFF \
		-DSOURCEMETA_CORE_URITEMPLATE=OFF \
		-DSOURCEMETA_CORE_SEMVER=OFF \
		-DSOURCEMETA_CORE_HTML=OFF \
		-DSOURCEMETA_CORE_EXTENSION_ALTERSCHEMA=OFF \
		-DSOURCEMETA_CORE_EXTENSION_EDITORSCHEMA=OFF \
		-DSOURCEMETA_CORE_INSTALL=OFF

.PHONY: $(STATIC_LIBS)
$(STATIC_LIBS): $(CMAKE_BUILD)/CMakeCache.txt
	$(CMAKE) --build $(CMAKE_BUILD) --target octue_cruzer --parallel 4

dist/wrapper.js: wrapper.cc $(STATIC_LIBS) | dist
	$(EMCC) $(CXXFLAGS) $(LDFLAGS) -o $@ wrapper.cc $(STATIC_LIBS)
