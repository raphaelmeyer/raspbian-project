all: application unit-tests

unit-tests: host-src
	cmake --build ~/host --target unit-tests
	~/host/unit-tests/unit-tests

application: target-src
	cmake --build ./target --target display

clean-target:
	cmake --build ./target --target clean

clean-host:
	cmake --build ~/host --target clean

clean: clean-target clean-host

target-src:
	mkdir -p ~/target
	cd ~/target && cmake -DCMAKE_TOOLCHAIN_FILE=/vagrant/rpi.cmake /vagrant/source/

host-src:
	mkdir -p ~/host
	cd ~/host && cmake /vagarant/source/

