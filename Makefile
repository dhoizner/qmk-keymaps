USER = dhoizner

KEYBOARDS = relic
PATH_relic = projectcain/relic

all: $(KEYBOARDS)

FLASH?=false

.PHONY: $(KEYBOARDS)
$(KEYBOARDS):
	# init submodule
	git submodule update --init --recursive
	git submodule update --remote

	# cleanup old symlinks
	for f in $(KEYBOARDS); do rm -rf qmk_firmware/keyboards/$(PATH_$@)/keymaps/$(USER); done
	rm -rf qmk_firmware/users/$(USER)

	# add new symlinks
	ln -s $(shell pwd)/user qmk_firmware/users/$(USER)
	ln -s $(shell pwd)/$@ qmk_firmware/keyboards/$(PATH_$@)/keymaps/$(USER)

	# run lint check
	cd qmk_firmware; qmk lint -km $(USER) -kb $(PATH_$@) --strict

	# run build
ifeq ($(FLASH),true)
	make BUILD_DIR=$(shell pwd)/build -j1 -C qmk_firmware $(PATH_$@):$(USER):flash
else
	make BUILD_DIR=$(shell pwd)/build -j1 -C qmk_firmware $(PATH_$@):$(USER)
endif

	# cleanup symlinks
	for f in $(KEYBOARDS); do rm -rf qmk_firmware/keyboards/$(PATH_$@)/keymaps/$(USER); done
	rm -rf qmk_firmware/users/$(USER)

clean:
	rm -rf obj_*
	rm -f *.elf
	rm -f *.map
	rm -f *.hex
	rm -rf ./build
