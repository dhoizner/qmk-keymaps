USER = dhoizner

KEYBOARDS = relic dactyl

PATH_relic = projectcain/relic
QMK_relic = qmk_firmware

PATH_dactyl = handwired/wylderbuilds/3x5_2
QMK_dactyl = wylderbuilds_qmk

all: $(KEYBOARDS)

FLASH?=false

.PHONY: $(KEYBOARDS)
$(KEYBOARDS):
	# init submodule
	git submodule update --init --recursive
	# git submodule update --remote

	# cleanup old symlinks
	for f in $(KEYBOARDS); do rm -rf $(QMK_$@)/keyboards/$(PATH_$@)/keymaps/$(USER); done
	rm -rf qmk_firmware/users/$(USER)
	rm -rf wylderbuilds_qmk/users/$(USER)

	# add new symlinks
	ln -s $(shell pwd)/user $(QMK_$@)/users/$(USER)
	ln -s $(shell pwd)/$@ $(QMK_$@)/keyboards/$(PATH_$@)/keymaps/$(USER)

	# run lint check
	cd $(QMK_$@); qmk lint -km $(USER) -kb $(PATH_$@) --strict

	# run build
ifeq ($(FLASH),true)
	make BUILD_DIR=$(shell pwd)/build -j1 -C $(QMK_$@) $(PATH_$@):$(USER):flash
else
	make BUILD_DIR=$(shell pwd)/build -j1 -C $(QMK_$@) $(PATH_$@):$(USER)
endif

	# cleanup symlinks
	for f in $(KEYBOARDS); do rm -rf $(QMK_$@)/keyboards/$(PATH_$@)/keymaps/$(USER); done
	rm -rf qmk_firmware/users/$(USER)
	rm -rf wylderbuilds_qmk/users/$(USER)

clean:
	rm -rf obj_*
	rm -f *.elf
	rm -f *.map
	rm -f *.hex
	rm -rf ./build
