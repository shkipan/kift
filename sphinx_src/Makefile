BASE=sphinxbase
POCKET=pocketsphinx

BASE_PATH=$(shell cd ../lib/ && pwd)/Sphinx
CONFIG_PATH="PKG_CONFIG_PATH=$(BASE_PATH)/lib/pkgconfig"

#
all:
	echo $(BASE_PATH)
	cd $(BASE)/build && pwd && ../configure --prefix=$(BASE_PATH) && make check && make && make install
	export $(CONFIG_PATH) && cd $(POCKET)/build && pwd && ../configure --prefix=$(BASE_PATH) && make check && make && make install

clean:
	cd $(BASE)/build && rm -rf *
	cd $(POCKET)/build && rm -rf *

fclean: clean
	cd $(BASE_PATH) && rm -rf *