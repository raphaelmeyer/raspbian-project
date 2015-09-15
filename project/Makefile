all: application unit-tests

unit-tests: host-src
	cmake --build ~/host --target unit-tests
	~/host/unit-tests/unit-tests

application: target-src
	cmake --build ~/target --target display
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

