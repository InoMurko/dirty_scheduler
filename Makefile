.PHONY: update-deps

ERLANG_BIN       = $(shell dirname $(shell which erl))
GITHASH       = $(shell git rev-parse --verify HEAD)

$(if $(ERLANG_BIN),,$(warning "Warning: No Erlang found in your path, this will probably not work"))

all: compile

compile:
	@echo ${GITHASH} > VERSION
	./rebar compile
	
clean:
	./rebar delete-deps
	./rebar clean
	rm -f ebin/*
