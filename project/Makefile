all: display unit-tests

unit-tests: host-src
	cmake --build ~/host --target $@
	~/host/unit-tests/$@

integration-tests: host-src
	cmake --build ~/host --target $@
	~/host/integration-tests/$@

display: target-src
	cmake --build ~/target --target $@
	cp ~/target/main/display ~/artifacts/

clean-target:
	cmake --build ~/target --target clean

clean-host:
	cmake --build ~/host --target clean

clean: clean-target clean-host

target-src:
	mkdir -p ~/target
	cd ~/target && cmake -DCMAKE_TOOLCHAIN_FILE=~/project/rpi.cmake ~/project/source/

host-src:
	mkdir -p ~/host
	cd ~/host && cmake ~/project/source

