SOURCES = controller/* model/* view/*

.PHONY: all dist clean install uninstall dvi build

build:
	cmake -S . -B ./../build
	cmake --build ./../build

install: build
	cp -rf ./../build/PhotoLab.app $(HOME)/Applications/

uninstall:
	rm -rf $(HOME)/Applications/PhotoLab.app

clean:
	rm -rf ./../build

style:
	clang-format -i $(SOURCES)
	clang-format -n -verbose -style=Google $(SOURCES)

dist: clean
	tar -czf PhotoLab.tgz ./*

dvi:
	open readme.pdf

tests:
	cmake -S ./test -B build_test
	cmake --build build_test
	./build_test/PhotoLab_test