# raspbian-project

## build

    vagrant up
    vagrant ssh -c "make -C project"

## root fs

    rsync -rl --delete-after --safe-links pi@raspberrypi:/{lib,usr} ./rootfs

