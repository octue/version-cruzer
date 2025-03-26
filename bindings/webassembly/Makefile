# Programs
EMCC ?= emcc
MKDIR ?= mkdir
SED ?= sed
NODE ?= node
CMAKE ?= cmake

# Misc
ROOT := ../..

# Flags
CFLAGS ?= -O3 -std=c11 -flto
CXXFLAGS ?= -O3 -std=c++20 -flto \
	-I$(ROOT)/vendor/core/vendor/uriparser/include \
	-I$(ROOT)/vendor/core/vendor/boost-regex/include \
	-I$(ROOT)/vendor/core/src/core/uri/include \
	-I$(ROOT)/vendor/core/src/core/json/include \
	-I$(ROOT)/vendor/core/src/core/regex/include \
	-I$(ROOT)/vendor/core/src/core/jsonpointer/include \
	-I$(ROOT)/vendor/core/src/core/jsonschema/include \
	-I$(ROOT)/src/include \
	-DOCTUE_CRUZER_EXPORT= \
	-DSOURCEMETA_CORE_URI_EXPORT= \
	-DSOURCEMETA_CORE_JSON_EXPORT= \
	-DSOURCEMETA_CORE_JSONPOINTER_EXPORT= \
	-DSOURCEMETA_CORE_JSONSCHEMA_EXPORT=

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

dist: ; $(MKDIR) $@
build: ; $(MKDIR) $@
build/uri: | build; $(MKDIR) $@
build/json: | build; $(MKDIR) $@
build/jsonpointer: | build; $(MKDIR) $@
build/jsonschema: | build; $(MKDIR) $@
build/cruzer: | build; $(MKDIR) $@

# URIParser
build/uriparser: | build; $(MKDIR) $@
build/uriparser/UriConfig.h: $(ROOT)/vendor/core/vendor/uriparser/src/UriConfig.h.in | build/uriparser
	$(SED) -e 's/@PROJECT_VERSION@/0.0.0/g' -e 's/#cmakedefine/#undef/g' $< > $@
build/uriparser/%.o: $(ROOT)/vendor/core/vendor/uriparser/src/%.c build/uriparser/UriConfig.h | build/uriparser
	$(EMCC) $(CFLAGS) -o $@ $< -I$(ROOT)/vendor/core/vendor/uriparser/include -I$(dir $(word 2,$^)) -c

build/jsonschema/official_resolver.in.cc: \
	$(ROOT)/vendor/core/src/core/jsonschema/official_resolver.cmake \
	$(ROOT)/vendor/core/src/core/jsonschema/official_resolver.in.cc \
	| build/jsonschema
	$(CMAKE) \
		-DPROJECT_SOURCE_DIR=$(ROOT)/vendor/core \
		-DOFFICIAL_RESOLVER_INPUT=$(ROOT)/vendor/core/src/core/jsonschema/official_resolver.in.cc \
		-DOFFICIAL_RESOLVER_OUTPUT=$@ -P $<

build/%.o: build/%.cc \
	| build/uri build/json build/jsonpointer build/jsonschema
	$(EMCC) $(CXXFLAGS) -o $@ -c $<
build/%.o: $(ROOT)/vendor/core/src/core/%.cc \
	| build/uri build/json build/jsonpointer build/jsonschema
	$(EMCC) $(CXXFLAGS) -o $@ -c $<
build/cruzer/%.o: $(ROOT)/src/%.cc \
	| build/cruzer
	$(EMCC) $(CXXFLAGS) -o $@ -c $<

dist/%.js: %.cc \
	$(patsubst ../../vendor/core/vendor/uriparser/src/%.c,build/uriparser/%.o,$(wildcard $(ROOT)/vendor/core/vendor/uriparser/src/*.c)) \
	$(patsubst ../../vendor/core/src/core/%.cc,build/%.o,$(wildcard $(ROOT)/vendor/core/src/core/uri/*.cc)) \
	$(patsubst ../../vendor/core/src/core/%.cc,build/%.o,$(wildcard $(ROOT)/vendor/core/src/core/json/*.cc)) \
	$(patsubst ../../vendor/core/src/core/%.cc,build/%.o,$(wildcard $(ROOT)/vendor/core/src/core/jsonpointer/*.cc)) \
	$(patsubst ../../vendor/core/src/core/%.cc,build/%.o,$(wildcard $(ROOT)/vendor/core/src/core/jsonschema/*.cc)) \
	build/cruzer/cruzer.o \
	| dist
	$(EMCC) $(CXXFLAGS) $(LDFLAGS) -o $@ $^
