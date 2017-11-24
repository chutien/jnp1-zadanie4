# Polecenia do uzywania:
# make
# make all
# make release
# make debug
# make clean

BIN=./bin_release
BIN_DEBUG=./bin_debug
CFLAGS=-O2 -Wall -Wextra -Winit-self -Wunreachable-code 
CXXFLAGS=-O2 -Wall -Wextra -Winit-self -Wunreachable-code -std=c++17
FLAGSPROD=-DNDEBUG

LIST:=dict.o dictglobal.o
OBJS:=$(addprefix $(BIN)/, $(LIST))
OBJS_DEBUG:=$(addprefix $(BIN_DEBUG)/, $(LIST))

.PHONY: all clean debug release test1 test2a test2b test_original test1_debug test2a_debug test2b_debug test_original_debug

debug: test1_debug test2a_debug test2b_debug test_original_debug
all: release debug
release: test1 test2a test2b test_original

clean:
	$(RM) -r $(BIN) $(BIN_DEBUG)




test1: $(OBJS) $(BIN)/dict_test1.o
	@mkdir -p `dirname $@`
	$(CXX) $(OBJS) $(BIN)/dict_test1.o -o $(BIN)/dictionary_test1

test2a: $(OBJS) $(BIN)/dict_test2a.o
	@mkdir -p `dirname $@`
	$(CXX) $(OBJS) $(BIN)/dict_test2a.o -o $(BIN)/dictionary_test2a

test2b: $(OBJS) $(BIN)/dict_test2b.o
	@mkdir -p `dirname $@`
	$(CXX) $(OBJS) $(BIN)/dict_test2b.o -o $(BIN)/dictionary_test2b
	
test_original: $(OBJS) $(BIN)/dict_test_original.o
	@mkdir -p `dirname $@`
	$(CXX) $(OBJS) $(BIN)/dict_test_original.o -o $(BIN)/dictionary_test_original


$(BIN)/dict.o: dict.cc dict.h
	@mkdir -p `dirname $@`
	$(CXX) $(CXXFLAGS) $(FLAGSPROD) -c -o $@ $<

$(BIN)/dictglobal.o: dictglobal.cc dictglobal.h
	@mkdir -p `dirname $@`
	$(CXX) $(CXXFLAGS) $(FLAGSPROD) -c -o $@ $<

$(BIN)/dict_test1.o: dict_test1.c
	@mkdir -p `dirname $@`
	$(CC) $(CFLAGS) $(FLAGSPROD) -c -o $@ $<

$(BIN)/dict_test2a.o: dict_test2a.cc
	@mkdir -p `dirname $@`
	$(CXX) $(CXXFLAGS) $(FLAGSPROD) -c -o $@ $<

$(BIN)/dict_test2b.o: dict_test2b.cc
	@mkdir -p `dirname $@`
	$(CXX) $(CXXFLAGS) $(FLAGSPROD) -c -o $@ $<
	
$(BIN)/dict_test_original.o: dict_test_original.cc
	@mkdir -p `dirname $@`
	$(CXX) $(CXXFLAGS) $(FLAGSPROD) -c -o $@ $<




test1_debug: $(OBJS_DEBUG) $(BIN_DEBUG)/dict_test1.o
	@mkdir -p `dirname $@`
	$(CXX) $(OBJS_DEBUG) $(BIN_DEBUG)/dict_test1.o -o $(BIN_DEBUG)/dictionary_test1

test2a_debug: $(OBJS_DEBUG) $(BIN_DEBUG)/dict_test2a.o
	@mkdir -p `dirname $@`
	$(CXX) $(OBJS_DEBUG) $(BIN_DEBUG)/dict_test2a.o -o $(BIN_DEBUG)/dictionary_test2a

test2b_debug: $(OBJS_DEBUG) $(BIN_DEBUG)/dict_test2b.o
	@mkdir -p `dirname $@`
	$(CXX) $(OBJS_DEBUG) $(BIN_DEBUG)/dict_test2b.o -o $(BIN_DEBUG)/dictionary_test2b
	
test_original_debug: $(OBJS_DEBUG) $(BIN_DEBUG)/dict_test_original.o
	@mkdir -p `dirname $@`
	$(CXX) $(OBJS_DEBUG) $(BIN_DEBUG)/dict_test_original.o -o $(BIN_DEBUG)/dictionary_test_original


$(BIN_DEBUG)/dict.o: dict.cc dict.h
	@mkdir -p `dirname $@`
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BIN_DEBUG)/dictglobal.o: dictglobal.cc dictglobal.h
	@mkdir -p `dirname $@`
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BIN_DEBUG)/dict_test1.o: dict_test1.c
	@mkdir -p `dirname $@`
	$(CC) $(CFLAGS) -c -o $@ $<

$(BIN_DEBUG)/dict_test2a.o: dict_test2a.cc
	@mkdir -p `dirname $@`
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BIN_DEBUG)/dict_test2b.o: dict_test2b.cc
	@mkdir -p `dirname $@`
	$(CXX) $(CXXFLAGS) -c -o $@ $<
	
	
$(BIN_DEBUG)/dict_test_original.o: dict_test_original.cc
	@mkdir -p `dirname $@`
	$(CXX) $(CXXFLAGS) -c -o $@ $<

