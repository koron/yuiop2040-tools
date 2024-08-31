PICO_PLATFORM=rp2040

ifeq ($(PICO_PLATFORM),rp2040)
	BUILD_DIR=build
else
	BUILD_DIR=build/$(PICO_PLATFORM)
endif

default: $(BUILD_DIR)/Makefile
	cmake --build $(BUILD_DIR) --parallel 8

$(BUILD_DIR)/Makefile: CMakeLists.txt */CMakeLists.txt
	cmake -B $(BUILD_DIR)

.PHONY: clean
clean:
	if [ -f $(BUILD_DIR)/Makefile ] ; then make -C $(BUILD_DIR) clean ; fi

.PHONY: distclean
distclean:
	rm -rf build
	rm -f tags

.PHONY: tags
tags:
	ctags --exclude=build/* --exclude=tmp/* -R .
