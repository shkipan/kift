BASE=sphinxbase
POCKET=pocketsphinx
all:
	cd $(BASE) && pwd && ./configure --prefix=$(CURDIR)/../lib/Sphinx && make check && make && make install
	cd $(POCKET) && pwd && ./configure --prefix=$(CURDIR)/../lib/Sphinx && make check && make && make install

clean:
	find . -name "*.o" -exec rm -rf {} \;