BASE=sphinxbase
POCKET=pocketsphinx
TRAIN=sphinxtrain
BASE_PATH=$(shell cd ../lib/ && pwd)/Sphinx
MAIN_PATH=$(shell pwd)
CONFIG_PATH="PKG_CONFIG_PATH=$(BASE_PATH)/lib/pkgconfig"

all:
	echo $(BASE_PATH)
	@mkdir -p $(BASE)/build
	@mkdir -p $(POCKET)/build
	@mkdir -p $(TRAIN)/build
	cd $(BASE)/build && pwd && ../configure --prefix=$(BASE_PATH) && make check && make && make install
	export $(CONFIG_PATH) && cd $(POCKET)/build && pwd && ../configure --prefix=$(BASE_PATH) && make check && make && make install
	export $(CONFIG_PATH) && cd $(TRAIN)/build && pwd && ../configure --prefix=$(BASE_PATH) --with-sphinxbase-build=$(MAIN_PATH)/sphinxbase/build/ && make check && make && make install

clean:
	@cd $(BASE)/build && rm -rf *
	@cd $(POCKET)/build && rm -rf *
	@cd $(TRAIN)/build && rm -rf *

fclean: clean
	@cd $(BASE_PATH) && rm -rf *